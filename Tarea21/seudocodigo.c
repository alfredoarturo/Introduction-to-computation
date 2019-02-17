#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*float **reservarmem(int n){
	float **mat = (float **)malloc(sizeof(float *) * n);
	mat[0] = (float *)malloc(sizeof(float)*n*n);
	for (int i = 1; i < n; ++i){
		*(mat + i) = *(mat + i -1) + n;
	}
	return mat;
}*/

float **reservarmem(int n){
	//reserva memoria para una matriz del tamaño indicado
	float **mat = (float **)malloc(sizeof(float *) * n);
	for (int i = 0; i < n; ++i){
		mat[i] = (float *)malloc(sizeof(float)*n*n);
	}
	return mat;
}

void liberarmem(float **matriz){
	//libera memoria de la matriz indicada
	free(matriz[0]);
	free(matriz);
}

float **copia_mat(float **matriz, int n, int i){
	//copia una matriz a otra de una dimencion menor.
	//Esto se usa para obtener el determinante con la definición clasica
	float **mat = reservarmem(n-1);
	for (int i = 0; i < n; ++i){
		if (i != n)
			mat[i] = matriz[i];
	}
	return mat;
}

double determinante(float **matriz, int n){
	//Función recursiva que obtiene el determinante de una matriz cuadrada dada.
	if (n == 2)
		return matriz[0][0]*matriz[1][1] - matriz[1][0]*matriz[0][1];
	double det = 0;
	for (int i = 0; i < n; ++i){
		det += (pow(-1, i+1) * determinante(copia_mat(matriz, n, i), n-1));
	}
	return det;
}

int main(void)
{
	float **aux = reservarmem(10);
	printf("%lf\n", determinante(aux, 10));
	liberarmem(aux);
	return 0;
}