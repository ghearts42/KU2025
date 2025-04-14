#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public: //인터페이스
    Complex();
    Complex(double re);
    Complex(double re, double im);  //construct
    ~Complex();
    
    // void operator=(const Complex *pc);
    void operator=(const Complex& rc);

    // int operator==(const Complex& rc);
    bool operator==(const Complex& rc);

    double real();
    double imag();
    
    void real(double re);
    void imag(double im);

private: //내부 구현(implemetation)
        double re;  //real
        double im;  //imaginary
};

#endif