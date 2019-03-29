#include <stdio.h>
#include <stdlib.h>

int SomaVet(int* v, int i){
	if(i == 0){
		return v[i];
	}
	else{
		return v[i] + SomaVet(v,i-1);
	}
}

int MaxVet(int* v, int i, int* max){
	if (i < 0){
		return *max;
	}
	else{
		if (v[i] > *max){
			max = &v[i];
		}
		return MaxVet(v,i-1,max);
	}
}

int MinVet(int* v, int i, int* min){
	if (i < 0){
		return *min;
	}
	else{
		if (v[i] < *min){
			min = &v[i];
		}
		return MinVet(v,i-1,min);
	}
}

int ProdVet(int* v, int i){
	if(i == 0){
		return v[i];
	}
	else{
		return v[i] * ProdVet(v,i-1);
	}
}

float MediaVet(int* v, int i, float tam){
	if(i != 0){
		return (v[i]/tam) + MediaVet(v,i-1,tam);
	}
	else{
		return (v[i]/tam);
	}
}

int main(){
	int i,j;
	printf("Informe a quantidade de valores:\n");
	scanf("%d", &i);
	int* v = (int*)malloc(i*sizeof(int));

	for(j = 0; j < i; j++){
		printf("Entre com o %d valor:", j+1);
		scanf("%d",&v[j]);
		printf("\n");
	}

	printf("Soma = %d\n", SomaVet(v,i-1));
	printf("Maior = %d\n", MaxVet(v,i-1,&v[i-1]));
	printf("Menor = %d\n", MinVet(v,i-1,&v[i-1]));
	printf("Produto = %d\n", ProdVet(v,i-1));
	printf("Media = %.2f\n", MediaVet(v,i-1,i));

	return 0;
}