//Written by Bailey Ivancic
//Written on the 10th March 2017

#include <stdio.h>

int main(void){

	int length = 0; //because type int, will run into overflow if too large (eg 2000)
	int height = 0;
	int width = 0;

	
	printf("Please enter prism length: ");
	scanf("%d", &length); //Reads the length
	
	printf("Please enter prism width: ");
	scanf("%d", &width); //Reads the width

	printf("Please enter prism height: ");
	scanf("%d", &height); //Reads the height

	int volume = 0;
	volume = (length*height*width); //Calculates the volume of the prism

	int area = 0;
	area = (2*((length*width)+(length*height)+(width*height))); //calculates area

	int edgeLength = 0;
	edgeLength = (4*(height + length + width)); //calculates edge length

	printf("A prism with sides %d %d %d has:\n", length, width, height);
	printf("Volume      = %d\n", volume);
	printf("Area        = %d\n", area);
	printf("Edge length = %d\n", edgeLength);

	return 0;
}
