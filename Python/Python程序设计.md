---
title: Python基础知识
data: 2022-03-26 14:00:30
tags:
- Python
categories:
- [ 编程语言, Python ]
description: Python基础语法，《Python程序设计》（第三版）读书笔记 ，待完善
---

# Python对象模型

| 对象类型       | 类型名称                       | 简要说明                               |
| -------------- | ------------------------------ | -------------------------------------- |
| 数字           | int float complex              | 数字大小没有限制，内置支持复数及其运算 |
| 字符串         | str                            |                                        |
| 字节串         | bytes                          |                                        |
| 列表           | list                           |                                        |
| 字典           | dict                           |                                        |
| 元组           | tuple                          |                                        |
| 集合           | set frozenset                  |                                        |
| 布尔型         | bool                           |                                        |
| 空类型         | Node Type                      |                                        |
| 异常           | Exception ValueError TypeError |                                        |
| 文件           |                                |                                        |
| 其他可迭代对象 |                                |                                        |
| 编程单元       |                                |                                        |

# Python变量

## Python变量的创建

在Python中，不需要事先声明变量名及其类型，直接赋值即可创建各种类型的变量，Python解释器会根据赋值或运算来自动推断变量类型。

Python是一种动态型语言——变量的类型可以随时改变，在显示修改其类型或删除之前，变量一直保持上次的类型。

大多数情况下，如果变量出现在赋值运算符的活复合赋值运算符的左边表示创建变量或修改变量的值，否则表示引用该变量的值，这一点同样适用于使用下标来访问列表、字典等可变序列以及其他自定义对象中元素的情况。字符串和元组属于不可变序列，这意味着不可通过下标的方式来修改其中的元素值。

修改变量的值实际修改的是变量的引用，其内存地址会发生变化。

```Python
>>> x = 3
>>> id(x)
22704288
>>> x += 1
>>> id(x)
22704304
>>> y = x
>>> id(y)
22704304
```

**内置函数id()**：返回变量所指值的内存地址。

Python采用基于值的内存管理方式，如果为不同变量赋值为相同值，这个值在内存中只保存一份，多个变量指向同一个值的内存空间首地址，以减少内存空间的占用，提高内存使用效率。Python启动时，会对[-5,256]的整数进行缓存。对于区间[-5,256]之外的整数，同一个程序中或交互模式下同一个语句中的同值不同名变量会共用同一个内存空间，不同程序或交互模式下不同语句不遵守这个约定。

Python不会对实数进行缓存，交互模式下不同语句中同值不同名的实数变量不会共用同一个内存空间同一个语句或同一个程序中的同值不同名变量会共用同一个内存空间。

## Python变量的赋值

Python允许同时为多个变量赋值：

```python
a = b = c = 1
```

上述示例创建了一个整型对象，值为1，`a, b, c`是同一对象的引用。

```python
x = 1
x, y, z = x+1, x+2, x+3

print(x, y, z)
# 输出：2 3 4
```

连续赋值语句中等式右边其实都是局部变量，先对右边局部变量进行计算然后依次完成赋值运算。

```
<变量 1>,<变量 2>,<变量 3>,...,<变量 N> = <表达式 ><表达式 ><表达式 >
```

## Python变量的回收

Python具有自动管理内存的功能，会跟踪所有的值，并自动删除不在使用或者引用次数为0的值。如果确定某个值不再使用，可以使用del命令显示删除该变量，值的引用次数减1，当某个变量的引用次数变为0时，将会被Python的垃圾回收机制自动删除并释放内存空间。可以使用标准库函数sys.getrefcount(x)查看对象x的值的引用次数。

## Python的可变与不可变数据类型

**变量作为函数实参传递**

```python
def fun( val1 ):
    val1 = val1 + 2

val2 = 0
fun(val2)
print(val2) # 结果0
```

实参 `val2`传递到函数 `fun()`中，相当于 `val1 = val2`，这时 `val1`和 `val2`指向同一个对象，在函数内部给 `val1`重新赋值，其实是 `val1`引用了一个新的对象，并不会修改实参 `val2`的值。

```python
def funList( a_list ):
    a_list[0] = 'X'
  
b_list = ['x', 'y', 'z']
funList( b_list )

print(b_list) # 输出 ['X', 'y', 'z']
```

`a_list`和 `b_list`是同一对象的引用，`b_list`在函数中调用对象自己的方法进行修改，这时并没有创建新的对象。

Python中，函数能不能修改外部变量取决于这个变量的类型是否是可修改类型，`string`、`tuples`、`int`、`float`是不可变数据类型，`list`、`set`、`dict`是可变数据类型。

## Python变量的命名规范

**Python自定义变量名规范**：

1. 变量名必须以字母、汉字或下划线开头，但以下划线开头的变量在Python中有特殊含义
2. 变量名中不能有空格以及标点符号（括号、引号、逗号、斜线、反斜线、冒号、句号、问号等）。
3. 不能使用关键字作为变量名，可以导入keyword模板后使用print(keyword.kwlist)查看所有PYthon关键字。
4. 不建议使用相同内置的模块名、类型名或函数名以及已导入的模块名及其成员名作为变量名，这会改变基类型和含义。
5. 变量名区分英文字母的大小写。

# 数字

在Python中，数字类型变量可以表示任意大的数值。

Python数值类型主要有整数，浮点数和复数。整数类型可以分为下面几种。

1. 十进制整数
2. 八进制整数
3. 二进制整数
4. 十六进制整数

Python中的复数与数学中复数的形式完全一致，都是由实部和虚部构成的，使用i或j来表示虚部。

```python
# Complex。py

a = 3 + 4j
b = 5 + 6j
c = a + b
print(c)
print(c.real)   # 查看复数实部
print(c.imag)   # 查看复数虚部
a.conjugate()   # 返回共轭复数
print(a*b)  # 复数乘法
print(a/b)  # 复数除法
```

Python3.6.x开始支持在数字中间位置使用单个下划线作为分隔符来提高数字的可读性，类似于数学上使用逗号作为千位分隔符，下划线可以位于数字中间任何位置，但不能在开始和结束位置。

# 字符串

在Python中，字符串属于不可变序列，一般使用单引号、双引号或三引号进行界定，并在单引号、双引号、三单引号、三双引号还可以互相嵌套，用来表示复杂字符串。空字符串表示为''或""或''''''，即一对不包含任何内容的任意字符串界定符。一对三单引号或三双引号表示的字符串支持换行，支持复排版格式的字符串，也可以在程序中表示较长的注释。

字符串界定符前面加字母r或R表示原始字符串，其中的特殊字符不进行转义，但字符串的最后不能是单个\符号。原始字符串主要用于正则表达式，也可以用来简化文件路径或URL的输入。

| 转义字符   | 含义                    |
| ---------- | ----------------------- |
| \n         | 换行符                  |
| \t         | 制表符                  |
| \r         | 回车                    |
| \ '        | 单引号                  |
| \uhhhh     | 4位十六进制数对应的字符 |
| \ "        | 双引号                  |
| \ \        | 一个 \                  |
| \ooo       | 3位八进制数对应的字符   |
| \xhh       | 2位十六进制数对应的字符 |
| \Uxxxxxxxx | 8位十六进制对应的字符   |

# 运算符与表达式

| 运算符示例          | 功能说明                                                     |
| ------------------- | ------------------------------------------------------------ |
| x+y                 | 算术加法，列表、元组、字符串合并                             |
| x-y                 | 算术减法，集合差集                                           |
| x*y                 | 乘法，序列重复                                               |
| x/y                 | 真除法，结果为实数                                           |
| x//y                | 求整商，向下取整                                             |
| -x                  | 相反数                                                       |
| x%y                 | 余数，字符串格式化                                           |
| x**y                | 幂运算，y可为实数                                            |
| x<y,x<=y,x>y,x>=y   | 大小比较，集合包含关系比较                                   |
| x==y,x!=y           | 相等/不相等比较                                              |
| x or y              | 逻辑或，短路运算符，最后计算的子表达式的值作为整个表达式的值 |
| x and y             | 逻辑与，短路运算符，最后计算的子表达式的值作为整个表达式的值 |
| not x               | 逻辑非                                                       |
| x in y, x not in y  | 成员测试运算符                                               |
| x is y, x is not y  | 测试两个对象引用的地址是否相同                               |
| \|、^、&、<<、>>、~ | 位运算符                                                     |
| &、\|、^            | 集合交集、并集、对称差集                                     |

# 列表

列表是Python的内置可变序列，是包含若干元素的有序连续内存空间。在形式上，列表的所有元素放在一对方括号"["和"]"中，相邻元素之间使用逗号隔开。当列表增加或删除元素时，列表对象自动进行内存的扩展或收缩，从而保证元素之间没有缝隙。

在Python中，同一个列表中元素的类型可以不相同，可以同时包含帧数、实数、字符串等基本类型，也可以是元组、列表、字典、集合以及其它自定义类型的对象。

列表的常用方法

| 方法                          | 说明                                                         |
| ----------------------------- | ------------------------------------------------------------ |
| append(x)                     | 将元素x添加至列表尾部                                        |
| extend(iterable)              | 将可迭代对象iterable中的所有元素添加到列表尾部               |
| insert(index, x)              | 在列表指定位置index处添加元素x                               |
| remove(x)                     | 在列表中删除首次出现的指定元素                               |
| pop([index])                  | 删除并返回列表对象指定位置的元素，默认为最后一个元素         |
| clear()                       | 删除列表中所有元素，但保留列表对象                           |
| index(x)                      | 返回第一个值为x的元素的下标，若不存在值为x的元素，则抛出异常 |
| count(x)                      | 返回指定元素x在列表中的出现次数                              |
| reverse(x)                    | 对列表元素进行原地翻转                                       |
| sort(key=None, reverse=False) | 列表元素进行原地排序                                         |
| copy()                        | 返回列表对象的浅复制                                         |

## 列表的创建与删除

1. 使用赋值运算符“=”直接将一个列表赋值给变量即可创建列表对象。

```python
a_list = [1, 2, 3]
```

2. 也可以使用 `list()`函数将元组、`range`对象、字符串或其他类型的可迭代对象类型的数据转换为列表。

```python
>>> a_list = list( (3, 5, 7, 9) )
>>> list(range(1, 10, 2))
[1, 3, 5, 7, 9]
>>> list('hello word')
['h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'd']
>>> x = list()	#创建空列表
```

3. 列表推导式可以快速生成符合特定要求的列表
4. 当不再使用list对象时，使用del命令删除这个list对象

## 列表元素的增加

(1)可以使用 `+`运算符来实现将元素添加到列表中的功能。严格意义上讲，这并不是真的为列表添加元素，而是创建一个新列表，并将原列表中的元素和新元素依次复制到新列表的内存空间。由于涉及大量元素的复制，该操作速度较慢，在涉及大量元素添加时不建议使用。

```python
aList = [3, 4, 5]
print("aList:{}，地址：{}".format(aList, id(aList)))
aList = aList + [6, 7, 8]
print("aList:{}，地址：{}".format(aList, id(aList)))
```

程序输出：

```python
aList:[3, 4, 5]，地址：2115227092736
aList:[3, 4, 5, 6, 7, 8]，地址：2115227996352
```

(2)使用列表对象的append()方法，原地修改列表，速度较快，是真正意义上的在列表尾部添加新元素。

```python
aList = [3, 4, 5]
print("aList:{}，地址：{}".format(aList, id(aList)))

for i in range(3):
    print("aList[{}]地址:{}".format( i, id(aList[i]) ))
  
aList.append(6)
print("aList:{}，地址：{}".format(aList, id(aList)))

for i in range(4):
    print("aList[{}]地址:{}".format( i, id(aList[i]) ))
```

程序输出：

```python
aList:[3, 4, 5]，地址：2115239179200
bList:[3, 4, 5, 6, 7, 8]，地址：2115239168256
aList:[3, 4, 5]，地址：2115227092736
aList:[3, 4, 5, 6, 7, 8]，地址：2115227996352
aList:[3, 4, 5]，地址：2115224406080
aList[0]地址:2115147426160
aList[1]地址:2115147426192
aList[2]地址:2115147426224
aList:[3, 4, 5, 6]，地址：2115224406080
aList[0]地址:2115147426160
aList[1]地址:2115147426192
aList[2]地址:2115147426224
aList[3]地址:2115147426256
```

Python采用的是基于值的自动内存管理方式，当内存对象修改值时，并不是直接修改变量的值，而是使变量指向新的值，这对所有类型都是一样的。

以列表为例，列表中包含的是元素的引用，而不是直接包含元素值。如果是直接修改列表变量的值，则与Python普通变量的情况是一样的；如果是通过下标来修改列表中的元素的值或通过列表对象自身提供的方法来增加和删除元素时，列表对象在内存中的起始地址是不变的，仅仅是被改变值的元素地址发生变化。

(3)使用列表对象的 `extend()`方法可以将另一个可迭代对象的所有元素添加至该列表对象尾部。通过 `extend()`方法来增加元素也不改变其内存首地址，属于原地操作。

```python
aList = [3, 4, 5]
print("aList:{}，地址：{}".format(aList, id(aList)))
for i in range(3):
    print("aList[{}]地址:{}".format( i, id(aList[i]) ))

aList.extend( [7, 8, 9] )
print("aList:{}，地址：{}".format(aList, id(aList)))
for i in range(6):
    print("aList[{}]地址:{}".format( i, id(aList[i]) ))
```

程序输出：

```python
aList:[3, 4, 5]，地址：2115224405440
aList[0]地址:2115147426160
aList[1]地址:2115147426192
aList[2]地址:2115147426224
aList:[3, 4, 5, 7, 8, 9]，地址：2115224405440
aList[0]地址:2115147426160
aList[1]地址:2115147426192
aList[2]地址:2115147426224
aList[3]地址:2115147426288
aList[4]地址:2115147426320
aList[5]地址:2115147426352
```

(4) 使用列表对象的 `insert(index, x)`方法将元素添加至列表的指定位置，也属于原地操作。`insert()`方法涉及插入位置之后所有元素的移动，这会影响处理速度，并且导致一些元素的下标发生变化，类似的还有 `remove()`方法、`pop()`函数弹出列表非尾部元素和使用del命令删除列表非尾部的情况。

```python
aList = [3, 4, 5]
print("aList:{}，地址：{}".format(aList, id(aList)))
for i in range(3):
    print("aList[{}]地址:{}".format( i, id(aList[i]) ))

aList.insert(3, 6)
print("aList:{}，地址：{}".format(aList, id(aList)))
for i in range(4):
    print("aList[{}]地址:{}".format( i, id(aList[i]) ))
```

程序输出;

```python
aList:[3, 4, 5]，地址：2115259739904
aList[0]地址:2115147426160
aList[1]地址:2115147426192
aList[2]地址:2115147426224
aList:[3, 4, 5, 6]，地址：2115259739904
aList[0]地址:2115147426160
aList[1]地址:2115147426192
aList[2]地址:2115147426224
aList[3]地址:2115147426256
```

(5)使用乘法来扩展列表对象，将列表与整数相乘，生成一个新列表，而不是真地扩展原列表，新列表是原列表中元素的重复。需要注意的是，当使用 `*`运算符将包含列表的列表进行重复并创建新列表时，是创建已有元素的引用。因此，当修改其中一个值时，相应的引用也会被修改。

```python
x = [ [None]*2 ]*3
print("x:{},地址：{}".format( x, id(x) ))

x[0][0] = '99'
print("x:{},地址：{}".format( x, id(x) ))
```

程序输出：

```python
x:[[None, None], [None, None], [None, None]],地址：2115259844032
x:[['99', None], ['99', None], ['99', None]],地址：2115259844032
```

## 列表元素的删除

1. 使用del命令删除列表中的指定位置上的元素（del属于原地操作）

```python
aList = [3, 4, 5]
print("aList:{}，地址：{}".format(aList, id(aList)))
for i in range(3):
    print("aList[{}]地址:{}".format( i, id(aList[i]) ))

del aList[0]
print("aList:{}，地址：{}".format(aList, id(aList)))
for i in range(2):
    print("aList[{}]地址:{}".format( i, id(aList[i]) ))
```

程序输出：

```python
aList:[3, 4, 5]，地址：2467643195072
aList[0]地址:2467562482032
aList[1]地址:2467562482064
aList[2]地址:2467562482096
aList:[4, 5]，地址：2467643195072
aList[0]地址:2467562482064
aList[1]地址:2467562482096
```

2. 使用列表的 `pop()`方法删除并返回指定（默认为最后一个）位置上的元素，如果给定的索引超出列表的范围，则抛出异常。（原地操作）

```python
aList = [3, 4, 5]
print("aList:{}，地址：{}".format(aList, id(aList)))
for i in range(3):
    print("aList[{}]地址:{}".format( i, id(aList[i]) ))

aList.pop()
print("aList:{}，地址：{}".format(aList, id(aList)))
for i in range(2):
    print("aList[{}]地址:{}".format( i, id(aList[i]) ))
```

程序输出：

```python
aList:[3, 4, 5]，地址：2467639369280
aList[0]地址:2467562482032
aList[1]地址:2467562482064
aList[2]地址:2467562482096
aList:[3, 4]，地址：2467639369280
aList[0]地址:2467562482032
aList[1]地址:2467562482064
```

3. 使用列表对象的 `remove()`方法删除首次出现的指定元素，如果列表中不存在要删除的元素，则抛出异常。（原地操作）

```python
aList = [3, 4, 5]
print("aList:{}，地址：{}".format(aList, id(aList)))
for i in range(3):
    print("aList[{}]地址:{}".format( i, id(aList[i]) ))

aList.remove(5)
print("aList:{}，地址：{}".format(aList, id(aList)))
for i in range(2):
    print("aList[{}]地址:{}".format( i, id(aList[i]) ))
```

程序输出：

```python
aList:[3, 4, 5]，地址：2467643192256
aList[0]地址:2467562482032
aList[1]地址:2467562482064
aList[2]地址:2467562482096
aList:[3, 4]，地址：2467643192256
aList[0]地址:2467562482032
aList[1]地址:2467562482064
```

实验：用 `remove()`方法删除列表中指定元素的所有重复。

```python
x = [1, 2, 1, 2, 1, 1, 1]
for i in x:
    print(i)
    if i == 1:
        x.remove(i)
        print(x)
```

程序输出：

```python
1
[2, 1, 2, 1, 1, 1]
1
[2, 2, 1, 1, 1]
1
[2, 2, 1, 1]
1
[2, 2, 1]
```

由于列表的的自动内存管理功能，在删除或增加列表元素时，python会自动对列表元素内存进行扩展或收缩并移动列表元素以保证所有元素之间没有空隙。每当插入或删除一个元素之后，该元素位置后面所有元素的索引值都会改变。

```python
x = list(range(20))
print(x)
for i in range(len(x)):
    del x[0]
print(x)
```

程序输出：

```python
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19]
[]
```

从后向前的顺序删除列表中的重复元素：

```python
x = [1, 2, 1, 2, 1, 1, 1]
for i in range(len(x)-1, -1, -1):
    print(i)
    if x[i] == 1:
        del x[i]
        print(x)
```

程序输出：

```python
6
[1, 2, 1, 2, 1, 1]
5
[1, 2, 1, 2, 1]
4
[1, 2, 1, 2]
3
2
[1, 2, 2]
1
0
[2, 2]
```

列表的切片操作：

示例1：

```python
x = [1, 2, 1, 2, 1, 1, 1]
for i in x[::]:
    print(i)
    if i == 1:
        x.remove(i)
        print(x)
```

程序输出：

```python
1
[2, 1, 2, 1, 1, 1]
2
1
[2, 2, 1, 1, 1]
2
1
[2, 2, 1, 1]
1
[2, 2, 1]
1
[2, 2]
```

示例2：

```python
x = [1, 2, 1, 2, 1, 1, 1]
for i in x[::-1]:
    print(i)
    if i == 1:
        x.remove(i)
        print(x)
```

程序输出：

```python
1
[2, 1, 2, 1, 1, 1]
1
[2, 2, 1, 1, 1]
1
[2, 2, 1, 1]
2
1
[2, 2, 1]
2
1
[2, 2]
```

## 列表元素访问与计数

1. 下标可直接访问列表中的元素。如果指定下标不存在，则抛出异常提示下标越界。
2. 使用列表对象的 `index()`方法可以获取指定元素首次出现的下标，语法为 `index(value, [start, [stop]])`，其中，start和stop用来指定搜索范围，start默认为0，stop默认为列表长度。若列表对象中不存在指定元素，则抛出异常提示列表中不存在该值。
3. 如果需要知道指定元素在列表中出现的次数，可以使用列表对象的 `count()`方法进行统计。这方法也可以用于元组、字符串以及 `range`对象。

## 成员资格判断

如果需要判断列表中是否存在指定的值，可以使用前面介绍的 `count()`方法；如果存在指定的值，则返回大于0的数；如果返回0.则表示不存在指定的值。或者，使用更加简洁的in关键字来判断一个值是否存在于列表中，返回结果为True或False。

关键字in和not in也可以用于其他可迭代对象，包括元组、字典、range对象、字符串、集合等，常用在循环语句中对可迭代对象中的元素进行遍历。

## 切片操作

切片是Python中有序序列的重要操作之一，适用于列表、元组、字符串、range对象等类型。切片使用2个冒号分隔的3个数字来完成：`[start:stop:step]`，第一个数字表示切片开始位置（默认为0），第二个数字表示切片截止（但不包含）位置（默认为列表长度），第三个数字表示切片的步长（默认为1），当步长省略时可以省略最后一个冒号；当步长为负数时，从右往左切。

可以使用切片来截取列表中的任何部分，得到一个新列表，也可以通过切片来修改和删除列表中的部分元素，甚至可以通过切片操作为列表对象增加元素。

与使用下标访问列表元素的方法不同，切片操作不会因为下标越界而抛出异常，而是简单地在列表尾部截断或返回一个空列表，代码具有更强的健壮性。

切片操作作用于元组和字符串时，只能用来读取其中的部分元素，但作用于列表时可以实现很多目的，例如原地修改列表内容，列表元素的增、删、改、查以及元素替换等操作都可以通过切片来实现，并且不影响列表对象在内存中的起始位置。

1. 尾部追加元素：

   ```python
   aList = [3, 5, 7]
   print(aList[len(aList):])
   print( "id(aList)={}".format(id(aList)) )
   aList[len(aList):] = [9]
   print(aList)
   print( "id(aList)={}".format(id(aList)) )
   ```

   程序输出：

   ```python
   []
   id(aList)=1744889706432
   [3, 5, 7, 9]
   id(aList)=1744889706432
   ```
2. 替换列表元素：

   示例1：

   ```python
   aList = [3, 5, 7]
   print( "id(aList)={}".format(id(aList)) )
   aList[0:3] = [1, 2, 3]
   print(aList)
   print( "id(aList)={}".format(id(aList)) )
   ```

   程序输出：

   ```python
   id(aList)=1744889368320
   [1, 2, 3]
   id(aList)=1744889368320
   ```

   示例2：

   切片不连续，要求等号两侧元素数量一样

   ```python
   aList = list(range(10))
   print( "aList={},id(aList)={}".format(aList, id(aList)) )
   aList[0::2] = [0] * ( len(aList)//2 )
   print( "aList={},id(aList)={}".format(aList, id(aList)) )
   ```

   程序输出：

   ```
   aList=[0, 1, 2, 3, 4, 5, 6, 7, 8, 9],id(aList)=1744889692928
   aList=[0, 1, 0, 3, 0, 5, 0, 7, 0, 9],id(aList)=1744889692928
   ```
3. 删除列表元素：

   示例1:

   ```python
   aList = [3, 5, 7]
   print( "id(aList)={}".format(id(aList)) )
   aList[0:3] = []
   print(aList)
   print( "id(aList)={}".format(id(aList)) )
   ```

   程序输出:

   ```python
   id(aList)=1744889704704
   []
   id(aList)=1744889704704
   ```

   示例2：

   del命令与切片操作来删除列表中的部分元素。

   ```python
   aList = list(range(10))
   print( "aList={},id(aList)={}".format(aList, id(aList)) )
   del aList[::2]
   print( "aList={},id(aList)={}".format(aList, id(aList)) )
   ```

   程序输出：

   ```python
   aList=[0, 1, 2, 3, 4, 5, 6, 7, 8, 9],id(aList)=1744888648192
   aList=[1, 3, 5, 7, 9],id(aList)=1744888648192
   ```

切片返回的是浅复制。所谓浅复制是指生成一个新的列表，并且把源列表中所有元素的引用都复制到新列表中。如果原列表中包含整数、实数、复数等基本类型或元组、字符串这样的不可变类型的数据，一般是没有问题的，包含列表等可变对象时情况比较复杂。

    示例1：

```python
aList = [3, 5, 7]
bList = aList[:]    #切片，浅复制
print( "aList == bList :{}".format(aList == bList) )    #切片完成，bList和aList中包含同样的元素引用
print( "aList is bList :{}".format(aList is bList) )    #切片得到的bList对象和aList对象不是同一个对象
bList[1] = 8    #列表中只包含可哈希对象，修改bList时不影响aList
print("bList:{}".format(bList))
print("aList:{}".format(aList))

aList = [3, [5], 7]
bList = aList[:]    #切片
bList[1].append(6)  #调用子列表的append()方法，这个方法是原地操作的
print("bList:{}".format(bList))
print("aList:{}".format(aList))
```

程序输出;

```python
aList == bList :True
aList is bList :False
bList:[3, 8, 7]
aList:[3, 5, 7]
bList:[3, [5, 6], 7]
aList:[3, [5, 6], 7]
```

示例2：

```python
import copy

aList = [3, [5], 7]
bList = copy.deepcopy(aList)	#深复制，递归复制，直到遇到可哈希对象	aList和bList完全独立，互不影响
print( "aList == bList :{}".format(aList == bList) )
print( "aList is bList :{}".format(aList is bList) )
bList[1].append(6)	#x
print("bList:{}".format(bList))
print("aList:{}".format(aList))
```

程序输出：

```python
aList == bList :True
aList is bList :False
bList:[3, [5, 6], 7]
aList:[3, [5], 7]
```

## 列表排序与逆序

使用列表对象自身提供的sort()方法可以进行原地排序，没有返回值，或者说返回空值None。

也可以使用内置函数sorted()对列表进行排序，与列表对象的sort()方法不同，内置函数sorted()返回新列表，并不对原列表进行任何修改。

Python提供了内置函数reversed()支持对列表元素进行逆序（注意，不是降序）排序，与列表对象的reverse()方法不同，内置函数reversed()不对原列表做任何操作，而是返回一个逆序排序后的迭代对象。

## 用于序列操作的常用内置函数

1. all()和any()

all()函数用来测试列表、元组等序列对象以及map()对象、zip对象等类似对象中是否所有元素都等价于True，any()函数用来测试序列或可迭代对象中是否存在等价于True的元素。

2. len(列表)

返回列表中的元素个数，同样适用于元组、字典、集合、字符串、range对象。

3. max(列表)、min(列表)

返回列表中的最大或最小元素，同样适用于元组、字符串、集合、range对象、字典等，要求所有元素之间可以进行大小比较。这两个函数支持使用key参数指定排序规则。

4. sum(列表)

对数值型列表的元素进行求和运算，对非数值型列表运算则需要指定第二个参数，同样适用于元组、集合、range对象、字典以及map对象、filter()对象等。

5. zip(*iteraables)

将多个可迭代对象对应位置的元素组合为元组，并返回包含这些元组对象的zip对象。

6. enmuerate(列表)

枚举列表、字典、元组或字符串中的元素，返回枚举对象，枚举对象中每个元素包含下标和元素值的元组。该函数对字符串、字典同样适用。

## 列表推导式

列表推导式语法形式为**[ exp for variable in iterable if condition ]**。

```python
aList = [ x*x for x in range(10) ]

# 等价于

aList = []
for x in range(10):
	aList.append(x*x)
```

1. 使用列表推导式实现嵌套列表得到平铺。

   ```python
   vec = [ [1, 2, 3], [4, 5, 6], [7, 8, 9]]
   ivec = [ num for elem in vec for num in elem ]
   print(ivec)
   ```

   程序输出：

   ```python
   [1, 2, 3, 4, 5, 6, 7, 8, 9]
   ```
2. 过滤不符合条件的元素

   ```python
   aList = [ -1, 0, 2, -6, 3, 9.4, -10 ]
   aList = [ x for x in aList if x>=0 ]
   print(aList)
   ```

   程序输出：

   ```python
   [0, 2, 3, 9.4]
   ```
3. 在列表推导式中使用多个循环

   ```python
   aList = [ (x, y) for x in range(3) for y in range(3) ]
   print(aList)
   ```

   程序输出：

   ```python
   [(0, 0), (0, 1), (0, 2), (1, 0), (1, 1), (1, 2), (2, 0), (2, 1), (2, 2)]
   ```
4. 使用列表推导式实现矩阵转置

   ```python
   matrix = [ [1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12] ]
   tmatrix = [ [row[i] for row in matrix] for i in range(4) ]
   print(tmatrix)
   ```

   程序输出：

   ```python
   [[1, 5, 9], [2, 6, 10], [3, 7, 11], [4, 8, 12]]
   ```
5. 列表推导式中可以使用函数或复杂表达式

   ```python
   def f(v):
       if v%2 == 0:
           v = v**2
       else:
           v = v+1
       return v
   print([f(v) for v in [2, 3, 4, -1] if v>0])
   print([v**2 if v%2==0 else v+1 for v in [2, 3, 4, -1] if v>0])  
   ```

   程序输出：

   ```python
   [4, 4, 16]
   [4, 4, 16]
   ```
6. 列表推导式支持文件对象迭代

   ```python
   fp = open('C:\install.log', 'r')
   print([line for line in fp])
   fp.close()
   ```
7. 使用列表推导式生成100以内的所有素数

   ```python
   from math import sqrt
   prime_list = [p for p in range (2, 100) if 0 not in [ p%d for d in range(2, int(sqrt(p))+1)] ]
   print( prime_list )
   ```

   程序输出：

   ```python
   [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
   ```

## 使用列表实现向量运算

# 元组

元组是轻量级列表，属于不可变序列。

## 元组的创建与删除

1. 使用“=”将一个元组赋值给变量，就可以创建一个元组变量。

   ```python
   a_tuple = ( 'a', 'b', 'mailgrim', 'z', 'example' )
   x = ()	# 空元组
   ```

   如果要创建只包含一个元素的元组，需要在唯一元素后面加一个逗号。创建含多个元素的元组没有这个限制。
2. 可以使用 `tuple()`函数将列表、字符串、字典、集合、map对象等其它类型可迭代对象转换为元组。

   ```python
   s = tuple()	# 空元组
   b_tuple = tuple('abcdefg')
   ```
3. 只能使用del命令删除整个元组对象，不能只删除元组中的部分元素，因为元组属于不可变序列。

## 元组与列表的区别

列表属于可变序列，可以随意地修改列表中的元素值以及增加和删除列表元素，元组属于 不可变序列，元组一旦定义就不允许通过任何方式更改。

元组也支持切片操作，但是只能通过切片来访问元组中的元素，不支持使用切片来修改元组中元素的值，也不支持使用切片操作来为元组增加或删除元素。

元组的访问和处理速度比列表块。

作为不可变序列，与整数、字符串一样、元组可用作字典的“键”和集合的元素，而列表则永远都不能这样使用。

虽然元组属于不可变序列，其元素的值是不可改变的，但是如果元组中包含可变序列，情况就略有不同。

```python
a_tuple = ([1, 2], 3)
a_tuple[0][0] = 5
print(a_tuple)
a_tuple[0].append(8)
print(a_tuple)
a_tuple[0] = a_tuple[0] + [10]
print(a_tuple)
```

程序输出:

```python
([5, 2], 3)
([5, 2, 8], 3)
---------------------------------------------------------------------------
TypeError                                 Traceback (most recent call last)
a:\SOURCE\source_py\source_ipynb\code-1.ipynb Cell 33' in <cell line: 6>()
      4 a_tuple[0].append(8)
      5 print(a_tuple)
----> 6 a_tuple[0] = a_tuple[0] + [10]
      7 print(a_tuple)

TypeError: 'tuple' object does not support item assignment
```

 如果元组中包含列表、字典、集合或其他可变类型的对象，这样元组不能作为字典“键”或集合的元素。

## 序列解包

在实际开发中，序列解包时非常重要和常用的一个用法，大幅度提高了代码的可读性，并且减少了程序员的代码输入量。例如，可以使用序列解包对多个变量同时进行赋值：

```python
x, y, z = 1, 2, 3
v_tuple = ( False, 3.5, 'exp' )
(x, y, z) = v_tuple
```

序列解包也可以用于列表和字典，但是对字典使用时，默认是对字典“键”操作，如果需要对“键：值”元素操作，需要使用字典的items()方法说明，如果需要对字典“值”操作，则需要使用字典的values方法明确指定。对字典操作时，不需要对元素的顺序考虑过多。

```python
a = [1, 2, 3]
b, c, d = a
s = {'a':1, 'b':2, 'c':3}
b, c, d = s.items()
b, c, d = s
b, c, d = s.values()
a, b = b, a
```

使用序列解包可以方便地同时遍历多个序列。

```python
keys = ['a', 'b', 'c', 'd']
values = [1, 2, 3, 4]
for k, v in zip(keys, values):
	print(k, v)
```

程序输出：

```python
a 1
b 2
c 3
d 4
```

在调用函数时，在实参前面加上一个或两个星号（*）也可以进行序列解包，从而实现将序列中地元素值依次传递给相同数量的形参。

```python
>>> print(*[1], *[2], 3, *[4, 5])
1 2 3 4 5
>>> def demo(a, b, c, d):
  		print(a, b, c, d)
>>> demo(**{'a':1, 'c':3}, **{'b':2, 'd':4})
1 2 3 4
```

## 生成器表达式

从形式上看，生成器表达式与列表推导式非常接近，只是生成器表达式使用括号而不是列表推导式所使用的方括号。与列表推导式本质上不同的是，生成器表达式的结果是一个生成器对象。使用生成器对象的元素时，可以根据需要将其传话为列表、集合、或元组，也可以使用内置函数next()、生成器对象的 `__next__()`方法获取下一个元素，或者直接使用for循环遍历。但是不管用哪种方法访问其元素，当所有元素访问结束以后，如果需要重新访问其中的元素，必须重新创建该生成器对象。也就是说，生成器对象中的每个元素只能使用一次，并且只能从前任往后顺序访问。

```python
>>> g = ( (i+2)**2 for i in range(10) )
>>> g
<generator object <genexpr> at 0x00000118FFF6DDD0>
>>> tuple(g)
(4, 9, 16, 25, 36, 49, 64, 81, 100, 121)
>>> tuple(g)
()
>>> g = ( (i+2)**2 for i in range(10) )
>>> list(g)
[4, 9, 16, 25, 36, 49, 64, 81, 100, 121]
>>> g = ( (i+2)**2 for i in range(10) )
>>> g.__next__()
4
>>> next(g)
9
>>> next(g)
16
>>> g = ( (i+2)**2 for i in range(10) )
>>> for i in g:
    	print(i, end=' ')
4 9 16 25 36 49 64 81 100 121
```

# 字典

字典是包含若干”键：值“对的无序可变序列，字典中的每个元素包含两个部分：”键“和”值“。定义字典时，每个元素的”键“和”值“用冒号分隔，相邻元素之间用逗号隔开，所有的元素都放在一对大括号“{”和“}”中。

字典中的“键”可以是Python中任意不可变数据，例如整数、实数、复数、字符串、元组等，但不能使用列表、集合、字典作为字典的“键”，包含列表、集合、字典的元组也不能作为字典的“键”。另外，字典中的“键”不允许重复，“值”可以重复。

## 字典的创建与删除

1. 使用“=”将一个字典赋值给一个变量即可创建一个字典变量。

   ```python
   a_dict =  {'server':'db.diveinpython3.org', 'datebse':'mysql'}
   ```
2. 使用内置函数dict()通过已有数据快速创建字典。

   ```python
   keys = ['a', 'b', 'c', 'd']
   values = [1, 2, 3, 4]
   a_dict = dict(zip(keys, values))
   x = dict()              # 空字典
   x = {}                  # 空字典
   ```

   或使用内置函数dict()根据指定的”键：值“来创建字典：

   ```python
   d = dict(name='Dong', age=37)
   ```

   还可以以给定内容为“键”，创建“值”为空或特定值的字典：

   ```python
   adict = dict.fromkeys(['name', 'age', 'sex'])
   print(adict)
   程序输出：
   {'name': None, 'age': None, 'sex': None}
   ```

当不再使用某个字典时 ，可以使用del命令删除整个字典，也可以使用del命令删除字典中指定的元素。

## 字典元素的读取

可以使用字典的键作为下标来访问字典元素的值，若指定的键不存在则抛出异常。

```python
aDict = {'name': 'Dong', 'age': 38, 'sex': 'male'}
print(aDict['name'])
print(aDict['tel'])
```

程序输出：

```python
Dong
---------------------------------------------------------------------------
KeyError                                  Traceback (most recent call last)
a:\SOURCE\source_py\source_ipynb\code-1.ipynb Cell 37' in <cell line: 3>()
      1 aDict = {'name': 'Dong', 'age': 38, 'sex': 'male'}
      2 print(aDict['name'])
----> 3 print(aDict['tel'])

KeyError: 'tel'
```

更加安全的字典元素访问方式时字典对象的get()方法。使用字典对象的get()方法可以获取指定键对应的值，并且可以在指定键不存在的时候返回指定值，如果不指定，则默认返回None。

```python
aDict = {'name': 'Dong', 'age': 38, 'sex': 'male'}
print(aDict.get('address'))
print(aDict.get('address', 'SDIBT'))
```

程序输出：

```python
None
SDIBT
```

使用字典对象的items()方法可以返回字典的键：值对，使用字典对象的keys()方法可以返回指定的键，使用指定对象的values()方法可以返回指定的“值”。

```python
>>> aDict = {'name':'Dong', 'age':38, 'sex':'male'}
>>> aDict.keys()
dict_keys(['name', 'age', 'sex'])
>>> aDict.values()
dict_values(['Dong', 38, 'male'])
>>> aDict.items()
dict_items([('name', 'Dong'), ('age', 38), ('sex', 'male')])
>>> for item in aDict.items():
...    print(item)
...
('name', 'Dong')
('age', 38)
('sex', 'male')

>>> for key, value in aDict.items():
...    print(key,value,sep=':')
...
name:Dong
age:38
sex:male
```

## 字典元素的添加和修改

当以指定键为下标为字典元素赋值时，若该键存在，则表示修改该键的值‘若不存在；则表示添加一个新的键值对，也就是添加一个新的元素。

```python
aDict = { 'name':'SuPeng', 'sex':'men', 'age':19 }
print(aDict)
aDict['age'] = 20
aDict['address'] = 'Chongqing'
print(aDict)
```

程序输出：

```python
{'name': 'SuPeng', 'sex': 'men', 'age': 19}
{'name': 'SuPeng', 'sex': 'men', 'age': 20, 'address': 'Chongqing'}
```

使用字典对象的update()方法将另一个字典的键值对一次性全部添加到当前字典对象，如果两个字典中存在相同的键，则以另一个字典中的值为准对当前字典进行更新。

当需要删除字典元素时，可以根据具体要求使用del命令删除字典中指定键对应的元素，或者也可以使用字典对象得到clear()方法来删除字典中所有元素，还可以使用字典对象的pop()方法删除并返回指定键的元素，或者使用字典对象的popitem()方法删除并返回字典中的一个元素。

## 字典应用案例

统计字符出现次数：

示例1：

```python
from random import choices
from string import ascii_letters, digits
z = ''.join(choices(ascii_letters,k=1000))
d = dict()
for ch in z:
    d[ch] = d.get(ch, 0) + 1
print(d)  
```

程序输出：

```python
{'x': 25, 'k': 12, 't': 21, 'E': 27, 'F': 18, 'l': 17, 'L': 20, 'B': 20, 'a': 20, 'b': 16, 'n': 20, 'R': 32, 'p': 15, 'c': 21, 'M': 19, 'g': 15, 'U': 22, 'X': 18, 'w': 25, 'I': 20, 'G': 20, 'Z': 20, 'q': 16, 'h': 21, 'C': 22, 'K': 22, 'P': 20, 'A': 15, 'Q': 15, 'd': 18, 'N': 25, 'Y': 18, 'j': 21, 'S': 29, 'u': 19, 'r': 26, 'o': 28, 'm': 19, 'O': 24, 'W': 21, 's': 25, 'i': 13, 'v': 19, 'T': 17, 'e': 17, 'f': 11, 'z': 13, 'D': 16, 'V': 13, 'H': 13, 'y': 9, 'J': 12}
```

也可以使用collections模块的defaultdict类来实现该功能。

```python
from collections import defaultdict
from random import choices
from string import ascii_letters, digits

z = ''.join(choices(ascii_letters,k=1000))
frequzences = defaultdict(int)
print(frequzences)
for item in z:
    frequzences[item] += 1
print(frequzences.items())  
```

程序输出：

```python
defaultdict(<class 'int'>, {})
dict_items([('F', 21), ('V', 30), ('P', 16), ('j', 16), ('c', 20), ('I', 17), ('n', 21), ('z', 20), ('H', 13), ('G', 17), ('E', 15), ('R', 21), ('Q', 28), ('Y', 22), ('Z', 23), ('S', 20), ('A', 23), ('r', 19), ('L', 26), ('u', 15), ('p', 22), ('y', 20), ('U', 20), ('w', 20), ('o', 21), ('v', 19), ('h', 21), ('a', 26), ('l', 17), ('J', 22), ('q', 26), ('K', 10), ('f', 19), ('k', 21), ('B', 17), ('b', 21), ('M', 16), ('C', 17), ('D', 20), ('g', 17), ('s', 18), ('N', 15), ('m', 15), ('T', 8), ('t', 14), ('e', 17), ('x', 14), ('O', 16), ('X', 22), ('d', 27), ('i', 20), ('W', 19)])
```

使用collections模块的Counter类可以快速实现这个功能，并且能够满足其他需要，例如查找出现次数最多的元素。

```python
from collections import Counter
from collections import defaultdict
from random import choices

z = ''.join(choices(ascii_letters,k=1000))
frequzences = Counter(z)
print(frequzences.items())
print("出现次数最多的1个字符和次数:",frequzences.most_common(1))
print("出现次数最多的3个字符和次数:",frequzences.most_common(3))

```

程序输出：

```python
dict_items([('r', 13), ('b', 21), ('m', 18), ('t', 23), ('L', 30), ('v', 29), ('f', 21), ('E', 17), ('O', 22), ('A', 23), ('F', 22), ('s', 29), ('u', 19), ('X', 22), ('K', 26), ('V', 28), ('a', 20), ('g', 18), ('x', 18), ('z', 18), ('i', 18), ('o', 22), ('j', 16), ('w', 19), ('J', 19), ('Q', 16), ('G', 27), ('y', 23), ('T', 16), ('H', 19), ('R', 19), ('W', 20), ('S', 16), ('N', 17), ('l', 13), ('e', 16), ('B', 18), ('Z', 16), ('d', 11), ('U', 17), ('c', 22), ('n', 19), ('q', 21), ('h', 12), ('p', 15), ('Y', 17), ('C', 25), ('I', 17), ('P', 17), ('D', 11), ('k', 16), ('M', 13)])
出现次数最多的1个字符和次数: [('L', 30)]
出现次数最多的3个字符和次数: [('L', 30), ('v', 29), ('s', 29)]
```

## 字典推导式

类似于列表推导式，Python也可以支持字典推导式快速生成符合特定条件的字典。

```python
aDict = {i:str(i) for i in range(1, 5)}
print(aDict)
x = ['A', 'B', 'C', 'D']
y = [ 'a', 'b', 'c', 'd']
aDict = {i:j for i,j in zip(x, y)}
print(aDict)
```

程序输出：

```python
{1: '1', 2: '2', 3: '3', 4: '4'}
{'A': 'a', 'B': 'b', 'C': 'c', 'D': 'd'}
```

# 集合

集合是**无序可变**的容器对象，与字典一样使用一对大括号作为界定符，同一个集合的元素之间不允许重复，集合中每个元素都是唯一的。

## 集合的创建于删除

直接将集合赋值给变量即可创建一个集合对象。

```python
a = {3, 5}
```

也可以使用set()函数将列表、元组等其他可迭代对象逆换为集合，如果原来地数据中存在重复元素，在转换为集合的时候只保留一个。

```python
a_set = set(range(8, 14))
print(a_set)
b_set = set([0, 1, 2, 3, 0, 1, 2, 3, 7, 8, 9])
print(b_set)
x = set()       #空集合
```

程序输出：

```python
{8, 9, 10, 11, 12, 13}
{0, 1, 2, 3, 7, 8, 9}
```

可以使用集合对象的add()方法增加元素（元素已存在时自动忽略）。另外，也可以使用集合对象的pop()方法弹出并删除其中的一个元素，或者使用集合对象的remove()方法直接删除指定元素，以及使用集合对象的clear()方法清空集合删除所有元素。当不再使用某个集合时，可以使用del命令删除整个集合。

```python
a = {1, 4, 2, 3}
print(a.pop())
a.remove(3)
print(a)
a.pop(2)
```

程序输出：

```python
1
{2, 4}
---------------------------------------------------------------------------
TypeError                                 Traceback (most recent call last)
a:\SOURCE\source_py\source_ipynb\code-1.ipynb Cell 45' in <cell line: 5>()
      3 a.remove(3)
      4 print(a)
----> 5 a.pop(2)

TypeError: set.pop() takes no arguments (1 given)
```

## 集合运算

Python集合支持交集、并集、差集以及子集测试等运算。

示例1：

```python
a_set = set([8, 9, 10, 11, 12, 13])
b_set = set([0, 1, 2, 3, 7, 8])
print(a_set | b_set)    # 并集
print(a_set & b_set)    # 交集
print(a_set - b_set)    # 差集
print(a_set ^ b_set)    # 对称差集
```

程序输出：

```python
{0, 1, 2, 3, 7, 8, 9, 10, 11, 12, 13}
{8}
{9, 10, 11, 12, 13}
{0, 1, 2, 3, 7, 9, 10, 11, 12, 13}
```

示例2：

```python
x = {1, 2, 3}
y = {1, 2, 5}
z = {1, 2, 3, 4}
print(x<y)  # 比较集的大小
print(x<z)  # x 是 z的子集
print(y<z)  # y 不是 z的子集
```

程序输出：

```python
False
True
False
```

## 集合运用案例

示例：生成不重复随机数的效率比较，不允许使用rarcdom模块的sample()函数。

```python
import random
import time

def RandomNumbers( number, start, end ):
    '''使用列表生成number个介于start~end的不重复随机数'''
    data = []
    n = 0
    while True:
        elemnt = random.randint(start, end)
        if elemnt not in data:
            data.append(elemnt)
            n += 1
            if n == number-1:
                break
    return data

def RandomNumbers1( number, start, end ):
    '''使用列表生成number个介于start~end的不重复随机数'''
    data = []
    while True:
        elemnt = random.randint(start, end)
        if elemnt not in data:
            data.append(elemnt)
            if len(data) == number-1:
                break
    return data

def RandomNumbers2( number, start, end ):
    '''使用列表生成number个介于start~end的不重复随机数'''
    data = set()
    while True:
        data.add(random.randint(start, end))
        if len(data) == number-1:
            break
    return data

start = time.time()
for i in range(10000):
    RandomNumbers(50, 1, 100)
print('RandomNumbers Time used:',time.time()-start)

start = time.time()
for i in range(10000):
    RandomNumbers1(50, 1, 100)
print('RandomNumbers1 Time used:',time.time()-start)

start = time.time()
for i in range(10000):
    RandomNumbers2(50, 1, 100)
print('RandomNumbers2 Time used:',time.time()-start)  
```

程序输出：

```python
RandomNumbers Time used: 0.4264869689941406
RandomNumbers1 Time used: 0.43109798431396484
RandomNumbers2 Time used: 0.3267791271209717
```

# 内置函数storted()

# 复杂数据结构

## 堆

## 队列

## 栈

## 链表

## 二叉树

## 有向图

# 选择与循环

## 条件表达式

在Python中，单个常量、变量或者任意合法表达式都可以作为条件表达式。

在选择和循环结构中，条件表达式的值只要不是False、0（或0.0、0j等）、空值None、空列表、空元组、空集合、空字典、空字符串、空range对象或其他可迭代对象，Python解释器均认为True等价。

Python中较特殊的运算符：关系运算符（<、>），逻辑运算符（and、or）

在Python中关系运算符可以连续使用，而在很多语言中是不行的。

```python
>>> print(1<2<3)
True
>>> print(1<2>3)
False
>>> print(1<3>2)
True
```

逻辑运算符and和or具有短路求值或惰性求值的特点，在设计条件表达式时，如果能够大概预测给条件失败的概率，并将多个条件根据and和or运算的惰性求值特性组织先后顺序，可以大幅度提高程序的运行效率。

## 选择结构

```python
if 表达式:	# 单分支选择结构
    语句块

if 表达式：	# 双分支选择结构
    语句块1
else:
    语句块2

if 表达式：	# 多分支选择结构
    语句块1
elif:
    语句块2
elif:
    语句块3
else:
    语句块4   

```

双分支选择结构还有一种更简洁的表达方式：

```python
表达式1	if  条件  else  表达式2
```

## 循环结构

while循环：

```
while 条件表达式:
	循环体
```

for循环：

```python
for 变量 in 可迭代对象:
	循环体
```

while循环和for循环都可以带else子句，如果循环因为条件表达式不成立而自然结束（不是因为执行了break或continue语句而结束循环），则执行else结构中的语句。

```
while 条件表达式:
	循环体
else:
	else子句代码块

和

for 变量 in 可迭代对象:
	循环体
else:
	else子句代码块
```

## break和continue语句

Python中的break和continue语句与C语言中的一般无二。

# 字符串


在Python中，字符串使用单引号、双引号、三单引号或三双引号作为界定符，不同的界定符之间可以互相嵌套。字符串属于不可变序列，不能对字符串对象进行元素增加、修改与删除操作。字符串对象提供的replace()、translate()以及其它类似方法并不是对原字符直接修改替换，而是返回一个修改替换后的结果字符串。


## 字符串格式化

字符串格式化用来整数、实数、列表等对象转化为特定格式的字符串。

```python
'%[-][+][0][m][.n]格式字符'% x
```

- %格式化标志：表示格式开始
- [-]指定左对齐输出
- [+]对正数加正号
- [0]指定空位填0
- [m]指定最小宽度
- [.n]指定精度
- 格式字符：指定类型
- %格式运算符
- 待转换表达式

| 格式化 | 说明                              |
| ------ | --------------------------------- |
| %s     | 字符串                            |
| %r     | 字符串（采用repr()的显示）        |
| %c     | 单个字符                          |
| %d     | 十进制整数                        |
| %i     | 十进制整数                        |
| %o     | 八进制整数                        |
| %x     | 十六进制整数                      |
| %e     | 指数（基底写为e）                 |
| %E     | 指数（基底写为E）                 |
| %f、%F | 浮点数                            |
| %g     | 指数（e）或浮点数（根据显示长度） |
| %G     | 指数（E）或浮点数（根据显示长度） |
| %%     | 字符“%”                         |


```python
>>> x = 1235
>>> '%o'%x
'2323'
>>> '%x'%x
'4d3'
>>> '%e'%x
'1.235000e+03'
>>> '%s'%65		# 类似str()
'65'
>>> '%d %c' % (65, 65)	# 如果格式化的对象多余一个，要放在元组中
'65 A'
>>> '%d' % '555'	# 试图将字符串转换为整数进行输出，抛出异常
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: %d format: a number is required, not str
```

**format()方法格式化**

基本使用格式：

```
<模板字符串>.format(<逗号分隔的参数>)
```

# 正则表达式

## 正则表达式

正则表达式由元字符及其不同组合来构成，通过巧妙地构造正则表达式可以匹配任意字符串，并完成复杂地字符串处理任务。

| 元字符 | 功能说明                                                   |
| ------ | ---------------------------------------------------------- |
| .      | 匹配除换行符以外的任意单个字符，单行模式下也可以匹配换行符 |
| *      | 匹配位于 * 之前的字符或子模式的0次或多次重复               |
| +      | 匹配位于 + 之前的字符或子模式的1次或多次重复               |
| -      | 用在[ ]内表示范围                                          |
| \|     | 匹配位于 \| 之前或之后的字符，表示二选一                   |
| ^      | 匹配行首，匹配以^后面的字符开头的字符串                    |
| $      | 匹配行尾，匹配以$之前的字符结束的字符串                    |
| ?      | 匹配位于？之前字符或子模式的0次或1次出现。                 |
| \      | 表示位于\之后的转义字符                                    |
| \num   | 此处的num是一个表示子模式序号的正整数。                    |
| \f     | 匹配换页符                                                 |
| \n     | 匹配换行符                                                 |
| \r     | 匹配一个回车符                                             |
| \b     | 匹配单词头或单词尾                                         |
| \B     | 与`\b`含义相反                                             |
| \d     | 匹配任何数字，相当于`[0-9]`                                |
| \D     | 与`\d`含义相反，等效于`[^0-9]`                             |
| \s     | 匹配任何空白字符                                           |
| \S     | 与'\s'含义相反                                             |
| \w     | 匹配任何字母、数字以及下划线，相当于[a-zA-Z0-9_]           |
| \W     | 与`\w`含义相反，与[ ^ a-zA-Z0-9_]等效                      |
| ( )    | 将位于()的内容作为一个整体对待，表示子模式                 |
| {m, n} | 按{}中次数进行匹配，至少m次，至多n次                       |
| []     | 匹配位于[]中的任意一个字符                                 |
| [^xyz] | 反向字符集，匹配除x,y,z之外的任何字符                      |
| [a-z]  | 字符范围，匹配指定范围内的任何字符                         |
| [^a-z] | 反向范围字符，匹配除小写英文字母之外的任何字符             |
|        |                                                            |

## re模块主要函数

| 函数                                  | 功能说明                                      |
| ------------------------------------- | --------------------------------------------- |
| compile(pattern[, flags])             | 创建正则表达式                                |
| search(pattern, string[, flags])      | 在整个字符串中寻找模式，返回Match对象或None   |
| match(pattern, string[, flags])       | 从字符串的开始处匹配模式，返回Match对象或None |
| findall(pattern, string[, flags])     | 返回字符串中模式的所有匹配项组成的列表        |
| split(pattern, string[, maxsplit=0])  | 根据模式匹配项                                |
| sub(pattern, repl, string[, count=0]) | 将字符串中所有pattern的匹配项用repl替换       |
| escape(string)                        | 将字符串中所有特殊正则表达式进行转义          |

其中，函数参数flags的值可以是re.I（忽略大小写），re.L，re.M（多行匹配模式），re.S（使元字符'.'匹配字符，包括换行符），re.U（匹配Unicode字符），re.X（忽略模式中的空格，并可以使用#注释）的不同组合（使用"|"进行组合）。

## 直接使用re模块函数

可以直接使用re模块函数来实现正则表达式操作





## 使用正则表达式对象

首先使用re模块的compile()函数将正则表达式编译生成正则表达式对象，然后再使用正则表达式对象提供的方法进行字符串处理，可以提高字符串处理速度，适合多次使用一个表达式的场景。

正则表达式对象的match(string[, pos[, endpos]])方法在字符串开头或指定位置进行搜索，模式必须出现在字符串开头或指定位置；search(string[, pos[, endpos]])方法在整个字符串或指定范围进行搜索；findall(string[, pos[, endpos]])方法在字符串中查找所有符合正则表达式的字符串并以列表形式返回。

 示例：

```python
import re
example = 'ShanDong Institute of Business and Technology'
pattern = re.compile(r'\bB\w+\b')           # 以B开头的单词
print( pattern.findall(example) )

pattern = re.compile(r'\w+g\b')             # 以g结尾的单词
print( pattern.findall(example) )
```

程序输出：

```python
['Business']
['ShanDong']
```

​      





## 子模式与Match对象

使用括号表示一个子模式，括号内的内容作为一个整体使用，例如"(red)+"可以匹配redred、redredred等多个重复red的情况。

```python
telNumber = '''Suppose my Phone N0. is 0535-1234567,
yours is 010-12345678, his is 025-87654321.
'''
pattern = re.compile(r'(\d{3,4})-(\d{7,8})')
print( pattern.findall(telNumber) )
```

程序输出：

```python
[('0535', '1234567'), ('010', '12345678'), ('025', '87654321')]
```

正则表达式对象的match()方法和search()方法以及re模块的同名函数匹配成功后都会返回Match对象。Match对象的主要发有group()（返回匹配的一个或多个子模式内容），groups()（返回一个包su偶有子模式内容的元组）、groupdict()（返回包含匹配的所有命名子模式内容的字典）、start()（返回指定子模式内容的起始位置），end()（返回指定子模式内容结束位置的下一个位置）、span()（返回一个包含指定子模式内容起始位置和结束位置的下一个位置的元组）等。下面的代码使用re模块的search()方法返回的Match对象来删除字符串中指定内容，可以自行尝试使用re.sub()函数改写。

使用子模式扩展语法可以实现更加复杂的字符串处理，子模式扩展         语法如下：

​                      

| 语法            | 功能说明                                                     |
| --------------- | ------------------------------------------------------------ |
| (?p<groupname>) | 为子模式命名                                                 |
| (?iLmsux)       | 设置匹配标志，可以是几个字母的组合，每个字母含义与编译标志相同 |
| (?:···)         | 匹配但不记录该匹配的子表达式                                 |
| (?p=groupname)  | 表示在此之前的命名为groupname的子模式                        |
| (?#···)         | 表示注释                                                     |
| (?=···)         | 用于正则表达式之后，表示如果“=”后的内容在字符串中出现则匹配，但不返回“=”之后的内容 |
| (?!···)         | 用于正则表达式之后，表示如果“!”后的内容在字符串中不出现则匹配，但不返回“!”之后的内容 |
| (?<=···)        | 用于正则表达式之前，与(?=···)含义相同                        |
| (?<!···)        | 用于正则表达式之前，与(?!···)含义相同                        |



# 函数



## 函数的定义

在Python中，定义函数的语法如下：

```python
def  函数名([参数列表])：
		    	       '''注释'''
		    	       函数体
```

- 函数形参不需要声明其类型，也不需要指定函数返回值类型
- 即使函数不需要接收任何参数，也必须保留一对空的括号
- 括号后面的冒号必不可少
- 函数体相对于def关键字必须保持一定的空格缩进。
- Python允许嵌套定义函数

如果在函数开头部分加上一段注释，在调用该函数时，输入左侧括号之后，立刻就会得到该函数的使用说明。



## 形参与实参

函数定义时括号内是使用逗号分隔开的形参，一个函数可以有形参，但是定义和调用时一对括号必须有，表示这是一个函数并且不接受参数。函数调用时向其传递实参，将实参的引用传递给形参。

在定义函数时，对参数个数并没有限制，如果有多个形参，则需要使用逗号进行分隔。

对于绝大多数情况下，在函数内部直接修改形参的值不会影响实参。

存在一些特殊情况，可以通过特殊的方式在函数内部修改实参的值。如果传递给函数的是Python可变序列，并且在函数内部使用下标或序列自身原地操作的方法为可变序列增加、删除或修改元素值时，修改后的结果可以反映到函数之外，实参也得到相应的修改。

## 参数类型

Python函数参数分类：

- 普通位置参数
- 默认值参数
- 关键参数
- 可变长参数

函数参数不需要指定参数的类型，也不需要指定函数的返回值类型。函数的返回值类型由return语句返回值的类型来决定，如果函数中没有return语句或者没有执行到return语句而返回或者执行不了带任何值的return语句，则函数都默认为返回空值None。

### 默认值参数

定义：在定义函数时为形参设置默认值。

调用带有默认参数的函数时，可以不对默认值参数进行赋值，也可以进行通过显示赋值来替换其默认值，既有较大的灵活性。如果需要，可以使用“函数名._ _defaults _ _"随时查看函数所有默认值参数的当前值，其返回值为一个元组，其中的元素依次表示每个默认参数的当前值。

在定义带有默认值参数的函数时，默认值参数必须全部出现在位置参数右侧。

多次掉用函数并且不为默认值参数传递值时，默认值参数只在函数定义时进行解释，然后默认值参数的引用不再变化。对于列表、字典等复杂类型的默认值参数，可能会导致很严重的逻辑错误。

```python
def demo(newitem, old_list = []):
    old_list.append(newitem)
    return old_list

print(demo('5', [1, 2, 3, 4]))
print(demo('aaa', ['a', 'b']))
print(demo('a'))
print(demo('b'))
```

### 关键参数

关键参数主要指调用函数时的参数传递方式，与函数定义无关。

可以通过关键参数可以按参数名字传值，实参顺序可以和形参顺序不一致。



### 可变长度参数

可变长度参数在定义函数时主要有两种形式：`paramenter` and `**paramenter`，前者用来接收多个位置实参并将其放在一个元组中，后者接收多个关键参数并将其放入字典中。



### 参数传递时的序列解包

为含有多个形参的函数传递参数时，可以使用Python列表、元组等其他可迭代对象作为实参，并在实参名称前加一个星号，python解释器会自动进行序列解包，然后传递给多个位置形参。如果使用字典对象作为实参，则默认使用字典的键；如果需要使用字典中的键值对，则需要使用items()方法，values()方法可以此类推。

如果使用字典作为实参，并在前面使用两个星号进行解包时，会把字典解包成为关键参数进行传递，字典的键作为参数名，字典的值作为参数的值



## return语句

函数的返回值类型由return语句返回值的类型来决定，如果函数中没有return语句或者没有执行到return语句而返回或者执行不了带任何值的return语句，则函数都默认为返回空值None。



## 变量作用域

在Python中主要有局部变量，nonlocal变量和全局变量三类，范围依次从近到远。在访问一个变量时首先使用局部变量，如果没有同名的局部变量则尝试使用外层函数中nonlocal变量，如果不存在外层函数或这同名的nonlocal变量则尝试使用全局变量，如果全局变量也不存在在尝试使用内置命名空间中的标识符，如果仍不存在则提示错误。





# OOP



## 类的定义与使用



## self参数

类的所有实例方法都至少有一个名为self的参数，并且必须是方法的第一个形参，self参数代表对象本身。在类的实例方法中访问实例属性时需要以self为前缀，但在外部通过对象名调用对象方法时并不需要传递这个参数，如果在外部通过类名调用对象方法则需要显示为self参数传值。









# 文件操作

**文本文件**：文本文件存储的是常规字符串，由若干文本行组成，通常每行以换行符`‘\n’`结尾。常规字符串是指记事本或其它文本编辑器能正常显示、编辑并且人类能够直接阅读和理解的字符串。

**二进制文本**：二进制文本把对象内容以字节串进行存储，无法用文本编辑器软件直接进行编辑，通常也无法被人类直接阅读和理解，需要使用专门的软件进行解码后读取、显示、修改或执行。

## 文件对象

Python通过打开文件并创建文件对象对文件内容进行读取、写入、删除、修改等操作，最后关闭并保存文件内容。Python内置了文件对象，通过`open()`函数即可以指定模式打开指定文件并创建文件对象,语法为：

```python
open(file, mode = 'rt', buffering = -1, encoding = None, errors = None, newline = None, closefd = True, opener = None) as fp:
```

- `file`指定了被打开的文件名称，如果打开的文件不在当前目录，还需指定完整路径，可以使用原始字符串。
- `mode`指定了打开文件后的处理方式
- `buffering`指定了读写文件的缓存模式，数值0代表不缓存，数值1表示缓存，如大于1则表示缓冲区的大小，默认值-1表示系统管理缓存。
- 如果执行正常，`open()`函数返回一个文件对象，通过该文件对象可以对文件进行各种操作，如果指定文件不存在、访问权限不够、磁盘空间不够或其它原因导致创建文件对象失败则抛出异常。

当对文件内容操作完以后，一定要关闭文件，以保证所做的任何修改都得到保存。

```python
fp.close()
```



**文件打开模式**

| 文件的打开模式 | 含义                                                        |
| -------------- | ----------------------------------------------------------- |
| ‘r’            | 只读模式，如果文件不存在，返回异常FileNotFoundError，默认值 |
| ‘w’            | 覆盖写模式，文件不存在则创建，存在则完全覆盖                |
| ‘x’            | 创建写模式，文件不存在则创建，存在则返回异常FielExistsError |
| ‘a’            | 追加模式，文件不存在则创建，存在则在文件最后追加内容        |
| ‘b’            | 二进制文件模式                                              |
| ‘t’            | 文本文件模式                                                |
| ‘+’            | 读写模式（可与其他模式组合使用）                            |

**文件对象常用属性**

| 属性   | 说明                                       |
| ------ | ------------------------------------------ |
| closed | 判断文件是否关闭，若文件被关闭，则返回True |
| mode   | 返回文件的打开模式                         |
| name   | 返回文件的名称                             |

**文件对象常用方法**

| 方法                   | 功能说明                                                     |
| ---------------------- | ------------------------------------------------------------ |
| flush()                | 把缓冲区的内容写入文件，但不关闭文件                         |
| close()                | 把缓冲区的内容写入文件，同时关闭文件，并释放文件对象         |
| read([size])           | 从文件中读取`size`字节（二进制文件）或字符（文本文件）的内容作为结果返回，如果省略`size`，则表示一次性读取所有作为结果 |
| readline()             | 从文件中读取一行内容作为结果返回                             |
| readlines()            | 把文本文件中的每行文本作为一个字符串存入列表中，返回该列表   |
| seek(offset[, whence]) | 把文件指针移到新的位置，`offset`表示相对于`whence`的偏移量，单位是字节。`whence`为0表示从文件头开始计算，1表示从当前位置开始计算，2表示从文件 |
| tell()                 | 返回文件指针的当前位置，单位是字节                           |
| truncate([size])       | 删除当前指针位置到文件末尾的内容。如果指定了`size`，则不论指针在什么位置都只留下前`size`字节，其余的删除 |
| write(s)               | 把`s`的内容写入文件                                          |
| writelines(s)          | 把列表中的字符串逐个写入文本文件，不添加换行                 |

## Few Examples

1. 向文本文件中写入内容

```python
s = '文本文件的读取方法\n文本文件的写入方法\n'
with open('sample.txt', 'at+') as f:
    f.write(s)
```

使用上下文管理关键字`with`可以自动管理资源，不论何种原因跳出`with`块，总能保证文件被正确关闭，并且可以在代码块执行完毕后自动还原进入该代码块时的现场。

2. 读取并显示文本文件的前n个字符

```python
with open('sample.txt', 'rt', encoding='utf8') as fp:
    n = 3
    print(fp.read(n))
```

3. 读取并显示文本文件所有行

```python
with open('sample.txt', encoding='utf8') as fp:
    for line in fp:
        print(line)
```

4. 读取文本文件data.txt(每行一个整数)中所有整数，将其升序排序后再写入文本文件data_asc.txt中

```python
with open('data.txt', 'rt') as fp:
    data = fp.readlines()
data = [int(line.strlip()) for line in data]    
data.sort()
data = [str(i)+'\n' for i in data]
with open('data_asc.txt', 'wt') as fp:
    fp.writelines(data)
```

5. 批量修改文本文件编码格式为UTF-8。

```python
from os import listdir
from chardet import datect							# 扩展库，需要先安装

fns = (fn for in listdir() if fn.endswith('.txt'))
for fn in fns:
    with open(fn, 'rb+') as fp:
        content = fp.read()
        #判断编码格式
        encoding = detect(content)['encoding']
        #格式转换
        content = content.decode(encoding).encode('utf-8')
        #写回文件
        fp.seek(0)
        fp.write(content)
```



## 二进制文件操作

序列化：简单地讲就是把Python对象在不丢失其类型信息地情况下转成二进制形式的过程。对象序列化后的字节串经过正确的反序列化过程应该能准确无误地恢复为原来的对象。

Python中常用的序列化模块有`struct`、`pickle`、`json`、`marshal`和`shelve`。

### pickle模块

1. 使用`pickle`模块写入二进制文件

```python
import pickle

i = 130000
a = 99.056
s = '中国人民 123abc'
lst = [[1, 2, 3], [4, 5, 6], [7, 8,  9]]
tu = (-5, 10 ,4)
coll = {4, 5, 6}
dic = {'a':'apple', 'b':'banana', 'g':'grape', 'o':'orange'}
data = [i, a, s, lst, tu, coll, dic]

with open('sample_pickle.dat', 'wb') as f:
    try:
        pickle.dump(len(data), f)		     #表示后面将要写入的数据个数
        for item in data:
            pickle.dumb(item, f)
    except:
        print("写入文件异常！")				#如果写文件异常则跳到此处执行
```

2. 读取写入二进制文件的内容

```python
import pickle

with open('sample_pickle.dat', 'rb') as f:
    n = pickle.load(f)							#读出文件的数据个数
    for i in range(n):
        x = pickle.load(f)
        print(x)
```



### struct模块

1. 使用struct模块写入二进制文件

```python
import struct

n = 130000000
x = 96.45
b = True
s = 'sl@中国'
sn = struct.pack('if?', n, x, b)				#序列化
with open('sample_struct.dat', 'wb') as fp:
    fp.write(sn)								#写入字符串
    fp.write(s.encode())						#字符串直接编码为字节串写入
```

2. 使用struct模块读取写入二进制文件的内容

```python
import struct

with open('sample_struct.dat', 'rb') as fp:
    sn = fp.read(9)				#整数，实数各占4字节，逻辑值占1字节
    tu = struct.unpack('if?', sn)
    n, x, bl = tu 
    print('n=', n, 'x=', x, 'bl=', bl)
    s = fp.read(9).decode()		#UTF-8编码，英文字符占1个字节，汉字占3字节
    print('s=', s)
```





## 文件级操作





   

 
