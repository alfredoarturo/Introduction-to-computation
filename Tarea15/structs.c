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
