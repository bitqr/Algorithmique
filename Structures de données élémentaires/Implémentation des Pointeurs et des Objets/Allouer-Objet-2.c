#include<stdio.h>
#include<stdlib.h>
#include"ImplementationObjets.h"


int allouer_objet_2(int *unique,int *libre2){
	if(*libre2 == -1){
		fprintf(stderr,"plus assez d'espace disponible");
		exit(EXIT_FAILURE);
		}
	else{
	 	int x = *libre2;
		*libre2 = unique[x-2];
		return x;
		}
}





