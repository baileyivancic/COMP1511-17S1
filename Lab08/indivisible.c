//Written by Bailey Ivancic

#define MAX_LINE 1000
#include <stdio.h>

int main(void)
{
    int array[MAX_LINE] = {0};
    int arrayTwo[MAX_LINE] = {0};
    int i = 0;
    int count = 0;
    while (i < MAX_LINE)
    {
        if (scanf("%d", &array[i]) < 1 )
        {
            break;
        }
        i++;
        count++;
    }

    i = 0;
    while (i < count)
    {
        arrayTwo[i] = array[i];
        i++;
    }

    i = 0; //array1 count
    int j = 0; //array2 count
    while (i < count)
    {
        while (j < count)
        {
                if (j != i)
                {
                    if (array[i] % arrayTwo[j] == 0)
                    {
                        array[i] = 0;
                    }
                }
            j++; 
        }
        i++;
        j = 0;
        
    }
    
    i = 0;
    printf("Indivisible numbers: ");
    while (i < count)
    {
      if (array[i] > 0)
      {
        printf("%d ", array[i]);
      }
      i++;
    }
    printf("\n");
    return 0;
}
