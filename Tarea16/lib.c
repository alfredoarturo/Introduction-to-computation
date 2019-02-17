#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define LIBRE 0	//si el lugar esta libre
#define OCUPADO 1	//si el lugar tiene un obstaculo



//genera el mundo
int **creaMatriz(int n){
	//crea matriz de nxn
	int **mundo = (int **)malloc(sizeof(int *) * n), i;
	mundo[0] = (int *)malloc(sizeof(int) * n * n);
	for (int i = 1; i < n; ++i){
		mundo[i] = mundo[i - 1] + n;
	}
	return mundo;
}


void destruyeMundo(int **mundo){
	//libera la memoria donde esta el mundo
	free(mundo[0]);
	free(mundo);
}


void crearMundoLimpio(int **mundo, int n){
	//pone ceros en todo el mundo
	int i, j;
	for (i = 0; i < n; ++i){
		for (j = 0; j < n; ++j){
			mundo[i][j] = 000;
		}
	}
}

int **mundo_limpio(int n){
	//regresa el mundo limpio
	int **mundo = creaMatriz(n);
	crearMundoLimpio(mundo, n);	
	return mundo;
}

void terminar(int **mundo){
	destruyeMundo(mundo);
}

//Las estructuras usadas en el programa
typedef struct {
	int x;
	int y;	
} pos;

typedef struct {
	int planosx;
	int planosy;
} plano;

typedef struct Molecula{
	pos inicial;       	//contiene la posicion en x, y en la que inicio
	pos actual;        	//contiene la posicion x, y en la que se encuantra actualmente
	plano planoActual;	//Lleva la cuenta de cuantas veces a cambiado de plano la molécula
} molecula;


//genera los obstaculos
int elegirObstaculo(){
	//elige de manera aleatoria el tamaño del obstaculo
	int obs = rand() % 3;
	if (obs == 0){
		return 1;
	}
	else if (obs == 1){
		return 3;
	}
	else if (obs == 2){
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



//todo lo relacionado con las moleculas
int numAleatorio(int n){
	//genera un numero aleatorio, se va a usar para la posición inicial
	int num = rand() % n;
	return num;
}

void obtenerPosicionInicial(int **mundo, int n, molecula uno){
	//regresa la posicion inicial de la molecula
	int x = numAleatorio(n), y = numAleatorio(n);
	if (mundo[x][y] != 1){
		uno.inicial.x = x;
		uno.inicial.y = y;
		uno.actual.x = x;
		uno.actual.y = y;
	}
	else{
		obtenerPosicionInicial(mundo, n, uno);
	}
}

void checarPlanox(int n, molecula mol){
	//aumenta o disminuye el numero de planos que la molecula se ha desplazado
	if (mol.actual.x > 0){
		if (mol.actual.x > n){
			mol.actual.x = mol.actual.x - n;
			mol.planoActual.planosx += 1;
		}
	}
	else if (mol.actual.x < 0){
		mol.actual.x += n;
		mol.planoActual.planosx -= 1;
	}
}

void checarPlanoy(int n, molecula mol){
	//aumenta o disminuye el numero de planos que la molecula se ha desplazado
	if (mol.actual.y > 0){
		if (mol.actual.y > n){
			mol.actual.y = mol.actual.y - n;
			mol.planoActual.planosy += 1;
		}
	}
	else if (mol.actual.y < 0){
		mol.actual.y += n;
		mol.planoActual.planosy -= 1;
	}
}

void derecha(int **mundo, molecula mol, int n){
	//agrega un valor a la derecha a la molecula
	if (mundo[(mol.actual.x + 1) % n][mol.actual.y] != 1){
		//se mueve la molecula
		mol.actual.x += 1;
		checarPlanox(n, mol);
	}
	//si rebota se queda en el mismo lugar
}

void izquierda(int **mundo, molecula mol, int n){
	//agrega un valor a la izquierda a la molecula
	if (mundo[(mol.actual.x - 1 + n) % n][mol.actual.y] != 1){
		mol.actual.x -= 1;
		checarPlanox(n, mol);
	}
}

void arriba(int **mundo, molecula mol, int n){
	//agrega un valor arriba a la molecula
	if (mundo[mol.actual.x][(mol.actual.y + 1) % n]){
		mol.actual.y += 1;
		checarPlanoy(n, mol);
	}
}

void abajo(int **mundo, molecula mol, int n){
	//agrega un valor abajo a la molecula
	if (mundo[mol.actual.x][(mol.actual.y - 1 + n) % n]){
		mol.actual.y -= 1;
		checarPlanoy(n, mol);
	}
}

void caminar(int **mundo, int n, molecula mol, int nPasos){
	//mover la molécula nPasos, no se puede quedar en el mismo lugar si rebota
	int mov = numAleatorio(4);
	printf("%d ", mov);
	for (int i = 0; i < nPasos; ++i){
		if (mov = 0){
			derecha(mundo, mol, n);
		}
		else if (mov = 1){
			arriba(mundo, mol, n);
		}
		else if (mov = 2){
			izquierda(mundo, mol, n);
		}
		else if (mov = 3){
			abajo(mundo, mol, n);
		}
		else{
			printf("mal");
		}
	}
}


molecula *crearMoleculas(int **mundo, int n, int nMoleculas, int nPasos){
	//crea un vector con el numero de moleculas indicado
	molecula *moleculas = (molecula *)malloc(sizeof(molecula) * nMoleculas);
	//se crean las posiciones iniciales de las moleculas y las hace moverse
	for (int i = 0; i < nMoleculas; ++i){
		//con esto se crea la posicion inicial de las moleculas
		obtenerPosicionInicial(mundo, n, moleculas[i]);
		//se obtiene la posicion final de las moleculas
		caminar(mundo, n, moleculas[i], nPasos);
	}
	return moleculas;
}

int *HacerHistograma(molecula *mol, int n, int nMoleculas, int nPasos){
	int *valores = (int *)malloc(sizeof(int)*(2*nPasos  + 1));
	int *hist, dist;
	hist = valores + nPasos - 1;
	for (int i = 0; i < nMoleculas; ++i){
		dist = mol[i].inicial.x - mol[i].actual.x + n*mol[i].planoActual.planosx;
		hist[dist] += 1;
	}
	return hist;
}

void imprimirHistograma(int *hist, int nPasos){
	int dist;
	for (int i = 0; i < 2 * nPasos + 1; ++i){
		dist = i - nPasos;
		printf("Distancia %d\n", dist);
		printf("Moleculas %d\n", hist[dist]);
	}
}


void run(int n, int nObstaculos, int nMoleculas, int nPasos){
	srand(time(NULL));
	int **mundo = mundo_limpio(n), *hist;
	ponerObstaculos(mundo, n, nObstaculos);
	imprimir(mundo, n);
	molecula *moleculas = crearMoleculas(mundo, n, nMoleculas, nPasos);
	hist = HacerHistograma(moleculas, n, nMoleculas, nPasos);
	imprimirHistograma(hist, nPasos);
	terminar(mundo);
	free(hist-nPasos + 1);
	free(moleculas);
}