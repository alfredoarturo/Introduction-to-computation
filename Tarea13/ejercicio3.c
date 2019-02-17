#include <stdio.h>

int main(void){
	printf("El tamaño de int es: %d\n", (int) sizeof(int));
	printf("El tamaño del apuntador int es: %d\n", (int) sizeof(int*));
	printf("El tamaño de float es: %d\n", (int) sizeof(float));
	printf("El tamaño del apuntador float es: %d\n", (int) sizeof(float*));
	printf("El tamaño de double es: %d\n", (int) sizeof(double));
	printf("El tamaño del apuntador double es: %d\n", (int) sizeof(double*));
	printf("El tamaño de char es: %d\n", (int) sizeof(char));
	printf("El tamaño del apuntador char es: %d\n", (int) sizeof(char*));
}