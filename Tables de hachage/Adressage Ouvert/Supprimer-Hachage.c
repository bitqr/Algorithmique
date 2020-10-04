#include"AdressageOuvert.h"
#include<stdlib.h>
#include<stdio.h>

int supprimer_hachage(int *T, int k, int m){
	int i=0,j;
	do{
		j = h(k,i,m);
		if(T[j] == k){
			T[j] = SUPPRIMEE;
			return 0;
			}
		else i++;
	}while(i!=m);
	fprintf(stderr,"element non present\n");
	exit(EXIT_FAILURE);
}


