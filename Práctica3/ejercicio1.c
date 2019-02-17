#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arreglo1d(int n){
	int *a = (int *) malloc(sizeof(int)*n);
	for (int i = 0; i < n; ++i){
		a[i] = (rand()%n);
	}
	return *a;
}

float promedio(int *a, int n){
	float prom = 0, suma;
	for (int i = 0; i < n; ++i){
		suma += (a[i]%n);
	}
	prom = suma/n;
	return prom;
}

int main(){
	int n, *p;
	float q;
	scanf("%d", &n);
	*p = arreglo1d(n);
	q = promedio(p, n);
	printf("Arreglo:\n");
	for (int i = 0; i < n; ++i){
		printf("%d ", p[i]%n);
	}
	printf("\n");
	printf("Promedio:\n");
	printf("%f\n", q);
	free(p);
	return 0;
}

