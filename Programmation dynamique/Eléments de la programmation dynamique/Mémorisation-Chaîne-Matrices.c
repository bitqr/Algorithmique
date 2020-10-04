#include"Mat.h"

memorisation_chaine_matrices(DIM *p, int **m){
	int n = p->longueur - 1;
	int i,j;
	for(i=0;i<n;i++)
		for(j=i;j<n;j++)
			m[i][j] = INFINI;
	return recuperer_chaine(p,0,n-1,m);
}



