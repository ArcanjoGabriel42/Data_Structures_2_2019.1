#include <iostream>
#include "AVL.h"

using namespace std;

void menu_insert(AVL* T);
void menu_remove(AVL* T);
void menu_search(AVL* T);
void menu_print(AVL* T);

int main(){

	AVL* tree = create_tree();
	int n, h;
	while(1){

		printf("AVL TREE\n\n");
		printf("1 - Insert in the Tree\n");
		printf("2 - Remove from the Tree\n");
		printf("3 - Search in the Tree\n");
		printf("4 - Print the Tree\n");
		printf("5 - Exit from the Program\n");

		cin >> n; 
		switch(n){

			case 1: menu_insert(tree);break;
			case 2: menu_remove(tree);break;
			case 3: menu_search(tree);break;
			case 4: menu_print(tree);break;
			case 5: free_tree(tree);
					printf("Program Finished\n");
					return 0;
			default: printf("Invalid Option\n");

		}
		system("clear");
	}
	return 0;
}

void menu_insert(AVL* T){
	system("clear");
	int n,i,v;
	printf("How many numbers do you like to enter:\n");
	cin >> n;
	for (i = 0; i < n; ++i)
	{
		printf("Enter with the %d number:\n", (i+1));
		cin >> v;
		T->root = insert(T->root,v);
	}
	system("clear");
}

void menu_remove(AVL* T){
	system("clear");
	int n,i,v;
	printf("How many numbers do you like to remove:\n");
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		printf("Enter with the %d number:\n", (i+1));
		cin >> v;
		T->root = remove_node_avl(T->root,v);
	}
	system("clear");
}

void menu_search(AVL* T){
	system("clear");
	int n,i,v;
	char c;
	do{
		system("clear");
		printf("Enter with the number you like to consult\n");
		cin >> v;
		Node* y = avl_search(T->root,v);
		cout << "Info = " << y->info<< endl;
		cout << endl;
		cout << "Would you like to consult another one(y/n)?" <<endl;
		scanf(" %c",&c);
	}while(c != 'n');
	system("clear");
}

void menu_print(AVL* T){
	system("clear");
	int n;
	while(1){
		printf("Which traversal do you like to see:\n");
		printf("1 - Preorder\n");
		printf("2 - Inorder\n");
		printf("3 - Postorder\n");
		printf("4 - Print all traversals\n");
		printf("5 - Exit\n");
		cin >> n;
		system("clear");
		switch(n){

			case 1: printf("Preorder:\n");print_pre_ord(T->root);printf("\n\n");break;

			case 2: printf("Inorder:\n");print_in_ord(T->root);printf("\n\n");break;

			case 3: printf("Postorded:\n");print_pos_ord(T->root);printf("\n\n");break;

			case 4: printf("Preorder:\n");
					print_pre_ord(T->root);
					printf("\n");
					printf("Inorder:\n");
					print_in_ord(T->root);
					printf("\n");
					printf("Postorded:\n");
					print_pos_ord(T->root);
					printf("\n");
					break;

			case 5: return;
		}
	}
}