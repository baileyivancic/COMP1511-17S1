//Written by Bailey Ivancic
//Written on 14/3/17

#include <stdio.h>

int main(void){

    int year = 0;
    int leapYear = 0;

    //reads inputted number
    printf("Enter year: ");
    scanf("%d", &year);
    
    
    //determines whether year is a leap year
    if (((year % 4 == 0) && (year % 100 != 0))
            ||((year % 100 == 0) && (year % 400 == 0)))
    {
        leapYear = 1;
    } 
    
    //Prints whether year is a leap year or not
    if (leapYear == 1){
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }


    return 0;
}
