#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tirar(int *dinero, int dinero_apostado, int num, int color){
	int numero = rand() % 37;
	if (num == numero){
		*dinero += dinero_apostado;
		printf("Ganaste\n");
	}
	else if (color != (numero % 2)){
		*dinero -= dinero_apostado;
		printf("Perdiste\n");
	}
	else{
		printf("No ganas nada\n");
	}
	printf("Dinero actual: %d\n", *dinero);
}

void ingesar(char *apostar, int *dinero_apostado, int *num, int *color, int *dinero){
	while (*apostar == 'Y' || *apostar == 'y'){
		printf("Y/N para apostar\n");
		scanf("%c", apostar);
		if (dinero >= 0 && *apostar != 'N'){
			printf("Ingresar dinero a apostar\n");
			scanf("%d", dinero_apostado);
			printf("Ingresa el numero al que se apuesta\n");
			scanf("%d", num);
			printf("Ingresa color 0 para negero, 1 para blanco\n");
			scanf("%d", color);
			tirar(dinero, *dinero_apostado, *num, *color);
		}
		else{
			break;
		}
	}
}

void run(char *apostar, int *dinero_apostado, int *num, int *color, int *dinero){
	ingesar(apostar, dinero_apostado, num, color, dinero);
}

int main(){
	srand(time(NULL));
	char *apostar = (char *)malloc(sizeof(char));
	int *dinero_apostado = (int *)malloc(sizeof(int)), *num = (int *)malloc(sizeof(int)), *color = (int *)malloc(sizeof(int)), *dinero = (int *)malloc(sizeof(int));
	*apostar = 'Y';
	dinero[0] = 500;
	run(apostar, dinero_apostado, num, color, dinero);
}