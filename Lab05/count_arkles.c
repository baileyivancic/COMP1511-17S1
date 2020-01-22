//written by Bailey Ivancic, 30/3/17
//counts the number of arkles in users input


#include <stdio.h>
#include "farnarkle.h"

// return number of arkles
int count_arkles(int sequence1[N_TILES], int sequence2[N_TILES]) 
{
    int i = 0;
    int arkles = 0;
    int j = 0;
    int sequence1_alt[N_TILES]; //identical array, farnarkles deleted
    int sequence2_alt[N_TILES]; //identical array, farnarkles deleted
    
    //makes array of farnarkles
    while (i < N_TILES)
    {
    
        if (sequence1[i] == sequence2[i])
        {            
            sequence1_alt[i] = 0;
            sequence2_alt[i] = 0;

        } 
        else 
        {
            sequence1_alt[i] = sequence1[i];
            sequence2_alt[i] = sequence2[i];
        }
    
     i++;
    }
    
    i = 0;
    
    //checks if the number is an arkle
    while (i < N_TILES)
    {
        while (j < N_TILES)
        {   
            
            if ((sequence1[i] == sequence2[j]) && (sequence1_alt[i] > 0) && (sequence2_alt[j] > 0))
            {
                arkles++;
                sequence1_alt[i] = 0;
                sequence2_alt[j] = 0;
                break;
            }
            j++;
        }
     j = 0;
     i++;
    }  
        return arkles;
}
