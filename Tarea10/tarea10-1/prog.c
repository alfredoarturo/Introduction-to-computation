#include <stdio.h>
#include "util.c"
#include "util.h"

int signo;
int pot2( int a ){
    int b;
    b = a*a;
    return b;
}

int main()
{
    int pow, b;
    b = 5;
    printf("Dame un numero:\n");
    scanf("%d", &pow);
    signo = 1;
    pow = cambia_signo(pow);
    printf("El signo cambiado es: %d\n", pow);
    pow = pot2(pow);
    printf("El cuadrado es: %d\n", pow);
    return 0;
}