#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("인자를 넣어라.\n");
        return 0;
    }
    printf("SCORE : %s --- %s/n", argv[1], atoi(argv[1]) >= 60 ? "합격" : "불합격");
    return 0;
}