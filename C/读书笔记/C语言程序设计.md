# 结构体和数据结构基础


## 结构体的定义

C语言的构造数据类型：
- 数组
- 结构体
- 共用体

**数组**是由相同的数据构成的一种数据结构，适合于对有相同属性的数据进行批处理；

**结构体**是将不同类型的数据成员组织到统一的名字下适合于对关系紧密、逻辑相关、具有相同或不同属性的数据进行处理；

**共用体**也能表示逻辑相关的不同类型的数据集合，但其数据成员是情形互斥的，每一时刻只有一个数据成员起作用。


定义结构体首先得声明一个**结构体模板（Structure Template）**

```c
struct 结构体名
{
    数据类型 成员1的名字;
    数据类型 成员2的名字;
    数据类型 成员3的名字;
    ......
    数据类型 成员n的名字;
};
```

结构体模板是由关键字`struct`及其后的结构体名组成的。分号是结构体声明的结束标志，不能省略。

结构体的名字，称为**结构体标签（Structure Tag）**，作为用户自定义的结构体类型的标志，用于与其它结构体类型相区别。

结构体中的各信息项是在结构体标签后的花括号内声明的；构成结构体的变量，称为**结构体成员（Structure Member）**。结构体成员的命名必须遵循变量的命名规则。




>   注意，结构体模板只是声明了一种数据类型，定义了数据的组织形式，并未声明结构体类型的变量，因而编译器不为其分配内存。

其次，利用已经定义好的结构体数据类型来定义结构体变量。C语言允许按如下两种方式定义结构体变量。

-   先声明结构体模板，再定义结构体变量。

    ```c
    struct student
    {
    	...
    };
    ...
    struct student stu1;
    ```

-   在声明结构体模板的同时定义结构体变量。

    ```c
    struct student
    {
    	...
    }stu1, stu2;
    ```

    当将结构体模板和结构体变量放在一起时，结构体标记是可选的。

## 关键字typedef

关键字`typedef`用于为系统固有的或程序员自定义的数据类型定义一个别名。 数据类型的别名通常使用大写字母，目的是为了与已有的数据类型相区分。

```c
typedef int INTEGER;
typedef struct student STUDENT;
typedef struct student
{
  	long studentID;
    char studentName[10];
    char studentSex;
    int yearOfBirth;
    int score[4];
}STUDENT;
```

>   注意，typedef只是为一种已存在的类型定义一个新的名字而已，并未定义一种新的数据类型。



## 结构体变量的初始化

结构体变量的成员可以通过将成员的初值置于花括号之内来进行初始化。

```c
STUDENT stu1 = { 202121100, "老六", 'm', 2000, { 80, 80, 80, 80 } };
//等价于 struct student stu1 = { 202121100, "老六", 'm', 2000, { 80, 80, 80, 80 } };
```

## 嵌套的结构体

**嵌套的结构体（Nested Structure）**就是在一个结构体内包含了另一个结构体作为其成员。

```c
typedef struct date
{
    int year;
    int month;
    int day;
}DATE;

typedef struct student
{
  	long studentID;
    char studentName[10];
    char studentSex;
   	DATE birthday;
    int score[4];
}STUDENT;

STUDENT stu1 = { 202121100, "老六", 'm', { 2000, 1, 1 }, { 80, 80, 80, 80 } };
```

## 结构体变量的引用
