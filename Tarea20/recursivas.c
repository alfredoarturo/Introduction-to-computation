#include <stdio.h>
#include <stdlib.h>

unsigned long factorialRecursive(unsigned long n){
	if (n == 1)
		return 1;
	return n * factorialRecursive(n-1);
}

unsigned long suma_de_enterosRecursive(unsigned long n){
	if (n == 1)
		return 1;
	return n + suma_de_enterosRecursive(n-1);
}

int strlenRecursive(char *cadena){
	if (*cadena == '\0')
		return 0;
	return 1 + strlenRecursive(cadena + 1);
}

int main(void){
	char *cadena = (char *)malloc(sizeof(char)*10);
	cadena[0] = 'H';
	cadena[1] = 'o';
	cadena[2] = 'l';
	cadena[3] = 'a';
	printf("%ld\n", factorialRecursive(5));
	printf("%ld\n", suma_de_enterosRecursive(5));
	printf("%d\n", strlenRecursive(cadena));
}