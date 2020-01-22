//Written by Bailey Ivancic
//Written on 10th March 2017

#include <stdio.h>
#include <math.h>

int main(void){

	double sideA = 0;
	double sideB = 0;
	double sideC = 0;

	//Gets inputs
	printf("Enter side 1: ");
	scanf("%lf", &sideA);

	printf("Enter side 2: ");
	scanf("%lf", &sideB);

	printf("Enter side 3: ");
	scanf("%lf", &sideC);


	//semi-perimeter variable
	double semi = ((sideA + sideB + sideC)/2);
	
	//area variable
	double area = (sqrt(semi*(semi-sideA)*(semi-sideB)*(semi-sideC)));

	//Checks if the inequality is true
	if ((sideA + sideB < sideC) || (sideB + sideC < sideA) || (sideA + sideC < sideB)) {
		printf("Error: triangle inequality violated.\n"); //if doesn't fit, print error
		return 0;	

	} else { //if it is true, print area
		printf("Area = %lf\n", area);
		return 1;
	}
    return 0;

}
