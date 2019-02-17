#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float **reservar_mem_v1(int r, int c){
	float **matriz = (float **)malloc(sizeof(float *) * r);
	for (int i = 0; i < r; ++i){
		matriz[i] = (float *)malloc(sizeof(float) * c);
	}
	return matriz;
}

float **reservar_mem_v2(int r, int c){
	float **matriz = (float **)malloc(sizeof(float *) * r);
	matriz[0] = (float *)malloc(sizeof(float) * r * c);
	for (int i = 1; i < r; ++i){
		matriz[i] = matriz[0] + c*i;
	}
	return matriz;
}
float sumaparamult(float **m1, float **m2, int i, int j, int r){
	float suma = 0;
	for (int k = 0; k < r; ++k){
		suma += m1[i][k] + m2[k][j];
	}
	return suma;
}

float **multiplicaMatriz(float **m1, float **m2, int rm1, int rm2, int cm2){
	float **mult = reservar_mem_v2(rm1, cm2);
	for (int i = 0; i < rm1; ++i){
		for (int j = 0; j < cm2; ++j){
			mult[i][j] = sumaparamult(m1, m2, i, j, rm1);
		}
	}
	return mult;
}

void llenarMatriz(float **matriz, int r, int c){
	for (int i = 0; i < r; ++i){
		for (int j = 0; j < c; ++j){
			matriz[i][j] = rand();
		}
	}
}

float **transpuesta_v1(float **matriz, int r, int c){
	float **n = reservar_mem_v1(c, r);
	for (int i = 0; i < r; ++i){
		for (int j = 0; j < c; ++j){
			n[j][i] = matriz[i][j];
		}
	}
	return n;
}

float **transpuesta_v2(float **matriz, int r, int c){
	float **n = reservar_mem_v2(c, r);
	for (int i = 0; i < r; ++i){
		for (int j = 0; j < c; ++j){
			n[j][i] = matriz[i][j];
		}
	}
	return n;
}

void liberarMem_v1(float **matriz, int r){
	for (int i = 0; i < r; ++i){
		free(matriz[i]);
	}
	free(matriz);
}

void liberarMem_v2(float **matriz){
	free(matriz[0]);
	free(matriz);
}

int main(void){
	srand(time(NULL));
	clock_t start, end;
	int r = 1000, c = 1000;
	float **A1 = reservar_mem_v1(r, c), **B1 = reservar_mem_v1(r, c);
	float **A2 = reservar_mem_v2(r, c), **B2 = reservar_mem_v2(r, c);
	llenarMatriz(A1, r, c);
	llenarMatriz(B1, r, c);
	llenarMatriz(A2, r, c);
	llenarMatriz(B2, r, c);

	float **B1t = transpuesta_v1(B1, r, c), **B2t = transpuesta_v2(B2, r, c);	

	start = clock();
	float **m1 = multiplicaMatriz(A1, B1, r, r, c);
	end = clock();

	double primer_mul = ((double) (end - start)) / CLOCKS_PER_SEC;

	start = clock();
	float **m2 = multiplicaMatriz(A2, B2, r, r, c);
	end = clock();

	double segunda_mul =((double) (end - start)) / CLOCKS_PER_SEC;

	printf("Primer multiplicacion: %lf, segunda multiplicacion: %lf\n", primer_mul, segunda_mul);


	start = clock();
	float **m1t = multiplicaMatriz(A1, B1t, r, r, c);
	end = clock();

	primer_mul =((double) (end - start)) / CLOCKS_PER_SEC;

	start = clock();
	float **m2t = multiplicaMatriz(A2, B2t, r, r, c);
	end = clock();

	segunda_mul =((double) (end - start)) / CLOCKS_PER_SEC;

	printf("Primer multiplicacion por transpuesta: %lf, segunda multiplicacion por transpuesta: %lf\n", primer_mul, segunda_mul);
	
	liberarMem_v1(A1, r);
	liberarMem_v1(B1, r);
	liberarMem_v2(m1);
	liberarMem_v2(m1t);
	liberarMem_v1(B1t, c);
	liberarMem_v2(A2);
	liberarMem_v2(B2);
	liberarMem_v2(m2);
	liberarMem_v2(m2t);
	liberarMem_v2(B2t);

	return 0;
}