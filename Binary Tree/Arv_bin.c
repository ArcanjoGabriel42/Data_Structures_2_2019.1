#include <stdio.h>
#include <stdlib.h>
#include "Arv_bin.h"

Arv_bin* arv_cria(Nodo* raiz){

	Arv_bin* arv = (Arv_bin*) malloc(sizeof(Arv_bin));

	arv->raiz = raiz;
	return arv;
}

Nodo* arv_cria_no(char c,Nodo* esq,Nodo* dir){
	
	Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));

	nodo->esq = esq;
	nodo->dir = dir;
	nodo->info = c;
	return nodo;
}

void arv_bin_ord(Arv_bin* arv, int ordem){

	switch(ordem){

	case 1:

		print_pre_ord(arv->raiz);

	break;

	case 2:

		print_in_ord(arv->raiz);

	break;

	case 3:

		print_pos_ord(arv->raiz);

	break;

	default:

		printf("Numero de ordem invalido\n");
	}

}


void print_pre_ord(Nodo* raiz){
	
	
	if (raiz != NULL){

		printf("%c ", raiz->info);

		print_pre_ord(raiz->esq);

		print_pre_ord(raiz->dir);
	}
}

void print_in_ord(Nodo* raiz){
	
	if (raiz != NULL){
		print_pre_ord(raiz->esq);
		printf("%c ", raiz->info);
		print_pre_ord(raiz->dir);
	}
}

void print_pos_ord(Nodo* raiz){

	if (raiz != NULL){
		print_pre_ord(raiz->esq);
		print_pre_ord(raiz->dir);
		printf("%c ", raiz->info);
	}

}

void print_format_arv(Arv_bin* arv){

	print_format_no(arv->raiz);

}

void print_format_no(Nodo* raiz){	
	printf("<");
	if (raiz != NULL){

		printf("%c", raiz->info);

		print_format_no(raiz->esq);

		print_format_no(raiz->dir);
	}
	printf(">");
}


void free_arv(Arv_bin* arv){

	free_nodo(arv->raiz);
	free(arv);
}

void free_nodo(Nodo* raiz){

	if (raiz != NULL){
		free_nodo(raiz->esq);
		free_nodo(raiz->dir);
		free(raiz);
	}
}

int arv_pertence(Arv_bin* arv, char c){

	return arv_pertence_no(arv->raiz, c);
}

int arv_pertence_no(Nodo* raiz, char c){

	if (raiz == NULL){
		return 0;
	}
	if (raiz->info == c){
		return 1;
	}
	if (arv_pertence_no(raiz->esq,c)){
		return 1;
	}
	return arv_pertence_no(raiz->dir,c);
}

Nodo* arv_busca(Arv_bin* arv, char c){

	arv_busca_no(arv->raiz, c);
}

Nodo* arv_busca_no(Nodo* raiz, char c){

	if (raiz == NULL){
		return raiz;
	}
	if (raiz->info == c){
		return raiz;
	}
	if(arv_busca_no(raiz->esq,c)){
		return raiz->esq;
	}
	else{
		return arv_busca_no(raiz->dir,c);
	}
}

int arv_altura(Arv_bin* arv){

	arv_altura_no(arv->raiz);

}

int arv_altura_no(Nodo* no){

	if (no == NULL){
		return -1;
	}
	else{

		int sae = arv_altura_no(no->esq);
		int sad = arv_altura_no(no->dir);
		return 1 + (sae > sad ? sae : sad);
	}

}
