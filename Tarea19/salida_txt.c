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

    fp = fopen("texto.txt", "wt");
    if(fp == NULL)
    {
        printf("No se abrio el archivo\n");
        exit(1);
    }

    fprintf(fp,"Entereos:\n");
    printf("Ingresa 3 enteros:\n");
    int i;
    for(i=0;i<3;i++)
    {
        scanf("%d",&enteros[i]);
        fprintf(fp,"%d ",enteros[i]);
    }

    fprintf(fp,"\n\nFlotantes:\n");
    printf("Ingresa 2 flotantes:\n");
    for(i=0;i<2;i++)
    {
        scanf("%f",&floats[i]);
        fprintf(fp,"%f ",floats[i]);
    }

    fprintf(fp,"\n\nComplejos:\n");
    printf("Ingresa las partes reales e imaginarias de 3 complejos:\n");

    for(i=0;i<3;i++)
    {
        scanf("%d",&complejos[i].r);
        scanf("%d",&complejos[i].r);
        fprintf(fp,"%d + %di ",complejos[i].r,complejos[i].i);
    }

    fprintf(fp,"\n\nCadena:\n");
    printf("\nIngresa una cadena de 20 caracteres:\n");
    scanf("%s",cadena);
    fprintf(fp,"%s",cadena);



    fprintf(fp,"\n\nDoubles:\n");
    printf("\nIngresa 10 doubles:\n");
    for(i=0;i<10;i++)
    {
        scanf("%lf",&doubles[i]);
        fprintf(fp,"%lf ",doubles[i]);
    }

    fclose(fp);

    return 0;
}