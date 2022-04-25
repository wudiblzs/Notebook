# 第一章 预备知识

# 第二章 开始学习C++

## 2.1myfirst.cpp

```c++
//myfirst.cpp	文件扩展名cpp是一种表示C++程序的常用方式
#include <iostream>
int main(void)
{
    using namespace std;
    cout << "Come up and C++ me some time.";
    cout << endl;
    cout << "You won`t regret it!" << endl;
    return 0;
}
```



# 第三章 处理数据



## 3.1简单变量



### 3.1.1变量名

==C++命名规则==：

- 在名称中只能使用字符字母、数字和下划线
- 名称的第一个字符不能是数字
- 区分大写字符和小写字符
- 不能将C++关键字用作名称
- 以两个下划线打头或以下划线和大写字母打头的名称被保留给实现（编译器及其使用资源）使用。以一个下划线开头的名称被保留给实现用作全局标识符。
- C++对于名称的长度没有限制，名称中所有的字符都有意义

### 3.1.2整型

C++基本整型

char

short

int

long

long long

### 3.1.3整型short,int,long and long long

- short 至少16位	-32768~+32767
- int 至少与short一样长
- long 至少32位，且至少与int一样长
- long long 至少64位，且至少与long一样长

1. 运算符sizeof和头文件limits

|    符号常量    |              表示              |
| :------------: | :----------------------------: |
|  **CHAR_BIT**  |         **char的位数**         |
|  **CHAR_MAX**  |        **char的最大值**        |
|  **CHAR_MIN**  |        **char的最小值**        |
| **SCHAR_MAX**  |    **signed char的最大值**     |
| **SCHAR_MIN**  |    **signed char的最小值**     |
| **UCHAR_MAX**  |   **unsigned char的最大值**    |
|  **SHRT_MAX**  |       **short的最大值**        |
|  **SHRT_MIN**  |       **short的最小值**        |
| **USHRT_MAX**  |   **unsigned short的最大值**   |
|  **INT_MAX**   |        **int的最大值**         |
|  **INT_MIN**   |        **int的最小值**         |
|  **UNIT_MAX**  |   **unsigned int 的最大值**    |
|  **LONG_MAX**  |        **long的最大值**        |
|  **LONG_MIN**  |        **long的最小值**        |
| **ULONG_MAX**  |      **unsigned的最大值**      |
| **ULONG_MIN**  |      **unsigned的最小值**      |
| **ULLONG_MAX** | **unsigned long long的最大值** |

2. 初始化
3. C++11初始化方式

### 3.1.4无符号型

### 3.1.5选择整型类型

### 3.1.6整型字面型

### 3.1.7C++如何确定常量的类型

**特殊后缀表示特定的类型**

- 整数默认类型int
- l or L  
- u or U
- UL
- ll or LL

### 3.1.8char类型：字符和小整数





### 3.4.4 类型转换



# 第四章 复合类型

## 4.1数组

**数组**（array）是一种数据格式，能够存储多个同类型的值。

> 数组声明应该指出以下三点：
>
> - 存储在每个元素中的值；
> - 数组名；
> - 数组中的元素数

声明数组的通用格式：

**typeName arrayName[arraySize];**



**有效下标值的重要性**

> 编译器不会检查使用的下标是否有效。
>
> 如果发生下标越界，可能破坏数据或代码，也可能导致程序异常终止。



**数组的初始化规则**

> 1. 只有在定义数组时才能使用初始化，此后就不能使用，也不能将一个数组赋值给另一个数组，只能使用下标分别给数组中的元素赋值。
> 2. 如果只对数组中的一部分初始化，则编译器将其它元素设置为0。
> 3. 如果初始化数组时方括号内为空，C++编译器将计算元素个数。



**C++11数组初始化方法**

> 1. 初始化数组时，可以忽略等号
> 2. 可不在大括号内包含任意东西，这将把所有元素都设置为零。
> 3. 列表初始化禁止缩窄转换。





## 4.2字符串

