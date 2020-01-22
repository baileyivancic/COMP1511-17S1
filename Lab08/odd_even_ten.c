//Written by Bailey Ivancic
//Prints odd numbers on one line, prints even numbers on other

#include <stdio.h>

int main(void)
{   
    int array[10] = {0};
    int i = 0;
    
    while (i < 10)
    {
        scanf("%d", &array[i]);
        i++;
    }

    printf("Odd numbers were: ");
    i = 0;
    while (i < 10)
    {
        if (array[i] % 2 != 0)
        {
            printf("%d ", array[i]);
        }
        i++;
    }
    
    printf("\n");
    i = 0;
    printf("Even numbers were: ");
    while (i < 10)
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
