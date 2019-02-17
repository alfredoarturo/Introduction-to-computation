#include "algebra.h"
#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

float pro_esc( float *v, float *u, int N ){
    float suma = 0;
    for(int n = 0; n < N; n++ ){
        suma += v[n] * u[n];
    }
    return suma;
}

float *suma( float *u, float *v, int N ){
    float *sum = crea_mem( N );
    for(int n = 0; n < N; n++ ){
        sum[n] = u[n] + v[n];
    }
    return sum;
}

float *resta(float *u, float *v, int N){
    float *res = crea_mem( N );
    for(int i = 0; i < N; ++i){
        res[i] = u[i] + v[i];
    }
    return res;
}

float *proyeccion(float *u, float *v, int N){
    float *proy = crea_mem(N), esc, norm;
    esc = pro_esc(u, v, N);
    norm = pro_esc(u, u, N);
    for (int i = 0; i < N; ++i){
        proy[i] = (esc/norm)*u[i];
    }
    return proy;
}

void libera_mem( float *m ){
    free( m );
}

float *crea_mem( int N ){
    return (float *) malloc( sizeof(float) * N );
}