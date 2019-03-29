#include <stdio.h>
#include <stdlib.h>

int inver(int a){
	if (a == 0){
		return a;
	}
	else{
		printf("%d", (a % 10));
		a = a / 10;
		inver(a);
	}
}

int main(){
	int x;
	printf("Insira o valor: ");
	scanf("%d", &x);
	printf("O valor invertido: ");
	inver(x);
	printf("\n");
	return 0;
}