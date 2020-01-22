//Written by Bailey Ivancic
//Used in Assignment 1
//Gets all attributes of digit, determines which one is most likely
//Used to find and print out digit in crack_digit

#include <stdio.h>
#include "captcha.h"
#include <math.h>

void get_number(int height, int width, int pixels[height][width])
{  
    int startRow = 0;
    int startColumn = 0;
    int boxWidth = 0;
    int boxHeight = 0;
    
    int startrowHole = 0;
    int startcolumnHole = 0;
    int boxwidthHole = 0;
    int boxheightHole = 0;
    
//BOUNDING BOX
        //two seperate bounding boxes - for pixels and altered
        boundingBoxHoles(height, width, pixels, &startrowHole, &startcolumnHole, &boxheightHole, &boxwidthHole);
        boundingBox(height, width, pixels, &startRow, &startColumn, &boxHeight, &boxWidth);
        int altered[boxheightHole][boxwidthHole];
        int boundedPixels[boxHeight][boxWidth];
        
        //copies the array of bounding_box to pixels and altered
        copyPixels(height, width, pixels, startrowHole, startcolumnHole, 
        boxheightHole, boxwidthHole, altered); //bounding box changed with border
        copyPixels(height, width, pixels, startRow, startColumn, 
        boxHeight, boxWidth, boundedPixels); //bounding box
        
//HOLES
        int holes = countHoles(boxheightHole, boxwidthHole, altered, 2);
        
//HORIZONTAL + VERTICAL BALANCE + HOLE BALANCE
        double horBalance = horizontalBalance(boxHeight, boxWidth, boundedPixels);
        double verBalance = verticalBalance(boxHeight, boxWidth, boundedPixels);
        double holBalance = holeBalance(boxheightHole, boxwidthHole, altered, holes);

//HOLE FRACTION
        double holeFraction = getholeFraction(boxheightHole, boxwidthHole, altered);

//TALLNESS
        double tallness = (double)boxHeight/(double)boxWidth; 
        
//DENSITY
        double density = get_density(boxHeight, boxWidth, boundedPixels);
        double holeDensity = get_holedensity(boxheightHole, boxwidthHole, altered);
        double leftDensity = get_leftDensity(boxHeight, boxWidth, boundedPixels);
        double rightDensity = get_rightDensity(boxHeight, boxWidth, boundedPixels);
        double bottomDensity = get_bottomDensity(boxHeight, boxWidth, boundedPixels);
        double topDensity = get_topDensity(boxHeight, boxWidth, boundedPixels);
        
//CALCULATE STARTING AREA OF HOLE
        int holePosition = get_holeposition(boxheightHole, boxwidthHole, altered, holes);
        
//CALCULATE HOLE HEIGHT
        int holeHeight = get_holeheight(boxheightHole, boxwidthHole, altered, holePosition, holes);
        
//CALCULATE PROBABILITY OF DIGIT
//uses attributes calculated and the averages for each to try and find best fitting number
//done through series of if statements checking attributes
//Full set of attribute data included in excel spreadsheet

    if (holes == 0) //possible digits = 1, 2, 3, 5, 7
    {
        if (topDensity > bottomDensity && varience(verBalance, 0.598) < 0.0535)
        {
            printf("7\n");
        }
    
        else
        {
            if (rightDensity > leftDensity && varience(topDensity, bottomDensity) < 0.06)
            {
                if (varience(tallness, 1.769) < 0.075)
                {
                    printf("1\n");
                }
                
                else
                {
                    printf("2\n");
                }
            }
            
            else
            {
                if (rightDensity > leftDensity && varience(horBalance, 0.572) < 0.052)
                {
                    printf("3\n");
                }
                
                else
                {
                    printf("5\n");
                }
            }
        }
    }
    
    else if (holes == 1) //possible digits = 0, 4, 6, 9
    {
        //hole start position
        if (holePosition <= 28) //can be 0, 4, 6
        {
            if (holBalance < 0.405) //can only be 6
            {
                printf("6\n");
            }
            
            else
            {
                if (varience(holeHeight, 32) < 18)
                {
                    printf("0\n");
                }
            
                else
                {
                    printf("4\n");
                }
            }
        }
        
        else if (holePosition > 28) //can be 0, 4, 9
        {   
            if (varience(holBalance, 0.66) < 0.045) //must be 9
            {
                printf("9\n");
            }
            
            else //narrowed down to 0 or 4
            {
                if (varience(holeHeight, 32) < 18)
                {
                    printf("0\n");
                }
                
                else
                {
                    printf("4\n");
                }    
            }
        }
    }
    
    else //only possible answer for two holes
    {
        printf("8\n");
    }
}
