#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int w;
   int h;
   int **R;
   int **G;
   int **B;
} imagen;

void reservarmem(imagen i1){
   i1.R = (int **)malloc(sizeof(int *) * i1.h);
   i1.G = (int **)malloc(sizeof(int *) * i1.h);
   i1.B = (int **)malloc(sizeof(int *) * i1.h);

   for (int i = 0; i < i1.h; ++i){
    i1.R[i] = (int *)malloc(sizeof(int) * i1.w);
    i1.G[i] = (int *)malloc(sizeof(int) * i1.w);
    i1.B[i] = (int *)malloc(sizeof(int) * i1.w);
  }
}

void sumaImagen(imagen *suma, imagen i1, imagen i2){
  imagen *img;

  if(i1.h == i2.h && i1.w == i2.w){
    img->h = i1.h;
    img->w = i1.w;
    for (int i = 0; i < i1.h; ++i){
      for (int j = 0; i < i1.w; ++j){
        *(*(img->R + i) + j) = *(*(i1.R + i) + j) + *(*(i2.R + i) + j); 
        *(*(img->G + i) + j) = *(*(i1.G + i) + j) + *(*(i2.G + i) + j); 
        *(*(img->B + i) + j) = *(*(i1.B + i) + j) + *(*(i2.B + i) + j); 
      }
    }
  }
  suma = img;
}

void restaImagen(imagen *resta, imagen i1, imagen i2){
  imagen *img;

  if(i1.h == i2.h && i1.w == i2.w){
    img->h = i1.h;
    img->w = i1.w;
    for (int i = 0; i < i1.h; ++i){
      for (int j = 0; i < i1.w; ++j){
        *(*(img->R + i) + j) = *(*(i1.R + i) + j) - *(*(i2.R + i) + j); 
        *(*(img->G + i) + j) = *(*(i1.G + i) + j) - *(*(i2.G + i) + j); 
        *(*(img->B + i) + j) = *(*(i1.B + i) + j) - *(*(i2.B + i) + j); 
      }
    }
  }
  resta = img;
}

imagen transpuesta(imagen i1){
  imagen trans;
  trans.h = i1.w;
  trans.w = i1.h;
  for (int i = 0; i < i1.h; ++i){
    for (int j = 0; j < i1.w; ++j){
      trans.R[j][i] = i1.R[j][i];
      trans.G[j][i] = i1.G[j][i];
      trans.B[j][i] = i1.B[j][i];
    }
  }
  return trans;
}

int sumaparamult(imagen i1, imagen i2, int i, int j){
  int suma = 0;
  for (int k = 0; k < i1.w; k++){
    suma += i1.R[i][k] + i2.R[k][j];
    suma += i1.G[i][k] + i2.G[k][j];
    suma += i1.B[i][k] + i2.B[k][j];
  }
  return suma;
}

imagen multiplicaImagen(imagen i1, imagen i2){
  imagen mult;
  mult.h = i1.h;
  mult.w = i2.w;
  for (int i = 0; i < i1.h; ++i){
    for (int j = 0; j < i2.w; ++j){
      mult.R[i][j] = sumaparamult(i1, i2, i, j);
    }
  }
  return mult;
}

void llenar(imagen i1){
  for (int i = 0; i < i1.h; ++i){
    for (int j = 0; j < i1.w; ++j){
      i1.R[i][j] = rand();
      i1.G[i][j] = rand();
      i1.B[i][j] = rand();
    }
  }
}

void liberarmem(imagen i1){
  for (int i = 0; i < i1.h; ++i){
    free(i1.R[i]);
    free(i1.G[i]);
    free(i1.B[i]);
  }
  free(i1.R);
  free(i1.G);
  free(i1.B);
}

void imprimir(imagen i1){
  for (int i = 0; i < i1.h; ++i){
    for (int j = 0; j < i1.w; ++j){
      printf("%d", i1.R[i][j]);
      printf("%d", i1.G[i][j]);
      printf("%d", i1.B[i][j]);
    }
  }
}

int main(void){
  imagen img1, i2;
  //imagen resta, suma, mult;
  img1.h = 19;
  img1.w = 19;
  //i2.h = 19;
  //i2.w = 19;
  reservarmem(img1);
  //reservarmem(i2);
  //llenar(img1);
  //llenar(i2);
  //sumaImagen(&suma, img1, i2);
  //restaImagen(&resta, img1, i2);
  //mult = multiplicaImagen(suma, resta);
  imprimir(img1);
  //imprimir(resta);
  //imprimir(mult);
  //liberarmem(img1);
  //liberarmem(i2);
  //liberarmem(suma);
  //liberarmem(resta);
}