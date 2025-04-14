#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
private: //내부 구현(implemetation)
    double re;  //real
    double im;  //imaginary

public: //인터페이스
    Complex(double re, double im);  //construct
    Complex(double re);
    Complex();
    ~Complex();

    double real();
    double imag();

    void real(double re);
    void imag(double im);
};

#endif