#include "Bin_Tree.h"

#include <stdio.h>

#include <stdlib.h>

#include <queue>

using namespace std;

Bin_tree* create_tree(){

	Bin_tree* t = (Bin_tree*) malloc(sizeof(Bin_tree));

	t->root = NULL;

	return t;
}

void free_tree(Bin_tree* tree){

	free_node(tree->root);
	free(tree);
}

void free_node(Node* no){
	if (no != NULL){
		free_node(no->left);
		free_node(no->right);
		free(no);
	}	
}

Node* binary_search(Node* r, int c){
	if (r == NULL || r->info == c){
		return r;
	}
	if (c < r->info){
		return binary_search(r->left,c);
	}
	else
		return binary_search(r->right,c);
	
}

Node* binary_search_iterative(Bin_tree* tree, int arg){
	
	Node* c;
	c = tree->root;

	while(c != NULL){
		if (c->info == arg){
			return c;
		}
		else if (arg < c->info){
			c = c->left;
		}
		else{
			c = c->right;
		}
	}
	return NULL;
}

Bin_tree* tree_insertion(Bin_tree* t, int c){
	t->root = node_insertion(t->root,c);
}

Node* node_insertion(Node* no, int c){
	
	if (no == NULL){
		no = (Node*) malloc(sizeof(Node));
		no->info = c;
		no->left = NULL;
		no->right = NULL;
	}
	else if(c < no->info){
		no->left = node_insertion(no->left,c);
	}
	else{
		no->right = node_insertion(no->right,c);
	}
	return no;
}

void print_in_ord(Node* no){
	if (no != NULL){
		print_in_ord(no->left);
		printf("%d ", no->info);
		print_in_ord(no->right);
	}
}

void remove_binary_search(Bin_tree* r, int c){
	
	r->root = remove_node(r->root, c);	
}

Node* remove_node(Node* r, int c){

	if (r == NULL)
		return NULL;

	else if (c < r ->info){
		r->left = remove_node(r->left, c);
	}
	else if (c > r-> info){
		r->right = remove_node(r->right, c);
	}
	else{
		if (r->left == NULL && r->right == NULL){
			free (r);
			r = NULL;
		}

		else if (r ->left == NULL){
			Node* aux = r;
			r = r->right;
			free(aux);
		}
		else if(r->right == NULL){
			Node* aux = r;
			r = r->left;
			free(r);
		}
		else{
			Node* aux = r -> left;
			while(aux->right != NULL){
				aux = aux->right;
			}

			r->info = aux->info;
			aux->info = c;
			r->left = remove_node(r->left, c);
		}
	}
	return r;
}

void remove_binary_search_successor(Bin_tree* r, int c){
	
	r->root = remove_node_successor(r->root, c);	
}

Node* remove_node_successor(Node* r, int c){
	if (r == NULL)
		return NULL;

	else if (c < r ->info){
		r->left = remove_node(r->left, c);
	}
	else if (c > r-> info){
		r->right = remove_node(r->right, c);
	}
	else{
		if (r->left == NULL && r->right == NULL){
			free (r);
			r = NULL;
		}

		else if (r ->left == NULL){
			Node* aux = r;
			r = r->right;
			free(aux);
		}
		else if(r->right == NULL){
			Node* aux = r;
			r = r->left;
			free(r);
		}
		else{
			Node* aux = r -> right;
			while(aux->left != NULL){
				aux = aux->right;
			}

			r->info = aux->info;
			aux->info = c;
			r->right = remove_node(r->left, c);
		}
	}
	return r;
}

/**
 * [Print the Nodes in a Postorder Traversals]
 * @param root [Pointer to a Struct Node]
 */
void print_pos_ord(Node* root){

	if (root != NULL){
		print_pos_ord(root->left);
		print_pos_ord(root->right);
		printf("%d ", root->info);
	}
}

/**
 * [The function interpretate the Node passed in parameter, 
 * as a tree root, and verify if the analyzed tree is a Binary Search
 * Tree.]
 * @param  no [Pointer to a Struct Node]
 * @return    [return 0 or 1 (False or True)]
 */
int is_binary_search(Node* no){
	if (no == NULL){
		return 1;
	}
	if (no->right == NULL){
		return is_binary_search(no->left);
	}
	if (no->left == NULL){
		return is_binary_search(no->right);
	}
	if (no->info > no->right->info){
		return 0;
	}
	if (no->info < no->left->info){
		return 0;
	}
	else{
		return is_binary_search(no->left) && is_binary_search(no->right);
	}
}

Node* binary_search_max_value(Node* r){
	if(r != NULL){
		if (r->right == NULL){
			return r ;
		}
		return binary_search_max_value(r->right);
	}
}

Node* binary_search_min_value(Node* r){
	while(r->left != NULL){
		r = r->left;
	}
	return r;
}

void kth_term_tree(Node* r,int* k){

	if(r != NULL){
		kth_term_tree(r->left,k);
		(*k)--;
		if (*k == 0){
			printf("Kth Term is: %d\n", r->info);
		}
		else{
			
			kth_term_tree(r->right,k);
		}
	}
}

int tree_compare(Bin_tree* t,Bin_tree* b){

	return node_compare(t->root,b->root);	
}

int node_compare(Node* t, Node* b){
	if ((t == NULL) && (b == NULL)){
		return 1;
	}
	if ((t != NULL) && (b == NULL)|| (t == NULL) && (b != NULL)){
		return 0;
	}
	if (t->info != b->info){
		return 0;
	}
	else{

		int sae = node_compare(t->left,b->left);
		int sad = node_compare(t->right,b->right);
		return (sae && sad);
	}
}

int nodes_single_son(Node* r){
	if(r == NULL){
		return 0;
	}
	if ((r->left != NULL) && (r->right == NULL)|| (r->left == NULL) && (r->right != NULL)){

		return 1 + nodes_single_son(r->right) + nodes_single_son(r->left);
	}
	else{
		return 0 + nodes_single_son(r->right) + nodes_single_son(r->left);
	}
}

int sequence_in_tree(Bin_tree* t, queue <int>* f){

	Node* n;
	do{
		n = binary_search(t->root,f->front());
		f->pop();
	}while ((n != NULL) && (!f->empty()));

	if (n){
		return 1;
	}
	else{
		return 0;
	}
}