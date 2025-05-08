// gcc -fPIC -shared -o libpluguin.so plugin.c
// file, objdump, strings

#include <stdio.h>

void hello()
{
    printf("Plugin\n");
}