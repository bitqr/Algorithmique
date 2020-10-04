#include"VDCB.h"

int **damier(CARRE **plateau, int n){
	int **S = (int **)malloc(n*sizeof(int *));
	int i,j;
	for(i=0;i<n;i++)
		S[i] = (int *)malloc(n*sizeof(int));
	double **C = (double **)malloc(n*sizeof(double *));
	for(i=0;i<n;i++)
		C[i] = (double *)malloc(n*sizeof(double));
	for(i=0;i<n;i++){
		S[n-1][i] = INIT;
		C[n-1][i] = 0;
	}
	double k,l,m;
	for(i=n-2;i>=0;i--){
		for(j=0;j<n;j++){
			if(j==0){
				k = plateau[i+1][j].h + C[i+1][j];
				l = plateau[i+1][j+1].hg + C[i+1][j+1];
				if(k>l){
					S[i][j] = HAUT;
					C[i][j] = k;
				}
				else{
					S[i][j] = HAUT_GAUCHE;
					C[i][j] = l;
				}
			}
			else{
				if(j==n-1){
					k = plateau[i+1][j].h + C[i+1][j];
					l = plateau[i+1][j-1].hd + C[i+1][j-1];
					if(k>l){
						S[i][j] = HAUT;
						C[i][j] = k;
					}
					else{
						S[i][j] = HAUT_DROITE;
						C[i][j] = l;
					}
				}
				else{
					k = plateau[i+1][j].h + C[i+1][j];
					l = plateau[i+1][j-1].hd + C[i+1][j-1];
					m = plateau[i+1][j+1].hg + C[i+1][j+1];
					S[i][j] = (k>l)?((k>m)?HAUT:HAUT_GAUCHE):((l>m)?HAUT_DROITE:HAUT_GAUCHE);
					C[i][j] = (k>l)?((k>m)?k:m):((l>m)?l:m);
				}
			}
		}
	}
	return S;
}

CARRE **creerDamier(int n, int rnd){
	CARRE **damier = (CARRE **)malloc(n*sizeof(CARRE *));
	int i,j;
	for(i=0;i<n;i++)
		damier[i] = (CARRE *)malloc(n*sizeof(CARRE));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			damier[i][j].h = (i==0)?-1:((rand()/(double)RAND_MAX)*2*rnd-rnd);
			damier[i][j].hg = (i==0 || j==0)?-1:((rand()/(double)RAND_MAX)*2*rnd-rnd);
			damier[i][j].hd = (i==0 || j==n-1)?-1:((rand()/(double)RAND_MAX)*2*rnd-rnd);	
		}
	return damier;
}

void afficherDamier(CARRE **damier, int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("(%.2f,%.2f,%.2f)\t",damier[i][j].hg,damier[i][j].h,damier[i][j].hd); 
		}
		printf("\n");
	}
}

void afficherSolution(int **sol, int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(sol[i][j] == HAUT)
				printf("HAUT");
			else
				if(sol[i][j] == HAUT_GAUCHE)
					printf("HG");
				else
					if(sol[i][j] == HAUT_DROITE)
						printf("HD");
					else
						printf("0");
			printf("\t");
		}
		printf("\n");
	}
}

int main(int argc, char **argv){
	CARRE **Damier = creerDamier(NDAMIER,RND);
	afficherDamier(Damier,NDAMIER);
	int **S = damier(Damier,NDAMIER);
	printf("\n\n");
	afficherSolution(S,NDAMIER);
	printf("\n\n");
	return 0;
}

