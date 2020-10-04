#include<stdio.h>
#include<stdlib.h>
#include"HachageChaine.h"
#define ENTREE 5
#define K 34

int h(int cle,int m){
	return cle%m;
}

void inserer_hachage_chainee(LSC **T,LSC *x,int m){
	int c = x->cle;
	int ind = h(c,m);
	LSC * t = T[ind];
	x->suiv = t;
	T[ind] = x;
}

LSC * creerElt(int cle){
	LSC * elt = (LSC *)malloc(sizeof(LSC));
	elt->cle = cle;
	elt->suiv = NULL;
	return elt;
}

LSC ** creerTableHachage(int taille){
	LSC ** T = (LSC **)malloc(taille * sizeof(LSC *));
	int i;
	for(i=0;i<taille;i++){
		T[i] = (LSC *)malloc(sizeof(LSC));
		T[i] = NULL;
	}
	return T;
}
	
void afficherTableHachage(LSC **T, int m){
	printf("Table de Hachage T :  \n");
	int i;
	for(i=0;i<m;i++){
		if(T[i] == NULL)
			printf("/ \n");
		else{
			LSC * x = T[i];
			while(x){
				printf("%d\t",x->cle);
				x = x->suiv;
			}
			printf("/ \n");
		}
	}
}

int main(int argc, char **argv){
	int tab[ENTREE] = {34,42,33,21,8};
	int i;
	LSC **T = creerTableHachage(M);
	for(i=0;i<ENTREE;i++)
		inserer_hachage_chainee(T,creerElt(tab[i]),M);
	afficherTableHachage(T,M);
	rechercher_hachage_chainee(T,K,M);
	LSC * elt = creerElt(66);
	inserer_hachage_chainee(T,elt,M);
	afficherTableHachage(T,M);
	supprimer_hachage_chainee(T,T[2]->suiv,M);
	afficherTableHachage(T,M);
	return 0;
}

