#include "Bin_Tree.h"

#include <stdio.h>

#include <stdlib.h>

#include <queue>

using namespace std;

int main(){
	
	int c, k, i;
	Bin_tree* t = create_tree();
	
	// Entering Values
	printf("1º Question \n");
	printf("Enter positive numbers to insert in a tree called T (enter with a negative one to stop): \n");
	scanf(" %d", &c);
	while(c > 0){
		tree_insertion(t,c);
		scanf(" %d", &c);
	}

	printf("\n\n");

	
	//Printing Tree in Inorder
	printf("T Inorder traverssal after insertion:\n");
	print_in_ord(t->root);


	remove_binary_search(t,30);
	printf("\n\n");

	printf("T Inorder traverssal after remove '30': \n");
	print_in_ord(t->root);
	printf("\n\n");


	printf("2º Question:\n");
	printf("Function 'remove' replacing the successor instead of the antecessor:\n");
	printf("Enter with a number to remove it from T:\n");
	scanf(" %d", &c);
	remove_binary_search(t, c);
	printf("\n\n");
	printf("T Inorder traverssal after removal:\n");
	print_in_ord(t->root); 
	printf("\n\n");


	printf("3º Question:\n");

	printf("T is a binary tree ?: ");
	if (is_binary_search(t->root)){
		printf("True");
	}
	else{
		printf("False");
	}
	printf("\n\n");

	printf("4º Question:\n");

	printf("The bigger value in T is : %d\n", binary_search_max_value(t->root)->info);
	printf("\n\n");

	printf("5º Question:\n");

	printf("The lesser value in T tree is: %d\n", binary_search_min_value(t->root)->info);
	printf("\n\n");

	printf("6º Question: \n");


	scanf("%d",&k);
	kth_term_tree(t->root,&k);
	printf("\n\n");
   

	printf("7º Question:\n");
	printf("Enter positive numbers to insert in a tree called B (enter with a negative one to stop): \n");
	Bin_tree* b = create_tree();
	scanf(" %d", &c);
	while(c > 0){
		tree_insertion(b,c);
		scanf(" %d", &c);
	}
	printf("T and B are equal?:");
	if (tree_compare(t,b)){
		printf("True\n");
	}
	else{
		printf("False\n");
	}
	printf("\n\n");

	printf("8º Question:\n");
	printf("Number of nodes with single connections in T: %d", nodes_single_son(t->root));
	printf("\n\n");

	printf("9º Question:\n");
	printf("Enter with the Preorder traverssal to build a tree called D (each number separated by space):\n");
	Bin_tree* d = create_tree();
	scanf(" %d", &c);
	while(c > 0){
		tree_insertion(d,c);
		scanf(" %d", &c);
	}
	printf("D Inorder traverssal after construction: \n");
	print_in_ord(d->root);
	printf("\n\n");

	printf("10º Question:\n");
	printf("Enter with a sequence of numbers to see if it is in the tree T: \n");
	
	queue <int> f;
	scanf("%d",&c);
	while(c >= 0){

		f.push(c);
		scanf("%d",&c);
	}

	if (sequence_in_tree(t,&f)){
		printf("It is in the tree T\n");
	}
	else{
		printf("It is not in the tree T\n");	
	}

	free_tree(t);
}