#include <iostream>
#include "RB_Tree.h"

using namespace std;

void menu_insert(RB_Tree* T){
	system("clear");
	int n,i,v;
	printf("How many numbers do you like to enter:\n");
	cin >> n;
	for (i = 0; i < n; ++i)
	{
		printf("Enter with the %d number:\n", (i+1));
		cin >> v;
		RB_insert_tree(T,v);
	}
	system("clear");
}

void menu_remove(RB_Tree* T){
	system("clear");
	int n,i,v;
	printf("How many numbers do you like to remove:\n");
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		printf("Enter with the %d number:\n", (i+1));
		cin >> v;
		RB_remove_tree(T,v);
	}
	system("clear");
}

void menu_search(RB_Tree* T){
	system("clear");
	int n,i,v;
	char c;
	do{
		printf("Enter with the number you like to consult\n");
		cin >> v;
		Node* y = RB_search(T,T->root,v);
		cout << "Info = " << y->info <<"\nColor = "<< y->color <<endl;
		cout << endl;
		cout << "Would you like to consult another one(y/n)?" <<endl;
		scanf(" %c",&c);
	}while(c != 'n');
	system("clear");
}

void menu_print(RB_Tree* T){
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

			case 1: printf("Preorder:\n");print_pre_ord(T,T->root);printf("\n\n");break;

			case 2: printf("Inorder:\n");print_in_ord(T,T->root);printf("\n\n");break;

			case 3: printf("Postorded:\n");print_pos_ord(T,T->root);printf("\n\n");break;

			case 4: printf("Preorder:\n");
					print_pre_ord(T,T->root);
					printf("\n");
					printf("Inorder:\n");
					print_in_ord(T,T->root);
					printf("\n");
					printf("Postorded:\n");
					print_pos_ord(T,T->root);
					printf("\n");
					break;

			case 5: return;
		}
	}
}