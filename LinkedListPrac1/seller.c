//Used for case 2
//Bot has something in cargo, and must sell it at most pofitable place
struct sellMove(struct bot* b)
{
    struct bot* left = b->previous;
    struct bot* right = b->next;
    struct bot* buyer = NULL;
    int profit = 0;
    int temp = 0;
    
    //checks if can sell at current location
    if (b->location->type == LOCATION_BUYER && 
        !strcmp(b->location->commodity->name, b->cargo->commodity->name))
    {
        temp = maxSell(left->location->quantity) * (left->location->price);
        profit = temp;
        buyer = b;
    }
    
    while (left->location != right->location)
    {
        if (left->location->type == LOCATION_BUYER &&
            !strcmp(left->location->commodity->name, b->cargo->commodity->name))
        {
            temp = maxSell(left->location->quantity) * (left->location->price);
            if (temp > profit) //this is most profitable location so far
            {
                buyer = left;
                profit = temp;
            }
        }
        
        if (right->location->type == LOCATION_BUYER &&
            !strcmp(right->location->commodity->name, b->cargo->commodity->name))
        {
            temp = maxSell(right->location->quantity) * (right->location->price);
            if (temp > profit) //this is most profitable location so far
            {
                buyer = right;
                profit = temp;
            }
        }
        left = left->previous;
        right = right->next;
    }
    return buyer;
}