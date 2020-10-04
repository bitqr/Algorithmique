#include "PROB.h"

NOEUD *creerEnsemble(int cle){
	NOEUD *x = (NOEUD *)malloc(sizeof(NOEUD));
	x->p = x;
	x->cle = cle;
	x->occupe=0;
}

void lier(NOEUD *x, NOEUD *y){
	if(x->cle < y->cle){
		y->p = x;
	}
	else{
		x->p = y;
	}
}

NOEUD * trouverEnsemble(NOEUD *x){
	if(x != x->p)
		x->p = trouverEnsemble(x->p);
	return x->p;
}

void unionEnsemble(NOEUD *x, NOEUD *y){
	lier(trouverEnsemble(x),trouverEnsemble(y));
}

int * ordonnancement_variante(int *D, int n){
	int i,j,ind;
	NOEUD **T = (NOEUD **)malloc(sizeof(NOEUD *)*n);
	int *O = (int *)calloc(n,sizeof(int));
	for(i=0;i<n;i++){
		T[i] = creerEnsemble(i+1);
	}
	for(i=0;i<n;i++){
		j = trouverEnsemble(T[D[i]-1])->cle;
		if(T[j-1]->occupe == 0){
			T[j-1]->occupe = 1;
			O[j-1] = i+1;
			ind = j-1;
		}
		else if(j>=2){
			T[j-2]->occupe = 1;
			O[j-2] = i+1;
			ind = j-2;
		}
		else if(T[n-1]->occupe == 0){
			T[n-1]->occupe = 1;
			O[n-1] = i+1;
			ind = n-1;
		}
		else{
			j = trouverEnsemble(T[n-1])->cle;
			T[j-2]->occupe = 1;
			O[j-2] = i+1;
			ind = j-2;
		}
		if((ind != n-1) && (T[ind+1]->occupe == 1)){
			unionEnsemble(T[ind],T[ind+1]);
		}
		if((ind != 0) && (T[ind-1]->occupe == 1)){
			unionEnsemble(T[ind-1],T[ind]);
		}
	}
	return O;
}

int main(int argc, char **argv){
	int D[7] = {4,2,4,3,1,4,6};
	int *O = ordonnancement_variante(D,7);
	printf("L'ordonnancement optimal est le suivant :\n\n");
	int i;
	for(i=0;i<7;i++){
		printf("Tache %d\n",O[i]); 
	}
	printf("\n\n");
	return 0;
}

