#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
	srand(time(NULL));
	int N = 88;
	float *myVec = (float *)malloc(sizeof(float)*N), *mit;
	for(int i = 0; i<N; ++i){
		myVec[i] = (rand() % 1000000);
		myVec[i] = myVec[i] / 1000000;
	}
	mit = myVec + (N/2);
	printf("Mitad\n");
	for (int i = 0; i < N/8; i ++){
		printf("%d  %f\n", i + (N/2), mit[i]);
	}
	printf("ultimo\n");
	for (int i = 0; i < N/4; ++i){
		printf("%d  %f\n", i +(3*N/4), *(myVec + i + (3*N/4)));
	}
	printf("Final\n");
	for (int i = N-1; i > -1; --i){
		printf("%d %f\n", i, myVec[i]);
	}
}