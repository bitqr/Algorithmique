#include"Hachage.h"
#include<stdlib.h>
#include<stdio.h>

OBJET * rechercher_adressage_direct(OBJET ** T,int k){
	return T[k];
}


OBJET ** creer_table(int taille){
	OBJET ** T = (OBJET **)malloc(taille*sizeof(taille));
	int i;
	for(i=0;i<taille;i++){
		T[i] = (OBJET *)malloc(sizeof(OBJET));
		T[i] = NULL;
		}
	return T;
}



int main(int argc, char **argv){
	OBJET ** T = creer_table(TAILLE);
	OBJET o2 = {2};
	OBJET o3 = {3};
	OBJET o5 = {5};
	OBJET o8 = {8};
	inserer_adressage_direct(T,&o2);
	inserer_adressage_direct(T,&o3);
	inserer_adressage_direct(T,&o5);
	inserer_adressage_direct(T,&o8);
	printf("Element recherche: %d\n	Trouve: %d\n" ,C,rechercher_adressage_direct(T,C)->cle);
	supprimer_adressage_direct(T,&o8);
	if(rechercher_adressage_direct(T,C) != NULL)
		printf("Element recherche: %d\n	Trouve: %d\n" ,C,rechercher_adressage_direct(T,C)->cle);
	else 
		printf("Element recherche: %d\nElement Non Trouve!!!\n",C);
	maximum_adressage_direct(T,TAILLE);
	return 0;
}



