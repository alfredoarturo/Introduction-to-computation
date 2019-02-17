#include <stdio.h>
#include "mylib.h"

char copy(char cad[1000], char dos[1000]){
	int i = 0;
	while(cad[i] != '\0'){
		dos[i] = cad[i];
		i = i + 1;
	}
	dos[i] = '\0';
	return 'a';
}

int longitud(char cadena[1000]){
	int i = 0; 
	while (cadena[i] != '\0'){
		i = i + 1;
	}
	return i;
}

char igual(char uno[1000], char dos[1000]){
	int i = 0;
	char r = 's';
	while (uno[i] != '\0'){
		if (uno[i] != dos[i]){
			r = 'n';
			break;
		}
		i = i + 1;
	}
	return r;
}

char mayusc (char cad[1000]){
	int i = 0;
	while(cad[i] != '\0'){
		if (cad[i] < 123 && cad[i] > 96){
			cad[i] =  cad[i] - 32;
		}
		i = i + 1;
	}
	return 'a';
}

char minusc (char cad[1000]){
	int i = 0;
	while(cad[i] != '\0'){
		if (cad[i] < 91 && cad[i] > 64){
			cad[i] =  cad[i] + 32;
		}
		i = i + 1;
	}
	return 'a';
}

char rellenar(int N, char letra){
	for (int i = 0; i < N; ++i){
		printf("%c", letra);
	}
	return 'a';
}

int busc(char original[1000], char buscar[1000]){
	int i = 0, a = 1, is = 0;
	a = longitud(buscar);
	while (original[i] != '\0'){
		a = 1;
		if (original[i] == buscar[0]){
			for (int p = 0; p < a; p++){
				if (original[i+a] != buscar[a]){
					a = 0;
					break;
				}
			}
			if (a == 1){
				break;
			}
		}
		else{
			a = 0;
		}
		i = i +1;
	}
	return a;
}

void limpiar(char cadena[1000]){
	for (int i; i <= 1000; ++i){
		cadena[i] = '\0';
	}
}
