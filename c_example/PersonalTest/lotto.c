#include <stdio.h>

void input_nums(int *lotto_nums);
void output_nums(int *lotto_nums);

int main(void)
{
    int lotto_nums[6];

    input_nums(lotto_nums);
    output_nums(lotto_nums);
    return 0;
}

void input_nums(int *lotto_nums)
{
    for (int i = 0; i < 6; ++i)
    {
        scanf("%d", &lotto_nums[i]);
        // scanf("%d", lotto_nums + i);
        if (i > 0)
        {
            for (int j = 0; j < i; ++j)
            {
                if (lotto_nums[i] == lotto_nums[j])
                {
                    printf("같다");
                    i -= 1;
                    j -= 1;
                    continue;
                }
            }
        }
    }
}
void output_nums(int *lotto_nums)
{
    for (int i = 0; i < 6; ++i)
    {
        printf("%d", lotto_nums[i]);
    }
}