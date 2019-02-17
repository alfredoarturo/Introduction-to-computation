#include <stdio.h>
#include <math.h>
#define MAX_DIM 1800
float F,f[MAX_DIM];
int N,n=0,k;
float inp, final;
int max, min;
int main()
{
    printf("Introduzca un valor para el dominio de la funcion\n");
    scanf("%d",&N);
    printf("Introduzca un valor para el periodo de la funcion\n");
    scanf("%d",&k);
    F=2*M_PI/N;
    for(n=0;n<N;n++)
    {
        f[n]= sin(F*k*n);
    }
    for(n=0;n<N;n++)
    {
        printf("f[%d]->%f\n",n,f[n]);
    }
    printf("Introduzca el valor a evaluar en la funcion\n");
    scanf("%f", &inp);
    min = ((int)inp);
    max = min + 1;
    final = ((f[max]-f[min])*(inp-min)/(max-min))+f[min];
    printf("La respuesta es: %f",final);
    return 0;
}
