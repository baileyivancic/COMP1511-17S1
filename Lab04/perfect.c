//Written by Bailey Ivancic on 19/3/17
//Reads a positive integer and prints all factors, their sum and whether or not the number is a perfect number

#include <stdio.h>

int main(void)
{

	int num = 0;
	int sum = 0;

	printf("Enter number: ");
	scanf("%d", &num);

	int i = 1;

	printf("The factors of %d are:\n", num);

    //checks the number is greater than 0
    if (num < 1)
    {
        printf("Please enter a positive number");
    } 
    
    else
    {

    //establishes a loop that checks each number between i and num
	while (i <= num)
	{
	    //checks to see if i is a factor of num
		if (num % i == 0)
		{
			printf("%d\n", i);
			sum = sum + i;
		}
		i = i + 1;
	}

	printf("Sum of factors = %d\n", sum);

    //successful condition (perfect)
	if (((sum - num) == num) && ((sum/2) == num))
	{
		printf ("%d is a perfect number\n", num);
	}
	
	//unsuccessful condition (not perfect)
	else 
	{
		printf("%d is not a perfect number\n", num);
	}
	
	}
	
	return 0;
}
