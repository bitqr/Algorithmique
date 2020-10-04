#include<stdio.h>
#include<stdlib.h>


typedef struct {
	unsigned int longueur;
	int * val;
	int poids;
} TABLEAU;

TABLEAU * creerTableauPoids(unsigned int l){
	TABLEAU * tab = (TABLEAU *) malloc(sizeof(TABLEAU));
	tab->longueur = l;
	tab->val = (int *) calloc(l,sizeof(int));
	tab->poids=-1;
	return tab;
}

void afficherTableauPoids(TABLEAU *A){
	int i;
	printf("Poids : %d\n\n",A->poids);
	for(i=0;i<A->longueur;i++)
		printf("%d",A->val[A->longueur-i-1]);
	printf("\n\n");
}

void incrementer_poids(TABLEAU *A){
	int i=0;
	while((i < A->longueur) && (A->val[i] == 1)){
		A->val[i] = 0;
		i++;	
	}
	if(i < A->longueur){
		if(i > A->poids)
			A->poids=i;
		A->val[i] = 1;
	}
	else
		A->poids=-1;
}

void reinitialiser(TABLEAU *A){
	int i;
	for(i=0;i<=A->poids;i++)
		A->val[i]=0;
	A->poids=-1;
}

int main(int argc, char ** argv){
	if(argc != 3){
		printf("usage : %s nb_bits nb_incrémentations\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	TABLEAU *A = creerTableauPoids(atoi(argv[1]));
	printf("Bonjour et bienvenue! Je vais afficher les résultats d'incrémentations successives d'un entier en base 2, modulo 2^%d\n\n",A->longueur);
	int i;
	printf("Le nombre initial :\n");
	afficherTableauPoids(A);
	for(i=0;i<atoi(argv[2]);i++){
		if(rand()%100 < 5){
			printf("Reinitialisation : \n\n");
			reinitialiser(A);	
		}
		else
			incrementer_poids(A);
		afficherTableauPoids(A);
	}
	return 0;
}


