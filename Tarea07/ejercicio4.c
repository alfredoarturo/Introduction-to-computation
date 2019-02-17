#include <stdio.h>

int main(){
	int n, f[10], desp, a;
	printf("Ingrsa 10 numeros\n");
	for (int n = 0; n < 10; ++n){
		scanf("%d", &f[n]);
	}
	printf("Ingresa el numero de lugares desplazados\n");
	scanf("%d", &desp);
	printf("Shift a la izquierda\n");
	for (n = 0; n < 10; ++n){
		a = (desp + n) % 10;
		printf("%i, ", f[a]);
	}
	printf("\nShift a la derecha\n");
	for (n = 0; n < 10; ++n){
		a = (n-desp+10) % 10;
		printf("%i, ", f[a]);
	}
	printf("\n");
	return 0;
}