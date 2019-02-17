#include <stdio.h>

int main(){
	float grados, final;
	int conv;
	printf("Ingresa 1 para convertir Celsius a Fahrenheit, 2 para convertir de Fahrenheit a Celcius\n");
	scanf("%i", &conv);
	if (conv == 1){
		printf("Ingresa los grados Celsius\n");
		scanf("%f", &grados);
		final = (1.8*grados) + 32;
		printf("%f grados Celsius son %f grados Fahrenheit.\n", grados, final);
	}
	else{
		printf("Ingresa los grados Fahrenheit\n");
		scanf("%f", &grados);
		final = (grados - 32)/1.8;
		printf("%f grados Fahrenheit son %f grados Celsius\n", grados, final);
	}
	return 0;
}