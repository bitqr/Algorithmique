#include"PCA.h"

FILES *choix_d_activites_glouton(TABLEAU *s, TABLEAU *f){
	int n = s->longueur;
	FILES *A = creer_file_vide(n-1);
	A = enfiler(A,1);
	int i=1;
	int m;
	for(m=2;m<n;m++)
		if(s->valeurs[m] >= f->valeurs[i]){
			A = enfiler(A,m);
			i = m;
		}
	return A;
}





