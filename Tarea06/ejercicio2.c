#include <stdio.h>
#include <math.h>

int main()
{
	int clave= 0;
	float num1, num2, final;
	while (clave != 8){
		printf("Ingresa 1 para sumar, 2 para restar, 3 para mutiplicar, 4 para dividir, 5 para sin, 6 para cos, 7 para tan y 8 para salir\n");
		scanf("%d", &clave);
		switch(clave){
			case 1:
				printf("Ingresa dos números para sumarlos\n");
				scanf("%f", &num1);
				scanf("%f", &num2);
				final = num1 + num2;
				printf("La suma es: %f\n", final);
				break;
			case 2:
				printf("Ingresa dos números para restarlos\n");
				scanf("%f", &num1);
				scanf("%f", &num2);
				final = num1 - num2;
				printf("La resta es: %f\n", final);
				break;
			case 3:
				printf("Ingesa dos números para multiplicarlos\n");
				scanf("%f", &num1);
				scanf("%f", &num2);
				final = num1 * num2;
				printf("El producto es: %f\n", final);
				break;
			case 4:
				printf("Ingresa dos números para dividirlos\n");
				scanf("%f", &num1);
				scanf("%f", &num2);
				final = num1 / num2;
				printf("La división es: %f\n", final);
				break;
			case 5:
				printf("Ingresa un núemro para sacar el seno\n");
				scanf("%f", &num1);
				final = sin(num1);
				printf("El seno es: %f\n", final);
				break;
			case 6:
				printf("Ingresa un numero para sacar el coseno\n");
				scanf("%f", &num1);
				final = cos(num1);
				printf("El coseno es: %f\n", final);
				break;
			case 7:
				printf("Ingresa un núemro para sacar la tangente\n");
				scanf("%f", &num1);
				final = tan(num1);
				printf("La tangente es: %f\n", final);
				break;
			case 8:
				printf("\n");
				break;
			default:
				printf("Clave no identificado\n");
				break;
		}
	}
	return 0;
}