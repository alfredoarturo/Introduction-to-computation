#include <stdio.h>
#include <stdlib.h>

int indmax(int *vec, int tamano){
	int max = vec[0], indmax = 0;
	for (int i = 1; i < tamano; ++i){
		if (vec[i] > max){
			max = vec[i];
			indmax = i;
		}
	}
	return indmax;
}

int ind3max(int *vec, int tamano){
	int indaux, aux;
	for (int i = 0; i < 3; ++i){
		indaux = indmax(vec + i, tamano - i);
		aux = vec[0];
		vec[0] = vec[indaux];
		vec[indaux] = aux;
		printf("%d %d %d %d %d\n", vec[0], vec[1], vec[2], vec[3], vec[4]);
	}
	return 2;
}

int ind3max_v2(int *vec, int tamano){
	int indmax1 = indmax(vec+1, tamano-2);
	int indmax2, max = -100;
	for (int i = 0; i < tamano; ++i){
		if (vec[i] > max && vec[i] != vec[indmax1]){
			indmax2 = i;
		}
	}
	int indmax3;
	max = -100;
	for (int i = 0; i < tamano; ++i){
		if (vec[i] > max){
			if (vec[i] != vec[indmax1] && vec[i] != vec[indmax2]){
				indmax3 = i;
			}
		}
	}
	return indmax3;
}

int main(void){
	int *vec = (int *)malloc(sizeof(int)*5);
	vec[0] = 1;
	vec[1] = 2;
	vec[2] = 690;
	vec[3] = 680;
	vec[4] = 90;
	printf("%d\n", vec[indmax(vec, 5)]);
	printf("%d\n", vec[ind3max_v2(vec, 5)]);
	printf("%d\n", vec[ind3max(vec, 5)]);

}