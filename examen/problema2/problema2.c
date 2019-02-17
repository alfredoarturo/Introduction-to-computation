#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib2.c"
#define tamVec 8


int main(){
	IMAG *vec, *trans;
	vec = reservarmem(tamVec);
	rellenar(vec, tamVec);
	//printf("Vector original\n");
	//imprimirImg(vec, tamVec);
	trans = transFourier(vec, tamVec);
	printf("Transformada de Fourier\n");
	imprimirImg(trans, tamVec);
	free(vec);
	free(trans);
}