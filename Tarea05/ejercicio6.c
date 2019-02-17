#include <stdio.h>

int main(){
	int conv;
	int horas, minutos;
	int final;
	printf("Ingresa 1 para convertir horas y minutos a segundos y 2 para convertir segundos a horas y minutos\n");
	scanf("%i", &conv);
	if (conv == 1){
		printf("Ingresa las horas\n");
		scanf("%i", &horas);
		printf("Ingresa los minutos\n");
		scanf("%i", &minutos);
		final = minutos*60 + horas*3600;
		printf("%i horas con %i minutos son %i segundos\n", horas, minutos, final);
	}
	else{
		int seg, segundos;
		printf("Ingresa los segundos\n");
		scanf("%i", &seg);
		horas = seg/3600;
		segundos = seg % 60;
		minutos = (seg-horas*3600)/60;
		printf("%i segundos son %i horas con %i minutos con %i segundos\n", seg, horas, minutos, segundos);
	}
	return 0;
}