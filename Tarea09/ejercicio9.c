#include <stdio.h>
#include "mylib.h"
#include "mylib.c"

int main(){
	//ejercicio1
	char cadena[1000], copia[1000];
	printf("Ingresa una cadena\n");
	scanf("%s", &cadena[0]);
	copy(cadena, copia);
	printf("%s\n", copia);
	limpiar(cadena);

	//ejercicio2
	printf("Ingresa una cadena para encontrar la longitud\n");
	char inp[1000];
	scanf("%s", &inp[0]);
	printf("%d\n", longitud(inp));

	//ejercicio3
	char cadena1[1000], cadena2[1000];
	printf("Ingresa dos cadenas para compararlas\n");
	printf("Ingresa la primer cadena\n");
	scanf("%s", &cadena1[0]);
	printf("Ingresa la segunda cadena\n");
	scanf("%s", &cadena2[0]);
	if (igual(cadena1, cadena2) == 's'){
		printf("Las cadenas son iguales\n");
	}
	else{
		printf("Las cadenas son distintas\n");
	}

	//ejercicio4
	printf("Ingresa una cadena a pasar a mayusculas\n");
	scanf("%s", &cadena[0]);
	mayusc(cadena);
	printf("%s\n", cadena);
	limpiar(cadena);

	//ejercicio5
	printf("Ingresa una cadena a pasar a minusculas\n");
	scanf("%s", &cadena[0]);
	minusc(cadena);
	printf("%s\n", cadena);
	limpiar(cadena);

	//ejercicio6
	char l;
	int n;
	printf("Ingresa una cadenae\n");
	scanf("%s", &cadena[0]);
	printf("Ingresa un caracter\n");
	scanf("%s", &l);
	printf("Ingresa las veces a poner en la cadena\n");
	scanf("%d", &n);
	rellenar(n, l);
	printf("%s\n", cadena);
	l = '\0';
	limpiar(cadena);

	//ejercicio7
	printf("Ingresa una cadenae\n");
	scanf("%s", &cadena[0]);
	printf("Ingresa un caracter\n");
	scanf("%s", &l);
	printf("Ingresa las veces a poner en la cadena\n");
	scanf("%d", &n);
	printf("%s", cadena);
	rellenar(n, l);
	printf("\n");
	l = '\0';
	limpiar(cadena);

	//ejercicio8
	char q[1000];
	int s;
	printf("Ingresa una cadena  ");
	scanf("%s", &cadena[0]);
	printf("Ingresa una cadena a buscar  ");
	scanf("%s", &q[0]);
	s = busc(cadena, q);
	if (s == 1){
		printf("%s si esta en la cadena\n", q);
	}
	else{
		printf("%s no esta en la cadena\n", q);
	}
	limpiar(cadena);
	return 0;
}