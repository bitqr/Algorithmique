#include"PLSC.h"

SEQUENCE * creerSequence(int longueur){
	SEQUENCE * S = (SEQUENCE *)malloc(sizeof(SEQUENCE));
	S->longueur = longueur;
	S->table = (char *)malloc(longueur * sizeof(char));
	S->entiers = (int *)malloc(longueur * sizeof(int));
	return S;
}

void initSequence(SEQUENCE *S, char *C){
	int i=0;
	int p = S->longueur;
	int ln = strlen(C);
	while(i<p && i <= ln){
		S->table[i] = C[i];
		i++;
	}
	if(i > ln)
		S->longueur = ln;
}

void afficheSequence(SEQUENCE *S){
	int i,l = S->longueur;
	for(i=0;i<l;i++)
		printf("%c",S->table[i]);
	printf("\n\n");
}

char ** initSP(int n, int m){
	char **t = (char **)malloc(n*sizeof(char*));
	int i,j;
	for(i=0;i<n;i++)
		t[i] = (char *)malloc(m*sizeof(char));
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			t[i][j]=' ';
	return t;
}

int ** initTables(int n, int m){
	int **t = (int **)malloc(n*sizeof(int*));
	int i,j;
	for(i=0;i<n;i++)
		t[i] = (int *)malloc(m*sizeof(int));
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			t[i][j]=0;
	return t;
}


int ** longueur_plsc(SEQUENCE *X, SEQUENCE *Y, char **b){
	int m = X->longueur;
	int n = Y->longueur;
	int i,j;
	int ** c = initTables(m+1,n+1);
	for(i=1;i<=m;i++)
		c[i][0] = 0;
	for(j=0;j<=n;j++)
		c[0][j] = 0;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(X->table[i-1]==Y->table[j-1]){
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = '`';
			}
			else{
				if(c[i-1][j] >= c[i][j-1]){
					c[i][j] = c[i-1][j];
					b[i][j] = '|';
				}
				else{
					c[i][j] = c[i][j-1];
					b[i][j] = '-';
				}
			}
	return c;
}


void afficherTables(int **A, int n, int m){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
			printf("%d\t", A[i][j]);
		printf("\n");
	}
}


void afficherTableCaracteres(char **A, int n, int m){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
			printf("%c\t", A[i][j]);
		printf("\n");
	}
}

int main(int argc, char **argv){
	SEQUENCE *X = creerSequence(LX);
	SEQUENCE *Y = creerSequence(LY);
	initSequence(X,"10010101");
	initSequence(Y,"010110110");
	afficheSequence(X);
	afficheSequence(Y);
	char **b = initSP(X->longueur + 1,Y->longueur + 1);
	int ** c = longueur_plsc(X,Y,b);
	afficherTables(c,X->longueur + 1,Y->longueur + 1);
	printf("\n\n\n");
	afficherTableCaracteres(b,X->longueur + 1,Y->longueur + 1);	
	printf("\n\n\n");
	imprimer_plsc(b,X,X->longueur,Y->longueur);
	printf("\n\n");
	int a = longueur_plsc_recensement(X,Y);
	printf("\n\nLa longueur d'une PLSC de X et Y est de %d\n",a);
	
	SEQUENCE *Z = creerSequence(N);
	int T[N] = {12,3,24,14,5,15,6,8,17,6,12,9,8,5,12,11,19,22,3,14};
	initSequenceEntiers(Z,T);
	printf("\n\n");
	plsc_croissante(Z);
	printf("\n\n");
	pls_croissante_efficace(Z);
	printf("\n\n");
	return 0;
}


