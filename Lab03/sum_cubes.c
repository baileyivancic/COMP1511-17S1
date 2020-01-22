//Written by Bailey Ivancic
//Written on 14/3/17
//Reads an integer and then prints the sum of its cubes

#include <stdio.h>

int main(void){


    int num = 0;
    int sum = 0;
    int index = 1;

    //reads number and saves to num
    printf("Sum how many cubes? ");
    scanf("%d", &num);
    
    //loops to calculate the sum and print a statement on each loop
    while (index < num)
    {
        sum = sum + (index*index*index);
        printf("%d^3 + ", index);
        index = (index + 1);
    }
    
    //prints the concluding statement of the loop and calculates final sum
    if (num != 0)
    {
        sum = (sum + (num * num * num));
        printf("%d^3 = %d\n", num, sum);
    
    }

    return 0;
}
