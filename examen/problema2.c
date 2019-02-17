#include <stdio.h>

int main(){
	int num1, aux;
	int i=0;
	int final[64];
	printf("Ingesa un numero a pasar a base 8\n");
	scanf("%i", &num1);
	aux = num1;
	while(aux>0){
		final[i]=(aux%8);
		aux = aux - (aux%8);
		aux = aux/8;
		i = i +1;
	}
	i = i-1;
	while (i >= 0){
		printf("%d", final[i]);
	i = i-1;
	}
	printf("\nEse fue el numero en base 8\n");
}
