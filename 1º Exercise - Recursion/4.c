#include <stdio.h>
#include <stdlib.h>

int PotencRec(int k, int n){
	if (n == 1){
		return k;
	}
	else{
		return k * PotencRec(k,n-1);
	}
}

int main(){
	int n,m;
	scanf("%d %d", &n,&m);
	printf("%d\n", PotencRec(n,m));
	return 0;
}