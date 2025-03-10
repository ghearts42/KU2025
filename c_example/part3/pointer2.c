#include <stdio.h>

int main(void)
{
    int Var_a;
    int *pVar_a;
    int **ppVar_a;

    Var_a = 100;
    pVar_a = &Var_a;
    ppVar_a = &pVar_a;

    **ppVar_a = 200;

    printf("Var_a: %d, &Var_a: %p\n", Var_a, &Var_a);
    printf("pVar_a: %p, *pVar_a: %d\n", pVar_a, *pVar_a);
    printf("ppVar_a: %p, *ppVar_a: %p, **ppVar_a: %d\n", ppVar_a, *ppVar_a, **ppVar_a);

    return 0;
}