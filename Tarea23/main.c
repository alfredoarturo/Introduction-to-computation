#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define ERROR 1
#define NO_ERROR 0
#define TRUE 1
#define FALSE 0

typedef struct {
	int x;
	int y;
} COORD;

typedef struct {
	int indTope;
	int tamMax;
	COORD *contenedor;
} PILA;

void gotoxy(int x, int y) {
    printf("%c[%d;%df",0x1B,x,y);
}

void iniPila(PILA *p, int tamMax){
	p->indTope = 0;
	p-> tamMax = tamMax;
	p->contenedor = (COORD *)malloc(sizeof(COORD) * tamMax);
}

int push(PILA *p, COORD n){
	if (p->indTope >= p->tamMax){
		return ERROR;
	}
	else{
		p->contenedor[p->indTope] = n;
		p->indTope += 1;
		return NO_ERROR;
	}
}

int pop(PILA *p){
	if (p->indTope != 0){
		p->indTope -= 1;
		return NO_ERROR;
	}
	else{
		return ERROR;
	}
}

int tope(PILA p, COORD *val){
	if (p.indTope != 0){
		*val = p.contenedor[p.indTope];
		return NO_ERROR;
	}
	else{
		return ERROR;
	}
}

int is_empty(PILA p){
	COORD a; 
	if (tope(p, &a) == ERROR)
		return TRUE;
	else
		return FALSE;
}

void liberarpila(PILA p){
	free(p.contenedor);
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

char **memoriamapa(int rows, int cols){
	char **mapa = (char **)malloc(sizeof(char *) * rows);
	mapa[0] = (char *)malloc(sizeof(char)* rows * cols);
	for (int i = 1; i < rows; ++i){
		mapa[i] = mapa[i-1] + cols;
	}
	return mapa;
}

void llenarmapa(char **mapa, const char *nombre, int rows, int cols){
	FILE *fp;
	fp = fopen(nombre, "rt");
	if (fp == NULL){
		printf("No se abrio el archivo\n");
		exit(1);
	}
	for (int i = 0; i < rows; ++i)
		fread(mapa[i], sizeof(char), cols, fp);
}

void imprimir(char **mapa, int rows, int cols){
	limpiar_pantala();
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			//if (mapa[i][j] != 'A' && mapa[i][j] != 'V'){
				gotoxy(i+1, j+1);
				printf("%c\n", mapa[i][j]);	
			//}
		}
	}
	gotoxy(15,0);
}

void agregaAPila(char **mapa, PILA *p, COORD actual, int cols, int rows){
	COORD temp;
	temp.x = actual.x;
	temp.y = actual.y + 1;
	if (temp.y < rows){
		if (mapa[temp.x][temp.y] != 'X' && mapa[temp.x][temp.y] != 'A' && mapa[temp.x][temp.y] != 'V'){
			push(p, temp);
			mapa[temp.x][temp.y] = 'A';
		}
	}
	temp.y = actual.y - 1;
	if (temp.y > 0){
		if (mapa[temp.x][temp.y] != 'X' && mapa[temp.x][temp.y] != 'A' && mapa[temp.x][temp.y] != 'V'){
			push(p, temp);
			mapa[temp.x][temp.y] = 'A';
		}
	}
	temp.x = actual.x - 1;
	temp.y = actual.y;
	if (temp.x > 0){
		if (mapa[temp.x][temp.y] != 'X' && mapa[temp.x][temp.y] != 'A' && mapa[temp.x][temp.y] != 'V'){
			push(p, temp);
			mapa[temp.x][temp.y] = 'A';
		}
	}
	temp.x = actual.x + 1;
	if (temp.x < cols){
		if (mapa[temp.x][temp.y] != 'X' && mapa[temp.x][temp.y] != 'A' && mapa[temp.x][temp.y] != 'V'){
			push(p, temp);
			mapa[temp.x][temp.y] = 'A';
		}
	}
}

COORD coordActual(char **mapa, int rows, int cols){
	COORD actual;
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			if (mapa[i][j] == 'I'){
				actual.x = i;
				actual.y = j;
			}				
		}
	}
	return actual;
}

void mover(char **mapa, COORD *actual, PILA p, int rows, int cols){
	mapa[actual->x][actual->y] = 'V';
	tope(p, actual);
	pop(&p);
	if (is_empty(p) != TRUE)
		mapa[actual->x][actual->y] = 'M';
	imprimir(mapa, rows, cols);
}

void caminar(char **mapa, COORD actual, PILA p, int rows, int cols){
	while (1){
		agregaAPila(mapa, &p, actual, rows, cols);
		mover(mapa, &actual, p, rows, cols);
		if (is_empty(p) == TRUE)
			break;
		if (mapa[actual.x][actual.y] == 'T')
			break;
	getchar();
	}

	if (mapa[actual.x][actual.y] == 'F'){
		printf("Salida encontrada\n");
	}
	else{
		printf("Salina no encontrada\n");
	}
}

void run(){
	int rows = 10;
	int cols = 11;
	char **mapa = memoriamapa(rows, cols);
	COORD actual;
	PILA p;
	iniPila(&p, 100);
	llenarmapa(mapa, "laberinto.txt", rows, cols);
	actual = coordActual(mapa, rows, cols);
	//agregaAPila(mapa, &p, actual, rows, cols);
	caminar(mapa, actual, p, rows, cols);
}

int main(){
	run();
	return 0;
}