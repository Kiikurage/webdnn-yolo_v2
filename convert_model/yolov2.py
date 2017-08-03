import chainer.functions as F
import chainer.links as L
import numpy as np
from chainer import Variable, Chain, serializers


class YOLOv2(Chain):
    def __init__(self, n_classes, n_boxes):
        super(YOLOv2, self).__init__()
        with self.init_scope():
            self.conv1 = L.Convolution2D(3, 32, ksize=3, stride=1, pad=1, nobias=True)
            self.bn1 = L.BatchNormalization(32, use_beta=False, eps=2e-5)
            self.bias1 = L.Bias(shape=(32,))

            self.conv2 = L.Convolution2D(32, 64, ksize=3, stride=1, pad=1, nobias=True)
            self.bn2 = L.BatchNormalization(64, use_beta=False, eps=2e-5)
            self.bias2 = L.Bias(shape=(64,))

            self.conv3 = L.Convolution2D(64, 128, ksize=3, stride=1, pad=1, nobias=True)
            self.bn3 = L.BatchNormalization(128, use_beta=False, eps=2e-5)
            self.bias3 = L.Bias(shape=(128,))

            self.conv4 = L.Convolution2D(128, 64, ksize=1, stride=1, pad=0, nobias=True)
            self.bn4 = L.BatchNormalization(64, use_beta=False, eps=2e-5)
            self.bias4 = L.Bias(shape=(64,))

            self.conv5 = L.Convolution2D(64, 128, ksize=3, stride=1, pad=1, nobias=True)
            self.bn5 = L.BatchNormalization(128, use_beta=False, eps=2e-5)
            self.bias5 = L.Bias(shape=(128,))

            self.conv6 = L.Convolution2D(128, 256, ksize=3, stride=1, pad=1, nobias=True)
            self.bn6 = L.BatchNormalization(256, use_beta=False, eps=2e-5)
            self.bias6 = L.Bias(shape=(256,))

            self.conv7 = L.Convolution2D(256, 128, ksize=1, stride=1, pad=0, nobias=True)
            self.bn7 = L.BatchNormalization(128, use_beta=False, eps=2e-5)
            self.bias7 = L.Bias(shape=(128,))

            self.conv8 = L.Convolution2D(128, 256, ksize=3, stride=1, pad=1, nobias=True)
            self.bn8 = L.BatchNormalization(256, use_beta=False, eps=2e-5)
            self.bias8 = L.Bias(shape=(256,))

            self.conv9 = L.Convolution2D(256, 512, ksize=3, stride=1, pad=1, nobias=True)
            self.bn9 = L.BatchNormalization(512, use_beta=False, eps=2e-5)
            self.bias9 = L.Bias(shape=(512,))

            self.conv10 = L.Convolution2D(512, 256, ksize=1, stride=1, pad=0, nobias=True)
            self.bn10 = L.BatchNormalization(256, use_beta=False, eps=2e-5)
            self.bias10 = L.Bias(shape=(256,))

            self.conv11 = L.Convolution2D(256, 512, ksize=3, stride=1, pad=1, nobias=True)
            self.bn11 = L.BatchNormalization(512, use_beta=False, eps=2e-5)
            self.bias11 = L.Bias(shape=(512,))

            self.conv12 = L.Convolution2D(512, 256, ksize=1, stride=1, pad=0, nobias=True)
            self.bn12 = L.BatchNormalization(256, use_beta=False, eps=2e-5)
            self.bias12 = L.Bias(shape=(256,))

            self.conv13 = L.Convolution2D(256, 512, ksize=3, stride=1, pad=1, nobias=True)
            self.bn13 = L.BatchNormalization(512, use_beta=False, eps=2e-5)
            self.bias13 = L.Bias(shape=(512,))

            self.conv14 = L.Convolution2D(512, 1024, ksize=3, stride=1, pad=1, nobias=True)
            self.bn14 = L.BatchNormalization(1024, use_beta=False, eps=2e-5)
            self.bias14 = L.Bias(shape=(1024,))

            self.conv15 = L.Convolution2D(1024, 512, ksize=1, stride=1, pad=0, nobias=True)
            self.bn15 = L.BatchNormalization(512, use_beta=False, eps=2e-5)
            self.bias15 = L.Bias(shape=(512,))

            self.conv16 = L.Convolution2D(512, 1024, ksize=3, stride=1, pad=1, nobias=True)
            self.bn16 = L.BatchNormalization(1024, use_beta=False, eps=2e-5)
            self.bias16 = L.Bias(shape=(1024,))

            self.conv17 = L.Convolution2D(1024, 512, ksize=1, stride=1, pad=0, nobias=True)
            self.bn17 = L.BatchNormalization(512, use_beta=False, eps=2e-5)
            self.bias17 = L.Bias(shape=(512,))

            self.conv18 = L.Convolution2D(512, 1024, ksize=3, stride=1, pad=1, nobias=True)
            self.bn18 = L.BatchNormalization(1024, use_beta=False, eps=2e-5)
            self.bias18 = L.Bias(shape=(1024,))

            self.conv19 = L.Convolution2D(1024, 1024, ksize=3, stride=1, pad=1, nobias=True)
            self.bn19 = L.BatchNormalization(1024, use_beta=False)
            self.bias19 = L.Bias(shape=(1024,))

            self.conv20 = L.Convolution2D(1024, 1024, ksize=3, stride=1, pad=1, nobias=True)
            self.bn20 = L.BatchNormalization(1024, use_beta=False)
            self.bias20 = L.Bias(shape=(1024,))

            self.conv21 = L.Convolution2D(3072, 1024, ksize=3, stride=1, pad=1, nobias=True)
            self.bn21 = L.BatchNormalization(1024, use_beta=False)
            self.bias21 = L.Bias(shape=(1024,))

            self.conv22 = L.Convolution2D(1024, n_boxes * (5 + n_classes), ksize=1, stride=1, pad=0, nobias=True)
            self.bias22 = L.Bias(shape=(n_boxes * (5 + n_classes),))

    def __call__(self, x):
        h = F.leaky_relu(self.bias1(self.bn1(self.conv1(x))), slope=0.1)
        h = F.max_pooling_2d(h, ksize=2, stride=2, pad=0)
        h = F.leaky_relu(self.bias2(self.bn2(self.conv2(h))), slope=0.1)
        h = F.max_pooling_2d(h, ksize=2, stride=2, pad=0)
        h = F.leaky_relu(self.bias3(self.bn3(self.conv3(h))), slope=0.1)
        h = F.leaky_relu(self.bias4(self.bn4(self.conv4(h))), slope=0.1)
        h = F.leaky_relu(self.bias5(self.bn5(self.conv5(h))), slope=0.1)
        h = F.max_pooling_2d(h, ksize=2, stride=2, pad=0)
        h = F.leaky_relu(self.bias6(self.bn6(self.conv6(h))), slope=0.1)
        h = F.leaky_relu(self.bias7(self.bn7(self.conv7(h))), slope=0.1)
        h = F.leaky_relu(self.bias8(self.bn8(self.conv8(h))), slope=0.1)
        h = F.max_pooling_2d(h, ksize=2, stride=2, pad=0)
        h = F.leaky_relu(self.bias9(self.bn9(self.conv9(h))), slope=0.1)
        h = F.leaky_relu(self.bias10(self.bn10(self.conv10(h))), slope=0.1)
        h = F.leaky_relu(self.bias11(self.bn11(self.conv11(h))), slope=0.1)
        h = F.leaky_relu(self.bias12(self.bn12(self.conv12(h))), slope=0.1)
        h = F.leaky_relu(self.bias13(self.bn13(self.conv13(h))), slope=0.1)

        high_resolution_feature = F.space2depth(h, 2)

        h = F.max_pooling_2d(h, ksize=2, stride=2, pad=0)
        h = F.leaky_relu(self.bias14(self.bn14(self.conv14(h))), slope=0.1)
        h = F.leaky_relu(self.bias15(self.bn15(self.conv15(h))), slope=0.1)
        h = F.leaky_relu(self.bias16(self.bn16(self.conv16(h))), slope=0.1)
        h = F.leaky_relu(self.bias17(self.bn17(self.conv17(h))), slope=0.1)
        h = F.leaky_relu(self.bias18(self.bn18(self.conv18(h))), slope=0.1)
        h = F.leaky_relu(self.bias19(self.bn19(self.conv19(h))), slope=0.1)
        h = F.leaky_relu(self.bias20(self.bn20(self.conv20(h))), slope=0.1)
        h = F.concat((high_resolution_feature, h), axis=1)  # output concatenation
        h = F.leaky_relu(self.bias21(self.bn21(self.conv21(h))), slope=0.1)
        h = self.bias22(self.conv22(h))

        return h


class CocoPredictor(Chain):
    def __init__(self, weight_path="./yolov2_darknet.model"):
        super(CocoPredictor, self).__init__()

        self.n_classes = 80
        self.n_boxes = 5

        with self.init_scope():
            self.predictor = YOLOv2(n_classes=self.n_classes, n_boxes=self.n_boxes)

        serializers.load_hdf5(weight_path, self.predictor)  # load saved model

    def __call__(self, image):
        """
        image(Variable): data order is NCHW with N=1. Channel is RGB order. Also whose data is divided by 255.
        """
        # forward propagation
        output = self.predictor(image)

        _, _, grid_h, grid_w = output.shape

        # split result
        output = F.reshape(output, (self.n_boxes, 1 + 1 + 1 + 1 + 1 + self.n_classes, grid_h, grid_w))
        x, y, w, h, conf, prob = F.split_axis(output, (1, 2, 3, 4, 5), axis=1)

        x = F.reshape(x, (self.n_boxes, 1, grid_h, grid_w))
        y = F.reshape(y, (self.n_boxes, 1, grid_h, grid_w))
        w = F.reshape(w, (self.n_boxes, 1, grid_h, grid_w))
        h = F.reshape(h, (self.n_boxes, 1, grid_h, grid_w))
        conf = F.reshape(conf, (self.n_boxes, 1, grid_h, grid_w))
        prob = F.reshape(prob, (self.n_boxes, self.n_classes, grid_h, grid_w))

        # activation
        x = F.sigmoid(x)
        y = F.sigmoid(y)
        w = F.exp(w)
        h = F.exp(h)
        conf = F.sigmoid(conf)
        prob = F.softmax(prob, axis=1)

        # convert x, y, w and h into normalized absolute position
        x_offset = Variable(np.zeros((1, 1, 1, x.shape[3]), dtype=np.float32))
        y_offset = Variable(np.zeros((1, 1, y.shape[2], 1), dtype=np.float32))
        w_anchor = Variable(np.zeros((self.n_boxes, 1, 1, 1), dtype=np.float32))
        h_anchor = Variable(np.zeros((self.n_boxes, 1, 1, 1), dtype=np.float32))

        x = (x + F.broadcast_to(x_offset, x.shape)) / grid_w
        y = (y + F.broadcast_to(y_offset, y.shape)) / grid_h
        w = (w * F.broadcast_to(w_anchor, w.shape)) / grid_w
        h = (h * F.broadcast_to(h_anchor, h.shape)) / grid_h

        return x, y, w, h, conf, prob, x_offset, y_offset, w_anchor, h_anchor
