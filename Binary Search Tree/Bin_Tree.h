#ifndef _ARV_BIN_H
#define _ARV_BIN_H

#include <stdio.h>

using namespace std;

typedef struct no{

	char info;
	struct no* left;
	struct no* right;

}Node;

typedef struct arv_bin{

	Node* raiz;

}Bin_tree;

Bin_tree* create_tree();

void free_tree(Bin_tree* tree);

void free_node(Node* no);

Node* binary_search(Node* r, char c);

Node* binary_search_iterative(Bin_tree* tree, char arg);

Bin_tree* tree_insertion(Bin_tree* t, char c);

Node* node_insertion(Node* no, char c);

void print_in_ord(Node* no);

void remove_binary_search(Bin_tree* r, char c);

Node* remove_node(Node* r, char c);

#endif