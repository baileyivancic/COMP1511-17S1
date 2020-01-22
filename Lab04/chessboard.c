//Written by Bailey Ivancic on 23/3/17
//Prints asterisks in the shape of c checcboard of dimensions nxn

#include <stdio.h>

int main(void)
{

  int size = 0;
  
  printf("Enter size: ");
  scanf("%d", &size);
  
  int vertical = 0;
  int horizontal = 0;
  int star = 0;
  
  while (vertical < size) //loops through the vertical rows
  { 
    
    while (horizontal < size)
    {
        if (star == 0) //if star set to no, print line
        {
            printf("-");
            star = 1; //sets star to yes for next time
        }
    
        else if (star == 1) //if star is set to yes, print star
        {
            printf("*");
            star = 0; //sets star to no for next time
        }
        
        horizontal++;
    
    }
    
    printf(" \n");
    horizontal = 0;
    vertical = vertical + 1; //advances the vertical loop
  }
  




    return 0;
}
