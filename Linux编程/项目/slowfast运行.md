# 需求
- 想用自己视频结合slowfast来进行人体的动作识别
- 想用自己的数据来进行训练，对一些特别动作的自学习自识别

GETTING_STARTED.md告诉我们怎么进行训练和测试，以及怎么用自己的视频进行跑

## 最简单的运行方式
linux环境下
```
python tools/run_net.py  --cfg demo/AVA/SLOWFAST_32x2_R50_SHORT.yaml
```
--cfg：指的是你的配置文件的位置，上面就是告诉python我自己的config文件在demo/AVA/SLOWFAST_32x2_R50_SHORT.yaml这个文件。

## 最灵活的运行方式
上面是配置好config文件，但是每次想训练还是想测试，都需要去更改文件，有点麻烦，slowfast也是可以通过命令更改的
```
python tools/run_net.py  --cfg demo/AVA/SLOWFAST_32x2_R50_SHORT.yaml  TEST.CHECKPOINT_FILE_PATH /public/jiangc/SLOWFAST_32x2_R101_50_50_v2.1.pkl  TEST.ENABLE: False
```
这行命令相对于上面那个来说，多了TEST.CHECKPOINT_FILE_PATH和TEST.UNABLE这两个，这说明很多配置的内容也是可以通过命令来更改的，不用每次更改文件，比如还有输入输出视频的位置等等的配置内容。

### 一份跑成功的配置参考
```
TRAIN:
  ENABLE: False
  DATASET: ava
  BATCH_SIZE: 16
  EVAL_PERIOD: 1
  CHECKPOINT_PERIOD: 1
  AUTO_RESUME: True
  CHECKPOINT_FILE_PATH: .SLOWFAST_32x2_R101_50_50_v2.1.pkl  #path to pretrain mod
  CHECKPOINT_TYPE: caffe2
DATA:
  NUM_FRAMES: 32
  SAMPLING_RATE: 2
  TRAIN_JITTER_SCALES: [256, 320]
  TRAIN_CROP_SIZE: 224
  TEST_CROP_SIZE: 256
  INPUT_CHANNEL_NUM: [3, 3]
DETECTION:
  ENABLE: True
  ALIGNED: False
AVA:
  BGR: False
  DETECTION_SCORE_THRESH: 0.8
  TEST_PREDICT_BOX_LISTS: ["person_box_67091280_iou90/ava_detection_val_boxes_and_labels.csv"]
SLOWFAST:
  ALPHA: 4
  BETA_INV: 8
  FUSION_CONV_CHANNEL_RATIO: 2
  FUSION_KERNEL_SZ: 5
RESNET:
  ZERO_INIT_FINAL_BN: True
  WIDTH_PER_GROUP: 64
  NUM_GROUPS: 1
  DEPTH: 101
  TRANS_FUNC: bottleneck_transform
  STRIDE_1X1: False
  NUM_BLOCK_TEMP_KERNEL: [[3, 3], [4, 4], [6, 6], [3, 3]]
  SPATIAL_DILATIONS: [[1, 1], [1, 1], [1, 1], [2, 2]]
  SPATIAL_STRIDES: [[1, 1], [2, 2], [2, 2], [1, 1]]
NONLOCAL:
  LOCATION: [[[], []], [[], []], [[6, 13, 20], []], [[], []]]
  GROUP: [[1, 1], [1, 1], [1, 1], [1, 1]]
  INSTANTIATION: dot_product
  POOL: [[[2, 2, 2], [2, 2, 2]], [[2, 2, 2], [2, 2, 2]], [[2, 2, 2], [2, 2, 2]], [[2, 2, 2], [2, 2, 2]]]
BN:
  USE_PRECISE_STATS: False
  NUM_BATCHES_PRECISE: 200
SOLVER:
  MOMENTUM: 0.9
  WEIGHT_DECAY: 1e-7
  OPTIMIZING_METHOD: sgd
MODEL:
  NUM_CLASSES: 80
  ARCH: slowfast
  MODEL_NAME: SlowFast
  LOSS_FUNC: bce
  DROPOUT_RATE: 0.5
  HEAD_ACT: sigmoid
TEST:
  ENABLE: False
  DATASET: ava
  BATCH_SIZE: 8
DATA_LOADER:
  NUM_WORKERS: 2
  PIN_MEMORY: True
 
NUM_GPUS: 1
NUM_SHARDS: 1
RNG_SEED: 0
OUTPUT_DIR: .
#TENSORBOARD:
#  MODEL_VIS:
#    TOPK: 2
DEMO:
  ENABLE: True
  LABEL_FILE_PATH: "/public/jiangc/newSlowfast/slowfast/demo/AVA/ava.json"
  INPUT_VIDEO: "/public/jiangc/newSlowfast/slowfast/slowfast/datasets/data/data/ava/2fwni_Kjf2M_Trim.mp4"
  OUTPUT_FILE: "/public/jiangc/newSlowfast/slowfast/slowfast/datasets/data/data/ava/IMG_3886.mp4"
#  DISPLAY_WIDTH: 640
#  DISPLAY_HEIGHT: 480
#  WEBCAM: 0
  DETECTRON2_CFG: "COCO-Detection/faster_rcnn_R_50_FPN_3x.yaml"
  #DETECTRON2_WEIGHTS: "/public/jiangc/newSlowfast/slowfast/demo/AVA/model_final_280758.pkl"
  DETECTRON2_WEIGHTS: "detectron2://COCO-Detection/faster_rcnn_R_50_FPN_3x/137849458/model_final_280758.pkl"
 ``` 
 
