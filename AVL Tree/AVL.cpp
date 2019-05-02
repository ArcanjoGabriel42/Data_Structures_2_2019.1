#include <iostream>
#include "AVL.h"

using namespace std;

AVL* create_tree(){
	AVL* tree = (AVL*) malloc(sizeof(AVL));
	tree->root = NULL;
	return tree;
}

void free_tree(AVL* tree){
	free_node(tree->root);
	free(tree);
}

void free_node(Node* no){
	if(no != NULL){
		free_node(no->left);
		free_node(no->right);
		free(no);
	}
}

Node* new_node(int k){
	Node* n = (Node*) malloc(sizeof(Node));
	n->info = k;
	n->left = NULL;
	n->right = NULL;
	n->height = 0;
	return n;
}

int balance_factor_node(Node* root){
	if(root == NULL){
		return 0;
	}
	return height(root->right) - height(root->left);
}

int height(Node* p){
	if(p == NULL){
		return -1;
	}
	return p->height;
}

Node* insert(Node* root, int k){
	if(root == NULL){
		return (new_node(k));
	}
	if(k < root->info){
		root->left = insert(root->left, k);
	}
	else if(k > root->info){
		root->right = insert(root->right,k);
	}
	else{
		return root;
	}

	root->height = 1 + max(height(root->left),height(root->right));

	int balance_factor = balance_factor_node(root);

	//Left Left Case
	if(balance_factor < -1 && k < root->left->info){
		return right_rotation(root);
	}
	//Right Right Case
	if(balance_factor > 1 && k > root->right->info){
		return left_rotation(root);
	}
	//Left Right Case
	if(balance_factor < -1 && k > root->left->info){
		root->left = left_rotation(root->left);
		return right_rotation(root);
	}
	//Right Left Case
	if(balance_factor > 1 && k < root->right->info){
		root->right = right_rotation(root->right);
		return left_rotation(root);
	}
	return root;
}

Node* right_rotation(Node* y){

	Node* x = y->left;
	Node* T2 = x->right;

	x->right = y;
	y->left  = T2;

	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	return x;
}

Node* left_rotation(Node* x){

	Node* y = x->right;
	Node* T2 = y->left;

	y->left  = x;
	x->right = T2;

	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	return y;
}

Node* remove_node_avl(Node* r, int k){
	if (r == NULL){
		return NULL;
	}
	else if(k < r->info){
		r->left  = remove_node_avl(r->left,k);
	}
	else if(k > r->info){
		r->right = remove_node_avl(r->right,k);
	}
	else{
		if(r->left == NULL && r->right == NULL){
			free(r);
			r = NULL;
		}
		else if(r->left == NULL){
			Node* aux = r;
			r = r->right;
			free(aux);
		}
		else if(r->right == NULL){
			Node* aux = r;
			r = r->left;
			free(aux);
		}
		else{
			Node* aux = r->left;
			while(aux->right != NULL){
				aux = aux->right;
			}
			r->info = aux->info;
			aux->info = k;
			r->left = remove_node_avl(r->left,k);
		}
	}
	if(r == NULL){
		return r;
	}

	r->height = 1 + max(height(r->left),height(r->right));

	int balance_factor = balance_factor_node(r);

	//Left Left Case
	if(balance_factor < -1 && balance_factor_node(r->left) <= 0){
		return right_rotation(r);
	}
	//Left Right Case
	if(balance_factor < -1 && balance_factor_node(r->left) > 0){
		r->left = left_rotation(r->left);
		return right_rotation(r);
	}
	//Right Right Case
	if(balance_factor > 1 && balance_factor_node(r->right) >= 0){
		return left_rotation(r);
	}
	//Right Left Case
	if(balance_factor > 1 && balance_factor_node(r->right) < 0){
		r->right = right_rotation(r->right);
		return left_rotation(r);
	}

	return r;
}

int max(int a, int b){
	return (a > b)? a : b;
}

void print_in_ord(Node* root){
	if(root != NULL){
		print_in_ord(root->left);
		printf("%d ", root->info);
		print_in_ord(root->right);
	}
}

void print_pos_ord(Node* root){
	if(root != NULL){
		print_pos_ord(root->left);
		print_pos_ord(root->right);
		printf("%d ", root->info);
	}
}

void print_pre_ord(Node* root){
	if(root != NULL){
		printf("%d ", root->info);
		print_pre_ord(root->left);
		print_pre_ord(root->right);
	}
}

Node* avl_search(Node* n, int k){
	if (n == NULL || n->info == k){
		return n;
	}
	else if(k < n->info){
		return avl_search(n->left,k);
	}
	else{
		return avl_search(n->right,k);
	}
}
