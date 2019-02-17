#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int r; //real
    int i; //imaginaria
}complejo;

int main(void){
    int enteros[3];
    float floats[2];
    complejo complejos[3];
    char cadena[20];
    double doubles[10];
    FILE *fp;

    fp = fopen("texto.dat", "wt");
    if(fp == NULL)
    {
        printf("No se abrio el archivo\n");
        exit(1);
    }

    printf("Ingresa 3 enteros:\n");
    int i;
    for(i=0;i<3;i++)
    {
        scanf("%d",&enteros[i]);
        fwrite(enteros+i, sizeof(int),1, fp);
    }

    printf("Ingresa 2 flotantes:\n");
    for(i=0;i<2;i++)
    {
        scanf("%f",&floats[i]);
        fwrite(floats + i, sizeof(float), 1, fp);
    }

    printf("Ingresa las partes reales e imaginarias de 3 complejos:\n");

    for(i=0;i<3;i++)
    {
        scanf("%d",&complejos[i].r);
        scanf("%d",&complejos[i].r);
        fwrite(complejos + i, sizeof(complejo), 1, fp);
    }

    printf("\nIngresa una cadena de 20 caracteres:\n");
    scanf("%s",cadena);
    fwrite(cadena, sizeof(char), 20, fp);



    printf("\nIngresa 10 doubles:\n");
    for(i=0;i<10;i++)
    {
        scanf("%lf",&doubles[i]);
        fwrite(doubles +i, sizeof(double), 1, fp);
    }

    fclose(fp);

    return 0;
}