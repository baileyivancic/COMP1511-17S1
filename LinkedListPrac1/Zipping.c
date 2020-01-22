//Written by Bailey Ivancic  
    
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/*

given two lists, interleave them like so:

list1: 1 -> 2 -> 3 -> X
list2: 4 -> 5 -> 6 -> X

list1 = zip_lists(list1, list2);

list1: 1 -> 4 -> 2 -> 5 -> 3 -> 6 -> X
list2: 4 -> 2 -> 5 ... (you dont need to worry about this list)

Note: 
1) You should return a pointer to the head of the first list. 
2) You should zip all of your nodes into the first list.
	note: because of this type of list, we cannot set the 
	second list to null 
3) You do not need to create any new nodes or free any nodes.
	(ie do not call malloc() or free()) 
4) *HINT* The lists may not be the same length 
	(if both lists are empty, return NULL)  


    COMPILE WITH:
    
    gcc  -std=c99 -Wall -Werror -O -o test_zip list.c zip.c test_prac.c

    RUN WITH:
    ./test_zip
*/

struct node* zip_lists(struct node* l1, struct node* l2)
{
    if (l1 == NULL && l2 == NULL)
    {
        return NULL;
    }
    
    if (l1 == NULL)
    {
        return l2;
    }
    
    if (l2 == NULL)
    {
        return l1;
    }
    
    struct node* curr1 = l1;
    struct node* curr2 = l2;
    struct node* prev = NULL;
	
    while (curr2 != NULL)
    {
        if (curr2->next == NULL)
        {
            printf("entered break loop\n");
            prev = curr1;
            curr1 = curr1->next;
            prev->next = curr2;
            prev = prev->next;
            prev->next = curr1;
            break;
        }
        
        else
        {
            printf("entered non break loop\n");
            prev = curr1;
            curr1 = curr1->next;
            prev->next = curr2;
            curr2 = curr2->next;
            prev = prev->next;
            
            if (curr1 == NULL)
            {
                break;
            }
            
            else
            {
                prev->next = curr1; 
            }
        }
    }
    printf("passed this\n");
	// you need to return the head of l1, however, 
	// feel free to modify the return variable 
	// (as long as you return a pointer to l1!)
	return l1;
}