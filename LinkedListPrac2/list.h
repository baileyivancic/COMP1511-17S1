#ifndef LIST_H_
#define LIST_H_

struct node
{
	struct node* next;
	int data;
};

struct node* create_node(int value);
struct node* append_node(struct node* list, int value);
struct node* prepend_node(struct node* old_head, int value);

int destroy_node(struct node* node);
int destroy_list(struct node* list);

void print_list(struct node* head);
void print_array_as_list(int* array, int size);

int list_length(struct node* l);
int verify_list(int* array, int size, struct node* l);

struct node* merge_in_order(struct node* l1, struct node* l2);


#endif // LIST_H_