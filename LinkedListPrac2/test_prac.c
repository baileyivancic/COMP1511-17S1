
#include <stdlib.h>
#include <stdio.h>

#include "list.h"

void test_empty_merge(void);
void test_simple_merges(void);
void test_typical_cases(void);

typedef struct node* node_ptr;


int main(int arg, char* argv[])
{

	printf("Testing merge_in_order()...\n*** *** *** *** *** *** *** ***\n");
	test_typical_cases();
	test_empty_merge();
	test_simple_merges();

	// add more tests here

	printf("*** *** *** *** *** *** *** ***\nAll tests passed, you are awesome!\n");
	return 0;
}

void test_typical_cases(void)
{
	printf("Testing some typical cases...\n");

	node_ptr l1 = NULL;
	node_ptr l2 = NULL;


	l1 = append_node(l1, 1);
	l1 = append_node(l1, 2);
	l1 = append_node(l1, 3);
	l1 = append_node(l1, 4);
	l1 = append_node(l1, 5);
	l1 = append_node(l1, 6);
	l1 = append_node(l1, 7);
	l1 = append_node(l1, 8);
	l1 = append_node(l1, 9);
	l1 = append_node(l1, 10);
	l1 = append_node(l1, 11);
	l1 = append_node(l1, 12);

	l2 = append_node(l2, 13);
	l2 = append_node(l2, 14);
	l2 = append_node(l2, 15);

	node_ptr merged_1 = merge_in_order(l1, l2);


	int a1[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; 
	int rc = verify_list(a1, 15, merged_1);
	if(rc){
		printf("Testing typical cases FAILED.\n");
		printf(" ->  Expected:\t" );
		print_array_as_list(a1, 15);
		printf(" ->  your list:\t" );
		print_list(merged_1);
		exit(0);
	}
	destroy_list(merged_1);




	node_ptr l3 = NULL;
	node_ptr l4 = NULL;


	l3 = append_node(l3, 1);
	l3 = append_node(l3, 3);
	l3 = append_node(l3, 5);
	l3 = append_node(l3, 7);
	l3 = append_node(l3, 9);
	l3 = append_node(l3, 11);
	l3 = append_node(l3, 13);
	l3 = append_node(l3, 15);
	l3 = append_node(l3, 17);
	l3 = append_node(l3, 19);
	l3 = append_node(l3, 21);
	l3 = append_node(l3, 23);

	l4 = append_node(l4, 2);
	l4 = append_node(l4, 4);
	l4 = append_node(l4, 6);

	node_ptr merged_2 = merge_in_order(l4, l3);


	int a2[15] = {1,2,3,4,5,6,7,9,11,13,15,17,19,21,23}; 
	rc = verify_list(a2, 15, merged_2);
	if(rc){
		printf("Testing typical cases FAILED.\n");
		printf(" ->  Expected:\t" );
		print_array_as_list(a2, 15);
		printf(" ->  your list:\t" );
		print_list(merged_2);
		exit(0);
	}
	destroy_list(merged_2);

	printf("\ttypical cases    \tPASSED.\n");	
}


void test_empty_merge(void)
{
	printf("Testing zip on an empty list...\n");

	node_ptr new = merge_in_order(NULL, NULL);

	int rc = verify_list(NULL, 0, new);
	if(rc){
		printf("Testing zip on an empty list FAILED.\n");
		printf("  ->   Expected your list pointer to be NULL, but it had value: %p\n", new);
		exit(0);
	}

	printf("\tmerging empty lists \tPASSED.\n");

}



void test_simple_merges(void)
{
	printf("Testing some simple edge cases...\n");

	node_ptr l1 = NULL;
	node_ptr l2 = NULL;


	// 1 non empty, 1 empty
	l1 = append_node(l1, 1);
	node_ptr merged_1 = merge_in_order(l1, l2);

	int a1[1] = {1};
	int rc = verify_list(a1, 1, merged_1);
	if(rc){
		printf("Testing simple edge cases FAILED.\n");
		printf(" ->  Expected:\t" );
		print_array_as_list(a1, 1);
		printf(" ->  your list:\t" );
		print_list(merged_1);
		exit(0);
	}



	// different lengths
	l1 = append_node(l1, 2);
	l2 = append_node(l2, 3);

	node_ptr merged_2 = merge_in_order(l1,l2);

	int a2[3] = {1,2,3};
	rc = verify_list(a2, 3, merged_2);
	if(rc){
		printf("Testing simple edge cases FAILED.\n");
		printf(" ->  Expected:\t" );
		print_array_as_list(a2, 3);
		printf(" ->  your list:\t" );
		print_list(merged_2);
		exit(0);
	}

	destroy_list(merged_2);
	

	// very different lengths, in list 2
	node_ptr l3 = NULL;
	l3 = append_node(l3, 90);
	l3 = append_node(l3, 91);
	l3 = append_node(l3, 92);
	l3 = append_node(l3, 93);
	l3 = append_node(l3, 94);
	l3 = append_node(l3, 95);

	int a3[6] = {90,91,92,93,94,95};

	node_ptr merged_3 = merge_in_order(NULL, l3);

	rc = verify_list(a3, 6, merged_3);
	if(rc){
		printf("Testing simple edge cases FAILED.\n");
		printf(" ->  Expected:\t" );
		print_array_as_list(a3, 6);
		printf(" ->  your list:\t" );
		print_list(l3);
		exit(0);
	}

	node_ptr l4 = NULL;

	l4 = append_node(l4, 0);
	l4 = append_node(l4, 1);
	l4 = append_node(l4, 2);
	l4 = append_node(l4, 3);
	l4 = append_node(l4, 4);
	l4 = append_node(l4, 5);

	node_ptr merged_4 = merge_in_order(l4, l3);

	int a4[12] = {0,1,2,3,4,5,90,91,92,93,94,95};
	
	rc = verify_list(a4, 12, merged_4);
	if(rc){
		printf("Testing simple edge cases FAILED.\n");
		printf(" ->  Expected:\t" );
		print_array_as_list(a4, 12);
		printf(" ->  your list:\t" );
		print_list(merged_4);
		exit(0);
	}
	destroy_list(merged_4);

	printf("\tsimple edge cases \tPASSED.\n");	

}


