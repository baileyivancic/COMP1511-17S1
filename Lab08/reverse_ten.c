//Written by Bailey Ivancic
//Reads ten integers from standard input, and prints them on one line on reverse order

#include <stdio.h>

int main(int argc, char* argv[])
{
    int array[10] = {0};
    int i = 0;
    
    while (i < 10)
    {
        scanf("%d", &array[i]);
        i++;
    }

    printf("Numbers were: ");
    i = 9;
    while (i >= 0)
    {
        printf("%d ", array[i]);
        i--;
    }
    
    printf("\n");
    
}
