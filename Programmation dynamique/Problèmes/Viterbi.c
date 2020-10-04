#include"VDCB.h"

int *viterbi(GRAPHE *G, int v0, char *phonemes, int nb_phonemes){
	int nbs = G->nombre_sommets;
	int **S = (int **)malloc(nbs * sizeof(int *));
	int i,v,k,j;
	for(i=0;i<nbs;i++)
		S[i] = (int *)malloc((nb_phonemes+1)*sizeof(int));
	for(i=0;i<nbs;i++)
		S[i][nb_phonemes] = 1;
	for(i=nb_phonemes-1;i>=0;i--){
		for(v=0;v<nbs;v++){
			j=0;
			for(k=0;k<nbs;k++)
				if(G->aretes[v][k] == phonemes[i] && S[k][i+1] != 0)
					j=k+1;
			S[v][i] = j;
		}
	}
	
	int *chemin = (int *)malloc((nb_phonemes+1)*sizeof(int));
	j=S[v0-1][0];
	if(j==0){
		fprintf(stderr,"Chemin Inexistant\n\n");
		exit(EXIT_FAILURE);
	}
	chemin[0] = v0;
	chemin[1] = j;
	k = j-1;
	for(j=2;j<=nb_phonemes+1;j++){
		chemin[j] = S[k][j-1];
		k = chemin[j] - 1;
	}
	return chemin;
}

GRAPHE *creerGraphe(int nbs){
	GRAPHE *G = (GRAPHE *)malloc(sizeof(GRAPHE));
	G->nombre_sommets = nbs;
	G->aretes = (char **)malloc(nbs*sizeof(char *));
	int i;
	for(i=0;i<nbs;i++)
		G->aretes[i] = (char *)malloc(nbs*sizeof(char));
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
		{'s','\0','r','\0','\0','\0','\0','\0','\0','\0'}
	};
	
	GRAPHE *G = creerGraphe(NS);
	int i,j;
	for(i=0;i<NS;i++)
		for(j=0;j<NS;j++)
			G->aretes[i][j] = aretes[i][j];
	
	char phoneme[NP] = {'s','l','a','u','m'};
	int *chemin = viterbi(G,10,phoneme,NP);
	
	for(i=0;i<=NP;i++)
		printf("%d->\t",chemin[i]);
	printf("\n\n");
	return 0;
}

