#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **arreglo2d(int r, int c){
	int **m = (int **)malloc(sizeof(int *) * r);
	for (int i = 0; i < c; ++i){
		m[i] = (int*)malloc(sizeof(int) * c);
	}
	for (int i = 0; i < r; ++i){
		for (int j = 0; j < c; ++j){
			m[i][j] = rand()%(c*r);
		}
	}
	return m;
}

void relenarDiagonal(int **matriz, int r, int c, int val){
	if (r == c){
		for (int i = 0; i< r; ++i){
			matriz[i][i] = rand()%val;
		}
	}
}

int **transpuesta(int **matriz, int r, int c){
	int **n = (int **)malloc(sizeof(int*) * c);
	for (int i = 0; i < c; ++i){
		n[i] = (int *)malloc(sizeof(int) * r);
	}
	for (int i = 0; i < r; ++i){
		for (int j = 0; j < c; ++j){
			n[j][i] = matriz[i][j];
		}
	}
	return n;
}

void imprimeMatriz(int **matriz, int r, int c){
	for (int i = 0; i < r; ++i){
		for (int j = 0; j < c; ++j){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}

void liberaMemoria(int **matriz, int r, int c){
	for (int i = 0; i < r; ++i){
		free(matriz[i]);
	}
	free(matriz);
}

int main(void){
	int r, c, val;
	srand(time(NULL));
	int **n, **t;
	printf("Ingresa el numero de filas\n");
	scanf("%d", &r);
	printf("Ingresa el numero de columnas\n");
	scanf("%d", &c);
	n = arreglo2d(r,c);
	printf("Matriz original\n");
	imprimeMatriz(n, r, c);
	t = transpuesta(n , r, c);
	printf("Ingresa un valor para cambiar en la diagonal\n");
	scanf("%d", &val);
	relenarDiagonal(n, r, c, val);
	printf("Matriz con cambio de diagonal\n");
	imprimeMatriz(n, r, c);
	printf("La matriz transpuesta a la original\n");
	imprimeMatriz(t, c, r);
	liberaMemoria(n, r, c);
	liberaMemoria(t, c, r);
}