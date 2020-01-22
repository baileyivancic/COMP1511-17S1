//Written by Bailey Ivancic
//Written 17/3/17
//Orders three integers without using if statements or while loops

#include <stdio.h>

int main(void){

    int numOne = 0;
    int numTwo = 0;
    int numThree = 0;
    
    //Input numbers
    printf("Enter integer: ");
    scanf("%d", &numOne);
    
    printf("Enter integer: ");
    scanf("%d", &numTwo);
    
    printf("Enter integer: ");
    scanf("%d", &numThree);

    printf("%d\n", (numOne <= numTwo) && (numOne <= numThree));


    return 0;
}
