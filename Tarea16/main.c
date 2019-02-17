//cada funcion debe tener la menor cantidad de lineas

#include <stdio.h>
#define LIBRE 0	//si el lugar esta libre
#define OCUPADO 1	//si el lugar tiene un obstaculo
#define T 10		//pasos que dan
#define N 100000		//numero de caminantes
#include "lib.c"


//Hay obstáculos de 1x1, 3x3 y 5x5
//se selecciona aleatoriamente el centro del obstaculo

int main(void){
	run(1000, 2000, N, T);
	return 0;
}