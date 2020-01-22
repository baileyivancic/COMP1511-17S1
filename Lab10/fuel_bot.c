//Written by Bailey Ivancic

#include "trader_bot.h"
#include <stdio.h>

char *get_bot_name(void);
void get_action(struct bot *b, int *action, int *n)
{
    //if fuel bot not a petrol station, should move to closest petrol station
    if (b->location->type != LOCATION_PETROL_STATION)
    {
        int moves = nearest_fuel(b);
    
        //if closest station cannot be reached in one move, move maximum
        if (moves > b-> maximum_move)
        {
            *action = 0;
            *n = b-> maximum_move;
        }   
        
        else
        {
            *action = 0;
            *n = moves;
        }
    } 
    
    //If fuel bot at petrol station and tank is not full, should buy exactly enough fuel to fill tank
    if (b->location->type == LOCATION_PETROL_STATION)
    {
        //if fuel bot at station and tank is full, should move maximum distance forward
        if (b -> fuel == b -> fuel_tank_capacity)
        {
            *action = 0;
            *n = b -> maximum_move;
        }
        
        else
        {
            int temp = b -> fuel_tank_capacity - b -> fuel;
            *action = 1;
            *n = temp;
        }
    } 
}

char *get_bot_name(void)
{
    return "Fuel Bot";
}
