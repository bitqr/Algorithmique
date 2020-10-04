#include"Mat.h"
#define N 6
#define INFINI 10000000
#define LIM 10 


MATRICE *creerMatrice(int nl, int nc){
	int ** m = (int **)malloc(nl*sizeof(int *));
	int i;
	for(i=0;i<nl;i++)
		m[i] = (int *)calloc(nc,sizeof(int));
	MATRICE *mat = (MATRICE *)malloc(sizeof(MATRICE));
	mat->lignes = nl;
	mat->colonnes = nc;
	mat->tab = m;
	return mat;
}



MATRICE * multiplier_matrices(MATRICE *A, MATRICE *B){
	if(A->colonnes != B->lignes){
		fprintf(stderr,"dimensions incompatibles\n");
		exit(EXIT_FAILURE);
	}
	else{
		MATRICE * C = creerMatrice(A->lignes,B->colonnes);
		int i,j,k;
		for(i=0;i<A->lignes;i++)
			for(j=0;j<B->colonnes;j++){
				(C->tab)[i][j] = 0;
				for(k=0;k<A->colonnes;k++)
					(C->tab)[i][j] = (C->tab)[i][j] + A->tab[i][k] * B->tab[k][j];
				}
		return C;
	}
}

void afficherMatrice(MATRICE *A){
	int i,j;
	for(i=0;i<A->lignes;i++){
		for(j=0;j<A->colonnes;j++)
			printf("%d\t", A->tab[i][j]);
		printf("\n");
	}
}	

DIM * creerDim(int n, int *t){
	DIM *m = (DIM *)malloc(sizeof(DIM));
	m->longueur = n;
	m->p = (int *)malloc(n*sizeof(int));
	int i;
	for(i=0;i<n;i++)
		m->p[i] = t[i];
	return m;
}


int ** initTable(int n){
	int **t = (int **)malloc(n*sizeof(int*));
	int i,j;
	for(i=0;i<n;i++)
		t[i] = (int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			t[i][j]=0;
	return t;
}

int ** ordre_chaine_matrices(DIM *p, int **s){
	int n = p->longueur-1;
	int **m = initTable(n);
	int i,l,j,k,q;
	for(i=0;i<n;i++)
		m[i][i]=0;
	for(l=2;l<=n;l++){ //l est la longueur de la chaine.
		for(i=0;i<n-l+1;i++){
			j = i+l-1;
			m[i][j] = INFINI;
			for(k=i;k<=j-1;k++){
				q = m[i][k] + m[k+1][j] + p->p[i]*p->p[k+1]*p->p[j+1];
				if(q < m[i][j]){
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	return m;
}


void afficherTable(int **A, int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d\t", A[i][j]);
		printf("\n");
	}
}		

void initMatrice(MATRICE *A){
	int i,j;
	for(i=0;i<A->lignes;i++){
		for(j=0;j<A->colonnes;j++)
			A->tab[i][j] = rand()%LIM - LIM/2;
	}
}
	

int main(int *argc, char **argv){
	srand(time(NULL));
	int ** s = initTable(N);
	int t[N+1] = {5,10,3,12,5,50,6};
	DIM *dm = creerDim(N+1,t);
	int **m = ordre_chaine_matrices(dm,s);
	afficherTable(m,N);
	printf("\n\n\n Le nombre minimal de multiplications pour cette instance est de %d\n\n\n", m[0][N-1]);
	printf("Voici le parenthesage optimal induisant ce cout: \n\n");
	affichage_parenthesage_optimal(s,0,N-1);
	printf("\n\n\n");
	MATRICE **A = (MATRICE **)malloc(N*sizeof(MATRICE *));
	int i;
	MATRICE *M;
	for(i=0;i<N;i++){
		A[i] = creerMatrice(t[i],t[i+1]);
		initMatrice(A[i]);
	}
	afficherTable(s,N);
	MATRICE * M2 = multiplication_chaine_matrices(A,s,0,N-1);
	printf("\n\n\n");
	afficherMatrice(M2);
	printf("\n\n\n");
	return 0;
}


 
