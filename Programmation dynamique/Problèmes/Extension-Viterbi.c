#include"VDCB.h"


int *extension_viterbi(GRAPHE_ETENDU *G, int v0, char *s, int k){
	int nbs = G->nombre_sommets;
	double proba;
	int **S = (int **)malloc(nbs * sizeof(int *));
	int i,v,k1,j;
	for(i=0;i<nbs;i++)
		S[i] = (int *)malloc((k+1)*sizeof(int));
	for(i=0;i<nbs;i++)
		S[i][k] = 1;
	double **C = (double **)malloc(nbs * sizeof(double *));
	for(i=0;i<nbs;i++)
		C[i] = (double *)malloc((k+1)*sizeof(double));
	for(i=0;i<nbs;i++)
		C[i][k] = 1.0;
	for(i=k-1;i>=0;i--){
		for(v=0;v<nbs;v++){
			j=0;
			proba = 0;
			for(k1=0;k1<nbs;k1++){
				if(G->aretes[v][k1] == s[i] && S[k1][i+1] != 0 && G->p[v][k1]*C[k1][i+1] > proba){
					j=k1+1;
					proba = G->p[v][k1]*C[k1][i+1];
				}
			}
			S[v][i] = j;
			C[v][i] = proba;
		}
	}
	
	int *chemin = (int *)malloc((k+1)*sizeof(int));
	j=S[v0-1][0];
	if(j==0){
		fprintf(stderr,"Chemin Inexistant\n\n");
		exit(EXIT_FAILURE);
	}
	chemin[0] = v0;
	chemin[1] = j;
	k1 = j-1;
	for(j=2;j<=k+1;j++){
		chemin[j] = S[k1][j-1];
		k1 = chemin[j] - 1;
	}
	printf("La probabilite de cette solution optimale est de %f\n\n",C[v0-1][0]);
	return chemin;
}

GRAPHE_ETENDU *creerGrapheEtendu(int nbs){
	GRAPHE_ETENDU *G = (GRAPHE_ETENDU *)malloc(sizeof(GRAPHE_ETENDU));
	G->nombre_sommets = nbs;
	G->aretes = (char **)malloc(nbs*sizeof(char *));
	int i;
	for(i=0;i<nbs;i++)
		G->aretes[i] = (char *)malloc(nbs*sizeof(char));
	G->p = (double **)malloc(nbs*sizeof(double *));
	for(i=0;i<nbs;i++)
		G->p[i] = (double *)malloc(nbs*sizeof(double));
	return G;
}

int main(int argc, char ** argv){

	char aretes[NS][NS] = {
	{'\0','l','\0','a','p','\0','\0','b','\0','n'},
	{'a','\0','\0','a','\0','\0','e','i','\0','\0'},
	{'n','\0','\0','\0','s','\0','\0','\0','c','i'},
	{'\0','\0','\0','\0','d','u','\0','\0','\0','\0'},
	{'e','\0','\0','\0','\0','r','\0','\0','l','\0'},
	{'\0','\0','\0','\0','m','\0','s','\0','\0','\0'},
	{'\0','\0','\0','t','\0','\0','\0','\0','\0','\0'},
	{'p','\0','\0','\0','\0','\0','o','\0','\0','\0'},
	{'\0','\0','e','\0','\0','e','a','\0','\0','\0'},
	{'s','\0','r','n','\0','\0','\0','\0','\0','\0'}
	};
	
	double p [NS][NS] = {
	{0,0.2,0,0.3,0.15,0,0.2,0,0.15},
	{0.4,0,0,0.2,0,0,0.3,0.1,0,0},
	{0.1,0,0,0,0.1,0,0,0,0.3,0.5},
	{0,0,0,0,0.8,0.2,0,0,0,0},
	{0.3,0,0,0,0,0.3,0,0,0.4,0},
	{0,0,0,0,0.5,0,0.5,0,0,0},
	{0,0,0,1,0,0,0,0,0,0},
	{0.1,0,0,0,0,0,0.9,0,0,0},
	{0,0,0.2,0,0,0.6,0.2,0,0,0},
	{0.3,0,0.3,0.4,0,0,0,0,0,0}
	};
	
	GRAPHE_ETENDU *G = creerGrapheEtendu(NS);
	int i,j;
	for(i=0;i<NS;i++)
		for(j=0;j<NS;j++){
			G->aretes[i][j] = aretes[i][j];
			G->p[i][j] = p[i][j];
		}
	
			
	
	char s[NP] = {'s','l','a','u','m'};
	
	int *chemin = extension_viterbi(G,10,s,NP);
	
	for(i=0;i<=NP;i++)
		printf("%d->\t",chemin[i]);
	printf("\n\n");

	return 0;
}




