#ifndef _ARV_BIN_H
#define _ARV_BIN_H

#include <stdio.h>

#include <queue>

using namespace std;

typedef struct no{

	int info;
	struct no* left;
	struct no* right;

}Node;

typedef struct arv_bin{

	Node* root;

}Bin_tree;

Bin_tree* create_tree();

void free_tree(Bin_tree* tree);

void free_node(Node* no);

Node* binary_search(Node* r, int c);

Node* binary_search_iterative(Bin_tree* tree, int arg);

Bin_tree* tree_insertion(Bin_tree* t, int c);

Node* node_insertion(Node* no, int c);

void print_in_ord(Node* no);

void remove_binary_search(Bin_tree* r, int c);

Node* remove_node(Node* r, int c);

void remove_binary_search_successor(Bin_tree* r, int c);

Node* remove_node_successor(Node* r, int c);

int is_binary_search(Node* no);

void print_pos_ord(Node* root);

Node* binary_search_max_value(Node* r);

Node* binary_search_min_value(Node* r);

int tree_compare(Bin_tree* t,Bin_tree* b);

int node_compare(Node* t, Node* b);

int nodes_single_son(Node* r);

int sequence_in_tree(Bin_tree* t, queue <int>* f);

void kth_term_tree(Node* r,int* k);

#endif