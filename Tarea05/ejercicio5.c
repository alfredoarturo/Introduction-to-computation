#include <stdio.h>
#include <math.h>

int main(){
	int conv;
	float inp, final;
	printf("1 para convertir de Grados a Radianes, 2 para convertir de Radianes a Grados\n");
	scanf("%i", &conv);
	if (conv == 1){
		printf("Ingresa los Grados\n");
		scanf("%f", &inp);
		final = inp * M_PI/180;
		printf("%f Grados son %f Radianes\n", inp, final);
	}
	else{
		printf("Ingresa los Radianes\n");
		scanf("%f", &inp);
		final = inp*180/M_PI;
		printf("%f Radianes son %f Grados\n", inp, final);
	}
	return 0;
}