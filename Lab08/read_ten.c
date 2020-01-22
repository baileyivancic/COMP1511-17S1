//Written by Bailey Ivancic
//Reads ten integers from standard input, stores them in an array, prints them one line

#include <stdio.h>
int main(void)
{   
    int numArray[10] = {0};
    
    int i = 0;
    
    while (i < 10)
    {
        scanf("%d", &numArray[i]);
        i++;   
    }
    
    printf("Numbers were: ");
    i = 0;
    while (i < 10)
    {
        printf("%d ", numArray[i]);
        i++;
    }
    printf("\n");
    return 0;
}
