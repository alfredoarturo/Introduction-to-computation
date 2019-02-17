#include <stdio.h>
#include <stdlib.h>

int strlenRecursive(char *cadena){
	if (*cadena == '\0')
		return 0;
	return 1 + strlenRecursive(cadena + 1);
}

void reverseRecursive(char *cadenaOriginal, char *cadenaRevertida){
	*(cadenaRevertida + strlenRecursive(cadenaOriginal) - 1) = *cadenaOriginal;
	if (strlenRecursive(cadenaOriginal) == 1)
		return;
	reverseRecursive(cadenaOriginal+1, cadenaRevertida);
	return;
}

void reverseInter(char *cadenaOriginal, char *cadenaRevertida){
	for (int i = 0; i < strlenRecursive(cadenaOriginal); ++i){
		*(cadenaRevertida + strlenRecursive(cadenaOriginal) -1 - i) = *(cadenaOriginal + i);
	}
}

void strcpyRecursive(char *cadenaOriginal, char *copiaCadena){
	*copiaCadena = *cadenaOriginal;
	if (strlenRecursive(cadenaOriginal) == 1)
		return;
	strcpyRecursive(cadenaOriginal+1, copiaCadena+1);
	return;
}

void strcpyInter(char *cadenaOriginal, char *copiaCadena){
	for (int i = 0; i < strlenRecursive(cadenaOriginal); ++i){
		*(copiaCadena + i) = *(cadenaOriginal + i);
	}
}

int main(void){
	char *cadena = (char *)malloc(sizeof(char) * 10);
	char *revertida = (char *)malloc(sizeof(char) * 10);
	char *revertida2 = (char *)malloc(sizeof(char) * 10);
	char *copia = (char *)malloc(sizeof(char) * 10);
	char *copia2 = (char *)malloc(sizeof(char) * 10);
	cadena[0] = 'H';
	cadena[1] = 'o';
	cadena[2] = 'l';
	cadena[3] = 'a';
	cadena[4] = ' ';
	cadena[5] = 'm';
	cadena[6] = 'u';
	cadena[7] = 'n';
	cadena[8] = 'd';
	cadena[9] = 'o';
	reverseRecursive(cadena, revertida);
	reverseInter(cadena, revertida2);
	strcpyRecursive(cadena, copia);
	strcpyInter(cadena, copia2);
	printf("%s\n", cadena);
	printf("%s\n", revertida);
	printf("%s\n", revertida2);
	printf("%s\n", copia);
	printf("%s\n", copia2);
	return 0;
}