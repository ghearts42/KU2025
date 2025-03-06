#include <stdio.h>
// 2부터 100까지 소수가 몇개 있는지 세기
int main(void){
    int sosu = 100;
    int answer = 0;
    int count = 0;
    
    for (int i = 2; i <= sosu; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (i % j == 0)
            {
                count += 1;
            }
        }
        if (count == 2)
        {
            answer += 1;
        }
        count = 0;
    }

    printf("%d 까지 세어보면 소수 숫자의 개수는 : %d 개 입니다.\n" , sosu , answer);
    return 0;
}