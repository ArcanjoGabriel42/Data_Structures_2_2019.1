#include <stdio.h>
#include <stdlib.h>
#include "Arv_bin.h"

int main(int argc, char const *argv[])
{
	char v;
	Arv_bin* arv = arv_cria(
				    arv_cria_no('a',
							
							arv_cria_no('b',
								
								NULL,
								
								arv_cria_no('d',NULL,NULL)
								),
							
							arv_cria_no('c',
								
								arv_cria_no('e',NULL,NULL),
								
								arv_cria_no('f',NULL,NULL)
								)
							)
						);
	printf("Pre Ordem\n");
	arv_bin_ord(arv,1);
	printf("\n");
	
	printf("In Ordem\n");
	arv_bin_ord(arv,2);
	printf("\n");
	
	printf("Pos Ordem\n");
	arv_bin_ord(arv,3);
	printf("\n");

	printf("Formatado\n");
	print_format_arv(arv);

	printf("\nEntre com uma letra: ");
	scanf("%c", &v);

	if (arv_pertence(arv,v)){
		printf("Está na Árvore\n");
	}else{
		printf("Não está na árvore\n");
	}
	Nodo* s = arv_busca(arv,v);
	if (s){
		
		printf("Está na Árvore\n");
		if (s->esq != NULL){
			printf("O valor a esquerda é %c\n", s->esq->info);
		}
		if (s->dir){
			printf("O valor a direita é %c\n", s->dir->info);
		}
	}else{
		printf("Não está na árvore\n");
	}

	printf("Altura da árvore é:%d\n", arv_altura(arv));

	free_arv(arv);
	return 0;
}