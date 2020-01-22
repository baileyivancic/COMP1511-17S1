//Written by Bailey Ivancic
//Used in Assignment 1
//Contains other functions useful in calculating digits

#include <stdio.h>
#include "captcha.h"

//Finds whether the hole is on the top or bottom
//Used to differentiate 6 from 9
//Returns a percentage of startrow/height
double get_holeposition(int height, int width, int altered[height][width], int holes)
{
    if (holes == 0)
    {
        return 1;
    }
    
    else
    {
    int startRow = 0; //printing out this number (not entering loop)
    int col = 0;
    int row = 0;
    int found = 0; //0 for not found, 1 for found position
    double startPercentage = 0;
    
    while (row < height && found == 0)
    {
        while (col < width && found == 0)
        {
            if (altered[row][col] == 3)
            {
                startRow = row;
                found = 1;
            }
            col++;
        }
    col = 0;
    row++;
    }   
    startPercentage = ((startRow/(double)height)*100);
    return startPercentage;
    }
}

double get_verticalblack(int height, int width, int altered[height][width])
{
    int row = 0;
    int col = 0;
    double num = 0; //count how many black read vertically
    int temp = 0;
    
    while (col < width)
    {
        while (row < height)   
        {
            if (altered[row][col] == 1)
            {
                temp++;
            }   
           row++;
        }
        
        if (temp > num)
        {
            num = col;
        }
        col++;
        row = 0;
        temp = 0;
    }
    num = (num/(double)width)*100;
    return num;
}

double get_holeheight(int height, int width, int altered[height][width], int start, int holes)
{ 
    if (holes == 0)
    {
        return 1;;
    }

    else
    {
    int col = 0;
    int row = height - 1;
    int found = 0; //0 for not found, 1 for found position
    double finishPercentage = 0;
    int finish = 0;
    
    while (row > 0 && found == 0)
    {
        while (col < width && found == 0)
        {
            if (altered[row][col] == 3)
            {
                finish = row;
                found = 1;
            }
            col++;
        }
    col = 0;
    row--;
    }   
    
    double holeHeight = (double)(finish - start);
    finishPercentage = ((holeHeight/(double)height)*100);
    return holeHeight;
    }
}
