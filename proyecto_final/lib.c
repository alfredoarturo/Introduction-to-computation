#include "lib.h"

/*Adaptaion de kbhit en linux*/
#include <sys/select.h>
int kbhit(void)
{
struct timeval tv;
fd_set read_fd;

tv.tv_sec=0;
tv.tv_usec=0;
FD_ZERO(&read_fd);
FD_SET(0,&read_fd);

if(select(1, &read_fd, NULL, NULL, &tv) == -1)
return 0;

if(FD_ISSET(0,&read_fd))
return 1;

return 0;
}
/*Fin de adaptacion de kbhit en linux*/

/*Inician las estructuras de datos usados*/
struct coord {
	int x;
	int y;
};					//marca la ubucacion (x, y) de un objeto

struct alien {
	COORD inicial;			//su coordenada con la que se imprime
	int x_final;			//su cordenada donde termina de imprimirse
	int vivo_muerto;		//Denota si está VIVO o MUERTO
	int punt;				//Es el puntaje que vale matar a este alien
};

struct grupoalien {
	ALIEN *aliens;			//es un arreglo de aliens
	int tam;				//tamaño del arreglo de aliens
	char *forma1, *forma2;	//Las formas que tiene, para que tenga movimiento
};

struct disp {
	COORD actual;			//posicion en la que está el disparo
	int activo;				//1 es activo, 0 es inactivo
};
/*Terminan las estructuras de datos usadas*/


/*Funciones para imporimir en pantalla*/
void gotoxy(int x, int y) {
	//pone el cursor en la posicion indicada
    printf("%c[%d;%df",0x1B,y,x);
}

void limpiar(){
	//limpia la pantalla, pone espacios
	for (int i = 0; i < 78; ++i){
		for (int j = 0; j < 27; ++j){
			printf(" ");
		}
	}
}

void imprimirAliens(GRUPOALIEN **aliens, int nTurno, int nGrupos){
	//imprime a los aliens en su coordenada indicada
	if (nTurno % 2 == 0){
		for (int j = 0; j < nGrupos; ++j){
			for (int i = 0; i < aliens[j]->tam; ++i){
				if(aliens[j]->aliens[i].vivo_muerto == VIVO){
					gotoxy(aliens[j]->aliens[i].inicial.x, aliens[j]->aliens[i].inicial.y);
					printf("%s\n", aliens[j]->forma1);
				}
			}
		}
	}
	else{
		for (int j = 0; j < nGrupos; ++j){
			for (int i = 0; i < aliens[j]->tam; ++i){
				if (aliens[j]->aliens[i].vivo_muerto == VIVO){
					gotoxy(aliens[j]->aliens[i].inicial.x, aliens[j]->aliens[i].inicial.y);
					printf("%s\n", aliens[j]->forma2);
				}
			}
		}
	}
}

void imprimirUsuario(int coor_x, char *usr){
	//imprime al usuario en su coordenada indicada
	gotoxy(coor_x, 22);
	printf("%s\n", usr);
}

void quitaCursor(){
	//quita el cursor de la pantall
	gotoxy(0,0);
}

void imprimirDisparos(DISP *disp, int nDisparos){
	//imprime los disparos en la posicion indicada
	for (int i = 0; i < nDisparos; ++i){
		if (disp[i].activo == 1){
			gotoxy(disp[i].actual.x, disp[i].actual.y);
			printf("%c\n", '!');
			gotoxy(disp[i].actual.x, disp[i].actual.y -1);
			printf("%c\n", '|');
		}
	}
}

void imprimirPuntaje(GRUPOALIEN **aliens, int nGrupos, int *scoreGlobal, int vidas){
	//imprime el puntaje y las vidas actuales
	int score = 0;
	int count = 0;
	for (int i = 0; i < nGrupos; ++i){
		for (int j = 0; j < aliens[i]->tam; ++j){
			if (aliens[i]->aliens[j].vivo_muerto == MUERTO){
				score += aliens[i]->aliens[j].punt;
			}
		}
	}
	score = score + *scoreGlobal;
	gotoxy(5, 2);
	printf("Score: %d\n", score);
	gotoxy(25, 2);
	printf("Vidas: %d\n", vidas);
}

void imprimirDisparosAlien(DISP *disp, int nDisparos){
	//imprime los disparos de los aliens en la posicion indicada
	for (int i = 0; i < nDisparos; ++i){
		if (disp[i].activo == 1){
			gotoxy(disp[i].actual.x, disp[i].actual.y);
			printf("|\n");
		}
	}
}
/*Terminana las funciones para imprimir en pantall*/

/*Funciones que dan funcionalidad a los aliens y usuario*/
void moverDisparosAlien(DISP *disp, int nDisparos){
	//mueve los disparos de los aliens
	for (int i = 0; i < nDisparos; ++i){
		if (disp[i].activo == 1){
			disp[i].actual.y += 1;
			if (disp[i].actual.y > 23){
				disp[i].activo = 0;
			}
		}
	}
	imprimirDisparosAlien(disp, nDisparos);
}

void dispararAlien(GRUPOALIEN **aliens, int nGrupos, DISP *disp, int nDisparos){
	//elige cuando disparan los aliens
	for (int i = 0; i < nGrupos; ++i){
		for (int j = 0; j < aliens[i]->tam; ++j){
			if (rand() % 2 == 0 && aliens[i]->aliens[j].vivo_muerto == VIVO){
				for (int k = 0; k < nDisparos; ++k){
					if (disp[k].activo == 0){
						disp[k].actual.x = aliens[i]->aliens[j].inicial.x + 2;
						disp[k].actual.y = aliens[i]->aliens[j].inicial.y;
						disp[k].activo = 1;
						break;
					}
				}
			}
		}
	}
	moverDisparosAlien(disp, nDisparos);
}

void quitarVida(DISP *disp, int nDisparos, int coor_x, int *vidas){
	//quita una vida al usuario cuando le pega un alien
	for (int i = 0; i < nDisparos; ++i){
		if (disp[i].actual.y == 22){
			if (disp[i].actual.x >= coor_x && disp[i].actual.x <= coor_x + 5){
				*vidas -= 1;
			}
			if (*vidas == 0){
				GameOver();
			}
		}
	}
}

void mover_y(GRUPOALIEN **aliens, int nGrupos){
	//mueve a los aliens en las coordenadas y
	for (int i = 0; i < nGrupos; ++i){
		for (int j = 0; j < aliens[i]->tam; ++j){
			aliens[i]->aliens[j].inicial.y += 1;
			if (aliens[i]->aliens[j].inicial.y == 22){
				GameOver();
				return;
			}
		}
	}
}

void direccion(GRUPOALIEN **aliens, int nGrupos, int *dir){
	//establece la direccion que deben tener los aliens
	for (int i = 0; i < nGrupos; ++i){
		for (int j = 0; j < aliens[i]->tam; ++j){
			if (aliens[i]->aliens[j].inicial.x < 3 && aliens[i]->aliens[j].vivo_muerto == VIVO){
				*dir = *dir * -1;
				mover_y(aliens, nGrupos);
				return;
			}
			else if (aliens[i]->aliens[j].x_final > 78 && aliens[i]->aliens[j].vivo_muerto == VIVO){
				*dir = *dir * -1;
				mover_y(aliens, nGrupos);
				return;
			}
		}
	}
}

void mover_x(GRUPOALIEN **aliens, int nGrupos, int dir){
	//mueve a los aliens en el eje x
	for (int i = 0; i < nGrupos; ++i){
		for (int j = 0; j < aliens[i]->tam; ++j){
			aliens[i]->aliens[j].inicial.x = aliens[i]->aliens[j].inicial.x + 2*dir;
			aliens[i]->aliens[j].x_final = aliens[i]->aliens[j].x_final + 2*dir;
		}
	}
}

void dispara(DISP *disp, int coor_x){
	//Esto es lo que pasa cuando dispara el usuario
	for (int i = 0; i < 100; ++i){
		if (disp[i].activo == 0){
			disp[i].actual.x = coor_x + 2;
			disp[i].actual.y = 23;
			disp[i].activo = 1;
			return;
		}
	}
}

void moverDisparos(DISP *disp, int nDisparos){
	//mueve los disparos del usuario
	for (int i = 0; i < nDisparos; ++i){
		if(disp[i].activo == 1){
			disp[i].actual.y -= 2;
		}
		if(disp[i].actual.y <= 3){
			disp[i].activo = 0;
		}
	}
	imprimirDisparos(disp, nDisparos);
}

void moverUsuario(char *usr, int *coor_x, char c, DISP *disp){
    //Esto es para mover al usuario
    if (c == USR_IZQUIERDA && *coor_x - 1 > 1){
     	*coor_x -= 1;
    }
    if(c == USR_DERECHA && *coor_x + 1 < 76){
      	*coor_x += 1;
    }
    if(c == DISPARO){
    	dispara(disp, *coor_x);
    }
}

void matarAlien(DISP *disp, GRUPOALIEN **aliens, int nGrupos){
	//esto es para matar a un alien
	for(int i = 0; i < 100; ++i){
		for (int j = 0; j < nGrupos; ++j){
			for (int k = 0; k < aliens[j]->tam; ++k){
				if (disp[i].activo == 0 || aliens[j]->aliens[k].vivo_muerto == MUERTO){
					continue;
				}
				if (disp[i].actual.y == aliens[j]->aliens[k].inicial.y || disp[i].actual.y - 1 == aliens[j]->aliens[k].inicial.y){
					if (disp[i].actual.x >= aliens[j]->aliens[k].inicial.x + 1 && disp[i].actual.x <= aliens[j]->aliens[k].inicial.x + 4){
						aliens[j]->aliens[k].vivo_muerto = MUERTO;
						disp[i].activo = 0;
					}
				}
			}
		}
	}
	moverDisparos(disp, 100);
}
/*Terminan funciones que le dan funcionalidades a los aliens y usuario*/


/*Otras funciones*/
void delay(int a){
	//este es el retardo que se usa
	for (long int i = 0; i < 80000000 - a; ++i){

	}
}

void GameOver(){
	//Termina el juego
	limpiar();
	gotoxy(30, 10);
	printf("GameOver\n");
	exit(1);
}

GRUPOALIEN *crearGrupoalien(int nAliens, char *tipoAlien1, char *tipoAlien2, COORD inicial, int puntaje){
	//genera un grupo alien
	GRUPOALIEN *grupoalien;
	grupoalien = (GRUPOALIEN *)malloc(sizeof(GRUPOALIEN));
	grupoalien->forma1 = (char *)malloc(sizeof(char) * 5);
	grupoalien->forma1 = tipoAlien1;
	grupoalien->forma2 = (char *)malloc(sizeof(char) * 5);
	grupoalien->forma2 = tipoAlien2;
	grupoalien->tam = nAliens;
	grupoalien->aliens = (ALIEN *)malloc(sizeof(ALIEN) * nAliens);
	for (int i = 0; i < nAliens; ++i){
		grupoalien->aliens[i].inicial.x = inicial.x + 5*i;
		grupoalien->aliens[i].inicial.y = inicial.y;
		grupoalien->aliens[i].x_final = inicial.x + 5*i + 3;
		grupoalien->aliens[i].vivo_muerto = VIVO;
		grupoalien->aliens[i].punt = puntaje;
	}
	return grupoalien;
}

DISP *disparos(int nDisparos){
	//genera vector de disparos
	DISP *dis = (DISP *)malloc(sizeof(DISP) * nDisparos);
	for(int i = 0; i < nDisparos; ++i){
		dis[i].actual.x = 0; dis[i].actual.y = 0;
	}
	return dis;
}

int pasarNivel(GRUPOALIEN **aliens, int nGrupos, int *score){
	//guarda score y cambia el nuvel
	for (int i = 0; i < nGrupos; ++i){
		for (int j = 0; j < aliens[i]->tam; ++j){
			if (aliens[i]->aliens[j].vivo_muerto == VIVO){
				return 0;
			}
		}
	}
	for(int i = 0; i < nGrupos; ++i){
		for (int j = 0; j < aliens[i]->tam; ++j){
			*score += aliens[i]->aliens[j].punt;
		}
	}
	return 1;
}

void nivel(int nNivel, int *score){
	//tiene las características que debe de tener un nivel
	GRUPOALIEN **aliens = (GRUPOALIEN **)malloc(sizeof(GRUPOALIEN*) * 5);
	COORD inicial;
	DISP *disparosAliens = disparos(5 * nNivel), *dispUser = disparos(100);
	int turno = 0, dir = DERECHA, coor_x = 40, vidas = nNivel + 1;
	inicial.x = 3;
	inicial.y = 3;
	aliens[0] = crearGrupoalien(NALIENS, " -o_ ", " _o- ", inicial, 250);
	inicial.y += 2;
	aliens[1] = crearGrupoalien(NALIENS, " ,^, ", " .-. ", inicial, 200);
	inicial.y += 2;
	aliens[2] = crearGrupoalien(NALIENS, " o^o ", " *^* ", inicial, 150);
	inicial.y += 2;
	aliens[3] = crearGrupoalien(NALIENS, " -X- ", " _X_ ", inicial, 100);
	inicial.y += 2;
	aliens[4] = crearGrupoalien(NALIENS, " <O> ", " <o> ", inicial, 50);

	char *usr = (char *)malloc(sizeof(char) * 5);
	usr = "/-^-\\";
	char c;

	system ("/bin/stty raw");
	while(c!= 'p'){
		c = 'h';
		limpiar();
		imprimirPuntaje(aliens, 5, score, vidas);
		if (kbhit() == 1)
			c = getchar();
		moverUsuario(usr, &coor_x, c, dispUser);
		imprimirUsuario(coor_x, usr);
		imprimirAliens(aliens, turno,5);
		direccion(aliens, 5, &dir);
		mover_x(aliens, 5, dir);
		matarAlien(dispUser, aliens, 5);
		dispararAlien(aliens, 5, disparosAliens, 5 * nNivel);
		//quitarVida(disparosAliens, 5 * nNivel, coor_x, &vidas);
		quitaCursor();
		delay(90000*turno*nNivel);
		turno ++;
		if (pasarNivel(aliens, 5, score) == 1){
			break;
		}
	}

	if (c == 'p'){
		exit(1);
	}

	for (int i  = 0; i < 5; ++i){
		free(grupoalien[i]->forma1);
		free(grupoalien[i]->forma2);
		free(grupoalien[i]->aliens);
		free(grupoalien[i]);
	}
	free(grupoalien);
	free(disparosAliens);
	free(dispUser);
	free(usr);
}

void run(){
	//esta funcion comienza el juego
	int score = 0;
	limpiar();
	int niv = 1;
	gotoxy(30, 10);
	printf("Space invaders\n");
	delay(-100000000);
	while(niv < 4){
		limpiar();
		gotoxy(30, 10);
		printf("Nivel: %d\n", niv);
		printf("Score: %d\n", score);
		delay(-1000000000);
		nivel(niv, &score);
		++niv;
	}
}