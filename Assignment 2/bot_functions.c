//Written by Bailey Ivancic
//Used within Assignment 2
//Houses all functions used for trader bot

#include <stdio.h>
#include "trader_bot.h"
#include "myBot.h"

//Used for case 1
//Finds most profitable commodity to buy, and the most profitable place to buy from
struct location* buyMove(struct bot* b)
{
    struct location* runner = b->location; //this bot will go through commodities
    struct location* seller = NULL; //stores most profitable seller
    int profit = 0; //how much we can buy * price we can sell for - how much we can sell * price we buy for
    int temp = 0;
    
    do
    {
        if (runner->type == LOCATION_SELLER && runner->quantity != 0)
        {
            int amount = maxBuy(b, runner);
            
            //this bot will check profit at all buyers of that commodity
            struct location* check = sellMove(b, runner->commodity, amount); 
            
            if (check == NULL)
            {
                runner = runner->next;
                continue;
            }
            
            if (amount > check->quantity) 
            {
                amount = check->quantity;
            }
      
            int temp = amount*(check->price) - amount*(runner->price);
                
            printf("amount - %s %d %d\n", runner->name, amount, temp);
            
            if (temp > profit && check->quantity != 0) //checks is vendor will give most profit so far
            {
                profit = temp;
                seller = runner;
            }
        }
        runner = runner->next;
    } while (runner != b->location); 
    return seller;
}

//Used for case 2
//Bot has something in cargo, and must sell it at most pofitable place
struct location* sellMove(struct bot* b, struct commodity* item, int amount)
{
  struct location *curr = b->location;
  struct location *seller = NULL;
  int temp = 0;
  
    do
    {
        if (curr->type == LOCATION_BUYER && curr->commodity == item && curr->quantity != 0)
        {
            int sellAmount = maxSell(curr, amount);
            
            if (sellAmount * curr->price > temp) 
            {
                temp = sellAmount * curr->price;
                seller = curr;
            }
        }
    curr = curr->next; 
    } while (curr != b->location);  
 
    return seller;   
}

//Used for selling DONE
//Returns maximum amount of items bot can sell
int maxSell(struct location* vendor, int cargo)
{
    int buying = vendor->quantity;

    if (buying > cargo)
    {
        return cargo;
    }   
    return buying;
}

//Used for buying DONE
//Returns maximum amount of items bot can buy
int maxBuy(struct bot* b, struct location* vendor)
{
    //Must find lowest amount can buy, as this will be limiting factor
    int countFinal = vendor->quantity; //will store actual amount we can buy
    int tempWeight = (b->maximum_cargo_weight)/(vendor->commodity->weight);
    int tempVolume = (b->maximum_cargo_volume)/(vendor->commodity->volume);
    int tempPrice = (b->cash)/(vendor->price);
    
    if (vendor->quantity == 0)
    {
        return 0;
    }
    
    if (tempWeight < countFinal)
    {
        countFinal = tempWeight;
    }
    
    if (tempVolume < countFinal)
    {
        countFinal = tempVolume;
    }
    
    if (tempPrice < countFinal)
    {
        countFinal = tempPrice;
    }
    return countFinal;
}

//Fuel function for robot
//Moves bot in direction of nearest fuel station
void getFuel(struct bot* b, int *action, int* n)
{
    int move = lookFuel(b->location);
    printf("Move - %d\n", move);
    
    //no fuel stations left, try and sell anything
    if (move == 1025)
    {
         if (b->cargo != NULL && b->cargo->quantity > 0) //carrying something
         {
            struct location* buyer = sellMove(b, b->cargo->commodity, b->cargo->quantity);
            int count1 = 0; //counter for left moves
            int count2 = 0; //counter for right moves
            int countFinal = 0;

            //checking if bot is at most profitable buyer
            if (b->location == buyer)
            {
                *n = maxSell(buyer, b->cargo->quantity);
                *action = ACTION_SELL;
                return;
            }
            
            else //bot has to move
            {
                printf("we're in the right loop\n");
                struct location* left = b->location->previous;
                struct location* right = b->location->next;
                    
                do
                {
                    if (left == buyer)
                    {
                        countFinal = count1-1;
                        break;
                    }
                        
                    if (right == buyer)
                    {
                        countFinal = count2+1;
                        break;
                    }
                        
                    left = left->previous;
                    right = right->next;
                    count2++;
                    count1--;
                } while (left != right);
                
                if (left == right && left == buyer)
                {
                    countFinal = count2 + 1;
                }
                
                *action = ACTION_MOVE;
                *n = countFinal;
                return;
            }   
         }
    }
    
    //bot is at fuel station (buy fuel)
    if (move == 0)
    {
        if (b->location->quantity == 0) //out of fuel
        {
            printf("gone into yet another loop\n");
            //we have stuff in cargo
            if (b->cargo != NULL)
            {
                printf("Gone into the cargo loop\n");
                struct location* buyer = sellMove(b, b->cargo->commodity, b->cargo->quantity);
                int count1 = 0; //counter for left moves
                int count2 = 0; //counter for right moves
                int countFinal = 0;

                struct location* left = b->location->previous;
                struct location* right = b->location->next;
                    
                do
                {
                    if (left == buyer)
                    {
                        countFinal = count1-1;
                        break;
                    }
                        
                    if (right == buyer)
                    {
                        countFinal = count2+1;
                        break;
                    }
                        
                    left = left->previous;
                    right = right->next;
                    count2++;
                    count1--;
                } while (left != right);
                
                if (left == right && left == buyer)
                {
                    countFinal = count2 + 1;
                }
                
                *action = ACTION_MOVE;
                *n = countFinal;
                return;   
            }
        }
        
        *n = b->fuel_tank_capacity - b->fuel;
        *action = ACTION_BUY;
        return;
    }
    
    //bot is not at fuel station  
    if (move != 0)
    {
        //won't make it to most profitable
        if (move > b->fuel)
        {
            if (b->cargo != NULL)
            {
                move = closeBuyer(b);
            }
        }
    
        *n = move;
        *action = ACTION_MOVE;
        return;
    }
}

//Function for finding nearest fuel
int lookFuel(struct location *l)
{
    struct location* currentF = l;
    struct location* currentB = l;
    int countF = 0;
    int countB = 0;

    do
    {
        if (currentF->type == LOCATION_PETROL_STATION && currentF->quantity != 0)
        {
            if (countF == 0)
            {
                return 0;
            }
            return countF;
        }
        
        else if (currentB->type == LOCATION_PETROL_STATION && currentB->quantity != 0)
        {
            if (countB == 0)
            {
                return 0;
            }
            return countB;
        }
        
        else
        {
            countF++;
            countB--;
            currentF = currentF->next;
            currentB = currentB->previous;
        }
    } while (currentF != l && currentB != l);
    return 1025;
}

//Gets average price of fuel on the map
int avgFuelPrice(struct location* runner)
{
    struct location* curr = runner;
    int count = 0;
    int price = 0;
    
    do
    {
        if (curr->type == LOCATION_PETROL_STATION)
        {
            price = price + curr->price;
            count++;
        }
        
        curr = curr->next;
    } while (runner != curr);
    
    price = price/count;
    
    return price;
}

//finds distance between two locations (used for fuel)
int distance (struct location* runner, struct location* place)
{
    int countLeft = 0;
    int countRight = 0;
    struct location* currLeft = runner;
    struct location* currRight = runner;
    
    do
    {
        if (currLeft == place)
        {
            return countLeft;
        }
        
        if (currRight == place)
        {
            return countRight;
        }
    
        countLeft++;
        countRight++;
        currRight = currRight->next;
        currLeft = currLeft->previous;
    } while (currLeft != runner || currRight != runner);
    
    return countLeft;
}

//Dump function
//If there are no buyers for the commodity we have in our cargo, we must dump it
void dump(int* action, int* n, struct bot* b)
{
    //search world for buyer of our commodity
    if (sellMove(b, b->cargo->commodity, b->cargo->quantity) == NULL)
    {
        //need to look for nearest dump
        int moves = closeDump(b);
        if (moves == 0) //at dump
        {
            *action = ACTION_DUMP;
            *n = b->cargo->quantity;
            return;
        }
        
        else //need to move to dump
        {
            *n = moves;
            *action = ACTION_MOVE;
            return;
        }
    }
    return;
}

//Function for finding nearest buyer
int closeBuyer(struct bot* b)
{
    struct commodity* item = b->cargo->commodity;
    struct location* currentF = b->location;
    struct location* currentB = b->location;
    int countF = 0;
    int countB = 0;

    do
    {
        if (currentF->type == LOCATION_BUYER && currentF->quantity != 0 && currentF->commodity == item)
        {
            if (countF == 0)
            {
                return 0;
            }
            return countF;
        }
        
        else if (currentB->type == LOCATION_BUYER && currentB->quantity != 0 && currentB->commodity == item)
        {
            if (countB == 0)
            {
                return 0;
            }
            return countB;
        }
        
        else
        {
            countF++;
            countB--;
            currentF = currentF->next;
            currentB = currentB->previous;
        }
    } while (currentF != b->location && currentB != b->location);
    return 1025;
}

//Function for finding nearest dump
int closeDump(struct bot* b)
{
    struct location* currentF = b->location;
    struct location* currentB = b->location;
    int countF = 0;
    int countB = 0;

    do
    {
        if (currentF->type == LOCATION_DUMP)
        {
            if (countF == 0)
            {
                return 0;
            }
            return countF;
        }
        
        else if (currentB->type == LOCATION_DUMP)
        {
            if (countB == 0)
            {
                return 0;
            }
            return countB;
        }
        
        else
        {
            countF++;
            countB--;
            currentF = currentF->next;
            currentB = currentB->previous;
        }
    } while (currentF != b->location && currentB != b->location);
    return 1025;
}
