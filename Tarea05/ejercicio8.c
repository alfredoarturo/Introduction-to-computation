#include <stdio.h>
int i=0;
int suma, longitud, media;
char car[2000];

int main() {
	printf("Ingresa una cadena de caracteres para sacar la media\n");
	scanf("%s", &car[0]);
	while (car[i] != '\0') {
		i = i +1;
	}
	longitud = i;
	i = 0;
	while (i < longitud){
		suma = suma + car[i];
		i = i + 1;
	}
	media = suma/longitud;
	printf("La media de los caracteres es: %i\n", media);
	return 0;
}