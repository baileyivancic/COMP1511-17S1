//Written by Bailey Ivancic

#define MAX_LINE 1000
#include <stdio.h>

int main(void)
{
    int array[MAX_LINE] = {0};
    int i = 0;
    int count = 0;
    while (i < MAX_LINE)
    {
        if (scanf("%d", &array[i]) < 0 )
        {
            break;
        }
        i++;
        count++;
    }

    i = 0;
    printf("Odd numbers were: ");
    while (i < count)
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
    while (i < count)
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
