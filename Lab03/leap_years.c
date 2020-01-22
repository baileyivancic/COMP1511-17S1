//Written by Bailey Ivancic
//Written on 14/3/17
//Inputs two years and displays the leap years within that range
//Pieces of code taken from is_leap_year.c

#include <stdio.h>


int main(void){

    int startYear = 0;
    int finishYear = 0;

    printf("Enter start year: ");
    scanf("%d", &startYear);
    
    printf("Enter finish year: ");
    scanf("%d", &finishYear);
    
    printf("The leap years between %d and %d are:", startYear, finishYear);
    
    int index = startYear;
    
    //goes through a loop to determine if each year within the range is a leap year
    while (index <= finishYear)
    {
        // if leap year, prints the year before doing another pass
        if (((index % 4 == 0) && (index % 100 != 0))||((index % 100 == 0) && (index % 400 == 0)))
         {
            printf(" %d", index); 
         
         }
        index = (index + 1);
        
    }
   
    printf(" \n");
   
    return 0;

}
