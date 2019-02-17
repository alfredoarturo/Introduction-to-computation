#include <stdio.h>

int main(){
	int maxnum, minnum;
	int num1= 0, num2=0, num3=0, num4=0, num5=0;
	printf("Introduzca 5 numeros\n");
	scanf("%i, %i, %i, %i, %i", &num1, &num2, &num3, &num4, &num5);
	if (num1 < num2){
		maxnum = num2;
		minnum = num1;
	}
	else{
		minnum = num2;
		maxnum = num1;
	}
	if (maxnum < num3){
		maxnum = num3;
	}
	else{
		if (minnum > num3) {
			minnum = num3;
		}
	}
	if (maxnum < num4) {
		maxnum = num4;
	}
	else{
		if (minnum > num4){
			minnum = num4;
		}
	}
	if (maxnum < num5){
		maxnum = num5;
	}
	else{
		if (minnum > num5){
			minnum = num5;
		}
	}
	printf("El mayor numero es: %i y el menor numero es. %i\n", maxnum, minnum);
	return 0;
}