#include <stdio.h>
int main () {
	int num1;
	int num2;
	int num3;
	printf("Introduce el primer numero\n");
	scanf("%i", &num1);
	printf("Introduce el segundo numero\n");
	scanf("%i", &num2);
	printf("Introduce el terer numero\n");
	scanf("%i", &num3);
	if (num1 > num2) {
		if (num1 > num3){
			printf("El mayor numero es: %i\n", num1);
		}
		else{
			printf("El mayor numero es: %i\n", num3);
		}
	}
	else{
		if (num2 > num3){
			printf("El mayor numero es: %i\n", num2);
		}
		else{
			printf("El mayor numero es: %i\n", num3);
		}
	}
	return 0;
}