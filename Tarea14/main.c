#include <stdio.h>
#include <stdlib.h>

float **matriz(int N,int M){
   float **m = (float **)malloc(sizeof(float *) * N);
   int i;
   for(i = 0; i < N; ++i){
      m[i] = (float *)malloc(sizeof(float) * M);
   }
   return m;
}

short int ***cuboide(int N, int M, int O){
   short int ***cub = (short int ***)malloc(sizeof(short int **)*N);
   int i, j;
   for (i = 0; i < N; ++i){
      *(cub + i) = (short int **)malloc(sizeof(short int *)*M);
   }
   for (i = 0; i<N; ++i){
      for (j = 0; j < M; ++j){
        *(*( cub + i) + j) = (short int *)malloc(sizeof(short int) * O);
      }
   }
   return cub;
}

void matriz_v2(float ***m, int N,int M){
   *m = (float **)malloc(sizeof(float *) * N);
   int i;
   for(i = 0; i < N; ++i){
      *(*m + i) = (float *)malloc(sizeof(float) * M);
   }
}

void liberaMemoMatriz2D(float **mat, int N){
   int i;
   for (i = 0; i < N; ++i){
      free(mat[i]);
   }
   free(mat);
}

void liberarMemoMatriz3D(short int ***mat, int N, int M){
   int i, j;
   for (i = 0; i < N; ++i){
      for (j = 0; j < M; ++j){
         free(mat[i][j]);
      }
   }
   for (i = 0; i < N; ++i){
      free(mat[i]);
   }
   free(mat);
}

void llenar_2d(float **mat, int N, int M){
   int i, j;
   for (i = 0; i < N; ++i){
      for (j = 0; j < M; ++j){
         mat[i][j] = rand() % 1000;
      }
   }
}

void llenar_3d(short int ***mat, int N, int M, int O){
   int i, j, k;
   for (i = 0; i < N; ++i){
      for (j = 0; j < M; ++j){
         for (k = 0; k < 0; ++k){
            mat[i][j][k] = rand() % 1000;
         }
      }
   }
}

void imprimir_2d(float **mat, int N, int M){
   int i, j;
   for (i = 0; i < N; ++i){
      for ( j = 0; j < M; ++j){
         printf("%f ", mat[i][j]);
      }
      printf("\n");
   }
}

void imprimir_3d(short int ***mat, int N, int M, int O){
   int i, j, k;
   for (i = 0; i < N; ++i){
      for (j = 0; j < M; ++j){
         for (k = 0; k < O; ++k){
            printf("%d ", mat[i][j][k]);
         }
         printf("\n");
      }
      printf("\n");
   }
}

int main(void){
   float **a, **b;
   short int ***c;
   int N = 12;
   int M = 15;
   int O = 17;
   a = matriz(N, M);
   matriz_v2(&b, N, M);
   c = cuboide(N, M, O);
   llenar_2d(a, N, M);
   llenar_2d(b, N, M);
   llenar_3d(c, N, M, O);
   printf("Primer matriz 2d\n");
   imprimir_2d(a, N, M);
   printf("Segundamatriz 2d\n");
   imprimir_2d(b, N, M);
   printf("Matriz 3d\n");
   imprimir_3d(c, N, M, O);
   liberaMemoMatriz2D(a, N);
   liberaMemoMatriz2D(b, N);
   liberarMemoMatriz3D(c, N, M);
}
