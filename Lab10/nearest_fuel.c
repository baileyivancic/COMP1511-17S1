//Written by Bailey Ivancic
//Returns the distance to the nearest fuel station

#include "trader_bot.h"
#include <stdio.h>
#include "myBot.h"

int fuelDistance(struct location *l)
{
    struct location* start = l;
    struct location* currentF = l->next;
    struct location* currentB = l->previous;
    
    int countF = 0;
    int countB = 0;
    
    if (start->type == LOCATION_PETROL_STATION)
    {
        return 0;
    }
    
    while (currentF != start && currentB != start)
    {
        if (currentF->type == LOCATION_PETROL_STATION)
        {
            return countF+1;
        }
        
        else if (currentB->type == LOCATION_PETROL_STATION)
        {
            return countB-1;
        }
        
        else
        {
            countF++;
            countB--;
            currentF = currentF->next;
            currentB = currentB->previous;
        }
    }
}
