# Basic C++ Programming





# Procedural Programming







# Generic Programming





## 指针的算术运算



## Iterator泛型指针

每个标准容器都提供一个名为begin()的操作函数，可以返回一个iterator，指向第一个元素。另一个名为end()的操做数 会返回一个iterator，指向最后一个元素的下一位置。 

### 定义

`iterator`定义应该提供：

1. 迭代对象（某个容器）的类型，这可以用来决定任何访问下一个元素；
2. iterator所指的元素类型，这可决定iterator提领操作的返回值。

```c++
vector<string> svec;

// 以下是标准库中的iterator语法。
// iter指向一个vector，后者类型为string。
// iter一开始指向svect的第一个元素。

vector<string>::iterator iter = svect.begin(); 
```



```c++
const vector<string> cs_vec;

vector<string>::const_iterator iter = cs_vec.begin(); 
```

const_iterator允许我们读取vector的元素，但不允许任何写入操作。

## 所有容器的共同操作

- equality (==)和inequality (!=)运算符，返回true或false。
- assignment (=) 运算符，将某个容器复制给另一个容器。
- empty() 会在容器无任何元素时返回true，否则返回false。
- size() 返回容器内目前持有的元素个数。
- clear() 删除所有元素。



## 使用顺序容器

```c++
#include <vector>
#include <list>
#include <deque>
```

### 定义顺序性容器

1. 产生空的容器

```c++
list<string> slist;
vector<int> ivect;
```

2. 产生特定大小的容器。每个元素都已其默认值作为初值

```c++
list<int> ilist(1024);
vector<string> svec(32);
```

3. 产生特定大小的容器，并为每个元素指定初值。

```c++
list<int> ilist(10, -1);
vector<string> svec(16, "unassigned");
```

4. 通过一对iterator产生容器。这对iterator用来标示一整组作为初值的元素的范围。

```c++
int ia[8] = { 1, 1, 2, 3, 5,  8, 13, 21 };
vector<int> fib( ia, ia+8 );
```

5. 根据某个容器产生处新容器。复制原容器内的元素，作为新容器的初值。

```c++
list<string> slist;
// 填充slist
list<string> slist2(slist);
```

有两个特别的操作函数，允许我们在容器末尾进行插入和删除操作：`push_back()`和`pop_back()`。`push_back()`会在末端插入一个元素，`pop_back()`会删除最后一个元素。除此之外，list和deque还提供了`push_front()`和`pop_front()`。`pop_front()`和`pop_back()`这两个操作函数并不会返回被删除的元素值。因此，如果要读取最前端元素的值，应该采用`front()`。如果要读取末端元素的值，应该采用`back()`。

push_front()和push_back()都属于特殊化的插入操作。每个容器除了拥有通用的插入函数insert()，还支持四种变形。

1. iterator insert( iterator position, elemType value)可将value插入position之前。它会返回一个iterator，指向被插入的元素。
2. void insert( iterator position, int count, elemType value )可在position之前插入count个元素，这些元素的值都和value相同。
3. void insert( iterator1 position, iterator2 first, iterator2 last )可在position之前插入[first, last)所标示的各个元素。
4. iterator insert( iterator position )可在position之前插入元素。元素的初值为其所属类型的默认值。

pop_front()和pop_back()都属于特殊化的删除操作。每个容器除了拥有通用的删除函数erase()，还支持两种变形。

1. iterator erase( iterator posit )可删除posit所指的元素。
2. iterator erase( iterator first， iterator last )可删除[first, last)所标示的各个元素。

erase()函数返回指向被删除之最后一个元素的下一位置。

## 使用泛型算法

```c++
#include <algorithm>
```

1. find()用于搜索无序集合中是否存在某值。搜索范围由iterator[first, last)标出。如果找到目标，find()会返回一个iterator指向该值，否则返回一个iterator指向last。
2. binary_search()用于有序集合的搜索。如果找到目标，就返回true；否则返回false。binary_search()比find()更有效率。
3. count()返回数值相符的元素数目。
4. search()比对某个容器内是否存在某个子序列。     

  

## 如何设计一个泛型算法

> How to Design a Generic Algorithm

泛型算法接受三个参数：两个iterator标示出检测范围，第三个参数是我们想要寻找地数值。

### Function Object

**function object：某种class的实例对象，这类class对function call运算符做了重载操作，如此一来可使function object被当成一般函数使用。**

标准库先定义了一组function object，分为算术运算、关系运算和逻辑运算三大类。以下列表中的type在实际运用时会被替换为内置类型或class类型：

- 六个算术运算：plus<type> 	minus<type>	negate<type>	multiplies<type>	divides<type>	modules<type>
- 六个关系运算：less<type> 	less_equal<type> 	greater<type> 	greater_equal<type> 	equal_to<type> 	not_equal<type> 	
- 三个逻辑运算符，分别对应于&&、||、！运算符：logical_and<type> 	logical_or<type> 	logical_not<type> 	

​    欲使用事先定义的function object，首先得包含相关头文件：

```c++
#include <functional>
```

如默认情形下，sort()会使底部元素的类型所提供的less-than运算符，将元素升序排序。如果我们传入greater_than function object，元素就会已降序排序。

```c++
sort( vec.begin(), vec.end(), greater<int>() );
```

其中的`greater<int>()`会产生一个未命名的class template object，传给sort()。

binary_search()期望其搜索对象先经过less-than运算符排序。为了正确搜索vector，必须转给它某个function object object，供vector排序使用：

```c++
binary_search( vec.begin(), vec.end(), elem, greater<int>() );
```



### Function Object Adapter

function object adapter会对function object进行修改操作。所谓binder adapter（绑定适配器）会将function object的参数绑定至某特定值，使binary（二元）function object转化为unary（一元）function object。这正是我们需要的。标准库提供了两个binary adapter：bindlst会将指定值绑定至第一操作数，bind2nd则将指定值绑定至第二操作数。

另一种adapter是所谓的negator，它会对function object的真伪值取反。not1可对unary function object的真伪值取反，not2可对binary function object的真伪值取反。



## 使用Map



## 使用Set



## 如何使用Iterator Inserter



## 使用iostream Iterator







# Object-Based Programming

`class`名称被视为一个类型的名称，如内置类型`int`、`float`、`double`。

`class`有两部分组成：一组公开的`(public)`操作函数和运算符，以及一组私有的`(private)`实现细节。操作函数和运算符统称为`class`的`member function`（成员函数），并代表这个class的公开接口。身为`class`的用户，只能访问其公开接口。

`class`的`private`实现细节可有`member function`的以及于此`class`相关的任何数据组成。

class用户通常不关心此等实现细节。身为一个用户，我们只利用公开接口来进行编程。这种情形下，只要接口没有更改，即使实现细节，重新打造，所有的应用程序代码也不需要变动。

## 如何实现一个`class`

### 1.`class`的声明

```c++
class Stack;
```

此句为`class Stack`的前置声明（**forward declaration**），将`class`告诉编译器，并未提供`class`的的具体细节。前置声明使得我们可以进行类指针（**class pointer**）的定义，或以此`class`作为数据类型。

```c++
Stack *ptr = nullptr;
void process( const Stack&);
```

在定义实际的`class Stack object`或访问`Stack`的任一`member`之前，**必须**先定义`class`本身。

```c++
class Stack {
public:
    // ...public接口
private:
    // ...private的实现部分
};
```

`class`定义由两部分组成：`class`的声明，以及紧接在声明之后的主体。主体部分由一对大括号括住，并以分号结尾。主体内的两个关键字`public`和`private`，用来标示每个块的`member`访问权限。`Public member`可以在程序的任何地方被访问，`private member`只能在`member function`或是`class friend`内被访问。

```c++
//	Stack.h
class Stack {
public:
    // 	...public接口
    // 	任何操作函数如果执行成功返回true
    // 	pop和peek会将字符串内置于elem内
    bool	push( const string& );
    bool	pop( string &elem );
    bool	peek( string &elem );
	void	fill_stack( Stack &stack, istream &is = cin );
        
    bool	empty();
    bool	full();
    
    //	szie()定义于class本身中。
    //	其它member则仅仅只是声明。
    int		size()	{ return _stack.size(); }
    
private:
    // ...private的实现部分
    vector<string> _stack;
};

```

```c++
void	fill_stack( Stack &stack, istream &is = cin )
{
    string str;
    while ( is >> str && ! stack.full() )
        stack.push( str );
    
    cout << "Read in " << stack.size() << " elements\n";
}
```

所有`member function`都必须在`class`主体内进行声明。至于是否要同时进行定义，可自由决定。**如果要在`class`主体内定义，这个`member function`会自动被视为`inline`函数。**在主体之外定义`memeber function`，必须使用特殊的语法，目的在于分辨该函数属于一个`class`。如果希望函数为`inline`，应该在最前面指定关键字`inline`。   

```c++
inline bool
Stack::empty()
{
    return _stack.empty();
}
bool
Stack::pop( string &elem )
{
    if ( empty() )
        return false;
    
    elem = _stack.back();
    _stack.pop_back();
    return true;
}
```

`class`名称之后的两个冒号（`Stack::`）即所谓的`class scope resolution`（类作用域解析）运算符。

对`inline`函数而言，定义于`class`主题内或主题外，并没有区别。然而就像`non-member inline function`一样，它也应该被放在头文件中。`class`定义及其`inline member function`通常会被放在于`class`同名的头文件中。

`non-line member function`应该放在程序代码文件中定义，该文件通常于`class`同名，其后接着扩展名。

```c++
inline bool
Stack::full()
{ return _stack.size() == _stack.max_size(); }
bool
Stack::peek( string &elem )
{
    if ( empty() )
        return false;
    
    elem = _stack.back();
    return true;
}
bool
Stack::push( const string &elem )
{
    if ( full() )
        return false;
    
    _stack.push_back( elem );
    return true;
}
```




















​                            

# Object-Oriented Programming







# Programming with Templates





# Exception Handing



