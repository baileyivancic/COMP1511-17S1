//Written by Bailey Ivancic
//Prints the world

#include "trader_bot.h"
#include <stdio.h>

void print_location(struct location* current);
void print_world(struct bot *b)
{
    struct location* start = b->location;
    struct location* current = start->next;
    
    // print_location(start);
    
    do
    {
        print_location(current);
        current=current->next;
    } while (current != start); 
}

void print_location(struct location* current)
{

    if(current == NULL)
    {
        printf("%s: error: current location was NULL\n", __func__);
        return;
    }
         
    if (current->type == LOCATION_START)//
    {
        printf("%s: start\n", current->name);
    }
    
    else if (current->type == LOCATION_SELLER)
    {
        printf("%s: will sell %d units of %s for $%d\n", current->name, 
            current->quantity, current->commodity->name, current->price);
    }
    
    else if (current->type == LOCATION_BUYER)
    {
        printf("%s: will buy %d units of %s for $%d\n", current->name, 
            current->quantity, current->commodity->name, current->price);
    }
    
    else if (current->type == LOCATION_PETROL_STATION)
    {
        printf("%s: Petrol station %d units of available fuel for $%d\n", current->name, 
            current->quantity, current->price);
    }
    
    else if (current->type == LOCATION_DUMP)//
    {
        printf("%s: dump\n", current->name);
    }
    
    else if (current->type == LOCATION_OTHER)//
    {
        printf("%s: other\n", current->name);
    }
}
