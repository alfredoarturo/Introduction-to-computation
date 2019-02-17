#include <stdio.h>

int main(){
   char palabra[2000];
   int longitud;
   int aux=1, i=0;
   printf("Ingresa una cadena de caracteres\n");
   scanf("%s", &palabra[0]);
   while (palabra[i] != '\0'){
      i = i + 1;
   }
   longitud = i;
   i = 0;
   while (i < longitud){
      if (palabra[i] != palabra[(longitud-i)-1]){
         aux = 0;
      }
      i = i + 1;
   }
   if (aux == 1){
      printf("Si es palindromo\n");
   }
   else{
      printf("No e spalindromo\n");
   }
}
