#include <stdio.h>
#define LEN_INPUT 11

int main(void) {
    char s1[LEN_INPUT];
    int a;
    scanf("%s %d", s1, &a);

    while(a <= 5 && a >=1){
        printf("%s", s1);
        a -= 1;
    }

    return 0;
}