#include <iostream>
#include "complex.h"

int main()
{
    Complex c1(3.0, 4.0);
    Complex c2(3.0);
    Complex c3;

    c3.real(3.0);
    c3.imag(4.0);

    std::cout << "c1 : (" << c1.real() << ", " << c1.imag() << "i)" << std::endl;
    std::cout << "c2 : (" << c2.real() << ", " << c2.imag() << "i)" << std::endl;
    std::cout << "c3 : (" << c3.real() << ", " << c3.imag() << "i)" << std::endl;
    return 0;
}