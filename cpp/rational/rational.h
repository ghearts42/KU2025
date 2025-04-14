#ifndef Rational_H
#define Rational_H

class Rational
{
private: //내부 구현(implemetation)
    int num;  //real
    int den;  //imaginary

public: //인터페이스
    Rational(int num, int den);  //construct
    Rational(int num);
    Rational();
    ~Rational();

    int getNumerator();
    int getDenominator();

    void SetNumerator(int num);
    void SetDenominator(int den);
};

#endif