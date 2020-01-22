//Written by Bailey Ivancic, 30/3/17
//Plays farnarkle, includes main function

#include <stdio.h>
#include "farnarkle.h"
#include <time.h>
#include <stdlib.h>

int generate_random_number(void);

int main(void) {
    int hidden_sequence[N_TILES];
    int entered_sequence[N_TILES];
    create_random_tiles(hidden_sequence);
    int turn = 1;
    int farnarkles = 0;
    int arkles = 0;
    
    //loops through checking the user's input until 4 farnarkles
    while (farnarkles < 4)
    {
        printf("Enter guess for turn %d: ", turn);
        read_tiles(entered_sequence);
        farnarkles = count_farnarkles(entered_sequence, hidden_sequence);
        arkles = count_arkles(entered_sequence, hidden_sequence);
        printf("%d farnarkles %d arkles\n", farnarkles, arkles);
        turn++;
    }
    
        printf("You win\n");
    
    return 0;

} 

//random number generated
int generate_random_number(void)
{
    // need to 'seed' the random gen
    // (we essentially choose a starting sequence number)
    
    srand(time(NULL));
    
    return ((rand()%MAX_TILE) +1);//rand num inside bounds
}
