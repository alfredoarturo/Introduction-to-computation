#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define PROM(a, b) float((a+b)/2)
#define ERROR 1
#define NO_ERROR 0
#define TAMANO 30

typedef struct {
	int x, y;
} COORD;

typedef struct {
	int indTope;
	int tamMax;
	COORD *contenedor;
} PILA;

void iniPila(PILA *p, int tamMax){
	p->indTope = 0;
	p-> tamMax = tamMax;
	p->contenedor = (COORD *)malloc(sizeof(COORD) * tamMax);
}

int push(PILA *p, COORD n){
	if (p->indTope >= p->tamMax){
		return ERROR;
	}
	else{
		p->contenedor[p->indTope] = n;
		p->indTope += 1;
		return NO_ERROR;
	}
}

int pop(PILA *p){
	if (p->indTope != 0){
		p->indTope -= 1;
		return NO_ERROR;
	}
	else{
		return ERROR;
	}
}

int tope(PILA p, COORD *val){
	if (p.indTope != 0){
		*val = p.contenedor[p.indTope];
		return NO_ERROR;
	}
	else{
		return ERROR;
	}
}

void liberarpila(PILA p){
	free(p.contenedor);
}

int *crearvectorEnteros(int tamano){
	int *a = (int *)malloc(sizeof(int) * tamano);
	for (int i = 0; i < tamano; ++i){
		a[i] = rand() % 100;
		printf("%d ", a[i]);
	}
	printf("\n");
	return a;
}

int comparaEnteros(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

void imprimirent(int *a, int tam){
	for (int i = 0; i < tam; ++i){
		printf("%d ", a[i]);
	}
	printf("\n");
}

float *crearvectorFloat(int tamano){
	float *a = (float *)malloc(sizeof(float) * tamano);
	float x;
	for (int i = 0; i < tamano; ++i){
		x = rand();
		a[i] = x/(RAND_MAX);
		printf("%f ", a[i]);
	}
	printf("\n");
	return a;
}

int comparaFloat(const void *a, const void *b){
	if (*(float *)a > *(float * )b)
		return *(float *)a > *(float *)b;
	return *(float *)a - *(float *)b;
}

void imprimirfloat(float *a, int tam){
	for (int i = 0; i < tam; ++i){
		printf("%f ", a[i]);
	}
	printf("\n");
}

double *crearvectordouble(int tamano){
	double *a = (double *)malloc(sizeof(double) * tamano);
	double x;
	for (int i = 0; i < tamano; ++i){
		x = rand();
		a[i] = x/(RAND_MAX);
		printf("%lf ", a[i]);
	}
	printf("\n");
	return a;
}

int comparaDouble(const void *a, const void *b){
	if ( *(double *)a > *(double *)b)
		return *(double *)a > *(double *)b;
	return *(double *)a - *(double *)b;
}

void imprimirdouble(double *a, int tam){
	for (int i = 0; i < tam; ++i){
		printf("%lf ", a[i]);
	}
	printf("\n");
}

unsigned long int *crearvectorlong(int tamano){
	unsigned long int *a = (unsigned long int *)malloc(sizeof(unsigned long int) * tamano);
	for (int i = 0; i < tamano; ++i){
		a[i] = rand();
		printf("%ld ", a[i]);
	}
	printf("\n");
	return a;
}

int comparaLong(const void *a, const void *b){
	return *(unsigned long int *)a - *(unsigned long int *)b;
}

void imprimirlong(unsigned long int *a, int tam){
	for (int i = 0; i < tam; ++i){
		printf("%ld ", a[i]);
	}
	printf("\n");
}

int main(void){
	srand(time(NULL));
	PILA a;
	COORD b, c, d;
	b.x = 10;
	b.y = 20;
	c.x = 15;
	c.y = 14;
	iniPila(&a, 10);
	printf("%d\n", push(&a, b));
	printf("%d\n", push(&a, c));
	printf("%d\n", pop(&a));
	printf("%d\n", tope(a, &d));
	printf("%d, %d\n", d.x, d.y);
	liberarpila(a);

	//Otra parte de la tarea
	int *vecint;
	vecint = crearvectorEnteros(TAMANO);
	qsort(vecint, TAMANO, sizeof(int), &comparaEnteros);
	imprimirent(vecint, TAMANO);
	if (TAMANO % 2 == 0){
		printf("Mediana es: %f\n", (float)(vecint[(TAMANO-2)/2] + vecint[TAMANO/2])/2);
	}
	else{
		printf("Medianan es: %f\n", (float)vecint[(TAMANO-1)/2]);
	}
	free(vecint);

	float *vecfloat;
	vecfloat = crearvectorFloat(TAMANO);
	qsort(vecfloat, TAMANO, sizeof(float), &comparaFloat);
	imprimirfloat(vecfloat, TAMANO);
	if (TAMANO % 2 == 0){
		printf("Mediana es: %f\n", (float)(vecfloat[(TAMANO-2)/2] + vecfloat[TAMANO/2])/2);
	}
	else{
		printf("Medianan es: %f\n", (float)vecfloat[(TAMANO-1)/2]);
	}
	free(vecfloat);

	double *vecdouble;
	vecdouble = crearvectordouble(TAMANO);
	qsort(vecdouble, TAMANO, sizeof(double), &comparaDouble);
	imprimirdouble(vecdouble, TAMANO);
	if (TAMANO % 2 == 0){
		printf("Mediana es: %lf\n", (float)(vecdouble[(TAMANO-2)/2] + vecdouble[TAMANO/2])/2);
	}
	else{
		printf("Medianan es: %lf\n", (float)vecdouble[(TAMANO-1)/2]);
	}
	free(vecdouble);

	unsigned long int *veclong;
	veclong = crearvectorlong(TAMANO);
	qsort(veclong, TAMANO, sizeof(unsigned long int), &comparaLong);
	imprimirlong(veclong, TAMANO);
		if (TAMANO % 2 == 0){
		printf("Mediana es: %f\n", (float)(vecint[(TAMANO-2)/2] + vecint[TAMANO/2])/2);
	}
	else{
		printf("Medianan es: %f\n", (float)vecint[(TAMANO-1)/2]);
	}
	free(veclong);
}