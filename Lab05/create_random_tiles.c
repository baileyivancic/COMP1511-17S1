//written by Bailey Ivancic, 30/3/17
//generates random numbers


#include <stdlib.h>
#include <time.h>
#include "farnarkle.h"

// set tiles to pseudo-random values
void create_random_tiles(int tiles[N_TILES]) 
{
    int i = 0;

    // seed (initialize) pseudo-random number generate with current time in seconds
    srand(time(NULL));

    i = 0;
    while (i < N_TILES) 
    {
        tiles[i] = rand() % MAX_TILE + 1;
        i = i + 1;
    }
}

