#include <stdio.h>
#include <stdlib.h>

void BinarRec(int n){
	int i;
	if (n < 2){
		printf("%d", n);
	}
	else{
		i = n % 2;
		BinarRec(n / 2);
		printf("%d",i);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	BinarRec(n);
	return 0;
}