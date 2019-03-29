#include "Bin_Tree.h"

#include <stdio.h>

#include <stdlib.h>

using namespace std;

Bin_tree* create_tree(){

	Bin_tree* t = (Bin_tree*) malloc(sizeof(Bin_tree));

	t->raiz = NULL;

	return t;
}

void free_tree(Bin_tree* tree){

	free_node(tree->raiz);
	free(tree);
}

void free_node(Node* no){
	if (no != NULL){
		free_node(no->left);
		free_node(no->right);
		free(no);
	}	
}

Node* binary_search(Node* r, char c){
	if (r == NULL || r->info == c){
		return r;
	}
	if (c < r->info){
		return binary_search(r->left,c);
	}
	else
		return binary_search(r->right,c);
	
}

Node* binary_search_iterative(Bin_tree* tree, char arg){
	
	Node* c;
	c = tree->raiz;

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

Bin_tree* tree_insertion(Bin_tree* t, char c){
	t->raiz = node_insertion(t->raiz,c);
}

Node* node_insertion(Node* no, char c){
	
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
		printf("%c ", no->info);
		print_in_ord(no->right);
	}
}

void remove_binary_search(Bin_tree* r, char c){
	
	r->raiz = remove_node(r->raiz, c);
	
}

Node* remove_node(Node* r, char c){

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