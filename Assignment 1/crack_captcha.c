//Written by Bailey Ivancic
//Part 2 of assignment 1

/*
performs same function as crack digit, except this program splits the captcha 
image given to it into 4 seperate digits, so the same process and functions 
can be used on the individual digits

*/

#include <stdio.h>
#include "captcha.h"

int main(int argc, char *argv[]) 
{
    int height = 0;
    int width = 0;

    //checks that program is able to get dimensions
    if (get_pbm_dimensions(argv[1], &height, &width) != 1) 
    {
        return 1;
    }

    int pixels[height][width];

    if (read_pbm(argv[1], height, width, pixels)) 
    {
        int startCol = 0;
        int row = 0;
        int col = 0;
        int i = 0;
        
        while (col < width && i == 0)
        {
            while (row < height && i == 0)
            {
                if (pixels[row][col] == 1)
                {
                    i = 1;
                    startCol = col;
                }
                row++;
            }
            col++;
            row = 0;
        }
        
        row = 0;
        col = startCol;
        int endCol = 0; //column number of ending column
        int empty = 0; //flag to check if column is free of digit
        int found = 0;
        
        while (col < width && found == 0)
        {
            while (row < height && found == 0)
            {
                if (pixels[row][col] == 1)
                {
                    empty = 1;
                }  
                row++;
            }
            if (empty != 1)
            {
                endCol = col;
                found = 1;
            }
            col++;
            row = 0;
            empty = 0;
        }
    
        int arrayOne[height][endCol];
        copyPixels(height, width, pixels, 0, 0, height, endCol, arrayOne);
        get_numberCaptcha(height, endCol, arrayOne);
        
        startCol = endCol;
        row = 0;
        col = startCol;
        i = 0;
        
        while (col < width && i == 0)
        {
            while (row < height && i == 0)
            {
                if (pixels[row][col] == 1)
                {
                    i = 1;
                    startCol = col;
                }
                row++;
            }
            col++;
            row = 0;
        }
        
        //Second one
        row = 0;
        int store = endCol;
        col = startCol;
        endCol = 0; //column number of ending column
        empty = 0; //flag to check if column is free of digit
        found = 0;
        
        while (col < width && found == 0)
        {
            while (row < height && found == 0)
            {
                if (pixels[row][col] == 1)
                {
                    empty = 1;
                }  
                row++;
            }
            if (empty != 1)
            {
                endCol = col;
                found = 1;
            }
            col++;
            row = 0;
            empty = 0;
        }
    
        int temp = endCol - store;
        int arrayTwo[height][temp];
        copyPixels(height, width, pixels, 0, store, height, temp, arrayTwo);
        get_numberCaptcha(height, temp, arrayTwo);
        
        startCol = endCol;
        row = 0;
        col = startCol;
        i = 0;
        
        while (col < width && i == 0)
        {
            while (row < height && i == 0)
            {
                if (pixels[row][col] == 1)
                {
                    i = 1;
                    startCol = col;
                }
                row++;
            }
            col++;
            row = 0;
        }
        
        //Third one
        row = 0;
        store = endCol;
        col = startCol;
        endCol = 0; //column number of ending column
        empty = 0; //flag to check if column is free of digit
        found = 0;
        
        while (col < width && found == 0)
        {
            while (row < height && found == 0)
            {
                if (pixels[row][col] == 1)
                {
                    empty = 1;
                }  
                row++;
            }
            if (empty != 1)
            {
                endCol = col;
                found = 1;
            }
            col++;
            row = 0;
            empty = 0;
        }
    
        temp = endCol - store;
        int arrayThree[height][temp];
        copyPixels(height, width, pixels, 0, store, height, temp, arrayThree);
        get_numberCaptcha(height, temp, arrayThree);
        
        startCol = endCol;
        row = 0;
        col = startCol;
        i = 0;
        
        while (col < width && i == 0)
        {
            while (row < height && i == 0)
            {
                if (pixels[row][col] == 1)
                {
                    i = 1;
                    startCol = col;
                }
                row++;
            }
            col++;
            row = 0;
        }
        
        //Fourth one
        row = 0;
        store = endCol;
        col = startCol;
        endCol = 0; //column number of ending column
        empty = 0; //flag to check if column is free of digit
        found = 0;
        
        while (col < width && found == 0)
        {
            while (row < height && found == 0)
            {
                if (pixels[row][col] == 1)
                {
                    empty = 1;
                }  
                row++;
            }
            if (empty != 1)
            {
                endCol = col;
                found = 1;
            }
            col++;
            row = 0;
            empty = 0;
        }
        
        if (endCol < startCol)
        {
            endCol = width - 1;
        }
    
        temp = endCol - store;
        int arrayFour[height][temp];
        copyPixels(height, width, pixels, 0, store, height, temp, arrayFour);
        get_numberCaptcha(height, temp, arrayFour);
        printf("\n");
    }
    return 0;
}
