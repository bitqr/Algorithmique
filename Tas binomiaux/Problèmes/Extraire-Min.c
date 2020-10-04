#include"TAS_2_3_4.h"

NOEUD_TAS_2_3_4 *extraire_min(TAS_2_3_4 *T){
	NOEUD_TAS_2_3_4 *x=minimum(T);
	supprimer(T,x);
	return x;
}



