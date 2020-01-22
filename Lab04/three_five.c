// Written by Bailey Ivancic
// Written on 19/3/17
// Reads a positive integer n and prints all integers < n divisible by 3 or 5

#include <stdio.h>

int main(void)
{

	int num = 0;

    //collects number from user
	printf("Enter number: ");
	scanf("%d", &num);

	int i = 1;

    //goes through all pos int below number and checks modulus of 5 and 3
	while (i < num)
	{
	    //if successful, prints number
		if ((i % 5 ==0) || (i % 3 == 0)) 
		{
			printf("%d", i);
			printf(" \n");
		}

		i = i + 1;
		
	}

	return 0;
}   
