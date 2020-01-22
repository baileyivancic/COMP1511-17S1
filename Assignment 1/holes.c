//Written by Bailey Ivancic, 16/4/17
//Contains all functions relating to holes of the image
//idea derived from wikipedia and related sites, all code written myself

#include <stdio.h>
#include "captcha.h"

//Calculates the holes of an image
//uses a recursive method to check all the cells around the current one
//changes all 0's to a specified marker
//if program finds 0 in altered array, it means there is a hole inside digit
void getHoles(int height, int width, int row, int col, int altered[height][width], int marker)
{
	if ((row < 0) || (col < 0) || (row >= height) || (col >= width) )
	{
		return; //has gone out of bounds of pixels[][]
	}

	if (altered[row][col] != 0)
	{
		return; //has already been changed to marker or is a 1
	}

	altered[row][col] = marker;
	
	getHoles(height, width, (row + 1), col, altered, marker); //moves one up
	getHoles(height, width, (row - 1), col, altered, marker); //moves one down
	getHoles(height, width, row, (col + 1), altered, marker); //moves one right
	getHoles(height, width, row, (col - 1), altered, marker); //moves one left
	getHoles(height, width, (row + 1), (col + 1), altered, marker); // moves one diagonal (right up)
	getHoles(height, width, (row - 1), (col + 1), altered, marker); //moves one diagonal (right down)
	getHoles(height, width, (row + 1), (col - 1), altered, marker); //moves one diagonal (left up)
	getHoles(height, width, (row - 1), (col - 1), altered, marker); //moves one diagonal (left down)
}

int countHoles(int height, int width, int altered[height][width], int marker)
{
    //marks pixels around digit in altered array
	getHoles(height, width, 0, 0, altered, 2);
    
    int row = 0;
    int col = 0;
    int holes = 0; //flag for holes (1 for holes detected, 0 otherwise)
    int colMark = 0;
    int rowMark = 0;
    
    //simple scan to check array for zeroes
    while (row < height)
    {
        while (col < width)
        {
            if (altered[row][col] == 0)
            {
                holes = 1;
                colMark = col;
                rowMark = row;
                break;
            }
            col++;
        }
        row++;
        col = 0;
    }
    
    //differentiates between 1 and 2 holes
    //uses new marker and changes zero pixels to marker
    //if zeroes still remain, must be a second hole
    if (holes > 0)
    {
        getHoles(height, width, rowMark, colMark, altered, 3);
        
        row = 0;
        col = 0;
        while (row < height)
        {
            while (col < width)
            {
                if (altered[row][col] == 0)
                {
                    holes = 2;
                    break;
                }
                col++;
            }
            row++;
            col = 0;
        }
    }
    return holes;
}

//get area of white pixels in holes as fraction of bounding box
double getholeFraction(int height, int width, int altered[height][width])
{
    double totalPixels = (width * height);
    int row = 0;
    int col = 0;
    double count = 0;
        
    while (row < height)
    {
        while (col < width)
        {
            if (altered[row][col] == 3)
            {
                count++;
            }
            col++;    
        }
        row++;
        col = 0;
        }
        
        double holeFraction = (count/totalPixels);
    return holeFraction;
}
