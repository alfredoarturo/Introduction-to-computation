#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct bienes {
	float valor;
	char nombre[100];
} bien;

void vaciar(int *vec, int tamano){
	for (int i = 0; i<tamano; ++i){
		vec[i] = 0;
	} 
}

void dec2bin(int num, int *vec, int tamano){
	for(int i = 0; i<tamano; ++i){
		vec[i] = num % 2;
		num -= num % 2;
		num = num/2;
	}
}

float diferenciaDinero(int *casos, int tamano, bien *bienes){
	float socio1 = 0, socio2 = 0, dif = 0;
	for (int i = 0; i < tamano; i++){
		if (casos[i] == 1){
			socio1 += bienes[i].valor;
		}
		else{
			socio2 += bienes[i].valor;
		}
	}
	if (socio2 < socio1){
		dif = socio1 - socio2;
	}
	else{
		dif = socio2 - socio1;
	}
}

int main(void){
	int n = 7, m = 2;
	bien *bienes = (bien *)malloc(sizeof(bien)*n);
	bienes[0].valor = 7000000;
	strcpy(bienes[0].nombre, "oficina_san_juan");
	bienes[1].valor = 5000000;
	strcpy(bienes[1].nombre, "oficina_centro");
	bienes[2].valor = 4200000;
	strcpy(bienes[2].nombre, "oficina_6");
	bienes[3].valor = 1300000;
	strcpy(bienes[3].nombre, "almacen_los_puntes");
	bienes[4].valor = -1500000;
	strcpy(bienes[4].nombre, "deuda_santander");
	bienes[5].valor = 2000000;
	strcpy(bienes[5].nombre, "oficina_el_toral");
	bienes[6].valor = 440000;
	strcpy(bienes[6].nombre, "tractor");

	int ncasos = pow(m, n);
	int i, idxmejor = -1, *bin = (int *)malloc(sizeof(int)*n);

	dec2bin(ncasos-1, bin, n);
	float mejorcaso = diferenciaDinero(bin, n, bienes), dif;

	for(i=0; i < ncasos; ++i){
		vaciar(bin, n);
		dec2bin(i,bin,n);
		dif = diferenciaDinero(bin, n, bienes);
		if (dif < mejorcaso){
			mejorcaso = dif;
			idxmejor = i;
		}
	}

	vaciar(bin, n);
	dec2bin(idxmejor, bin, n);
	printf("Mejor diferencia: %f\n\n", mejorcaso);
	printf("socio1\n");
	for(int i = 0; i < n; ++i){
		if (bin[i] == 1){
			printf("%s, %f\n", bienes[i].nombre, bienes[i].valor);
		}
	}
	printf("\nsocio2\n");
	for (int i = 0; i < n; ++i){
		if (bin[i] == 0){
			printf("%s, %f\n", bienes[i].nombre, bienes[i].valor);
		}
	}
	free(bin);
	free(bienes);
}