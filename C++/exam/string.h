#ifndef __MYSTRING__
#define __MYSTRING__

class String
{
private:
    char* m_data;
public:
    String(const char* cstr = 0);                       // 构造函数
    String(const String& str);                          // 拷贝构造函数
    String& operator=(const String& str);               // 重载赋值运算符、拷贝赋值
    ~String();                                          // 析构函数
    char* get_c_str() const { return m_data; }                                               
};

inline
String::String(const char* cstr = 0)
{
    if (cstr) {
        m_data = new char[strlen(cstr)+1];
        strcpy(m_data, cstr);
    }
    else {                                              // 未指定初值
        m_data = new char[1];
        *m_data = '\0';
    }
}

inline
String::~String()
{
    delete[] m_data;
}

inline
String::String(const String& str)
{
    m_data = new char[ strlen(str.m_data)+1 ];
    strcpy(m_data, str.m_data);
}

inline
String::String& operator=(const String& str)
{
    if (this == &str)                                   // 检测自我赋值
        return *this;

    delete[] m_data;
    m_data = new char[ strlen(str.m_data)+1 ];
    strcpy(m_data, str.m_data);
    return *this;
}

#endif
