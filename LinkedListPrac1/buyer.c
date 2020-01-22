//Used for case 1
//Finds most profitable commodity to buy, and the most profitable place to buy from
struct buyMove(struct bot* b)
{
    struct bot* runner = b->location; //this bot will go through commodities
    struct bot* seller = NULL; //stores most profitable seller
    int profit = 0; //how much we can buy * price we can sell for
    int temp = 0;
    
    do
    {
        if (runner->type == LOCATION_SELLER)
        {
            struct bot* check = b->location; //this bot will check profit at all buyers of that commodity
            int amount = maxBuy(b->maximum_cargo_weight, b->maximum_cargo_volume, b->cash, runner->price, runner->quantity, runner->commodity->weight, runner->commodity->volume);
            do
            {
                if (check->type == LOCATION_BUYER && check->commodity == runner->commodity)
                {
                    //Now know that check if a buyer of our commodity
                    //Must check how much profit we will have from selling to this vendor
                    if (amount > maxSell(check->quantity, amount))
                    {
                        amount = maxSell(check->quantity, amount);
                    }
                    temp = amount*(check->price) - amount*(runner->price)
                    if (temp > profit) //checks is vendor will give most profit so far
                    {
                        profit = temp;
                        seller = runner;
                    }
                }
            check = check->next; 
            } while (check != b->location);
        }
        runner = runner->next;
    } while (runner != b->location); 
    return seller;
}