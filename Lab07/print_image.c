//written by Bailey Ivancic, 16/4/17
//prints a given image

#include <stdio.h>
#include "captcha.h"

void print_image(int height, int width, int pixels[height][width])
{
    int row = height - 1;
    int col = 0;
    
    //loops through vertical
    while (row >= 0)
    {
        while (col < width) //loops through horizontal
        {
            if (pixels[row][col] == 1) //black
            {
                printf("*");
            }
            
            else if (pixels[row][col] == 0) //white
            {
                printf(".");
            }
            col = col + 1;
        }
        row--;
        col = 0;
        printf("\n");
    }
}


