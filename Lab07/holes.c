//Written by Bailey Ivancic, 16/4/17
//Calculates the holes of an image
//uses a recursive method to check all the cells around the current one
//if program finds 0 in altered array, it means there is a hole inside digit

//UNTESTED

#include <stdio.h>
#include "captcha.h"

void calcHoles(int height, int width, int pixels[height][width], int row, int col, int altered[height][width], int marker)
{
	if ((row < 0) || (col < 0) || (row >= height) || (col >= width) )
	{
		return; //has gone out of bounds of pixels[][]
	}

	if (pixels[row][col] != altered[row][col])
	{
		return; //has already been changed to marker
	}

	altered[row][col] = marker;

	calcholes(height, width, pixels, (row + 1), col, altered, marker); //moves one up
	calcholes(height, width, pixels, (row - 1), col, altered, marker); //moves one down
	calcholes(height, width, pixels, row, (col + 1), altered, marker); //moves one right
	calcholes(height, width, pixels, row, (col - 1), altered, marker); //moves one left
	calcholes(height, width, pixels, (row + 1), (col + 1), altered, marker); // moves one diagonal (right up)
	calcholes(height, width, pixels, (row - 1), (col + 1), altered, marker); //moves one diagonal (right down)
	calcholes(height, width, pixels, (row + 1), (col - 1), altered, marker); //moves one diagonal (left up)
	calcholes(height, width, pixels, (row - 1), (col + 1), altered, marker); //moves one diagonal (left down)
}

/*int countHoles(int height, int width, int pixels[height][width], int altered[height][width], int marker)
{
	

    print_image();

}/*
