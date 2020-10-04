#include"Jos.h"

#define N 40
#define M 4

int mc;

LDCC *CreerElement(int cle){
	LDCC *elem = (LDCC *)malloc(sizeof(LDCC));
	elem->cle = cle;
	return elem;
}

LDCC * creerListeDepart(int n){
	int i;
	LDCC *t = CreerElement(1);
	t->tete = t;
	LDCC *c = t;
	LDCC *w;
	for(i=2;i<=n;i++){
		c->suiv = CreerElement(i);
		w = c;
		c = c->suiv;
		c->pred = w;
		c->tete = t;
	}
	c->suiv = t;
	c->tete = t;
	t->pred = c;
	return t; 
}

LDCC *supprimerElement(LDCC *x){
	LDCC *avant = x->pred;
	LDCC *apres = x->suiv;
	avant->suiv = apres;
	apres->pred = avant;
	x->pred = x->suiv = NULL;
	free(x);
	return apres;
}

int *josephus(int n,int m){
	int *T = (int *)malloc(n*sizeof(int));
	int k=0,j;
	LDCC *L = creerListeDepart(n);
	mc = M;
	m = mc;
	while(k<n){
		j=1;
		while(j<m){
			L=L->suiv;
			j++;
		}
		T[k]=L->cle;
		printf("%d\n",T[k]);
		k++;
		L = supprimerElement(L);
	}
	return T;
}

int main(int *argc, char **argv){
	printf("Permutation de Josephus(%d,%d) par la methode lineaire supposant que m est une constante:\n",N,M);
	int *T = josephus(N,M);
	printf("\n"); 
	printf("Permutation de Josephus(%d,%d) par la methode en O(n.lg(n)) supposant que m n'est pas une constante:\n",N,M);
	int *T2 = josephus_efficace(N,M);
	printf("\n");
	return 0;
}

