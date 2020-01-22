
#include <stdlib.h>
#include <stdio.h>

#include "list.h"

void test_empty_zip(void);
void test_simple_edges(void);
void test_typical_cases(void);

typedef struct node* node_ptr;


int main(int arg, char* argv[])
{

	printf("Testing zip_lists()...\n*** *** *** *** *** *** *** ***\n");
	test_empty_zip();
	test_simple_edges();
	test_typical_cases();


	printf("*** *** *** *** *** *** *** ***\nAll tests passed, you are awesome!\n");
	return 0;
}

void test_empty_zip(void)
{
	printf("Testing zip on an empty list...\n");

	node_ptr new = zip_lists(NULL, NULL);

	int rc = verify_list(NULL, 0, new);
	if(rc){
		printf("Testing zip on an empty list FAILED.\n");
		printf("  ->   Expected your list pointer to be NULL, but it had value: %p\n", new);
		exit(0);
	}



	printf("\tzipping empty lists \tPASSED.\n");

}



void test_simple_edges(void)
{
	printf("Testing some simple edge cases...\n");

	node_ptr l1 = NULL;
	node_ptr l2 = NULL;


	// 1 non empty, 1 empty
	l1 = append_node(l1, 1);
	l1 = zip_lists(l1, l2);

	int a1[1] = {1};
	int rc = verify_list(a1, 1, l1);
	if(rc){
		printf("Testing simple edge cases FAILED.\n");
		printf(" ->  Expected:\t" );
		print_array_as_list(a1, 1);
		printf(" ->  your list:\t" );
		print_list(l1);
		exit(0);
	}



	// different lengths
	l1 = append_node(l1, 2);
	l2 = append_node(l2, 3);

	l1 = zip_lists(l1,l2);

	int a2[3] = {1,3,2};
	rc = verify_list(a2, 3, l1);
	if(rc){
		printf("Testing simple edge cases FAILED.\n");
		printf(" ->  Expected:\t" );
		print_array_as_list(a2, 3);
		printf(" ->  your list:\t" );
		print_list(l1);
		exit(0);
	}

	destroy_list(l1);
	

	// very different lengths, in list 2
	node_ptr l3 = NULL;
	l3 = append_node(l3, 90);
	l3 = append_node(l3, 91);
	l3 = append_node(l3, 92);
	l3 = append_node(l3, 93);
	l3 = append_node(l3, 94);
	l3 = append_node(l3, 95);

	int a3[6] = {90,91,92,93,94,95};

	l3 = zip_lists(NULL, l3);

	rc = verify_list(a3, 6, l3);
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

	l4 = zip_lists(l4, l3);

	int a4[12] = {0, 90, 1, 91, 2, 92, 3, 93, 4, 94, 5, 95};
	
	rc = verify_list(a4, 12, l4);
	if(rc){
		printf("Testing simple edge cases FAILED.\n");
		printf(" ->  Expected:\t" );
		print_array_as_list(a4, 12);
		printf(" ->  your list:\t" );
		print_list(l3);
		exit(0);
	}
	destroy_list(l4);

	printf("\tsimple edge cases \tPASSED.\n");	

}


void test_typical_cases(void)
{
	printf("Testing some typical cases...\n");

	node_ptr l1 = NULL;
	node_ptr l2 = NULL;


	l1 = append_node(l1, 'a');
	l1 = append_node(l1, 'b');
	l1 = append_node(l1, 'c');
	l1 = append_node(l1, 'd');
	l1 = append_node(l1, 'e');
	l1 = append_node(l1, 'f');
	l1 = append_node(l1, 'g');
	l1 = append_node(l1, 'h');
	l1 = append_node(l1, 'i');
	l1 = append_node(l1, 'j');
	l1 = append_node(l1, 'k');
	l1 = append_node(l1, 'l');

	l2 = append_node(l2, 'z');
	l2 = append_node(l2, 'x');
	l2 = append_node(l2, 'y');

	l1 = zip_lists(l1, l2);


	int a1[15] = {'a','z','b','x','c','y','d','e','f','g','h','i','j','k','l'}; 
	int rc = verify_list(a1, 15, l1);
	if(rc){
		printf("Testing typical cases FAILED.\n");
		printf(" ->  Expected:\t" );
		print_array_as_list(a1, 15);
		printf(" ->  your list:\t" );
		print_list(l1);
		exit(0);
	}
	destroy_list(l1);

	node_ptr l3 = NULL;
	node_ptr l4 = NULL;



	l3 = append_node(l3, 'a');
	l3 = append_node(l3, 'b');
	l3 = append_node(l3, 'c');
	l3 = append_node(l3, 'd');
	l3 = append_node(l3, 'e');
	l3 = append_node(l3, 'f');
	l3 = append_node(l3, 'g');
	l3 = append_node(l3, 'h');
	l3 = append_node(l3, 'i');
	l3 = append_node(l3, 'j');
	l3 = append_node(l3, 'k');
	l3 = append_node(l3, 'l');

	l4 = append_node(l4, 'z');
	l4 = append_node(l4, 'x');
	l4 = append_node(l4, 'y');

	l3 = zip_lists(l4, l3);


	int a2[15] = {'z', 'a','x','b','y','c','d','e','f','g','h','i','j','k','l'}; 
	rc = verify_list(a2, 15, l3);
	if(rc){
		printf("Testing typical cases FAILED.\n");
		printf(" ->  Expected:\t" );
		print_array_as_list(a2, 15);
		printf(" ->  your list:\t" );
		print_list(l3);
		exit(0);
	}
	destroy_list(l3);

	printf("\ttypical cases    \tPASSED.\n");	
}