#include <stdio.h>

int main(void)
{
    FILE *fp;

    fp = fopen("output.txt", "a");

    if (fp == NULL)
    {
        printf("파일 없음");
        return 1;
    }
    putc('A', fp);
    putc('A', stdout);
    fputc('B', fp);
    fputc('B', stdout);
    // puts deprecicate 지원 종료
    fputs("puts로 문자가 간다.", fp);
    fputs("puts로 문자가 간다.", stdout);

    fprintf(fp, "fprintf로 문자가 간다.");
    fprintf(stdout, "fprintf로 문자가 간다.");
    fflush(fp);
    fflush(stdout);

    // EOF == -1;

    fclose(fp);
    return 0;
}