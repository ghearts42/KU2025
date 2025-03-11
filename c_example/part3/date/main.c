#include "date.h"

int main(void)
{
    Date d;

    d.year = 2025;
    d.month = 3;
    d.day = 11;
    Date c = {2024, 2, 10};
    Date b = {
        .year = 2023,
        .month = 1,
        .day = 9,
        .temp = {1, 2, 3, 4, 5, 6}};
    Date today;
    today = b;
    printDate(&today);
    today.temp[0] = 10;
    printDate(&today);
    printDate(&d);
    printDate(&c);
    printDate(&b);

    return 0;
}