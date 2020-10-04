#include<stdio.h>
#include<stdlib.h>
#include"ListesChainees.h"


void supprimer(LSCC *L,int x){
	while(L->suiv->cle != x && L->suiv != L->tete)
		L = L->suiv;
	if(L->suiv->cle == x){
		L->suiv = L->suiv->suiv;
		L = L->tete;
	}
	printf("Liste apres suppression:\n");
	afficherLSCC(L);
}


		

int main(int argc, char ** argv){
	LSCC * l1 = creerElement(1);
	LSCC * l2 = creerElement(4);
	LSCC * l3 = creerElement(9);
	LSCC * l4 = creerElement(16);
	l1->suiv = l2;
	l1->tete = l1;
	l2->suiv = l3;
	l2->tete = l1;
	l3->suiv = l4;
	l3->tete = l1;
	l4->suiv = l1;
	l4->tete = l1;
	LSCC * L = l1;
	printf("Liste initiale:\n");
	afficherLSCC(L);

	inserer(L,11);
		
	supprimer(L,9);
	
	printf("L'element recherche est %d\n",rechercher(L,16)->cle);

	inverser(L);
	
	return 0;
}
