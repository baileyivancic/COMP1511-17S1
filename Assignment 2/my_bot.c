//Written by Bailey Ivancic
//Part of Assignment 2

#include <stdio.h>
#include "trader_bot.h"
#include "myBot.h"

void get_action(struct bot *b, int *action, int *n)
{
/*
    CASE 3
    Only happens if 4 turns left
    Likely not enough time to do anything, so try and maximise profit we have
    If cargo in hold, sell it
    Otherwise move and do nothing
    DON'T BUY ANYTHING
*/
    if (b->turns_left <= 7)
    {
        printf("Case 3 accessed\n");
        if (b->cargo != NULL && b->cargo->quantity > 0)
        {
            struct location* temp = sellMove(b, b->cargo->commodity, b->cargo->quantity);
            int count1 = 0; //counter for left moves
            int count2 = 0; //counter for right moves
            int countFinal = 0;

            //checking if bot is at most profitable buyer
            if (b->location == temp)
            {
                *n = maxSell(temp, b->cargo->quantity);
                *action = ACTION_SELL;
                return;
            }
            
            else //bot has to move
            {
                struct location* left = b->location->previous;
                struct location* right = b->location->next;
                    
                do
                {
                    if (left == temp)
                    {
                        countFinal = count1-1;
                        break;
                    }
                        
                    if (right == temp)
                    {
                        countFinal = count2+1;
                        break;
                    }
                        
                    left = left->previous;
                    right = right->next;
                    count2++;
                    count1--;
                } while (left != right);
                
                if (left == right && left == temp)
                {
                    countFinal = count2 + 1;
                }
                
                *action = ACTION_MOVE;
                *n = countFinal;
                return;
            }   
        }
        else
        {
            *action = ACTION_MOVE;
            *n = b->maximum_move;
        }   
    }

/*
    CASE 1
    Bot has nothing in cargo, must go buy something
    Must search world for most profitable combination of buying and selling goods
    Moves robot in direction of seller of best scenario
*/
    else if (b->cargo == NULL)
    {
        printf("Case 1 accessed\n");
        //checks if bot fuel is high enough
        if ((b->fuel < 0.44*b->fuel_tank_capacity))
        {
            if (b->cargo != NULL && sellMove(b, b->cargo->commodity, b->cargo->quantity) == b->location) 
            {
                *action = ACTION_SELL;
                *n = maxSell(sellMove(b, b->cargo->commodity, b->cargo->quantity), b->cargo->quantity);
            }
            getFuel(b, action, n);
            return;
        }
        struct location* temp = buyMove(b);
        int count1 = 0; //counter for left moves
        int count2 = 0; //counter for right moves
        int countFinal = 0;
        
        //check is bot is at most profitable seller
        if (b->location == temp)
        {
            //want to find how much we can sell
            *n = maxBuy(b, sellMove(b, temp->commodity, temp->quantity));
            *action = ACTION_BUY;
            return;
        }   
        
        else //bot has to move
        {
            struct location* left = b->location->previous;
            struct location* right = b->location->next;
                
            do
            {
                if (left == temp)
                {
                    countFinal = count1-1;
                    break;
                }
                    
                if (right == temp)
                {
                    countFinal = count2+1;
                    break;
                }
                    
                left = left->previous;
                right = right->next;
                count2++;
                count1--;
            } while (left != right);
            
            if (left == right && left == temp)
            {
                countFinal = count2 + 1;
            }
            
            *action = ACTION_MOVE;
            *n = countFinal;
            return;
        }
    }
    
/*
    CASE 2
    Bot has something in cargo, and must go sell it at most profitable place
    Searches world for most profitable buyer of goods in cargo
*/
    else if (b->cargo->quantity > 0)
    {
        printf("Case 2 accessed\n");
        //checks if bot has enough fuel
        //dump(action, n, b);
        if ((b->fuel < 0.44*b->fuel_tank_capacity))
        {
            if (b->location->type == LOCATION_BUYER && b->cargo->commodity == b->location->commodity) 
            {
                *action = ACTION_SELL;
                *n = maxSell(sellMove(b, b->cargo->commodity, b->cargo->quantity), b->cargo->quantity);
                return;
            }
            printf("we've gone into fuel if\n");
            getFuel(b, action, n);
            return;
        }
        struct location* buyer = sellMove(b, b->cargo->commodity, b->cargo->quantity);
        
        if (buyer == NULL)
        {
            //DUMP FUNCTION
            printf("we got in here, time to fix\n");
            
        }
        
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

char *get_bot_name(void)
{
    return "The merchant of CSE";
}
