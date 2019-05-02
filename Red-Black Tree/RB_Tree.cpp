#include <iostream>
#include "RB_Tree.h"

using namespace std;

RB_Tree* create_tree(){

	RB_Tree* t = (RB_Tree*) malloc(sizeof(RB_Tree));
	Node* n = (Node*) malloc(sizeof(Node));
	n->color = 'B';
	n->info = 0;
	n->left = n->right = NULL;
	t->root = t->nil = n;
	return t;
}

void free_tree(RB_Tree* tree){
	free_node(tree,tree->root);
	free(tree->nil);
	free(tree);
}

void free_node(RB_Tree* T, Node* no){
	if (no != T->nil){
		free_node(T,no->left);
		free_node(T,no->right);
		free(no);
	}
}
void left_rotation(RB_Tree* T, Node* x){
	Node* y = x->right;
	x->right = y->left;
	if(y->left != T->nil){
		y->left->father = x;
	}
	y->father = x->father;
	if(x->father == T->nil){
		T->root = y;
	}
	else if(x == x->father->left){
		x->father->left = y;
	}
	else{
		x->father->right = y;
	}
	y->left = x;
	x->father = y;
}

void right_rotation(RB_Tree* T, Node* x){
	Node* y = x->left;
	x->left = y->right;
	if(y->right != T->nil){
		y->right->father = x;
	}
	y->father = x->father;
	if(x->father == T->nil){
		T->root = y;
	}
	else if(x == x->father->right){
		x->father->right = y;
	}
	else{
		x->father->left = y;
	}
	y->right = x;
	x->father = y;
}

void RB_insert_tree(RB_Tree* T, int z){
	Node* v = (Node*) malloc(sizeof(Node));
	v->info = z;
	RB_insert_node(T,v);
}

void RB_insert_node(RB_Tree* T, Node* z){

	Node* y = T->nil;
	Node* x = T->root;
	while(x != T->nil){
		y = x;
		if (z->info < x->info){
			x = x->left;
		}
		else{
			x = x->right;
		}
	}
	z->father = y;
	if (y == T->nil){
		T->root = z;
	}
	else if(z->info < y->info){
		y->left = z;
	}
	else{
		y->right =z;
	}
	z->left  = T->nil;
	z->right = T->nil;
	z->color  = 'R';
	RB_insert_fix(T,z);
}

void RB_insert_fix(RB_Tree* T, Node* z){

	while(z->father->color == 'R'){
		if (z->father == z->father->father->left){
			Node* y = z->father->father->right;
			if (y->color == 'R'){
				//Case 1 -
				//Recolora pai,tio e avô
				z->father->color = 'B';
				y->color = 'B';
				z->father->father->color = 'R';
				z = z->father->father;
			}
			else {
				//Case 2
				//Rotação simples e recoloração
				if (z == z->father->right){
					z = z->father;
					left_rotation(T,z);
				}
				//Case 3
				//Recoloração do avô e do pai e rotação
				z->father->color = 'B';
				z->father->father->color = 'R';
				right_rotation(T,z->father->father);
			}	
		}
		else{
			Node* y = z->father->father->left;
			if (y->color == 'R'){
				//Case 1 -
				//Recolora pai,tio e avô
				z->father->color = 'B';
				y->color = 'B';
				z->father->father->color = 'R';
				z = z->father->father;
			}
			else {
				//Case 2
				//Rotação simples e recolo
				if (z == z->father->left){
					z = z->father;
					right_rotation(T,z);
				}
				//Case 3
				//Recoloração do avô e do pai e rotação
				z->father->color = 'B';
				z->father->father->color = 'R';
				left_rotation(T,z->father->father);
			}	
		}
	}
	T->root->color = 'B';
}

void RB_transplant(RB_Tree* T,Node* u, Node* v){
	if (u->father == T->nil){
		T->root = v;
	}
	else if (u == u->father->left){
		u->father->left = v;
	}
	else{
		u->father->right = v;
		v->father = u->father;
	}

}

Node* tree_minimum(RB_Tree* T, Node* x){
	while(x->left != T->nil){
		x = x->left;
	}
	return x;
}

void RB_remove_tree(RB_Tree* T, int k){
	Node* z = RB_search(T,T->root,k);
	RB_remove_node(T,z);
}

void RB_remove_node(RB_Tree* T,Node* z){

	Node* x;
	Node* y = z;
	char y_original = y->color;
	if (z->left == T->nil){
		x = z->right;
		RB_transplant(T,z,z->right);
	}
	else if(z->right == T->nil){
		x = z->left;
		RB_transplant(T,z,z->left);
	}
	else{
		y = tree_minimum(T,z->right);
		y_original = y->color;
		x = y->right;
		if(y->father == z){
			x->father = y;
		}
		else{
			RB_transplant(T,y,y->right);
			y->right = z->right;
			y->right->father = y;
		}
		RB_transplant(T,z,y);
		y->left = z->left;
		y->left->father = y;
		y->color = z->color;
	}
	if(y_original == 'B'){
		RB_remove_fix(T,x);
	}
}

void RB_remove_fix(RB_Tree* T, Node* x){
	while(x != T->root && x->color == 'B'){
		if (x == x->father->left)
		{
			Node* w = x->father->right;
			if(w->color == 'R'){
				w->color = 'B';
				x->father->color = 'R';
				left_rotation(T,x->father);
				w = x->father->right;
			}

			if (w->left->color == 'B' && w->right->color == 'B'){
				w->color = 'R';
				x = x->father;
			}
			else{ 
				if(w->right->color == 'B'){
					w->left->color = 'B';
					w->color = 'R';
					right_rotation(T, w);
					w = x->father->right;
				}
				w->color = x->father->color;
				x->father->color = 'B';
				w->right->color = 'B';
				left_rotation(T,x->father);
				x = T->root;
			}
		}
		else{
			Node* w = x->father->left;
			if(w->color == 'R'){
				w->color = 'B';
				x->father->color = 'R';
				left_rotation(T,x->father);
				w = x->father->left;
			}

			if (w->right->color == 'B' && w->left->color == 'B'){
				w->color = 'R';
				x = x->father;
			}
			else{ 
				if(w->left->color == 'B'){
					w->right->color = 'B';
					w->color = 'R';
					right_rotation(T, w);
					w = x->father->left;
				}
				w->color = x->father->color;
				x->father->color = 'B';
				w->right->color = 'B';
				left_rotation(T,x->father);
				x = T->root;
			}
		}
	}
	x->color = 'B';
}

Node* RB_search(RB_Tree* T, Node* r, int k){
	if (r ==  T->nil || r->info == k){
		return r;
	}
	if (k < r->info){
		return RB_search(T,r->left,k);
	}
	else{
		return RB_search(T,r->right,k);
	}
}

void print_in_ord(RB_Tree* T,Node* root){
	if(root!= T->nil){
		print_in_ord(T,root->left);
		printf("(%d,%c) ", root->info, root->color);
		print_in_ord(T,root->right);
	}
}

void print_pos_ord(RB_Tree* T,Node* root){
	if(root != T->nil){
		print_pos_ord(T,root->left);
		print_pos_ord(T,root->right);
		printf("(%d,%c) ", root->info, root->color);
	}
}

void print_pre_ord(RB_Tree* T, Node* root){
	if(root != T->nil){
		printf("(%d,%c) ", root->info, root->color);
		print_pre_ord(T,root->left);
		print_pre_ord(T,root->right);
	}
}

