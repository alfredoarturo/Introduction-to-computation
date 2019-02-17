#include <stdio.h>
#include <math.h>

int main() {
	float a;
	float b;
	float c;
	float raiz1;
	float raiz2;
	float dis;
	printf("Introduce el coeficiente de x²\n");
	scanf("%f", &a);
	printf("Introduce el coeficiente de x¹\n");
	scanf("%f", &b);
	printf("Introduce el coeficiente de x⁰\n");
	scanf("%f", &c);
	dis = b*b - 4*a*c;
	if (dis > 0){
		raiz1 = (-b + (sqrt(dis))/2*a);
		raiz2 = (-b - (sqrt(dis))/2*a);
		printf("Las raices de la ecuacion son: %f, %f\n", raiz1, raiz2);
	}
	return 0;
}