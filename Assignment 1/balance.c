//Written by Bailey Ivancic
//Used in Assessment 1
//Calculates all types of balances

#include <stdio.h>
#include "captcha.h"
//calculates the vertical balance of an image
double verticalBalance(int height, int width, int boundedPixels[height][width])
{
    double num = 0; //counts num of black pixels
    double rowSum = 0;
    int row = 0;
    int col = 0;
    double verticalBalance = 0;
    double tempHeight = height;
    
    while (col < width)
    {
        while (row < height)
        {
            if (boundedPixels[row][col] == 1)
            {
                num++;
                rowSum = rowSum + row;
            }
         row++; 
        }
    row = 0;
    col++;
    }
    verticalBalance = (rowSum/num + 0.5)/tempHeight;
    return verticalBalance; 
}

//calculates horizontal balance of image
double horizontalBalance(int height, int width, int boundedPixels[height][width])
{
    double num = 0; //counts num of black pixels
    double colSum = 0;
    int row = 0;
    int col = 0;
    double horizontalBalance = 0;
    double tempWidth = width;
    
    while (row < height)
    {
        while (col < width)
        {
            if (boundedPixels[row][col] == 1)
            {
                num++;
                colSum = colSum + col;
            }
         col++; 
        }
    col = 0;
    row++;
    }
    horizontalBalance = (colSum/num + 0.5)/tempWidth;
    return horizontalBalance;
}

//calculates balance of the hole in terms of height of image
double holeBalance(int height, int width, int holePixels[height][width], int holes)
{
    if (holes == 0)
    {
        return 1;
    }

    double num = 0; //counts num of pixels in hole
    double rowSum = 0;
    int row = 0;
    int col = 0;
    double holeBalance = 0;
    
    while (col < width)
    {
        while (row < height)
        {
            if (holePixels[row][col] == 3)
            {
                num++;
                rowSum = rowSum + row;
            }
            row++; 
        }
        row = 0;
        col++;
    }
    holeBalance = (rowSum/num + 0.5)/(double)height;
    return holeBalance;
}
