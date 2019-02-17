#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct NumeroComplejo {
	float ent;
	float img;
} complejo;

float anguloEntreDosComplejos(complejo *u, complejo *v){
	float an;
	an = abs(atan(u->img/u->ent)-atan(v->img/v->ent));
	return an;
}

int main(void){
	
	srand(time(NULL));
	
	int n = 1002;
	
	complejo *v = (complejo *)malloc(sizeof(complejo) * n);
	
	for (int i = 0; i < n; ++i){
		(v + i)->ent = rand() % 1000000;
		(v + i)->ent = (v + i)->ent / 1000000;
		(v + i)->img = sqrt(1 - pow((v + i)->ent, 2));
		(v + i)->img = ((v + i)->img) * pow(-1, rand() % 2);
		printf("Complejo num %d\n", i);
		printf("%f ", (v + i)->ent);
		printf("%fi\n", (v + i)->img);
	}

	for (int i = n-i; i > n - 60; --i){
		float a;
		a = anguloEntreDosComplejos((v+i), (v+i-1));
		printf("El angulo entre %f + %fi y %f + %fi es:\n", (v+i)->ent, (v+i)->img, (v-1+i)->ent, (v-1+i)->img);
		printf("%f\n", a);
	}
}