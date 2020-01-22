//Written by Bailey Ivancic, 9/4/17
//prints the occurance frequency of an entered argument

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isupper(int c);
int islower(int c); //zero false, non-zero true

int main(int argc, char *argv[])
{

    int countArray[26] = {0};
    char c = getchar();
    int temp = 0;
    double sum = 0;
    
    //Reads through the wntered input until user specifies to stop
    //adds to corresponding array element when letter is found
    while (c != EOF)
    {
        //printf("%c\n", c);
        if (islower(c)) //lower case
        {
            temp = c - 'a';
            countArray[temp]++;
            sum++;
        }
        
         if (isupper(c)) //upper case
        {
            temp = c - 'A';
            countArray[temp]++;
            sum++;
        }
    
        c = getchar();
        temp = 0;
    }


    int i = 0;
    while (i < 26)
    {
        char letter = 'a' + i;
        double decimal = 0.0;
        decimal = (countArray[i]/sum);
        printf("'%c' %lf %d\n", letter, decimal, countArray[i]);
        i++;
    }
    

    return 0;
}
