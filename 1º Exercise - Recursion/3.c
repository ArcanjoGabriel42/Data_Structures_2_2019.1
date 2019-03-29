#include <stdio.h>
#include <stdlib.h>

int MultipRec(int n1,int n2){
	if (n2 == 1){
		return n1;
	}
	else{
		return n1 + MultipRec(n1,n2-1);
	}
}

int main(){
	int n,m,x,neg = 0;
	printf("Digite os valores:");
	scanf("%d %d", &n,&m);
	if (((n < 0) && (m > 0)) || ((n > 0) && (m < 0))){
		neg = 1; 
	}
	x = MultipRec(abs(n),abs(m));
	if (neg)
	{
		x = x * -1;
	}
	printf("A multiplicação de %d e %d é: %d\n", n,m,x);
	return 0;
}