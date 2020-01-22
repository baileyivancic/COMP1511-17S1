//Written by Bailey Ivancic
//Written on 10th March 2017

#include <stdio.h>

int main(void){

	//User inputs age, gets scanned
	int age = 0;
	printf("Enter your age: ");
	scanf("%d", &age);
	
	//declaring variables as well as calculating ranges and bounds
	int tooYoung = ((age/2)+7);
	int diffOne = (age - tooYoung);
	int diffTwo = (diffOne * 2);
	int tooOld = (age + diffTwo);
	
	//empty range for young ages, checks for young ages
	if (age > 16){
	    printf("Your dating range is %d to %d years old.\n", tooYoung, tooOld);
	    return 0;
	
	} else{
	    printf("You are too young to be dating.\n");
	    return 1;
	}
	
	

	return 0;
}
