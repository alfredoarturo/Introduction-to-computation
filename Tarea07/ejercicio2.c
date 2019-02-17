#include <stdio.h>

int main(){
	int n, f[10];
	printf("Ingrsa 10 numeros\n");
	for (int n = 0; n < 10; ++n){
		scanf("%d", &f[n]);
	}
	printf("Shift a la derecha\n");
	for (n = 0; n < 9; ++n){
		printf("%i, ", f[n+1]);
	}
	printf("%i, ", f[0]);
	printf("\n");
	printf("Shift a la izquierda\n");
	printf("%i, ", f[9]);
	for (n = 1; n < 10; ++n){
		printf("%i, ", f[n-1]);
	}
	printf("\n");
	return 0;
}