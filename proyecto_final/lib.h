typedef struct coord COORD;
typedef struct alien ALIEN;
typedef struct grupoalien GRUPOALIEN;
typedef struct disp DISP;
typedef struct records RECORDS;

int kbhit(void);
void gotoxy(int x, int y);
void limpiar();
void delay(int a);
void GameOver();
GRUPOALIEN *crearGrupoalien(int nAliens, char *tipoAlien1, char *tipoAlien2, COORD inicial, int puntaje);
void imprimirAliens(GRUPOALIEN **aliens, int nTurno, int nGrupos);
void mover_y(GRUPOALIEN **aliens, int nGrupos);
void direccion(GRUPOALIEN **aliens, int nGrupos, int *dir);
void mover_x(GRUPOALIEN **aliens, int nGrupos, int dir);
DISP *disparos(int nDisparos);
void imprimirUsuario(int coor_x, char *usr);
void quitarCursor();
void dispara(DISP *disp, int coor_x);
void imprimirDisparos(DISP *disp, int nDisparos);
void moverDisparos(DISP *disp, int nDisparos);
void moverUsuario(char *usr, int *coor_x, char c, DISP *disp);
void matarAlien(DISP *disp, GRUPOALIEN **aliens, int nGrupos);
int pasarNivel(GRUPOALIEN **aliens, int nGrupos, int *score);
void imprimirPuntaje(GRUPOALIEN **aliens, int nGrupos, int *scoreGlobal, int vidas);
void imprimirDisparosAlien(DISP *disp, int nDisparos);
void moverDisparosAlien(DISP *disp, int nDisparos);
void dispararAlien(GRUPOALIEN **aliens, int nGrupos, DISP *disp, int nDisparos);
void quitarVida(DISP *disp, int nDisparos, int coor_x, int *vidas);
void nivel(int nNivel, int *score);
void run();