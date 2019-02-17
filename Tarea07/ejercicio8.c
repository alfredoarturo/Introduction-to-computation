#include <stdio.h>

int main(){
	char inp[10000];
	int i = 0;
	printf("Ingrese una cadena de caracteres\n");
	scanf("%s", &inp[0]);
	while (inp[i] != '\0'){
		if (inp[i] > 64 && inp[i] < 91){
			printf("%c", inp[i]+32);
		}
		else{
			printf("%c", inp[i]);
		}
		i = i + 1;
	}
	printf("\n");
	return 0;
}