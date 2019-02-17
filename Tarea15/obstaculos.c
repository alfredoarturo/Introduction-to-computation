#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "structs.c"
#include "mundo.c"
#define LIBRE 100	//si el lugar esta libre
#define OCUPADO 101	//si el lugar tiene un obstaculo


int elegirObstaculo(){
	//elige de manera aleatoria el tamaño del obstaculo
	int obs = rand() % 3;
	if (obs == 0){
		printf("%d\n", obs);
		return 1;
	}
	else if (obs == 1){
		printf("%d\n", obs);
		return 3;
	}
	else if (obs == 2){
		printf("%d\n", obs);
		return 5;
	}
}

int elegirCoordenadasObstaculos(int n){
	//elige aletoriamente un número módulo el número indicado
	//esta funció se usará para elegir las coordenadas de los obstaculos
	int obs = rand() % n;
	return obs;
}

void llenarObstaculos(int **mundo, int n, int xinicial, int yinicial, int tamano){
	//llena con unos y ceros el mundo
	for (int i = yinicial; i < yinicial + tamano; ++i){
		for (int j = xinicial; j < xinicial + tamano; ++j){
			mundo[(yinicial + i) % n][(xinicial + j) % n] = OCUPADO;
		}
	}
}

void colocarObstaculo(int **mundo, int n, int x, int y, int tamano){
	//coloca obstaculo en la posicion dada
	//con el tamaño ingresado
	int posx = (x - (tamano - 1)/2) % n;
	int posy = (y + (tamano - 1)/2) % n;
	if (posx > 0 && posy > 0){
		llenarObstaculos(mundo, n, posx, posy, tamano);
	}
	else if (posx < 0 && posy > 0){
		llenarObstaculos(mundo, n, posx + n, posy, tamano);
	}
	else if (posx > 0 && posy < 0){
		llenarObstaculos(mundo, n, posx, posy + n, tamano);
	}
	else if (posx < 0 && posy < 0){
		llenarObstaculos(mundo, n, posx + n, posy + n, tamano);
	}
}

void ponerObstaculos(int **mundo, int n, int nObstaculos){
	//coloca el numero de obstaculos indicados
	for (int i = 0; i < nObstaculos; ++i){
		colocarObstaculo(mundo, n, elegirCoordenadasObstaculos(n), elegirCoordenadasObstaculos(n), elegirObstaculo());
	}
}

void imprimir(int **mundo, int n){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			printf("%d ", mundo[i][j]);
		}
		printf("\n");
	}
}

void inciarMundoconOsbtaculos(int n, int nObstaculos){
	//crea un mundo con obstaculos
	srand(time(NULL));
	int **mundo = mundo_limpio(n);
	ponerObstaculos(mundo, n, nObstaculos);
	imprimir(mundo, n);
	terminar(mundo);
}

/*float porcentajeDeOstaculos(int **mundo, int n){
	//saca el porcentaje de ocupados respecto al total del datos
	int i, j, cuenta, porcentaje;
	for (i = 0; i < n; ++i){
		for (j = 0; j < n; ++j){
			if (mundo[i][j] == OCUPADO){
				cuenta += 1;
			}
		}
	}
	return cuenta/(n*n);
}

int porcentajeAlcanzado(int *mundo, int n, float porcentaje){
	//revisa que el porcentaje ocupado no sea mayor
	float porcentajeActual = porcentajeDeOstaculos(**mundo, n);
	if (porcentajeActual < porcentaje){
		return 0;
	}
	else{
		return 1;
	}
}

void ponerObstaculos(int **mundo, int n, float porcentaje){ //en lugar de float porcentaje puede ser int nObstaculos
	//llena cierto porcentaje de los lugares del mundo
	//puede poner solo cierto numero de obstaculos de 1x1, 3x3, 5x5
	int tamano = elegirObstaculo(), coordenadax = elegirCoordenadasObstaculos(n), coordenaday = elegirCoordenadasObstaculos(n);
	
}

void crearObstaculos(int **mundo, int n, float porcentaje){

}*/