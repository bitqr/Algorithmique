#include<stdio.h>
#include<stdlib.h>
#include"ArbreBinaireRecherche.h"
#define N 100


void empiler(PILE *P,ABR *x){
    P->sommet++;
    P->tableau[P->sommet]=x;
}


int pile_vide(PILE *P){
    return(P->sommet==-1);
}


ABR *depiler(PILE *P){
    if(pile_vide(P)){
        printf("Erreur, debordement negatif!\n");
        exit(EXIT_FAILURE);
    }
    P->sommet--;
    return P->tableau[P->sommet+1];
}

PILE *creer_pile(int taille){
    PILE *P = (PILE*)malloc(sizeof(PILE));
    ABR **t = (ABR **)malloc(taille*sizeof(ABR *));
    int i;
    for(i=0;i<taille;i++)
    	 t[i] = (ABR *)malloc(taille*sizeof(ABR));
    P->sommet=-1;
    P->taille=taille;
    P->tableau=t;
    return P;
}



void parcours_infixe_non_recursif(ABR *x){
	PILE * P = creer_pile(N);
	empiler(P,x);
	while(!pile_vide(P)){
		if(x->droite){
			depiler(P);
			empiler(P,x->droite);
			empiler(P,x);
			}
		if(x->gauche)
			empiler(P,x->gauche);
		if(x->gauche == NULL){
			printf("%d\t",depiler(P)->cle);
			printf("%d\t",depiler(P)->cle);
			}
		x = P->tableau[P->sommet];
		}
}



		



