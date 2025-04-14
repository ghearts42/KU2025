#include <iostream>

int main()
{
    std::cout << "HW" << std::endl;

    // std::cout << "HW";
    operator<<(std::cout, "HW");
    // std::cout.operator<<("HW");

    //std:cout << std::endl;
    // operator<<(std::cout, std::endl);
    std::cout.operator<<(std::endl);

    operator<<(std::cout, "HW").operator<<(std::endl);

    return 0;
}