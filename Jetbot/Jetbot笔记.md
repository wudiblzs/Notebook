# OpenCV开源平台计算机视觉库



## OpenCV简介

OpenCV全称"Open source Computer Vision Library"

OpenCV是一个通用的开放源代码计算机视觉库，至今在入侵检测、目标检测、人脸检测、人脸识别、人脸跟踪等领域大显身手。

## 图像的读入和保存

1. 图像的读入

```python
import cv2 as cv
img = cv.imread('wanye.png', 0)

cv.imwrite('test.png', img)
```

`imread('name.jpg', 0)`第一个参数是图片的路径，第二个参数是如何读取这副这副图片。

- cv.IMREAD_COLOR——以灰度模式读入图片，可以用0表示
- cv.IMREAD_GRAYSCALE——读入衣服彩色图片，可以用1表示
- cv.IMREAD_UNCHANGED——读入一副图片，并包括其alpha通道，可以用2表示

2. 图像的保存

`imwrite('dname.jpg', img)`第一个参数是保存的文件名，第二个参数是保存的图像。

## 视频流的读入和保存

1. 打开摄像头：

```python
cap = cv.VideoCapture(0)
```

- 参数0表示设备的默认摄像头，当设备有多个摄像头时可以改变参数选择



2. 读取摄像头的视频流：

```python
ret, frame = cap.read()
```

- 无参数，但需放在死循环中不断读取形成视频
- read()方法返回值为bool型



3. 获取摄像头工作态

```python
cap.isOpened()
```

- isOpened()方法返回值为bool型
- Sometimes, cap may not have initialized the capture. In that case, this code shows error. You can check whether it is initialized or not by the method **`cap.isOpened()`**. If it is `True`, OK. Otherwise open it using **`cap.open()`**.

4. 获取视频特征

```python
cap.get(propld)
```

- `propld`是0到18的整型参数，每个数字都表示视频的一个属性。

Full details can be seen here: [cv::VideoCapture::get()](https://docs.opencv.org/4.1.1/d8/dfe/classcv_1_1VideoCapture.html#aa6480e6972ef4c00d74814ec841a2939). 

示例：

```python
# 获取视频流帧的宽度和高度
cap.get(cv.CAP_PROP_FRAME_WIDTH)
cap.get(cv.CAP_PROP_FRAME_HEIGHT)
# 自定义视频流的宽度和高度
ret = cap.set(cv.CAP_PROP_FRAME_WIDTH,320)
ret = cap.set(cv.CAP_PROP_FRAME_HEIGHT,240)
```



5. 释放摄像头资源和关闭窗口：

```python
cap.release()
cv.destroyAllWindows()
```

- 无参数，程序关闭之前务必关闭摄像头，释放资源



6. 读取视频文件：

```python
cap = cv.VideoCapture('filename')
```

保存视频：

创建一个VideoWriter对象，并指定输出文件名



7. 指定使用XVID编码器：

```python
fourcc =  cv.VideoWriter_fourcc(*'XVID')	# 序列解包
# or
fourcc = cv.VideoWriter_fourcc('X', 'V', 'I', 'D')
```

- In Fedora: DIVX, XVID, MJPG, X264, WMV1, WMV2. (XVID is more preferable. MJPG results in high size video. X264 gives very small size video)
- In Windows: DIVX (More to be tested and added)
- In OSX: MJPG (.mp4), DIVX (.avi), X264 (.mkv).

8. 指定输出文件：

```python
out =  cv.VideoWriter('out.avi', fourcc, 20.0, (640, 480))
```

- 上面函数参数依次表示输出视频名称，编码器，帧率，帧宽和高。



示例1：

```python
import cv2 as cv
# 打开默认摄像头
cap = cv.VideoCapture(0)

while cap.isOpened():
    # get a frame
    ret, frame = cap.read()
    # show a frame
    cv.imshow('capture', frame)
    if cv.waitKey(1) & 0xFF == ord('q'):
        break
cap.release()
cv.destroyAllWindows()

```

OpenCV官方教程示例：

```python
# 从摄像头获取视频流
import numpy as np
import cv2 as cv

cap = cv.VideoCapture(0)
if not cap.isOpened():
    print("Cannot open camera")
    exit()
while True:
    # Capture frame-by-frame
    ret, frame = cap.read()
    # if frame is read correctly ret is True
    if not ret:
        print("Can't receive frame (stream end?). Exiting ...")
        break
    # Our operations on the frame come here
    gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
    # Display the resulting frame
    cv.imshow('frame', gray)
    if cv.waitKey(1) == ord('q'):
        break
# When everything done, release the capture
cap.release()
cv.destroyAllWindows()
```



```python
# 从视频文件获取视频流
import numpy as np
import cv2 as cv

cap = cv.VideoCapture('genshin.flv')
while cap.isOpened():
    ret, frame = cap.read()
    # if frame is read correctly ret is True
    if not ret:
        print("Can't receive frame (stream end?). Exiting ...")
        break
    gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
    cv.imshow('frame', gray)
    if cv.waitKey(1) == ord('q'):
        break
cap.release()
cv.destroyAllWindows()
```



## OpenCV的绘图函数



```python
import cv2 as cv
```



1. 绘制直线

```python
cv.line(img, startPoint, endPoint, color, thickness)
```

- `img`：需要绘制的目标图像对象
- `startPoint`：起始位置像素坐标
- `endPoint`：结束位置像素坐标
- `color`：绘制使用的颜色
- `thickness`：绘制的线条宽度
- `lineType`: 线段的类型。可以取值8， 4， 和CV_AA， 分别代表8邻接连接线，4邻接连接线和反锯齿连接线。默认值为8邻接。为了获得更好地效果可以选用CV_AA(采用了高斯滤波)。



2. 绘制圆

```python
cv.circle(img, centerPoint, radius, color, thicksness)
```

- `img`：需要绘制的目标图像对象
- `centerPoint`：绘制圆的圆心位置像素坐标
- `radius`：绘制圆的半径
- `color`：绘制圆的颜色
- `thickness`：绘制线条宽度，thickness是负数表示圆被填充



3. 绘制矩形

```python
cv.rectangle(img, point1, point2, color, thickness)
```

- `img`：需要绘制的目标图像对象
- `point1`：左上顶点位置像素坐标
- `point2`：右下顶点位置像素坐标
- `color`：绘制使用的颜色
- `thickness`：绘制的线条宽度



4. 书写文本

```python
cv.putText(img, text,point, font, size, color, thickness)
```

- `img`：需要绘制的目标图像对象
- `text`：绘制的文字
- `point`：左上顶点位置像素坐标
- `color`：绘制使用的颜色
- `thickness`：绘制的线条宽度

`img`可以是`np.zeros()`对象、`cv.imread()`对象以及视频流的frame。

[更多,详解用OpenCV绘制各类几何图形](https://developer.huawei.com/consumer/cn/forum/topic/0203817055180040399?fid=0101592429757310384)



## OpenCV之图片缩放

```python
cv.resize(InputArray src, OutputArray dst, size, fx, fy, interpolation)
```

- `InputArray src`：输入图片
- `OutputArray dst`：输出图片
- `size`：输出图片尺寸
- `fx, fy`：沿着x轴，y轴缩放系数
- ` interpolation`：插入方式



## HSV颜色空间以及颜色空间转换（RGB——HSV）

一般对颜色空间的图像进行有效处理都是在HSV空间进行的，HSV（色调Hue，饱和度Saturation，亮度Value）是根据颜色的直观性创建的一种颜色空间，也称六角锥体空间。

对于图像而言，识别相应的颜色在RGB空间、HCV空间或者其它颜色空间都是可行的。但HSV的优势在于H代表的色调基本上可以确定某种颜色，再结合饱和度和亮度信息判断是否大于某一个阙值。RGB由三个分量构成，需要判断每种分量的贡献比例以识别相应的颜色。综上，HSV空间的识别范围更广，更方便。

![img](https://gimg2.baidu.com/image_search/src=http%3A%2F%2Fwww.adearth.ac.cn%2Ffileup%2F1001-8166%2FFIGURE%2F2019-34-5%2FImages%2F1001-8166-2019-34-5-552%2F62fd84bc-c0f2-491b-a878-04b03cf00455-F004.png&refer=http%3A%2F%2Fwww.adearth.ac.cn&app=2002&size=f9999,10000&q=a80&n=0&g=0n&fmt=auto?sec=1651755625&t=046f06e89044ffad75890f3f6492920b)

三种颜色空间的转换（Gray BGR HSV）：

常用的颜色空间转换的方法，BGR→Gray和BGR→HSV。注：Gray和HSV不可以互相转换。

颜色空间转换

```python
cv.cvtColor(input_image, flag)
```

- `BGR→Gray`：flag  =  cv.COLOR_BGR2GRAY
- `BGR→HSV`：flag = cv.COLOR_BGR2HSV  

OpenCV中HSV颜色空间的取值范围：

H[0, 179]	S[0, 255]	V[0, 255]

![img](https://gimg2.baidu.com/image_search/src=http%3A%2F%2Fimg-blog.csdnimg.cn%2F20200717172141628.png%3Fx-oss-process%3Dimage%2Fwatermark%2Ctype_ZmFuZ3poZW5naGVpdGk%2Cshadow_10%2Ctext_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NDU1MTY0Ng%3D%3D%2Csize_16%2Ccolor_FFFFFF%2Ct_70&refer=http%3A%2F%2Fimg-blog.csdnimg.cn&app=2002&size=f9999,10000&q=a80&n=0&g=0n&fmt=auto?sec=1651756171&t=fa0aabaa1f5786bd47a110bf998838e3)





# 卷神经网络（CNN）

卷积神经网络（Convolutional Neural Network, CNN）是一种前馈神经网络，它的人工神经元可以响应一部分覆盖范围内的周围单元，对于大型图像处理有出色表现。

卷积神经网络由一个或多个卷积层和顶端的全连通层（对应经典的神经网络）组成，同时也包括关联权重和池化层（pooling layer）。这一结构使得卷积神经网络能够利用输入数据的二维结构。与其他深度学习结构相比，卷积神经网络在图像和语音识别方面能够给出更好的结果。这一模型也可以使用反向传播算法进行训练。相比较其他深度、前馈神经网络，卷积神经网络需要考量的参数更少，使之成为一种颇具吸引力的深度学习结构。

## 人工神经网络





## 卷积运算





## 使用GPU加速CNN







# TensorFlowAI框架



## TensorFlowAI简介







# PytorchAI框架

## Pytorch简介





## ResNet-18模型

