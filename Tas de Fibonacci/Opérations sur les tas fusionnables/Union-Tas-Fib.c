#include"TASFIB.h"

TAS_FIBONACCI *union_tas_fib(TAS_FIBONACCI *T1, TAS_FIBONACCI *T2){
	TAS_FIBONACCI *T=creer_tas_fib();
	T->min=T1->min;
	concatenerListes(T2->min,T->min);
	if(T1->min==NIL||(T2->min!=NIL&&T2->min->cle<T1->min->cle))
		T->min=T2->min;
	T->n=T1->n+T2->n;
	free(T1);
	free(T2);
	return T;
}

