#ifndef _RB_TREE_H
#define _RB_TREE_H

#include <stdio.h>
	
typedef struct No{
	No* father;
	No* right;
	No* left;
	char color;
	int info;
		
}Node;

typedef struct arv
{
	Node* root;
	Node* nil;
}RB_Tree;

RB_Tree* create_tree();

void free_tree(RB_Tree* tree);

void free_node(RB_Tree* T, Node* no);

void RB_insert_tree(RB_Tree* T, int z);

void RB_insert_node(RB_Tree* T, Node* z);

void RB_transplant(RB_Tree* T, Node* u, Node* v);

Node* tree_minimum(RB_Tree* T, Node* x);

void RB_remove_tree(RB_Tree* T,int k);

void RB_remove_node(RB_Tree* T,Node* z);

void left_rotation(RB_Tree* T, Node* x);

void right_rotation(RB_Tree* T, Node* x);

void RB_insert_fix(RB_Tree* T, Node* z);

void RB_remove_fix(RB_Tree* T, Node* x);

Node* RB_search(RB_Tree* T,Node* r, int k);

void print_pre_ord(RB_Tree* T,Node* root);

void print_in_ord(RB_Tree* T,Node* root);

void print_pos_ord(RB_Tree* T,Node* root);


#endif