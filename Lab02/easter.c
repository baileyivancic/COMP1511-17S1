// Written by Bailey Ivancic
// Written on the 10th March, 2017

#include <stdio.h>

int main(void){

	int year = 0;
	printf("Enter Year:");
	scanf("%d", &year);


	int a = (year%19);
	int b=(year/100);
	int c=(year%100);
	int d=(b/4);
	int e=(b%4);
	int f=((b+8)/25);
	int g=((b-f+1)/3);
	int h=((19*a+b-d-g+15)%30);
	int i=(c/4);
	int k=(c%4);
	int l=((32+2*e+2*i-h-k)%7);
	int m=((a+11*h+22*l)/451);
	int easterMonthInt =((h+l-7*m+114)/31); //3 = march, 4 = april
	int p=((h+l-7*m+114)%31);
	int easterDate = (p+1);
	
	
	//easter in March, checks easterMonthInt
	if (easterMonthInt == 3){
		printf("Easter is March %d in %d.\n", easterDate, year);
		return 0;

	//easter in April, checks easterMonthInt
	} else if (easterMonthInt == 4){
		printf("Easter is April %d in %d.\n", easterDate, year);
		return 0;
	}

	
	


	return 0;
	}



