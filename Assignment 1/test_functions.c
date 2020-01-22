//Written by Bailey Ivancic
//Used for Assignment 1
//Used to test functions

#include <stdio.h>
#include "captcha.h"
#include <math.h>

//Taken from the forum, used in my code to generate file names for testing
//Uploaded by Jared Steiner
void make_filename(int num, int ver, char filename[15]) {

    int pointer_point = 0;

    pointer_point += sprintf(filename, "digit/");
    pointer_point += sprintf(filename + pointer_point,"%d", num);
    pointer_point += sprintf(filename + pointer_point, "_");
    if (ver < 10) {
        sprintf(filename + pointer_point, "0%d.pbm", ver);
    } else {
        sprintf(filename + pointer_point, "%d.pbm", ver);
    }
}

int test(int argc, char *argv[]) 
{

double max = 0;
double min = 50;
double avg = 0;
double sum = 0;
int digit_num = 0;
int version = 0;
double temp = 0;
double stdDev = 0;
while (digit_num < 10) {                // For the Digits [0-9]
    while (version < 100) {       // For versions [0-99]

        char filename[15];
        make_filename(digit_num, version, filename); 

    //declaring all variables
    int height = 0;
    int width = 0;
    
    int startRow = 0;
    int startColumn = 0;
    int boxWidth = 0;
    int boxHeight = 0;
    
    int startrowHole = 0;
    int startcolumnHole = 0;
    int boxwidthHole = 0;
    int boxheightHole = 0;

    if (get_pbm_dimensions(filename, &height, &width) != 1) 
    {
        return 1;
    }

    int pixels[height][width];
    if (read_pbm(filename, height, width, pixels)) 
    {
    
//BOUNDING BOX
        //two seperate bounding boxes - for pixels and altered
        boundingBoxHoles(height, width, pixels, &startrowHole, 
        &startcolumnHole, &boxheightHole, &boxwidthHole);
        boundingBox(height, width, pixels, &startRow, &startColumn, &boxHeight, &boxWidth);
        int altered[boxheightHole][boxwidthHole];
        int boundedPixels[boxHeight][boxWidth];
        
        for (int i = 0; i < boxHeight; i++)
        {
            for(int j = 0; j < boxWidth; j++)
            {
                boundedPixels[i][j] = 0;   
            }
        }
        
        for (int i = 0; i < boxheightHole; i++)
        {
            for(int j = 0; j < boxwidthHole; j++)
            {
                altered[i][j] = 0;   
            }
        }
      
        //copies the array of bounding_box to pixels and altered
        copyPixels(height, width, pixels, startrowHole, startcolumnHole, 
        boxheightHole, boxwidthHole, altered); //bounding box changed with border
        copyPixels(height, width, pixels, startRow, startColumn, 
        boxHeight, boxWidth, boundedPixels); //bounding box
        
        //Insert test function here
        double leftDensity = get_bottomDensity(boxHeight, boxWidth, boundedPixels);
        
        if (min > leftDensity)
        {
            min = leftDensity;
        }
        
        if (max < leftDensity)
        {
            max = leftDensity;
        }
        avg = avg + leftDensity;
        
            }
            version++;
        }
        printf("Number = %d\n", digit_num);
        printf("Min = %lf\n", min);
        printf("Max = %lf\n", max);
        printf("Avg = %lf\n", avg/100);
        min = 50;
        max = 0;
        avg = 0;
        digit_num++;
        version = 0;
    }
    return 0;
}
