///<reference path="../../../libs/webdnn.d.ts" />

import * as React from "react";
import dom from "../../../libs/dom";
import { loadImageDataFromCanvas } from "../../../libs/til/load_image_data";
import * as style from "./style.scss";

declare function require(path: string): any;

const Labels = [
    "person", "bicycle", "car", "motorcycle", "airplane", "bus", "train", "truck", "boat", "traffic light",
    "fire hydrant", "stop sign", "parking meter", "bench", "bird", "cat", "dog", "horse", "sheep", "cow", "elephant",
    "bear", "zebra", "giraffe", "backpack", "umbrella", "handbag", "tie", "suitcase", "frisbee", "skis", "snowboard",
    "sports ball", "kite", "baseball bat", "baseball glove", "skateboard", "surfboard", "tennis racket", "bottle",
    "wine glass", "cup", "fork", "knife", "spoon", "bowl", "banana", "apple", "sandwich", "orange", "broccoli", "carrot",
    "hot dog", "pizza", "donut", "cake", "chair", "couch", "potted plant", "bed", "dining table", "toilet", "tv",
    "laptop", "mouse", "remote", "keyboard", "cell phone", "microwave", "oven", "toaster", "sink", "refrigerator",
    "book", "clock", "vase", "scissors", "teddy bear", "hair drier", "toothbrush"
];
const Colors = ['#f00', '#0f0', '#00f', '#ff0', '#f0f', '#0ff', '#f80', '#80f', '#f08', '#08f', '#080'];
const ANCHORS = [[0.738768, 0.874946], [2.42204, 2.65704], [4.30971, 7.04493], [10.246, 4.59428], [12.6868, 11.8741]];

interface State {
    initialized: boolean
    running: boolean
}

export default class App extends React.Component<{}, State> {
    private runner: WebDNN.DescriptorRunner<WebDNN.GraphDescriptor>;
    private $video: HTMLVideoElement;
    private $input: HTMLCanvasElement;
    private $output: HTMLCanvasElement;
    private requested: boolean = false;

    constructor() {
        super();
        this.state = {
            initialized: false,
            running: false
        };
    }

    componentDidMount() {
        this.initAsync();
    }

    private onClick() {
        this.setState({ running: !this.state.running });

        if (this.requested) return;
        this.requested = true;
        requestAnimationFrame(() => this.run());
    }

    private async initAsync() {
        this.$video = dom.getFromRef<HTMLVideoElement>(this, 'video');
        this.$input = dom.getFromRef<HTMLCanvasElement>(this, 'input');
        this.$output = dom.getFromRef<HTMLCanvasElement>(this, 'output');

        this.runner = await WebDNN.load('./model');

        let xy_offset = new Float32Array(14);
        for (let i = 0; i < 14; i++) {
            xy_offset[i] = i;
        }
        this.runner.getInputViews()[1].set(xy_offset);
        this.runner.getInputViews()[2].set(xy_offset);

        let w_anchor = new Float32Array(5);
        let h_anchor = new Float32Array(5);
        for (let i = 0; i < 5; i++) {
            w_anchor[i] = ANCHORS[i][0];
            h_anchor[i] = ANCHORS[i][1];
        }

        this.runner.getInputViews()[3].set(w_anchor);
        this.runner.getInputViews()[4].set(h_anchor);

        let stream = await navigator.mediaDevices.getUserMedia({
            video: true,
            audio: false
        });

        this.$video.srcObject = stream;
        this.$video.play();

        this.setState({ initialized: true });
    }

    private async run() {
        this.requested = false;

        let $input = this.$input;
        let $output = this.$output;

        $input.getContext('2d')!.drawImage(this.$video, 0, 0, 448, 448);
        this.runner.getInputViews()[0].set(loadImageDataFromCanvas($input));

        await this.runner.run();

        let x = this.runner.getOutputViews()[0].toActual();
        let y = this.runner.getOutputViews()[1].toActual();
        let w = this.runner.getOutputViews()[2].toActual();
        let h = this.runner.getOutputViews()[3].toActual();
        let conf = this.runner.getOutputViews()[4].toActual();
        let prob = this.runner.getOutputViews()[5].toActual();

        const DETECTION_THRESHOLD = 0.5;
        let boxes: Box[] = [];
        for (let i = 0; i < 5 * 14 * 14; i++) {
            let maxScore = 0;
            let maxK = -1;

            for (let k = 0; k < 80; k++) {
                if (prob[i * 80 + k] > maxScore) {
                    maxScore = prob[i * 80 + k];
                    maxK = k;
                }
            }

            let probability = maxScore * conf[i];
            if (probability < DETECTION_THRESHOLD) continue;

            boxes.push({
                x0: Math.round(Math.min(1, Math.max(0, x[i] - w[i] / 2)) * 448),
                y0: Math.round(Math.min(1, Math.max(0, y[i] - h[i] / 2)) * 448),
                x1: Math.round(Math.min(1, Math.max(0, x[i] + w[i] / 2)) * 448),
                y1: Math.round(Math.min(1, Math.max(0, y[i] + h[i] / 2)) * 448),
                conf: conf[i],
                classId: maxK,
                className: Labels[maxK],
                probability: probability,
                classProbabilities: Array.from(prob.slice(i * 80 + 0, i * 80 + 80))
            });
        }
        boxes = nonMaximumSuppression(boxes);

        let context = $output.getContext('2d')!;
        context.drawImage(this.$video, 0, 0, 448, 448);

        context.font = '16px "sans-serif"';
        for (let box of boxes) {
            context.strokeStyle = Colors[box.classId % Colors.length];
            context.lineWidth = 3;
            context.strokeRect(box.x0, box.y0, box.x1 - box.x0, box.y1 - box.y0);

            context.fillStyle = Colors[box.classId % Colors.length];
            let w = context.measureText(box.className).width;
            context.fillRect(box.x0, box.y0 - 20, w + 8, 20);
            context.strokeRect(box.x0, box.y0 - 20, w + 8, 20);

            context.fillStyle = '#000';
            context.fillText(box.className, box.x0 + 4, box.y0 - 4);
        }

        if (this.requested) return;
        this.requested = true;
        requestAnimationFrame(() => this.run());
    }

    render() {
        return (
            <div className={style.app}>
                <video ref="video" />
                <canvas width="448" height="448" ref="input" style={{ display: 'none' }} />
                <canvas width="448" height="448" ref="output" />
                <button disabled={!this.state.initialized} onClick={() => this.onClick()}>{
                    this.state.initialized ?
                    this.state.running ?
                    'STOP' :
                    'RUN' :
                    'INITIALIZING...'
                }</button>
            </div>
        );
    }
}

interface Box {
    x0: number,
    y0: number,
    x1: number,
    y1: number,
    conf: number,
    classId: number,
    className: string,
    probability: number,
    classProbabilities: number[]
}

function intersection(bb1: Box, b2: Box) {
    return Math.max(0, Math.min(bb1.x1, b2.x1) - Math.max(bb1.x0, b2.x0)) *
        Math.max(0, Math.min(bb1.y1, b2.y1) - Math.max(bb1.y0, b2.y0));
}

function union(b1: Box, b2: Box) {
    return (b1.x1 - b1.x0) * (b1.y1 - b1.y0) + (b2.x1 - b2.x0) * (b2.y1 - b2.y0) - intersection(b1, b2);
}

function iou(b1: Box, b2: Box) {
    return intersection(b1, b2) / union(b1, b2);
}

function nonMaximumSuppression(boxes: Box[]) {
    const IOU_THRESHOLD = 0.5;
    let result: Box[] = [];

    boxes = boxes.sort((b1, b2) => b1.probability < b2.probability ? -1 : b1.probability > b2.probability ? +1 : 0);

    for (let i = 0; i < boxes.length; i++) {
        let flag = true;
        for (let j = i + 1; j < boxes.length; j++) {
            if (iou(boxes[i], boxes[j]) > IOU_THRESHOLD) {
                flag = false;
                break;
            }
        }
        if (flag) result.push(boxes[i]);
    }

    return result;
}
