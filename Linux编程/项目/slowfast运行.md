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

