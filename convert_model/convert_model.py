import sys

import chainer
import numpy as np
import webdnn
from PIL import Image
from chainer import Variable
from scipy.misc import imresize
from webdnn.frontend.chainer import ChainerConverter

from yolov2 import CocoPredictor

sys.setrecursionlimit(10000)


def main():
    width = 448
    height = 448

    predictor = CocoPredictor()
    image = Variable(np.zeros((1, 3, 448, 448), dtype=np.float32))
    with chainer.using_config('train', False):
        x, y, w, h, conf, prob, x_offset, y_offset, w_anchor, h_anchor = predictor(image)

    graph = ChainerConverter().convert_from_inout_vars([image, x_offset, y_offset, w_anchor, h_anchor], [x, y, w, h, conf, prob])

    desc = webdnn.backend.generate_descriptor("webgpu", graph, constant_encoder_name="eightbit")
    desc.save("../docs/model")

    desc = webdnn.backend.generate_descriptor("webassembly", graph, constant_encoder_name="eightbit")
    desc.save("../docs/model")

if __name__ == "__main__":
    main()
