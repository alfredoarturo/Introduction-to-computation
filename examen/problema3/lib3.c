#define linea 40

float **reservarmem(){
	float **mat = (float **)malloc(sizeof(float *) * 2);
	mat[0] = (float *)malloc(sizeof(float) * 6);
	mat[1] = mat[0] + 3;
	return mat;
}

char **mat(FILE *fp){
	char **mat = (char **)malloc(sizeof(char *) * 2);
	mat[0] = (char *)malloc(sizeof(char) * linea * 2);
	mat[1] = mat[0] + linea;
	fgets(mat[0], linea, fp);
	fgets(mat[1], linea, fp);
	printf("%s", mat[0]);
	printf("%s\n", mat[1]);
	return mat;
}

char *charfloat(char *mat, int incio){
	char *aux = (char *)malloc(sizeof(char) * linea);
	int a = 0;
	for (int j = incio; j < linea; ++j){
		if (mat[j] != ' ' && mat[j] != '\0' && mat[j] != '\n'){
			aux[a] = mat[j];
			++a;
		}
		else{
			return aux;
		}
	}
}

float **charToFloat(char **mat){
	float **vec = reservarmem();
	char *aux = charfloat(mat[0], 0);
	char *aux2 = charfloat(mat[0], strlen(aux) + 1);
	char *aux3 = charfloat(mat[0], strlen(aux) + strlen(aux2) + 2);
	char *aux4 = charfloat(mat[1], 0);
	char *aux5 = charfloat(mat[1], strlen(aux) + 1);
	char *aux6 = charfloat(mat[1], strlen(aux) + strlen(aux2) + 2);
	vec[0][0] = atof(aux);
	vec[0][1] = atof(aux2);
	vec[0][2] = atof(aux3);
	vec[1][0] = atof(aux4);
	vec[1][1] = atof(aux5);
	vec[1][2] = atof(aux6);
	return vec;
}

float *soluciones(float **vec){
	float *sol = (float *)malloc(sizeof(float) * 2);
	if ((vec[1][1] - (vec[1][0] * vec[0][1] / vec[0][0])) != 0){
		sol[0] = (vec[1][2] - (vec[1][0] * vec[0][2] / vec[0][0])) / (vec[1][1] - (vec[1][0] * vec[0][1] / vec[0][0]));
	}
	else{
		printf("No hay soluciones\n");
		exit(1);
	}
	sol[1] = vec[0][2] - (vec[0][1] * sol[0] / vec[0][0]);
	printf("Soluciones %f, %f\n", sol[0], sol[1]);
	return sol;
}

void write(const char *archivo, float *sol){
	FILE *fp;
	fp = fopen(archivo, "wb");
	fwrite(sol, sizeof(float),1, fp);
	fwrite(sol + 1, sizeof(float), 1, fp);
	fclose(fp);
}

void run(){
	FILE *fp;
	fp = fopen("mat.txt", "rt");
	if(fp == NULL){
        printf("No se abrio el archivo\n");
        exit(1);
    }
    char **m = mat(fp);
    float **M = charToFloat(m);
    float *sol = soluciones(M);
    write("sol.dat", sol);
    free(sol);
    free(m[0]);
    free(m);
    free(M[0]);
    free(M);
}