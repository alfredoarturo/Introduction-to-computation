#include <stdio.h>

int main(){
	int n, f[10], num1, enc;
	printf("Ingersa 10 numeros\n");
	for (n = 0; n < 10; ++n){
		scanf("%d", &f[n]);
	}
	printf("Ingersa el numero a buscar\n");
	scanf("%d", &num1);
	for (n = 0; n < 10; ++n){
		if (f[n]==num1){
			enc = 1;
		}
	}
	if (enc == 1){
		printf("El numero %d esta en la lista\n", num1);
	}
	else{
		printf("El número %d no esta en la lista\n", num1);
	}
	return 0;
}