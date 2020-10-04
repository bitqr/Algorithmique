#include"TASBIN.h"

void tas_binomial_supprimer(TAS_BINOMIAL **T, NOEUD_TAS_BINOMIAL *x){
	tas_binomial_diminuer_cle(*T,x,-INFINI);
	tas_binomial_extraire_min(T);
}


