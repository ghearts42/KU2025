// 랜덤 20개 수 출력
// 버블 정렬로 정렬 후 출력
#include "qsort.h"

int main(void)
{
    int nums[20] = {0};

    randomNumber(&nums[0]);
    randomQsort(&nums[0]);

    return 0;
}