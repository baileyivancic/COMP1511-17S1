//written by Bailey Ivancic, 16/4/17
//Copies pixels within a specified height and range to a new array

#include <stdio.h>
#include "captcha.h"

void copy_pixels(int height, int width, int pixels[height][width],int start_row, int start_column, int copy_height, int copy_width, int copy[copy_height][copy_width])
{
    int row = start_row;
    int col = start_column;
    int tempRow = 0; 
    int tempCol = 0;
    int finishRow = copy_height + start_row; //where program stops copying
    int finishCol = copy_width + start_column; //where program stops copying

    while (row < finishRow)
    {
        while (col < finishCol)
        {
            copy[tempRow][tempCol] = pixels[row][col];
            col++;
            tempCol++;
        }  
        row++;
        tempRow++;
        col = start_column; 
        tempCol = 0;
    }
}
