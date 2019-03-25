#ifndef _ARV_BIN_H
#define _ARV_BIN_H

#include <stdio.h>

typedef struct no{

	char info;
	struct no* esq;
	struct no* dir;

}Nodo;

typedef struct arv_bin{

	Nodo* raiz;

}Arv_bin;

Arv_bin* arv_cria(Nodo* raiz);

Nodo* arv_cria_no(char c,Nodo* esq,Nodo* dir);

void  arv_bin_ord(Arv_bin* arv, int ordem);

void print_pre_ord(Nodo* raiz);

void print_in_ord(Nodo* raiz);

void print_pos_ord(Nodo* raiz);

void print_format_no(Nodo* raiz);

void print_format_arv(Arv_bin* arv);

void free_arv(Arv_bin* arv);

void free_nodo(Nodo* raiz);

int arv_pertence(Arv_bin* arv, char c);

int arv_pertence_no(Nodo* raiz, char c);

Nodo* arv_busca(Arv_bin* arv, char c);

Nodo* arv_busca_no(Nodo* raiz, char c);

int arv_altura(Arv_bin* arv);

int arv_altura_no(Nodo* no);

#endif