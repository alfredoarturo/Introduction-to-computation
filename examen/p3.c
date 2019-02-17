#include <stdio.h>

int main(){
	int num1, aux;
	int i=0;
	int final[64];
	printf("Ingesa un numero a pasar a base 16\n");
	scanf("%i", &num1);
	aux = num1;
	while(aux>0){
		final[i]=(aux%16);
		aux = aux - (aux%16);
		aux = aux/16;
		i = i +1;
	}
	i = i-1;
	while (i >= 0){
		switch(aux%16){
			case 10:
				printf("A");
				break;
			case 11:
				printf("B");
				break;
			case 12:
				printf("C");
				break;
			case 13:
				printf("D");
				break;
			case 14:
				printf("E");
				break;
			case 15:
				printf("F");
				break;
			default:
				printf("%d", final[i]);
				break;
		}
		
	i = i-1;
	}
	printf("\nEse fue el numero en base 16\n");
}
