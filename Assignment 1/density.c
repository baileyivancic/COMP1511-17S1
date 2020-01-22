//Written by Bailey Ivancic
//Used in Assessment 1
//Contains all attribute functions related to density

#include <stdio.h>
#include "captcha.h"

//calculates fraction of pixels in bounding box that are black
double get_density(int height, int width, int boundedPixels[height][width])
{
    int row = 0;
    int col = 0;
    double totalPixels = (double)(height * width);
    double count = 0;
       
    while (row < height)
    {
        while (col < width)
        {
            if (boundedPixels[row][col] == 1)
            {
                count++;
            }
            col++;
        }
        row++;
        col = 0;
    }        
     double density = (count/totalPixels);
     return density;
}

//Density of holes to 1's in digit
double get_holedensity(int height, int width, int boundedPixels[height][width])
{
    double holeDensity = 0;
    int row = 0;
    int col = 0;
    int countOne = 0;
    int countTwo = 0;
    
    //count for 1's
    while (row < height)
    {
        while (col < width)
        {
            if (boundedPixels[row][col] == 1)
            {
                countOne++;
            }
            col++;
        }   
        row++;
        col = 0;
    }
    
    //count for 0's
    col = 0;
    row = 0;
    while (row < height)
    {
        while (col < width)
        {
            if (boundedPixels[row][col] == 3)
            {
                countTwo++;
            }
            col++;
        }   
        row++;
        col = 0;
    }
    
    //compare 0's to 1's
    holeDensity = ((double)countTwo / (double)countOne);
    return holeDensity;
}

//density of left half of image
double get_leftDensity(int height, int width, int boundedPixels[height][width])
{
    int row = 0;
    int col = 0;
    int tempWidth = (width/2);
    double totalPixels = (double)(height * tempWidth);
    double count = 0;
       
    while (col < tempWidth)
    {
        while (row < height)
        {
            if (boundedPixels[row][col] == 1)
            {
                count++;
            }
            row++;
        }
        col++;
        row = 0;
    }        
     double leftDensity = (count/totalPixels);
     return leftDensity;
}   

//density of right half of image
double get_rightDensity(int height, int width, int boundedPixels[height][width])
{
    int tempWidth = (width/2);
    int row = 0;
    int col = tempWidth;
    double totalPixels = (double)(height * tempWidth);
    double count = 0;
       
    while (col < width)
    {
        while (row < height)
        {
            if (boundedPixels[row][col] == 1)
            {
                count++;
            }
            row++;
        }
        col++;
        row = 0;
    }        
     double rightDensity = (count/totalPixels);
     return rightDensity;
} 

//density of top half of image
double get_topDensity(int height, int width, int boundedPixels[height][width])
{
    int tempHeight = (height/2);
    int row = tempHeight;
    int col = 0;
    double totalPixels = (double)(tempHeight * width);
    double count = 0;
       
    while (row < height)
    {
        while (col < width)
        {
            if (boundedPixels[row][col] == 1)
            {
                count++;
            }
            col++;
        }
        row++;
        col = 0;
    }        
     double topDensity = (count/totalPixels);
     return topDensity;
} 

//density of bottom half of image
double get_bottomDensity(int height, int width, int boundedPixels[height][width])
{
    int tempHeight = (height/2);
    int row = 0;
    int col = 0;
    double totalPixels = (double)(tempHeight * width);
    double count = 0;
       
    while (row < tempHeight)
    {
        while (col < width)
        {
            if (boundedPixels[row][col] == 1)
            {
                count++;
            }
            col++;
        }
        row++;
        col = 0;
    }        
     double bottomDensity = (count/totalPixels);
     return bottomDensity;
} 
