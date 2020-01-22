//Written by Bailey Ivancic, 16/4/17
//Calculates the horizontal balance of an image

#include <stdio.h>
#include "captcha.h"

double get_horizontal_balance(int height, int width, int pixels[height][width])
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
            if (pixels[row][col] == 1)
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

#include <stdio.h>
#include "captcha.h"

double get_vertical_balance(int height, int width, int pixels[height][width])
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
            if (pixels[row][col] == 1)
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

