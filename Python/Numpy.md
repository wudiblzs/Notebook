# Numpy入门

## Numpy库概述

为了简洁代码和避免与常用命名混淆,建议以如下方式引用`numpy`库。

```python
import numpy as np
```

## numpy库解析

### 创建数组

numpy库常用的创建数组（ndarray类型）的函数共有7个。

| 函数                           | 描述                                        |
| ------------------------------ | ------------------------------------------- |
| np.array([x, y, z], dtype=int) | 从Python列表和元组创造数组                  |
| np.arange(x, y, i)             | 创建一个x到y，以i为步长的数组               |
| np.linspace(x, y, n)           | 创建一个由x到y，等分成n个元素的数组         |
| np.indices((m, n))             | 创建一个m行n列的矩阵                        |
| np.random.rand(m, n)           | 创建一个m行n列的随机数组                    |
| np.one(m, n, dtype)            | 创建一个m行n列全为1的数组， dtype是数据类型 |
| np.empty(m, n, dtype)          | 创建一个m行n列全为0的数组， dtype是数据类型 |

### 常用属性

ndarray的基本属性

| 属性             | 描述                                          |
| ---------------- | --------------------------------------------- |
| ndarray.ndim     | 数组轴的个数，也被称作秩                      |
| ndarray.shape    | 数组在每个维度上大小的整数元组                |
| ndarray.size     | 数组元素的总个数                              |
| ndarray.dtype    | 数组元素的数据类型，dtype类型可以用于创建数组 |
| ndarray.itemsize | 数组中每个元素的字节大小                      |
| ndarray.data     | 包含实际数组元素的缓冲区地址                  |
| ndarray.flat     | 数组元素的迭代器                              |





### ndarray类的形态操作方法

| 方法                       | 描述                                         |
| -------------------------- | -------------------------------------------- |
| ndarray.reshape(n, m)      | 不改变数组ndarray，返回一个维度为(n,m)的数组 |
| ndarray.resize(new_shape)  | 与reshape()作用相同，直接修改数组ndarray     |
| ndarray.swapaxes(ax1, ax2) | 将数组n个维度中任意两个维度进行调换          |
| ndarray.flatten()          | 对数组进行降维，返回一个折叠后的一维数组     |
| ndarray.revel()            | 作用np.flatten(),但是返回数组的一个视图      |





### ndarray类的索引和切片方法



| 方法       | 描述                                   |
| ---------- | -------------------------------------- |
| x[i]       | 索引第i一个元素                        |
| x[-i]      | 从后往前索引第i个元素                  |
| x[n:m]     | 默认步长为1，从前往后索引，不包含m     |
| x[-m:-n]   | 默认步长为1，从后往前索引，结束位置为n |
| x[n: m :i] | 指定i为步长的由n到m的索引              |



### numpy库的算术运算函数



| 函数                         | 描述         |
| ---------------------------- | ------------ |
| np.add(x1, x2[, y])          | y = x1 + x2  |
| np.subtract(x1, x2[, y])     | y = x1 - x2  |
| np.multiply(x1, x2[, y])     | y = x1 * x2  |
| np.divide(x1, x2[, y])       | y = x1 / x2  |
| np.floor_divide(x1, x2[, y]) | y = x1 // x2 |
| np.negative(x[, y])          | y = -x       |
| np.power(x1, x2[, y])        | y = x1 ** x2 |
| np.remainder(x1, x2[, y])    | y = x1 % x2  |

输出参数y可选，如果没有指定，将创建并返回一个新的数组保存计算结果；如果指定计算参数，则将结果保存到参数中。



### numpy库的比较函数

| 函数                          | 描述                         |
| ----------------------------- | ---------------------------- |
| np.equal(x1, x2[, y])         | y = x1 == x2                 |
| np.not_euqap(x1, x2[, y])     | y = x1 != x2                 |
| np.less(x1, x2[, y])          | y = x1 < x2                  |
| np.less_equal(x1, x2[, y])    | y = x1 <= x2                 |
| np.greater(x1, x2[, y])       | y = x1 > x2                  |
| np.greater_equal(x1, x2[, y]) | y = x1 >= x2                 |
| np.where(condition[x, y])     | 根据给出的条件判断输出x还是y |



### numpy库其它运算函数

| 函数                            | 描述                                       |
| ------------------------------- | ------------------------------------------ |
| np.abs(x)                       | 计算基于元素的整型、浮点或其他复数的绝对值 |
| np.sqrt(y)                      | 计算每个元素的平方根                       |
| np.squre(x)                     | 计算每个元素的平方                         |
| np.sign(x)                      | 计算每个元素的符号：1(+),0,-1(-)           |
| np.ceil(x)                      | 计算大于或等于每个元素的最小值             |
| np.floor(x)                     | 计算小于或等于每个元素的最大值             |
| np.rint(x[, out])               | 圆整，取每个元素为最近的整数，保留数据类型 |
| np.exp(x[, out])                | 计算每个元素的指数值                       |
| np.log(x),np.log10(x),nplog2(x) | 计算自然数对(e)，基于10、2的对数，log(1+x) |

