//Written by Bailey Ivancic on 20/3/17
//reads an integer and then prints a nxn pattern of asterisks and dashes

#include <stdio.h>

int main(void)
{

    int size = 0;

    //reads in number
    printf("Enter size: ");
    scanf("%d", &size);

    //initialises variables
    int i = 0;
    int position = 0;
    int first = 0;
    int last = (size -1);
    
    //vertical height
    while (i < size)
    {
       while (position < size) //horizontal length
       {
            // checks if star needs to be printed
            if ((position == first) || (position == last))
            {
                printf("*");
            }
            
            //otherwise prints a dash
            else 
            {
                printf("-");
            }
   
            position = position + 1;
       
       }
       
       //advances the position of the star pointer
       printf(" \n");
       position = 0;
       first = first + 1;
       last = last -1;
       i = i+1;
    }

    return 0;
}
