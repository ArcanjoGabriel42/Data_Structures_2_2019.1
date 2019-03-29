#include "Bin_Tree.h"

#include <stdio.h>

#include <stdlib.h>

using namespace std;

int main(){
	char c;
	Bin_tree* t = create_tree();
	printf("Enter some letters to insert in the tree(enter with 0 to stop): \n");
	scanf(" %c", &c);
	while(c != '0'){
		tree_insertion(t,c);
		scanf(" %c", &c);
	}
	printf("\n");
	
	
	printf("Enter with a letter to search for it in the tree: \n");
	scanf(" %c",&c);
	Node* n = binary_search_iterative(t,c);
	if (n != NULL){
		printf("It is in the tree\n\n");
	}
	else{
		printf("Unable to find\n\n");
	}
	
	print_in_ord(t->raiz);
	printf("\n\n");

	printf("Now enter with a letter to remove it from the tree: \n");
	scanf(" %c",&c);
	remove_binary_search(t,c);
	printf("\n\n");

	print_in_ord(t->raiz);

	free_tree(t);
}