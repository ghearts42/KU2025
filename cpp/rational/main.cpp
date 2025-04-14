#include <iostream>
#include "rational.h"

int main()
{
    Rational c1(3, 4);
    Rational c2(3);
    Rational c3;

    c3.SetNumerator(c1.getNumerator());
    c3.SetDenominator(c1.getDenominator());

    std::cout << "c1 : (" << c1.getNumerator() << ", " << c1.getDenominator() << "i)" << std::endl;
    std::cout << "c2 : (" << c2.getNumerator() << ", " << c2.getDenominator() << "i)" << std::endl;
    std::cout << "c3 : (" << c3.getNumerator() << ", " << c3.getDenominator() << "i)" << std::endl;
    return 0;
}