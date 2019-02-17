#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	float *vec = (float *)malloc(sizeof(float) * 10000), x;
	srand(time(NULL));
	for (int i = 0; i < 10000; ++i){
		x = rand();
		x = x / RAND_MAX;
		vec[i] = (rand() % 211) + x - 20;
	}

	FILE *fp;
	fp =fopen("aleatorio.dat", "wb");
	if(fp == NULL){
        printf("No se abrio el archivo\n");
        exit(1);
    }
    for (int i = 0; i < 10000; ++i){
    	fwrite(vec + i, sizeof(float), 1 , fp);
    }
    fclose(fp);
}