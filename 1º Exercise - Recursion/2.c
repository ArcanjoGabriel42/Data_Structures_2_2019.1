#include <stdio.h>
#include <stdlib.h>

int somatorio(int n){
	if (n == 0){
		return n;
	}
	else{
		return n + somatorio(n -1);
	}
}

int main(){
	int n;
	printf("Digite o valor:");
	scanf("%d", &n);
	n = somatorio(n);
	printf("O Somatorio do valor escolhido é: %d\n", n);
	return 0;
}