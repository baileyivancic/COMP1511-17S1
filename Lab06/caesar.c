//Written by Bailey Ivancic, 9/4/17
//encrypts characters using a caesar cipher

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isupper (int c);
int islower(int c);

char cipher(int original, int shift, int size);

int main(int argc, char *argv[])
{

	//gets inputted shift
	int shift = (atoi(argv[1]));
	char c = getchar();
	int temp = 0;
	while (c != EOF)
	{
		//uppercase
        if (isupper(c))
        {
            temp = cipher(c, shift, 0);
            temp = temp + 'A';
            putchar(temp);
        }
        
        //lowercase
        else if (islower(c))
        {
            temp = cipher(c, shift, 1);
            temp = temp + 'a';
            putchar(temp);
        }
    
        //other character
        else
        {
            putchar(c);
        }

        c = getchar();
	}
    return 0;
}

//finds the ciphered letter
char cipher(int original, int shift, int size)
{
    int newNum = 0;
    if (size == 0)
    {
        if (shift < 0)
        {
            shift = 26 + (shift % 26);
        }
            newNum = original - 'A' + shift;
            newNum = newNum % 26;
    }

     if (size == 1)
    {
        if (shift < 0)
        {
            shift = 26 + (shift % 26);
        }
            newNum = original - 'a' + shift;
            newNum = newNum % 26;
    }
	
	return newNum;
}
