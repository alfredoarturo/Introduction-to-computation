#include <stdio.h>
#include "lib.h"
#include "lib.c"

int main(){
   int p, final;
   printf("Ingresa un numero para ver si es primo\n");
   scanf("%d", &p);
   final = funcion1(p);
   if (final == 1){
      printf("Es primo\n");
   }
   else{
      printf("No es primo\n");
   }
   printf("Ingresa un numero para llevar a 1\n");
   scanf("%d", &p);
   final = funcion2(p);
   printf("Se llego a 1 en %d pasos\n", final);
}
