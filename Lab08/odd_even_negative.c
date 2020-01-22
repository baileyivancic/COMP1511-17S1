//Written by Bailey Ivancic

#define MAX_LINE 1000
#include <stdio.h>

int main(void)
{
    int array[MAX_LINE] = {0};
    int i = 0;
    while (i < MAX_LINE)
    {
        scanf("%d", &array[i]);
        if (array[i] < 0)
        {
            break;
        }
        i++;
    }

    i = 0;
    printf("Odd numbers were: ");
    while (array[i] > 0)
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
    while (array[i] > 0)
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
