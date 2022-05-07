- 数据分析是用适当的方法对收集来的大量数据进行分析。帮助人们做出判断，以便采取适当的行动。
- 数据分析的流程：提出问题，准备数据，分析数据，获得数据，获得结论，成果可视化

# matplotlib—数据可视化

**matplotlib**:最流行的Python底层绘图库，主要做数据可视化图表。

```python
# 示例1
# 导入pyplot
from matplotlib import pyplot as plt	
x = range(2, 26, 2)
y = [15, 13, 14, 5, 17, 20, 25, 26, 26, 24, 22, 18, 15]
# 设置图片大小
plt.figure(figsize=(20, 8), dpi=80)	#dpi为像素点数量
# 绘图
plt.plot(x, y)
# 设置x轴的刻度
plt.xticks(x)
# plt.xticks([i/2 for i in range(4, 49)])

# 展示图像
plt.show()
# 保存
plt.savefig("./imagename.png")	
# plt.savefig("./imagename.svg")可以保存为svg这种矢量图格式

```



```python
from matplotlib import pyplot as plt
import random

# 显示中文字符
plt.rcParams['font.family'] = ['sans-serif']
plt.rcParams['font.sans-serif'] = ['SimHei']

x = range(0, 120)
y = [random.randint(20, 35) for i in range(120)]

plt.figure(figsize=(20, 8), dpi=90)

plt.plot(x, y)

_xtick_lables = ["{}点{}分".format(8+i//60, 0+i%60) for i in range(120)]
# 取步长，数字与字符串一一对应，数据长度一样
plt.xticks(x[::3], _xtick_lables[::3], rotation=90) # rotation为顺时针旋转的角度

# 绘制网格
plt.grid(alpha=1) # alpha为网格透明度

plt.show()
```



```python
from matplotlib import pyplot as plt
import math as m


x = range(0, 120)
y1 = [m.cos(t) for t in x]
y2 = [m.sin(t) for t in x]

plt.figure(figsize=(20, 8), dpi=90)

# 绘制多条曲线
plt.plot(x, y1)
plt.plot(x, y2)

# 绘制网格
plt.grid(alpha=1) # alpha为网格透明度

plt.show()
```



```python
from matplotlib import pyplot as plt
import math as m
from matplotlib import font_manager

my_font = font_manager.FontProperties(fname="C:\Windows\Fonts\Dengl.ttf")


x = range(0, 120)
y1 = [m.cos(t) for t in x]
y2 = [m.sin(t) for t in x]

plt.figure(figsize=(20, 8), dpi=90)

plt.plot(x, y1, label="cos(x)余弦函数", color="orange", linestyle=":", linewidth=5)
plt.plot(x, y2, label="sin(x)正弦函数", color="cyan", linestyle="--", linewidth=5)

# 绘制网格
plt.grid(alpha=1) # alpha为网格透明度

# 添加图例
plt.legend(prop=my_font, loc="upper left")  #prop为显示字体，loc为图例显示位置

plt.show()
```



## 导包

```python
from matplotlib import pyplot as plt
```

## 创建绘图区域

```python
plt.figure(figsize=(20, 8), dpi=80)
```

- 创建一个大小为`figsize`绘图区域
- `dpi`为像素点



```python
plt.axes(rect, axisbg='w')
```

- 创建一个坐标系风格的子绘图区域
- axes()默认创建一个subplot(111)坐标系，参数rec=[left, bottom, width, height]中4个变量的范围都为[0, 1]，表示坐标系与全局绘图区域的关系。
- axisbg值背景色，默认为white



```python
plt.subplot(nrows, ncols, plot_number)
```

- 在全局绘图区域中创建一个子绘图区域
- 将全局绘图区域分成nrows行和ncols列，并根据先行后列的计数方式在plot_number位置生成一个坐标系。



```python
plt.subplot_adjust()
```

- 调整子绘图区域的布局





## 基础绘图表函数

```python
plt.plot(x, y, label, color, width)
```

- 根据x、y数组绘制直线、曲线
- label表示设置标签并在legend中显示

```python
plt.boxplot(data, notch, poistion)
```

- 绘制一个箱型图（Box-plot）

```python
plt.bar(left, height, width, bottom)
```

- 绘制一个条形图

```python
plt.barh(bottom, width, height, left)
```

- 绘制一个横向条形图

```python
plt.polar(theta, r)
```

- 绘制极坐标系

```python
plt.pie(data, explode)
```

- 绘制饼图

```python
plt.psd(x, NFFT=256, pad_to, Fs)
```

- 绘制功率谱密度图

```python
plt.specgram(x, NFFT=256, pad_to, F)
```

- 绘制谱图

```python
plt.cohere(x, y, NFFT=256, pad_to, Fs)
```

- 绘制X-Y的相关曲线

```python
plt.scatter()
```

- 绘制散点图（x，y是长度相同的序列）

```python
plt.step(x, y, where)
```

- 绘制步阶图

```python
plt.hist(x, bins, normed)
```

- 绘制直方图

```python
plt.contour(X, Y, Z, N)
```

- 绘制等值线

```python
plt.vlines()
```

- 绘制垂直线

```python
plt.stem(x, y, linefmt, markerfmt, basefmt)
```

- 绘制曲线每个点的水平轴线的垂线

```python
plt.plot_date()
```

- 绘制数据日期

```python
plt.plotfile()
```

- 绘制数据后写入文件

## 坐标轴设置函数

| 函数                                                     | 描述                      |
| -------------------------------------------------------- | ------------------------- |
| plt.axis(‘V’, ‘off’, ‘equal’, ‘scale’, ‘tight’, ‘image’) | 获取当前设置轴的属性      |
| plt.xlim(xmin, xmax)                                     | 设置当前x轴的取值范围     |
| plt.ylim(ymin, ymax)                                     | 设置当前y轴的取值范围     |
| plt.xscale()                                             | 设置x轴的缩放             |
| plt.yscale()                                             | 设置y轴的缩放             |
| plt.autoscale()                                          | 自动缩放轴视图的数据      |
| plt.text(x, y, s, fontdic, widthdash)                    | 为axes图轴添加注释        |
| plt.thetagrids(angles, labels, fmt, frac)                | 设置极坐标网格theta的位置 |
| plt.grid(on/off)                                         | 打开或关闭坐标格          |



## 标签设置函数

| 函数                                                         | 描述                                     |
| ------------------------------------------------------------ | ---------------------------------------- |
| plt.figlegend(handles, label, loc)                           | 为全局绘图区域放置图注                   |
| plt.legend()                                                 | 为当前坐标图放置图注                     |
| plt.xlabel()                                                 | 设置当前x轴的标签                        |
| plt.ylabel()                                                 | 设置当前y轴的标签                        |
| plt.xticks()                                                 | 设置当前x轴刻度位置的标签和值            |
| plt.yticks()                                                 | 设置当前y轴刻度位置的标签和值            |
| plt.clabel()                                                 | 为等值线图设置标签                       |
| plt.get_faiglabels()                                         | 返回当前绘图区域的标签列表               |
| plt.figtext(x, y, s, fontdic)                                | 为全局绘图区域添加文字                   |
| plt.title()                                                  | 设置标题                                 |
| plt.suptitle()                                               | 为当前绘图区域添加中心标题               |
| plt.text(x, y, s, fontdic, withdash)                         | 为坐标图轴添加注释                       |
| plt.annotate(note, xy, xytext, xycoords, textcoords, arrowpros) | 用箭头在指定数据点创建一个注释或一段文本 |



## 区域填充函数

| 函数                                  | 描述                     |
| ------------------------------------- | ------------------------ |
| fill(x, y, color)                     | 填充多边形               |
| fill_between(x, y1, y2, where, color) | 填充两条曲线围成的多边形 |
| fill_between(y, x1, x2, where, hold)  | 填充两条水平线之间的区域 |

