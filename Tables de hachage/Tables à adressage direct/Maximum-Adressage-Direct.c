#include"Hachage.h"
#include<stdlib.h>
#include<stdio.h>

int maximum_adressage_direct(OBJET ** T,int m){
	int i=m-1;
	while(T[i] == NULL && i>=0)
		i--;
	if(i>=0){
		fprintf(stdout,"L'élément maximal est %d\n",i);
		return i;
	}
	else{
		fprintf(stderr,"Table à adressage direct vide !!!\n");
		exit(EXIT_FAILURE);
	}
}

