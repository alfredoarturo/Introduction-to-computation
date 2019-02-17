#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int indmax(float *vec, int tamano){
	float max = vec[0], indmax = 0;
	for (int i = 1; i < tamano; ++i){
		if (vec[i] > max){
			max = vec[i];
			indmax = i;
		}
	}
	return indmax;
}

int main(void){
	float *vec = (float *)malloc(sizeof(float) * 10000);
	FILE *fp;
	fp =fopen("aleatorio.dat", "rb");
	if(fp == NULL){
        printf("No se abrio el archivo\n");
        exit(1);
    }
    for (int i = 0; i < 10000; ++i){
    	fread(vec + i, sizeof(float), 1, fp);
    }
    fclose(fp);
    float promedio, varianza;
    for (int i = 0; i < 10000; ++i){
    	promedio += (vec[i]/10000);
    }
    for( int i = 0; i < 10000; ++i){
    	varianza += pow(promedio- vec[i], 2);
    }
    varianza = sqrt(varianza/10000);
    int indmax1 = indmax(vec, 10000);
    printf("El promedio de los calores es: %f\n", promedio);
    printf("La varianza de los valores es: %f\n", varianza);
    printf("El maximo de os valores es: %f\n", vec[indmax1]);
}