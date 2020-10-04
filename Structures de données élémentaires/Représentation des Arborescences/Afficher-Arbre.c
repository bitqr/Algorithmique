#include<stdio.h>
#include<stdlib.h>
#include"Arborescence.h"


void afficher_arbre(ARBREBINAIRE * A){
	if(A != NULL){
		printf("%d\t",A->cle);
		afficher_arbre(A->gauche);
		afficher_arbre(A->droit);
		}
}



ARBREBINAIRE *creerNoeud(int cle,ARBREBINAIRE *g,ARBREBINAIRE *d,ARBREBINAIRE *p){
	ARBREBINAIRE * noeud = (ARBREBINAIRE *)malloc(sizeof(ARBREBINAIRE));
	noeud->cle = cle;
	noeud->gauche = g;
	noeud->droit = d;
	noeud->p = p;
	return noeud;
}

ARBRE *creerNoeud2(int cle,ARBRE *fig,ARBRE *frd,ARBRE *p){
	ARBRE * noeud = (ARBRE *)malloc(sizeof(ARBRE));
	noeud->cle = cle;
	noeud->filsg = fig;
	noeud->frered = frd;
	noeud->p = p;
	return noeud;
}

int main(int argc, char **argv){
	ARBREBINAIRE * A;
	ARBREBINAIRE * A1;
	ARBREBINAIRE * A2;
	ARBREBINAIRE * A11 = creerNoeud(4,NULL,NULL,A1); 
	ARBREBINAIRE * A12 = creerNoeud(18,NULL,NULL,A1); 
	ARBREBINAIRE * A21 = creerNoeud(121,NULL,NULL,A2); 
	ARBREBINAIRE * A22 = creerNoeud(8,NULL,NULL,A2);
	A1 = creerNoeud(12,A11,A12,A);
	A2 = creerNoeud(1,A21,A22,A);
	A = creerNoeud(22,A1,A2,NULL);
	
	ARBRE *B;
	ARBRE *B1;
	ARBRE *B3 = creerNoeud2(12,creerNoeud2(4,NULL,creerNoeud2(18,NULL,creerNoeud2(2,NULL,NULL,B),B),B3),NULL,B);
	ARBRE *B2;
	ARBRE *B21 = creerNoeud2(7,NULL,NULL,B2); 
	B2 = creerNoeud2(8,B21,B3,B);
	B1 = creerNoeud2(14,creerNoeud2(11,NULL,creerNoeud2(3,NULL,NULL,B1),B1),B2,B);
	B = creerNoeud2(4,B1,NULL,NULL);
	
	afficher_arbre(A); 
	printf("\n");
	afficher_arbre_2(A);
	printf("\n");
	afficher_arbre_3(B);
	printf("\n");
	afficher_arbre_4(A);
	printf("\n");
	return 0;
}
