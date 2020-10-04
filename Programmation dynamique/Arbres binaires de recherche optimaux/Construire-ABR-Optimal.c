#include"ABROPT.h"

void construire_abr_optimal(int **racine, int n){
	int r = racine[0][n-1];
	printf("k%d est la racine\n",r);
	construire_abr_recursif(racine,0,r-2,n,GAUCHE);
	construire_abr_recursif(racine,r,n-1,n,DROITE);
}

void construire_abr_recursif(int **racine, int i, int j, int n, int cote){
	if(cote == GAUCHE){
		if(i<=j){
			printf("k%d est l'enfant gauche de k%d\n",racine[i][j],j+2);
			construire_abr_recursif(racine,i,racine[i][j]-2,n,GAUCHE);
			construire_abr_recursif(racine,racine[i][j],j,n,DROITE);			
		}
		else{
			printf("d%d est l'enfant gauche de k%d\n",j+1,j+2);
		}
	}
	else{
		if(i<=j){
			printf("k%d est l'enfant droite de k%d\n",racine[i][j],i);
			construire_abr_recursif(racine,i,racine[i][j]-2,n,GAUCHE);
			construire_abr_recursif(racine,racine[i][j],j,n,DROITE);			
		}
		else{
			printf("d%d est l'enfant droite de k%d\n",i,i);
		}
	}
}




