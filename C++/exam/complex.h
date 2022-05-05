// 防御式声明
#ifndef __COMPLEX__
#define __COMPLEX__
// 前置声明forward declarations
#include <cmath>
#include <iostream>

class complex;
using std::ostream;
complex&
__doapl (complex* ths, const complex& r);

complex 
operator + (const complex& x, const complex& y);


// 类-声明class declarations
class complex   // class head
{               
private:        // class body
    double re, im; 
    friend complex& __doapl (complex*, const complex&);

public:
    complex (double r = 0, double i = 0)
        : re (r), im (i)                    // 初值列，初始列
    { }
    complex& operator += (const complex&);
    double  real () const   { return re; }
    void    real (double r) { re = r; }
    double  imag () const   { return im; }
    void    imag (double i) { im = i; }
    ~complex()  {}
};

// 类-定义class declarations
inline double
imag(const complex& x)
{
    return x.imag();
}

inline double
real(const complex& x)
{
    return x.real();
}

inline complex&
__doapl(complex* ths, const complex& r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline complex&
complex::operator += (const complex& r)
{
    return __doapl (this, r);
}

inline complex
operator + (const complex& x, const complex& y)
{
    return complex ( real (x) + real (y),
                     imag (x) + imag (y) );
}

inline complex
operator + (const complex& x, double y)
{
    return complex ( real (x) + y, imag (x) );
}

inline complex
operator + (double x, const complex& y)
{
    return complex ( x + real (y), imag (y) );
}

inline ostream&
operator << (ostream& os, const complex& x)
{
    return os << '(' << real(x) << ','
              << imag(x) << ')';
}
#endif