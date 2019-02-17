int *arreglo(int *num, int tam){
	int *vec = (int *)malloc(sizeof(int) * tam);
	int is = 0, count = 0;
	for (int i = 0; i < tam; ++i){
		for (int j = i+1; j < tam-1-i; ++j){
			if (num[i] == num[j]){
				is = 1;
			}
		}
		if (is == 0){
			vec[count] = num[i];
			count ++;
		}
		is = 0;
	}
	return vec;
}

int longitud(int *vec, int tam){
	int i  = 0, count = 0;
	while(i < tam){
		if (vec[i] != 0){
			count ++;
		}
		++i;
	}
	return count;
}