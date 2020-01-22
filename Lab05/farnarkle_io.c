//Written by Bailey Ivancic. 30/3/17
//includes read and print tile functions


#include <stdio.h>
#include "farnarkle.h"

//read N_TILES tiles into array tiles
//return 1 if sucessful, 0 otherwise
int read_tiles(int tiles[N_TILES]) 
{
    int i = 0;
    int totalRead = 0;
    
    //scans tiles into array
    while (i < N_TILES)
    {
        int temp = scanf("%d", &tiles[i]);
        if (temp != 1)
        {
            return 0;
        }
        i++;
    }
    i = 0;
    
    //checks tile is less than max tile
    while (i < N_TILES)
    {
        if (tiles[i] > MAX_TILE)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

//print tiles on a single line
void print_tiles(int tiles[N_TILES])
{
    int j = 0;
    while (j < N_TILES)
    {
        printf("%d ", tiles[j]);
        j++;
    }
    printf(" \n");
}
