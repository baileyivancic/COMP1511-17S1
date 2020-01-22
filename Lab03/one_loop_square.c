//Written by Bailey Ivancic
//Written on 15/3/17
//reads an integer and then prints a square of asterisks that size

#include <stdio.h>

int main(void){
    
    int height = 0;
    int index = 0;
    
    printf("Square size: ");
    scanf("%d", &height);
    
    while (index < (height*height))
    {
        if (index % height == 0 && index > 0)
        {
            printf(" \n");
            
        }
        printf("*");
        index = index + 1;
    
    }
    printf(" \n");
    
    return 0;
}
