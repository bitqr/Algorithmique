#include<stdio.h>
#include<stdlib.h> 
#include"AdressageOuvert.h"

int h(int k, int i, int m){
	if(i==0)
		return k%m;
	return (h(k,0,m) + i) % m;
}

int inserer_hachage(int *T, int m, int k){
	int i=0,j;
	do{
		j = h(k,i,m);
		if(T[j] == -1){
			T[j] = k;
			return j;
			}
		else i++;
	}while(i!=m);
	fprintf(stderr,"débordement de la table de hachage\n");
	exit(EXIT_FAILURE);
}

void afficherTable(int *T, int m){
	int i;
	for(i=0;i<m;i++){
		if(T[i]>-1)
			printf("%d\t",T[i]);
		else 
			printf("/\t");
	}
	printf("\n");
}

int main(int argc, char **argv){
	int T[M] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int A[N] = {34,45,18,6,12,15,9,10,23,11};
	int i;
	for(i=0;i<N;i++)
		inserer_hachage(T,M,A[i]);
	afficherTable(T,M);
	int rec = rechercher_hachage(T,12,M);
	printf("%d\n",rec);
	supprimer_hachage(T,23,M);
	afficherTable(T,M);
	inserer_hachage_modifie(T,M,20);
	afficherTable(T,M);
	return 0;
}

