//Written by Bailey Ivancic, 16/4/17
//Used in Assignment 1
//Prints a given image (array)

#include <stdio.h>
#include "captcha.h"

void printImage(int height, int width, int pixels[height][width])
{
    int row = height - 1;
    int col = 0;
    
    //loops through vertical
    while (row >= 0)
    {
        while (col < width) //loops through horizontal
        {
            printf("%d",pixels[row][col]);
            col++;
        }
        row--;
        col = 0;
        printf("\n");
    }
}
