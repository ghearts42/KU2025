// gcc -o main dlMain.c -ldl
// nm -D libplugin.so

#include <dlfcn.h> //정적링크 필요 -ldl
#include <stdio.h>

int main()
{
    void *handle;
    void (*hello_func)();
    printf("main start");
    getchar();
    handle = dlopen("./libplugin.so", RTLD_LAZY);
    hello_func = dlsym(handle, "hello");
    hello_func(); // plugin start
    dlclose(handle);
}