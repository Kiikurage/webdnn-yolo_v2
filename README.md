## MEMO

- YOLO v2 pretrained weights

    1. Download darknet weights data from [here](https://github.com/leetenki/YOLOv2/issues/2#issuecomment-307002296).
    2. Convert it into chainer weights data.

        ```
        python convert_darknet_weight.py ./path_to_darknet_weight
        ```

- Convert model

    ```
    python convert_model.py
    ```