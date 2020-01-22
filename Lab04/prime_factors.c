//Written by Bailey Ivancic on 26/3/17
//Prints out prime factors of a number, unless the number is prime

#include <stdio.h>

int main (void)
{

    //get number in
    int num = 0;
    printf("Enter number: ");
    scanf("%d", &num);
    
//step 1
//test if the number is prime
    int i = 2; //counting variable
    int prime = 2; //prime boolean, 0 for true and 1 for false
    int factorLimit = num; //variable used to show range of factors
    
    while ((i < factorLimit))
    {
        prime = 1;
        if (num % i == 0)
        {
            prime = 0;
            break;
        }
        
        i++;
    }
    
    if (prime == 1)
    {
        printf("%d is prime\n", num);
    }
    
    
//step 2
//finds 2 factors of a number
    int factorOne = 0;
    int factorTwo = 0;
    int factorCounter = 2;
    int factorCheck = 0; //variable to say if factors have been found
    int factorTwo_prime = 2;  //flag to check if factor is prime (1 prime)
    
    if (prime == 0) //checks to see if number is not prime
    {
        //finds two factors of the number
        while ((factorCounter < factorLimit) && (factorCheck == 0))
        {
            if (num % factorCounter == 0)
            {
                factorOne = factorCounter;
                factorTwo = (num/factorOne);
                factorCheck = 1; //found the factors of the number
            }
        
            factorCounter = factorCounter + 1;
        }
     
        printf("The prime factorization of %d is:\n%d ", num, factorOne);   
    }
//step 3
//splits second factor of number into primes

    int print = 0;
    //check to see if second factor is prime
    i = 2; //re-initialise counting variable
     while ((i < factorTwo))
    {
        factorTwo_prime = 1;
        
        if (factorTwo % i == 0)
        {
            factorTwo_prime = 0;
            break;
        }
        
        i++;
    }
    
    if (factorTwo_prime == 1)
    {
        printf("* %d ", factorTwo);
        print = 1;
    }  
        

    i = 2; //reinitialise counting variable
    
    //splits factor 2
    while ((i < factorTwo ))
        {
            factorTwo_prime = 1;
            if (factorTwo % i == 0)
            {
                printf("* %d ", i);
                factorTwo = (factorTwo/i);
                i = 1;
                factorTwo_prime = 0;
            }
            i = i + 1;
        }
         

     if ((factorTwo_prime == 1) && (print == 0))
     {
        printf("* %d ", factorTwo);
     }


    //prints final bit of message if number is not prime
    if (prime == 0)
    {
        printf("= %d\n", num);
    }
    
    return 0;
}
