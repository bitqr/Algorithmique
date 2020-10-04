#include<stdio.h>
#include<stdlib.h>
#include"ImplementationObjets.h"


int allouer_objet(int *succ, int *libre){
	if(*libre == -1){
		fprintf(stderr,"plus assez d'espace disponible");
		exit(EXIT_FAILURE);
		}
	else{
	 	int x = *libre;
		*libre = succ[x-1];
		return x;
		}
}






