#include <stdio.h>
int main()
{
	char oracion[2096];
	printf("¿Que oracion quieres imprimir?");
	scanf("%s", oracion);
	printf("Tu oracion es: %s\n", oracion);
	return 0;
}