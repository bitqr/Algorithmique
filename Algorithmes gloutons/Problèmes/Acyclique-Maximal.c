#include "PROB.h"

LISTE_ARETE *creerArete(ARETE ar){
	LISTE_ARETE * A = (LISTE_ARETE *)malloc(sizeof(LISTE_ARETE));
	A->suiv = NULL;
	A->cle = ar;
	return A;
}


void permuter_arete(ARETE* A, int i, int j){
     int tmp1 = A[i].a;
     int tmp2 = A[i].b;
     A[i].a = A[j].a;
     A[i].b = A[j].b;
     A[j].a=tmp1;
     A[j].b=tmp2;
}

int partition_arete(ARETE * A, int *w, int a, int b){
    int x = w[b];
    int i = a-1;
    int j,tmp;
    for(j=a;j<b;j++){
                     if(w[j]>=x){
                                 i++;
                                 permuter_arete(A,i,j);
				 tmp=w[i];
				 w[i]=w[j];
				 w[j]=tmp;
                                 }
                     }
    permuter_arete(A,i+1,b);
    tmp=w[i+1];
    w[i+1]=w[b];
    w[b]=tmp;
    return i+1;
}

void tri_rapide_arete(ARETE* A, int *w, int a, int b){
     if(a<b){
             int q=partition_arete(A,w,a,b);
             tri_rapide_arete(A,w,a,q-1);
             tri_rapide_arete(A,w,q+1,b);
             }
}


LISTE_ARETE *acyclique_maximal(GRAPHE_NO *G, int *w){
	int *S = G->sommet;
	ARETE *A = G->arete;
	ARETE a1; ARETE arete;
	a1.a = 0;
	a1.b = 0;
	LISTE_ARETE * L = creerArete(a1);
	L->tete = L;
	tri_rapide_arete(A,w,0,G->m-1);
	int c=0;
	int i;
	int *cycle = (int *)malloc(G->n * sizeof(int));
	for(i=0;i<G->n;i++){
		cycle[i]=0;
	}
	for(i=0;i<G->m;i++){
		if(cycle[A[i].a] == 0 && cycle[A[i].b] == 0){
			c++;
			cycle[A[i].a] = c;
			cycle[A[i].b] = c;
			arete.a = A[i].a;
			arete.b = A[i].b;
			L->suiv = creerArete(arete);
			L->suiv->tete = L->tete;
			L = L->suiv; 
		}
		else{
			if(cycle[A[i].a] == 0 || cycle[A[i].b]== 0){
				if(cycle[A[i].a] == 0){
					cycle[A[i].a] = cycle[A[i].b];
					
				}
				else{
					cycle[A[i].b] = cycle[A[i].a];
					
				}
				arete.a = A[i].a;
				arete.b = A[i].b;
				L->suiv = creerArete(arete);
				L->suiv->tete = L->tete;
				L = L->suiv;
			}
			else if(cycle[A[i].a] != cycle[A[i].b]){
				arete.a = A[i].a;
				arete.b = A[i].b;
				L->suiv = creerArete(arete);
				L->suiv->tete = L->tete;
				L = L->suiv;
				int j;
				for(j=0;j<G->n;j++)
					if(cycle[j] == cycle[A[i].b])
						cycle[j] = cycle[A[i].a];
			}
		}
	}
	return L->tete->suiv;
}


int main(int argc, char **argv){
	int w[M] = {10,5,3,4,1,1,2,3,8,3};
	GRAPHE_NO * G = (GRAPHE_NO *)malloc(sizeof(GRAPHE_NO));
	G->n =N;
	G->m = M;
	G->sommet = (int *)malloc(G->n * sizeof(int));
	int i;
	for(i=0;i<G->n;i++)
		G->sommet[i] = i;
	G->arete = (ARETE *)malloc(G->m*sizeof(ARETE)); 
	G->arete[0].a = 0; G->arete[0].b= 1;
	G->arete[1].a = 1; G->arete[1].b= 6;
	G->arete[2].a = 6; G->arete[2].b= 5;
	G->arete[3].a = 5; G->arete[3].b= 3;
	G->arete[4].a = 0; G->arete[4].b= 3;
	G->arete[5].a = 1; G->arete[5].b= 2;
	G->arete[6].a = 2; G->arete[6].b= 5;
	G->arete[7].a = 2; G->arete[7].b= 4;
	G->arete[8].a = 3; G->arete[8].b= 4;
	G->arete[9].a = 4; G->arete[9].b= 5;
	
	LISTE_ARETE * L = acyclique_maximal(G,w);
	
	printf("L'acyclique maximal du graphe est compose de :\n\n");
	
	while(L!=NULL){
		printf("L'arete { %d , %d }\n",L->cle.a,L->cle.b);
		L=L->suiv;
	}
	printf("\n\n");
	return 0;
}
