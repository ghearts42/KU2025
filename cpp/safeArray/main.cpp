#include <iostream>
#include "safeArray.h"

int main()
{
    safeArray arr1;
    safeArray arr2(10);
    int nums[] = {1,2,3,4,5};
    safeArray arr3(nums, 5);
    safeArray arr4 = arr3;

    arr1 = arr3;

    arr1 == arr3;

    for (int i = 0; i < arr1.size(); ++i)
    {
        std::cout << arr1[i] << std::endl;
    }
    
    arr1[5] = 6;

    return 0;
}