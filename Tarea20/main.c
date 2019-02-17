//la terminal es de 80 columnas y 30 filas.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	//contiene la posicion x, y de los caballos
	int x, y;
} caballo;

void gotoxy(int x, int y) {
    printf("%c[%d;%df",0x1B,y,x);
}

caballo *caballos(int numCaballos){
	caballo *vec = (caballo *)malloc(sizeof(caballo) * numCaballos);
	for (int i = 0; i < numCaballos; ++i){
		(vec + i)->x = 1;
		(vec + i)->y = i + 5;
	}
	return vec;
}

void mover (caballo *vec, int numCaballos){
	//si aleatoriamente da 1, el caballo avanza, de lo contrario no
	int a;
	for (int i = 0; i < numCaballos; ++i){
		a = rand() % 2;
		if (a == 1)
			(vec + i)->x +=1;
		if ((vec + i)->x >= 77)
			exit(EXIT_SUCCESS);
	}
}

void limpiar_pantala(){
	//llena la pantalla de espacios
	for (int i = 0; i < 81; ++i){
		for (int j = 0; j < 30; ++j){
			gotoxy(i, j);
			printf(" ");
		}
	}
}

void dibujar_meta(){
	//dibuja la meta
	for (int i = 1; i < 31; ++i){
		gotoxy(80, i);
		printf("|");
	}
}

void imprimir(caballo *vec, int numCaballos){
	//imprime los caballos
	for (int i = 0; i < numCaballos; ++i){
		gotoxy((vec+i)->x, (vec+i)->y);
		printf("<o/>");
	}
	dibujar_meta();
}

void carrera(caballo *vec, int numCaballos){
	//se inician las funciones que hacen que inicie la carrera
	getchar();					//usado para pausar la carrera
	limpiar_pantala();
	mover(vec, numCaballos);
	imprimir(vec, numCaballos);
	carrera(vec, numCaballos);
}

void run(int numCaballos){
	//genera lo necesario para que se pueda iniciar la carrera
	srand(time(NULL));
	caballo *vec = caballos(numCaballos);
	limpiar_pantala();
	imprimir(vec, numCaballos);
	carrera(vec, numCaballos);
	gotoxy(0,0);
}

int main(void) { 
    run(20);
    return 0;
}