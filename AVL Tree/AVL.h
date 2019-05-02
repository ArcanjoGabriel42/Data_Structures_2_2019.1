#ifndef _AVL_H
#define _AVL_H

#include <stdio.h>

typedef struct no{

	int info;
	int height;
	struct no* left;
	struct no* right;

}Node;

typedef struct arv_bin{

	Node* root;

}AVL;

AVL* create_tree();

void free_tree(AVL* tree);

void free_node(Node* no);

Node* new_node(int k);

int balance_factor_node(Node* root);

int height(Node* p);

Node* insert(Node* root, int k);

Node* right_rotation(Node* y);

Node* left_rotation(Node* x);

Node* remove_node_avl(Node* r, int k);

int max(int a, int b);

Node* avl_search(Node* n, int k);

void print_pre_ord(Node* root);

void print_in_ord(Node* root);

void print_pos_ord(Node* root);

#endif