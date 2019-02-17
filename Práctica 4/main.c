#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _complejo {
	float ent;
	float img;
} comp;

comp *conjugado(comp *n){
	comp *r = (comp *)malloc(sizeof(comp));
	r->ent = n->ent;
	r->img = (n->img)*-1;
	return r;
}

comp *suma(comp *uno, comp *dos){
	comp *s = (comp *)malloc(sizeof(comp));
	s->ent = uno->ent + dos->ent;
	s->img = uno->img + dos->img;
	return s;
}

comp *resta(comp *uno, comp *dos){
	comp *r = (comp *)malloc(sizeof(comp));
	r->ent = uno->ent - dos->ent;
	r->img = uno->img - dos->img;
	return r;
}

comp *multiplicacion(comp *uno, comp *dos){
	comp *m = (comp *)malloc(sizeof(comp));
	m->ent = ((uno->ent * dos->ent) - (uno->img * dos->img));
	m->img = ((uno->img * dos->ent) - (uno->ent * dos->img));
	return m;
}

comp *division(comp *uno, comp *dos){
	comp *d = (comp *)malloc(sizeof(comp));
	d->ent = (((uno->ent * dos->ent) + (uno->img * dos->img))/((uno->ent * uno->ent) + (dos->img * dos->img)));
	d->img = (((uno->img * dos->ent) - (uno->ent * dos->img))/((uno->ent * uno->ent) + (dos->img * dos->img)));
	return d;
}

float absol(comp *a){
	float v;
	v = sqrt((a->ent * a->ent)+(a->img * a->img));
	return v;
}

int main(){
	comp *complejo = (comp *) malloc(sizeof(comp)), *a;
 	comp *comp1 = (comp *) malloc(sizeof(comp)), *b;
	complejo->ent = 172;
	complejo->img = 55;
	comp1->ent = 33.3;
	comp1->img = 62;
	b = multiplicacion(resta(complejo, comp1), resta(complejo, comp1));
	printf("%f %f\n" , b -> ent, b -> img);
	
}
