//Written by Bailey Ivancic
//Used for Assignment 1
//Different variations of bounding boxes contained in here

#include <stdio.h>
#include "captcha.h"

//used for boundedPixels (normal bounding box)
void boundingBox(int height, int width, int pixels[height][width],
                  int *startRow, int *startColumn, int *boxHeight, int *boxWidth)
{
   int topRow = 0;
   int endCol = 0;
   
   //find starting row
   int row = 0;
   int col = 0;
     while (row < height)
     {
        while (col < width)
        {
            if (pixels[row][col] == 1)
            {
                *startRow = row;
                row = height;
                col = width;
            }
            col++;
        }
        row++;
        col = 0;
     }
   
   //find top row
     row = 0;
     col = 0;
     while (row < height)
     {
        while (col < width)
        {
            if (pixels[row][col] == 1)
            {
                topRow = row+1;
            }
            col++;
        }
        row++;
        col = 0;
     }
   
   //calculate height
   *boxHeight = topRow - *startRow;
   
   //find start col
   col = 0;
   row = 0;
   while (col < width)
   {
        while (row < height)
        {
            if (pixels[row][col] == 1)
            {
                *startColumn = col;
                row = height;
                col = width;
            }
            row++;
        }
        row = 0;
        col ++;
   }
   
      //find end col
   col = 0;
   row = 0;
   while (col < width)
   {
        while (row < height)
        {
            if (pixels[row][col] == 1)
            {
                endCol = col+1;
            }
            row++;
        }
        row = 0;
        col ++;
   }
   
   //Calculate width             
   *boxWidth =  endCol - *startColumn;          
}

//function used within getHoles()
//Finds bounding box of digit, bust also adds border of 0s around it
void boundingBoxHoles(int height, int width, int pixels[height][width],
   int *startrowHole, int *startcolumnHole, int *boxheightHole, int *boxwidthHole)
{
   int topRow = 0;
   int endCol = 0;
   
   //find starting row (-1)
   int row = 0;
   int col = 0;
     while (row < height)
   {
        while (col < width)
        {
            if (pixels[row][col] == 1)
            {
                *startrowHole = row -1;
                row = height;
                col = width;
            }
            col++;
        }
        row++;
        col = 0;
   }
   
   //find top row
     row = 0;
     col = 0;
     while (row < height)
   {
        while (col < width)
        {
            if (pixels[row][col] == 1)
            {
                topRow = row;
            }
            col++;
        }
        row++;
        col = 0;
   }
   
   //calculate height (+2)
   *boxheightHole = (topRow - *startrowHole) + 2;
   
   //find start col (-1)
   col = 0;
   row = 0;
   while (col < width)
   {
        while (row < height)
        {
            if (pixels[row][col] == 1)
            {
                *startcolumnHole = col -1;
                row = height;
                col = width;
            }
            row++;
        }
        row = 0;
        col ++;
   }
   
      //find end col
   col = 0;
   row = 0;
   while (col < width)
   {
        while (row < height)
        {
            if (pixels[row][col] == 1)
            {
                endCol = col;
            }
            row++;
        }
        row = 0;
        col ++;
   }
   
   //Calculate width (+2)      
   *boxwidthHole =  (endCol - *startcolumnHole) + 2;          
}
