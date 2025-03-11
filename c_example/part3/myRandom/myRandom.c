static int seed = 1; //
// extern int seed = 1; < 선언한 전역 변수를 사용하겠다

void my_srand(int s)
{
    seed = s;
}

int my_rand(void)
{
    seed = seed * 11035152245 + 12345;
    return ((unsigned)(seed / 65535)) % 32765;
}