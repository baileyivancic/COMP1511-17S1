
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/*

given two ordered lists, merge them so that they make one ordered list,  like so:

EXAMPLE 1: 
list1: 1 -> 2 -> 3 -> X
list2: 4 -> 5 -> 6 -> X

merged = merge_in_order(list1, list2);

merged: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> X


EXAMPLE 2: 
list1: 1 -> 5 -> 7 -> X
list2: 2 -> 3 -> 4 -> X

merged = merge_in_order(list1, list2);

merged: 1 -> 2 -> 3 -> 4 -> 5 -> 7 -> X



Note: 
1) You should return a pointer to the head of the merged list. 
2) You should merge all of your nodes into the first list.
	note: because of this type of list, we cannot set the 
	second list to null 
3) You do not need to create any new nodes or free any nodes.
	(ie do not call malloc() or free()) 
4) *HINT* The lists may not be the same length 
	(if both lists are empty, return NULL)  


    COMPILE WITH:
    
    gcc  -std=c99 -Wall -Werror -O -o test_merged list.c merge.c test_prac.c

    RUN WITH:
    ./test_merge
*/


struct node* merge_in_order(struct node* l1, struct node* l2)
{
    if (l1 == NULL && l2 == NULL)
    {
        printf("first if statement\n");
        return NULL;
    }
    
    else if (l1 == NULL)
    {
        printf("second if statement\n");
        return l2;
    }
    
    else if (l2 == NULL)
    {
        printf("third if statement\n");
        return l1;
    }
	
	if (l1->data > l2->data)
	{
	    printf("swapped\n");
	    struct node* swap = l2;
	    l2 = l1;
	    l1 = swap;
	}

	struct node* curr1 = l1;
    struct node* curr2 = l2;
    struct node* prev = NULL;
    
    if (curr1->next == NULL)
    {
        printf("fourth if statement\n");
        return l1;
    }
    
    struct node* temp = curr1->next;
	printf("temp = %d\n", temp->data);
	printf("entered this bit\n");
	printf("Curr 1 = %d\n", curr1->data);
	printf("Curr 2 = %d\n", curr2->data);
	
	while (temp != NULL && curr2 != NULL)
    {
        if (curr2->data < curr1->data)
        {
            if (curr2->data < temp->data)
            {
            prev = curr2;
            printf("1\n");
            curr1->next = curr2;
            printf("2\n");
            curr1 = temp;
            printf("3\n");
            temp = temp->next;
            printf("4\n");
            curr1->next = temp;
            curr2 = curr2->next;
            prev->next = curr1;
            printf("5\n");
            }
            
            else
            {
                curr1 = curr1->next;
                temp = temp->next;
            }
        }
        
        else
        {
            curr1 = curr1->next;
            temp = temp->next;
        }   
    }
	
	if (temp == NULL && curr2->next != NULL)
	{
	    curr1->next = curr2;
	}   
	
	return l1;
}
