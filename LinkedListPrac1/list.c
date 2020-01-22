#include <stdio.h>
#include <stdlib.h>

#include "list.h"


#define debug_print(X, fmt, ...) \
            do { if (X) fprintf(stderr, fmt, __VA_ARGS__); } while (0)


// create a node
struct node* create_node(int value)
{
	
	// allocate heap memory to store 
	struct node* new_node = malloc(sizeof(struct node));

	if(new_node == NULL)
	{
		printf("%s: error: failed to allocate memory for new node.\n", __func__);
		return NULL;
	}


	// need to initialise our structs variables (just like any other variables!)
	new_node->next = NULL;
	new_node->data = value;


	// since the node is in allocated memory, we can return a pointer to it safely
	return new_node;
}


// add a node to the end of the list
struct node* append_node(struct node* head, int value)
{
	// empty list case
	if(head == NULL){
		head = create_node(value);
	
	// list is not empty...
	} else {
		
		// need to iterate to end of list
		struct node* curr = head;
		while(curr->next != NULL){
			curr = curr->next;
		}

		// now add node to end (our curr should be pointing to the last node)
		curr->next = create_node(value);
	}

	return head;
}


// add a node to the front of the list
struct node* prepend_node(struct node* old_head, int value)
{
	struct node* new_head = create_node(value);
	new_head->next = old_head;

	return new_head;
}



// clean up and free a single node
int destroy_node(struct node* node)
{
	if(node == NULL)
	{
		printf("%s: error: node pointer was NULL.\n", __func__);
		return -1;
	}

	// optionally zero out data in node
	node->data = 0;

	free(node);
	return 0;
}


// clean up and destroy a list (this will clean/destroy each node in the list)
int destroy_list(struct node* list)
{
	if(list == NULL)
	{
		//printf("%s: error: list pointer was NULL.\n", __func__);
		return -1;
	}

	// create a pointer to the head of our list ( that we can use to iterate through )
	
	struct node* curr = list;
    struct node* prev = NULL;

	while( curr != NULL)
	{	
		prev = curr;
		curr = curr->next;
		destroy_node(prev);
	}

	return 0;
}

void print_list(struct node* head)
{
	/*
	if(head == NULL){
		printf("%s: error: list was NULL\n", __func__);
		return;
	}
	*/

	struct node* current = head;

	while(current != NULL){
		printf("[%d]->", current->data);
		current = current->next;
	}
	printf("[X]\n");
}


int list_length(struct node* l)
{
	struct node* curr = l;
	int i = 0;
	while(curr != NULL){
		curr = curr->next;
		i++;
	}

	return i;
}

// return 0 on identical lists
// return -1 otherwise
int verify_list(int* array, int size, struct node* l)
{

	int list_len = list_length(l);
	
	if(list_len != size ){
		return -1;
	}


	struct node* curr = l;
	int i = 0;
	
	while( (l != NULL) && (i < size) ){
		if(curr->data != array[i]){
			return -1;
		}
		i++;
		curr=curr->next;
	}

	return 0;
}

void print_array_as_list(int* array, int size)
{
	int i = 0;
	while(i < size){
		printf("[%d]->", array[i]);
		i++;
	}
	printf("[X]\n");

}
