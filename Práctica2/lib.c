#include <stdio.h>
#include "lib.h"

int funcion1 (int p){
   int i = 1, s= 2;
   while (s < p/2){
      if (p%s == 0){
         i = 0;
         break;
      }
   s = s +1;
   }
   return i;
}

int funcion2 (int num){
   int cont = 0;
   while (num != 1){
      cont = cont + 1;
      if (num % 2 == 0){
         num = num/2;
      }
      else{
         num = num*3 + 1;
      }
   }
   return cont;
}

