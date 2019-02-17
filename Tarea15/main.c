//cada funcion debe tener la menor cantidad de lineas

#include <stdio.h>
#define LIBRE 100	//si el lugar esta libre
#define OCUPADO 101	//si el lugar tiene un obstaculo
#define T 1000		//pasos que dan
#define N 10000		//numero de caminantes
#include "obstaculos.c"
#include "obstaculos.h"


//Hay obstáculos de 1x1, 3x3 y 5x5
//se selecciona aleatoriamente el centro del obstaculo

int main(void){
	inciarMundoconOsbtaculos(10, 3);
	return 0;
}