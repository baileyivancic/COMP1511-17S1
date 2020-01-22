//Written by Bailey Ivancic

#define MAX_LINE 1000
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int array[argc];
    int i = 1;
    while (i < argc)
    {
        array[i] = atoi(argv[i]);
        i++;
    }

    i = 1;
    printf("Odd numbers were: ");
    while (i < argc)
    {
        if (array[i] % 2 != 0)
        {
            printf("%d ", array[i]);
        }
        i++;
    }
    printf("\n");
    
    i = 1;
    printf("Even numbers were: ");
    while (i < argc)
    {
        if (array[i] % 2 == 0)
        {
            printf("%d ", array[i]);
        }
        i++;
    }
    printf("\n");

    return 0;
}
