//Written by Bailey Ivancic
//tests if a string is a palindrome

//Not working

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
    
    char array2[count];
    i = 0;
    int count2 = 0;
    while (i < count)
    {
        if (isalnum(array[i]))
        {
            array2[i] = tolower(array[i]);
            count2++;
        } 
        i++;
    }
    
    i = 0;
    int tempCount = (count2/2) + 1;
    int flag = 1; //1 for palindrome, 0 for not
    count = count2 - 1;
    while (i < tempCount)
    {
           if (array2[i] != array2[(count-i)])
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
