//Written by Bailey Ivancic on 23/3/17
//prints an nxn pattern of asterisks in the shape of a plus

#include <stdio.h>

int main(void)
{
    
    //Inputs size & saves to size
    int size = 0;
    
    printf("Enter size: ");
    scanf("%d", &size);
    
    int position = size/2;
    int vertical = 0;
    int horizontal = 0;
    
    while (vertical < size) //loops through to print correct height
    {
    
        if (vertical == position)
        {
            while (horizontal < size)
            {
                printf("*");
                horizontal = horizontal + 1;
            }    
            
            horizontal = 0; //allows another pass of horizontal
            
        }    
        
        else 
        {
        
            while (horizontal < size) //loops through to print current width
            {
                if (horizontal == position) //if middle of 
                {
                 printf("*");
                }
                
                else 
                {
                    printf("-");
                }
            
                horizontal = horizontal + 1; //increments the horizontal counter
                
            }
        } 
        
        vertical = vertical + 1; //incrememnts vertical counter
        horizontal = 0; //allows another pass of horizontal
        printf(" \n");
        
    }
    return 0;
}
