//Written by Bailey Ivancic
//Written on 14/3/17
//Reads a positive integer and then prints the cubes of the integers from 1 to n

#include <stdio.h>

int main(void){

    int num = 0;
    int index = 1;
    int sum = 0;

    //reads number and saves into num
    printf("Enter how many cubes: ");
    scanf("%d", &num);

    while (index <= num)
    {
        sum = (index * index * index);
        printf("%d^3 = %d\n", index, sum);      
        index = index + 1;
    }  
                                                                                                   
    return 0;
}
