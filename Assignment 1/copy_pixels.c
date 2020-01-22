//written by andrewt@unsw.edu.au April 2017 as COMP1511 solution
//Edited and modified for use in Assessment by Bailey Ivancic

#include <stdio.h>
#include "captcha.h"

//Copies pixels within specified height and range to new array
void copyPixels(int height, int width, int pixels[height][width], int start_row, int start_column, int copy_height, int copy_width, int copy[copy_height][copy_width]) {
    
    if (start_row < 0)
    {
        start_row = 0;
    }
    
      if (start_column < 0)
    {
        start_column = 0;
    }
    
    for (int row = 0; row < copy_height; row++) {
        for (int column = 0; column < copy_width; column++) {
            
            if ((start_row + row) >= height || (start_column+column)>=width)
            {
                copy[row][column] = 0;
            }
            else
            {
            copy[row][column] = pixels[start_row + row][start_column + column];
            }
        }
    }
}
