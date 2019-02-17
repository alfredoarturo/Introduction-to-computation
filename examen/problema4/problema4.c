#include <stdio.h>
#include <stdlib.h>
#include "lib4.c"

int main(){
	int *vec = (int *)malloc(sizeof(int) * 4);
	for (int i = 0; i < 4; ++i){
		scanf("%d", vec+i);
	}
	int *arr = arreglo(vec, 4);
	for (int i = 0; i < 4; ++i){
		if (arr[i] != 0)
			printf("%d ", arr[i]);
	}
	printf("Hay %d numeros\n", longitud(arr, 4));
	free(vec);
	free(arr);
}