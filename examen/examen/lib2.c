
typedef struct{
	float real;
	float img;
} IMAG;

IMAG *reservarmem(int tam){
	IMAG *vec = (IMAG *)malloc(sizeof(IMAG) * tam);
	return vec;
}

void rellenar(IMAG *vec, int tam){
	float a;
	for (int i = 0; i < tam; ++i){
		a =  rand();
		vec[i].real = ((a / RAND_MAX) * 10) - 5;
		a = rand();
		vec[i].img = ((a / RAND_MAX) * 10) - 5;
	}
}

IMAG* transFourier(IMAG *vec, int tam){
	IMAG *trans = reservarmem(tam);
	float seno;
	float coseno;
	for (int i = 0; i < tam; ++i){
		for (int j = 0; j < tam; ++j){
			seno = sin((2*M_PI/tam)*i*j);
			coseno = cos((2*M_PI/tam)*i*j);
			trans[i].real += vec[j].real*coseno + vec[j].img*seno;
			trans[i].img += vec[j].img*coseno - vec[j].real*seno;
		}
	}
	return trans;
}

void imprimirImg(IMAG * vec, int tam){
	for (int i = 0; i < tam; ++i){
		printf("X%d-> %f + %fi\n", i, vec[i].real, vec[i].img);
	}
}