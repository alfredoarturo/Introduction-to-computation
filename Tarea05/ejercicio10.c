#include <stdio.h>

int main(){
	char car[2000], final[2000];
	int i = 0, longitud, a;
	char aux;
	printf("Ingresa una cadena de caracteres para obtener la mediana\n");
	scanf("%s", &car[0]);
	while(car[i] != '\0'){
		i = i +1;
	}
	longitud = i;
	i = 0;
	while(i<longitud){
		a = 0;
		while(i-a>=0){
			if (car[i]< car[i-a]){
				aux = car[i-a];
				car[i-a] = car[i];
				car[i] = aux;
				a = 0;
			}
			else{
				aux = car[i];
				car[i] = car[i-a];
				car[i-a] = aux;
			}
			a = a + 1;
		}
		i = i + 1;
	}
	final[0] = car[longitud-1];
	i = 0;
	while(i<longitud-1){
		final[i+1] = car[i];
		i = i +1;
	}
	if (longitud % 2 ==1){
		printf("%c\n", final[longitud/2]);
	}
	else{
		printf("%c, %c\n", final[longitud/2], final[(longitud/2)+1]);
	}
	return 0;
}