#include <stdlib.h>
#include <stdio.h>

int **creaMatriz(int n){
	//crea matriz de nxn
	int **mundo = (int **)malloc(sizeof(int *) * n), i;
	mundo[0] = (int *)malloc(sizeof(int) * n * n);
	for (int i = 1; i < n; ++i){
		mundo[i] = mundo[i - 1] + n;
	}
	return mundo;
}


void destruyeMundo(int **mundo){
	//libera la memoria donde esta el mundo
	free(mundo[0]);
	free(mundo);
}


void crearMundoLimpio(int **mundo, int n){
	//pone ceros en todo el mundo
	int i, j;
	for (i = 0; i < n; ++i){
		for (j = 0; j < n; ++j){
			mundo[i][j] = 000;
		}
	}
}

int **mundo_limpio(int n){
	//regresa el mundo limpio
	int **mundo = creaMatriz(n);
	crearMundoLimpio(mundo, n);	
	return mundo;
}

void terminar(int **mundo){
	destruyeMundo(mundo);
}