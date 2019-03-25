#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Arv_bin.h"

using namespace std;

int main()
{

	char v;
	Arv_bin* arv = arv_cria(
				    arv_cria_no('a',
							
							arv_cria_no('b',
								
								arv_cria_no('d',NULL,NULL),
								
								arv_cria_no('e',NULL,NULL)
								),
							
							arv_cria_no('c',
								
								arv_cria_no('f',NULL,NULL),
								
								arv_cria_no('g',NULL,NULL)
								)
							)
						);
	printf("Preorder\n");
	arv_bin_ord(arv,1);
	printf("\n\n");
	
	printf("Inorder\n");
	arv_bin_ord(arv,2);
	printf("\n\n");
	
	printf("Postorder\n");
	arv_bin_ord(arv,3);
	printf("\n\n");

	printf("Formatted\n");
	print_format_arv(arv);
	printf("\n\n");

	printf("Enter with a a letter to know if it is in the Tree: ");
	scanf("%c", &v);

	if (arv_pertence(arv,v)){
		printf("%c is in the Tree\n\n",v);
	}else{
		printf("%c is not in the Tree\n\n",v);
	}


	printf("Enter with other to search for it, and retrieve its node: ");
	scanf(" %c", &v);

	Nodo* s = arv_busca(arv,v);
	if (s){
		
		printf("Node retrieved\n");
		if (s->esq){
			printf("Its left value is: %c\n\n", s->esq->info);
		}
		if (s->dir){
			printf("Its right value is: %c\n\n", s->dir->info);
		}
	}else{
		printf("It is not in the Tree\n");
	}

	printf("Tree Height:%d\n\n", arv_altura(arv));

	printf("Number of nodes: %d\n\n", tamanho(arv));

	printf("Breadth-first search(BFS): ");
	perc_larg(arv->raiz);
	printf("\n\n");

	printf("Mirror Tree:\n");
	print_format_arv(esp(arv));
	printf("\n\n");

	printf("Preorder Iterative:\n");
	print_pre_ord_iter(arv);
	printf("\n\n");

	printf("Inorder Iterative :\n");
	print_in_ord_iter(arv);
	printf("\n\n");

	printf("Postorder Iterative:\n");
	print_pos_ord_iter(arv);
	printf("\n\n");

	printf("Number of Leaves: ");
	printf("%d\n\n", folha_arv(arv));

	if(arv_estr_bin(arv)){
		printf("It is Binary\n\n");
	}
	else{
		printf("It is not Binary\n\n");
	}

	if(arv_bin_compl(arv)){
		printf("It is Complete\n\n");
	}
	else{
		printf("It is not Complete\n\n");
	}

	free_arv(arv);
	return 0;
}