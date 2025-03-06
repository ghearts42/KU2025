#include <stdio.h>

int main() {
    int a;
    printf("A : ");
    scanf("%d", &a);
    switch(a)
    {
        case 1:
            printf("A\n");
            break;
        case 2:
            printf("B\n");
            break;
        case 3:
            printf("C\n");
            break;
        default:
            printf("D\n");
        
    }
    
    return 0;
    }