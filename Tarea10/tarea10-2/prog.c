#include "algebra.h"
#include "algebra.c"
#include <stdio.h>

int main(){
    int N, n;
    float *u, *v, *sum, *res, esc, *proy;
    printf("Dame dimension:\n");
    scanf("%d", &N);
    u = crea_mem(N);
    v = crea_mem(N);

    printf("Introcuzca el primer vector\n");
    for(int i = 0; i < N; ++i){
        scanf("%f", &u[i]);
    }

    printf("Introduzca el segundo vector\n");
    for (int i = 0; i < N; ++i){
        scanf("%f", &v[i]);
    }

    sum = suma(u, v, N);
    res = resta(u, v, N);
    esc = pro_esc(u, v, N);
    proy = proyeccion(u, v, N);

    printf("Suma de los vectores:\n");
    for(int i = 0; i < N; ++i){
        printf("%f ", sum[i]);
    }

    printf("\nResta de los vectores:\n");
    for(int i = 0; i < N; ++i){
        printf("%f ", res[i]);
    }

    printf("\nProducto punto:\n%f\n", esc);

    printf("Proyeccion\n");
    for(int i = 0; i < N; ++i){
        printf("%f ", proy[i]);
    }
    printf("\n");

    libera_mem(u);
    libera_mem(v);
    libera_mem(sum);
    libera_mem(res);
    libera_mem(proy);
    return 0;

}