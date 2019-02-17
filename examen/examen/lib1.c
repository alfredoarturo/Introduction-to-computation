

char *reservarmem(int tam){
	char *uno = (char *)malloc(sizeof(char) * tam);
	return uno;
}

void basura(FILE *fp, int num){
	char *basura = reservarmem(line);
	for (int i = 0; i < num; ++i){
		fgets(basura, line, fp);
		//printf("%s", basura);
	}
}

char *inf(FILE *fp, int num){
	char *text = reservarmem(line);
	for (int i = 0; i < num; ++i){
		fgets(text, line, fp);
		//printf("%s", text);
	} 
	return text;
}

int strcmp1(char *a, char *b){
	for (int i = 0; i < 6; ++i){
		if (a[i] != b[i])
			return 1;
	}
	return 0;
}

char **lineas(FILE *fp, int Nlineas){
	char **texto = (char **)malloc(sizeof(char *) * Nlineas);
	texto[0] = (char *)malloc(sizeof(char) * line * Nlineas);
	for (int i = 1; i < Nlineas; ++i){
		texto[i] = texto[i-1] + line;
	}
	char *aux = reservarmem(7);
	basura(fp, 10);
	int a = 0;
	for (int i = 0; i < 10000; ++i){
		fgets(aux, 7, fp);
		if (strcmp1(aux + 1, "Cycle") == 0){
			basura(fp, 3);
			texto[a] = inf(fp, 1);
			++a;
		}
	}
	return texto;
}

double charfloat(char *texto){
	char *num = (char *)malloc(sizeof(char) * line);
	int i = 0;
	while(texto[i] != ' '){
		num[i] = texto[i];
		++i;
	}
	double a = strtod(num, NULL);
	return a;
}

/*double charfloat2(char *texto){
	char *num = (char *)malloc(sizeof(char) * line);
	int i = 0;
	while(texto[i] != ' '){
		if (texto[i] == 'D'){
			num[i] = 'E';
		}
		else{
			num[i] = texto[i];
			++i;
		}
	}
	double a = strtod(num, NULL);
	return a;
}*/

double *ErrMin(char **texto, int Nlineas){
	double *floats = (double *)malloc(sizeof(double) * Nlineas);
	int count = 0;
	for (int i = 0; i < Nlineas; ++i){
		for (int j = 0; j < line; ++j){
			if (j + 2 < line){
				if (texto[i][j] == 'E' && texto[i][j + 1] == 'r' && texto[i][j + 2] == 'r' && texto[i][j + 3] == 'M'){
					floats[count] = charfloat(texto[i] + j + 8);
					++count;
					break;
				}
			}
		}
	}
	return floats;
}

double *EnMin(char **texto, int Nlineas){
	double *floats = (double *)malloc(sizeof(double) * Nlineas);
	int count = 0;
	for (int i = 0; i < Nlineas; ++i){
		for (int j = 0; j < line; ++j){
			if (j + 2 < line && j-1 > 0){
				if (texto[i][j-1] != 'I' && texto[i][j] == 'E' && texto[i][j + 1] == 'n' && texto[i][j + 2] == 'M' && texto[i][j + 3] == 'i'){
					floats[count] = charfloat(texto[i] + j + 7);
					++count;
					break;
				}
			}
		}
	}
	return floats;
}

double prom(double *nums){
	double suma = 0;
	for (int i = 0; i < 11; ++i){
		suma += nums[i];
	}
	return suma/11;
}

double minimo(double *nums){
	double min = nums[0];
	for (int i = 0; i < 11; ++i){
		if (min > nums[i]){
			min = nums[i];
		}
	}
	return min;
}

double *run(const char *archivo){
	FILE *fp;
	fp = fopen(archivo, "rt");
	if(fp == NULL){
        printf("No se abrio el archivo\n");
        exit(1);
    }
    char **texto = lineas(fp, 11);
    double *Enmins = EnMin(texto, 11);
    double promedio = prom(Enmins);
    printf("El promedio es: %lf\n", promedio);
    double *Errmin = ErrMin(texto, 12);
    double menor = minimo(Errmin);
    printf("El menor ErrMin es: %lf\n", menor);

    //fclose (fp);
}