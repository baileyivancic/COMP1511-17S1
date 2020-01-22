//Written by Bailey Ivancic, 17/4/17
//Identifies the digit within an image

#include <math.h>
#include <stdio.h>
#include "captcha.h"

int main(int argc, char *argv[]) 
{

    //declaring all variables
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

    get_number(height, width, pixels);

    }
    return 0;
}
