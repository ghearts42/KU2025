#include <cassert>
#include "rational.h"

Rational::Rational(int num, int den)
{
    assert(den != 0);

    this->num=num;
    this->den=den;
}

Rational::Rational(int num)
{
    this->num = num;
    this->den = 1;
}

Rational::Rational()
{
    this->num = 0.0;
    this->den = 1;
}

Rational::~Rational()
{

}

int Rational::getNumerator()
{
    return this->num;
}

int Rational::getDenominator()
{
    return this->den;
}

void Rational::SetDenominator(int den)
{
    this->den = den;
}

void Rational::SetNumerator(int num)
{
    this->num = num;
}