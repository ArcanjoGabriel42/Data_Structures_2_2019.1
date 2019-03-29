#include <stdio.h>
#include <stdlib.h>

 void PrintNatCresc(int n){
 	if (n == 0){
 		printf("%d ",n);
 	}
 	else{
 		PrintNatCresc(n-1);
 		printf("%d ", n);
 	}
 }

void PrintNatDecre(int n){
 	if (n == 0){
 		printf("%d ",n);
 	}
 	else{
 		printf("%d ", n);
 		PrintNatDecre(n-1);
 	}
 } 

 int main()
 {
 	int n;
 	scanf("%d", &n);
 	printf("Crescente:\n");
 	PrintNatCresc(n);
 	printf("\n");
 	printf("Decrescente:\n");
 	PrintNatDecre(n);
 	printf("\n");
 	return 0;
 }