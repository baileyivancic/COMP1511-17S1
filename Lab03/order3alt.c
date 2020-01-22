//Written by Bailey Ivancic
//Written on 13/3/17

#include <stdio.h>


int main(void){

    //initialise variables
    int numOne = 0;
    int numTwo = 0;
    int numThree = 0;
    int small = 0;
    int medium = 0;
    int large = 0;
    int temp = 0;
    
    printf("Enter integer: ");
    scanf("%d", &numOne);
    small = numOne;
        
    printf("Enter integer: ");
    scanf("%d", &numTwo);
    medium = numTwo;
       
    printf("Enter integer: ");
    scanf("%d", &numThree);
    large = numThree;
       
    
    //checks if the the smallest value is smaller than the medium value
    if (small > medium){
        temp = medium;
        medium = small;
        small = temp;
     }
        
    //checks if the medium number is less than large
    if (medium > large){
        temp = large;
        large = medium;
        medium = temp;
    }

    //checks if the medium is greater than small
    if (small > medium){
        temp = small;
        small = medium;
        medium = temp;
    }


    //if (small <= medium && medium <= large){
       // printf("it fuckin worked");
   // }
        
    printf("The integers in order are: %d %d %d\n", small, medium, large);


    return 0;
}
