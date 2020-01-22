//Written by Bailey Ivancic
//tests if a string is a palindrome

#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE 4096

int main(int argc, char* argv[])
{
    char array[MAX_LINE];
    fgets(array, MAX_LINE, stdin);
    
    int i = 0;
    int count = 0; //counts the elements of array
    while (array[i] != '\n')
    {
        count++;
        i++;
    }      
    
    printf("Enter a string: ");
    
    i = 0;
    int tempCount = (count/2) + 1;
    int flag = 1; //1 for palindrome, 0 for not
    count = count - 1;
    while (i < tempCount)
    {
       if (array[i] != array[(count-i)])
       {
            flag = 0;
       } 
       i++; 
    }

    if (flag == 1)
    {
        printf("String is a palindrome\n");
    }
    
    else if (flag == 0)
    {
        printf("String is not a palindrome\n"); 
    }
    return 0;
}
