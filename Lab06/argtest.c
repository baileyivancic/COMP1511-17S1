#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("%d\n", argc);
    int i = 0;
    while (i < argc)
    {
    printf("arg[%d] = %s\n", i, argv[i]);
    i++;
    }


    return 0;
}
