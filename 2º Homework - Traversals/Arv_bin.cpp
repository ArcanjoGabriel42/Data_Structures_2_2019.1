#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Arv_bin.h"
#include <queue>
#include <stack>

using namespace std;

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
		print_in_ord(raiz->esq);
		printf("%c ", raiz->info);
		print_in_ord(raiz->dir);
	}
}

void print_pos_ord(Nodo* raiz){

	if (raiz != NULL){
		print_pos_ord(raiz->esq);
		print_pos_ord(raiz->dir);
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

int tamanho(Arv_bin* arv){

	tamanho_no(arv->raiz);

}

int tamanho_no(Nodo* no){

	if (no == NULL){
		return 0;
	}
	else{
		return 1 + tamanho_no(no->dir) + tamanho_no(no->esq);
	}

}

Arv_bin* esp(Arv_bin* arv){

	return arv_cria(esp_no(arv->raiz));
}

Nodo* esp_no(Nodo* raiz){
	if (raiz == NULL){
		return NULL;
	}
	else{
		return arv_cria_no(raiz->info,esp_no(raiz->dir),esp_no(raiz->esq));
	}


}

void perc_larg(Nodo* raiz){
	Nodo* p;
	queue <Nodo*> g;
	g.push(raiz);
	while(!(g.empty())){
		p = g.front();
		g.pop();
		if (p){
			printf("%c",p->info);
			g.push(p->esq);
			g.push(p->dir);
		}
	}
}

void print_pre_ord_iter(Arv_bin* arv){
	stack <Nodo*> p;
	Nodo* c = NULL;
	p.push(arv->raiz);
	while(!p.empty()){
		c = p.top();
		printf("%c ", c->info);
		p.pop();
		if(c->dir!=NULL){
			p.push(c->dir);
		}
		if(c->esq!=NULL){
			p.push(c->esq);
		}
	}
}

void print_in_ord_iter(Arv_bin* arv){
	stack <Nodo*> p;
	Nodo* c = NULL;
	p.push(arv->raiz);
	while(!p.empty()){
		c = p.top();
		while(c->esq){
			p.push(c->esq);
			c = p.top();
		}
		printf("%c ", c->info);
		p.pop();
		while(c->dir == NULL && !p.empty()){
			c = p.top();
			printf("%c ", c->info);
			p.pop();
		}
		if(c->dir != NULL){
				p.push(c->dir);
		}
	}
}

void print_pos_ord_iter(Arv_bin* arv){

	stack <Nodo*> r;
	stack <Nodo*> n;
	Nodo* c = NULL;
	n.push(arv->raiz);
	while(!n.empty()){

		c = n.top();
		n.pop();
		r.push(c);

		if(c->esq != NULL){
			n.push(c->esq);
		}

		if(c->dir != NULL){
			n.push(c->dir);
		}
	}
	while(!r.empty()){
		printf("%c ", r.top()->info);
		r.pop();
	}

}


int folha_arv(Arv_bin* arv){
	return folha_no(arv->raiz);
}

int folha_no(Nodo* raiz){

	if (raiz){

		if ((raiz->esq==NULL) && (raiz->dir == NULL)){

			return 1;

		}
		else{

			return folha_no(raiz->esq) + folha_no(raiz->dir);

		}
	}
}


int arv_estr_bin(Arv_bin* arv){ 

	return no_estr_bin(arv->raiz);
}

int no_estr_bin(Nodo* raiz){

	if(((raiz->esq == NULL) && (raiz->dir != NULL))||((raiz->esq != NULL) && (raiz->dir == NULL))){
		return 0;
	}
	if ((raiz->esq == NULL) && (raiz->dir == NULL)){
		return 1;
	}
	else
	{
		return (no_estr_bin(raiz->esq) && no_estr_bin(raiz->dir));
	}
}

int arv_bin_compl(Arv_bin* arv){

	return (tamanho(arv) == (pow(2,arv_altura(arv)+1)-1)? 1 : 0);
}