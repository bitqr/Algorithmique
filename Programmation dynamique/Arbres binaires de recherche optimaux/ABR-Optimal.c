#include"ABROPT.h"

float **creerMatrice(int m, int n){
	float **e = (float **)malloc(m*sizeof(float *));
	int i,j;
	for(i=0;i<m;i++)
		e[i] = (float *)malloc(n*sizeof(float));
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			e[i][j]=0.0;
	return e;
}

int **creerMatriceEntiers(int m, int n){
	int **e = (int **)malloc(m*sizeof(int *));
	int i,j;
	for(i=0;i<m;i++)
		e[i] = (int *)malloc(n*sizeof(int));
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			e[i][j]=0;
	return e;
}

float ** abr_optimal(float *p, float *q, int n, int **racine){
	int i,l,j,r;
	float t;
	float **e = creerMatrice(n+2,n+1);
	float **w = creerMatrice(n+2,n+1);
	for(i=1;i<n+2;i++){
		e[i][i-1] = q[i-1];
		w[i][i-1] = q[i-1];
	}
	for(l=1;l<=n;l++){
		for(i=1;i<=n-l+1;i++){
			j = i+l-1;
			e[i][j] = INFINI;
			w[i][j] = w[i][j-1] + p[j-1] + q[j];
			for(r=i;r<=j;r++){
				t = e[i][r-1] + e[r+1][j] + w[i][j];
				if(t < e[i][j]){
					e[i][j] = t;
					racine[i-1][j-1] = r;
				}
			}
		}
	}
	return e;
}

void afficherMatrice(float **e, int m, int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
			printf("%.2f\t",e[i][j]);
		printf("\n");
	}
}

void afficherMatriceEntiers(int **e, int m, int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
			printf("%d\t",e[i][j]);
		printf("\n");
	}
}

int main(int argc, char **argv){
	float p[N] = {0.15,0.10,0.05,0.10,0.20};
	float q[N+1] = {0.05,0.10,0.05,0.05,0.05,0.10};
	
	float p2[N2] = {0.04,0.06,0.08,0.02,0.10,0.12,0.14};
	float q2[N2+1] = {0.06,0.06,0.06,0.06,0.05,0.05,0.05,0.05};
	
	int **racine = creerMatriceEntiers(N2,N2);
	float **e = abr_optimal(p2,q2,N2,racine);
	afficherMatrice(e,N2+2,N2+1);
	printf("\n\n\n");
	afficherMatriceEntiers(racine,N2,N2);
	printf("\n\n\n");
	construire_abr_optimal(racine,N2);

	int **racine2 = creerMatriceEntiers(N2,N2);
	float **e2 = abr_optimal_efficace(p2,q2,N2,racine2);
	afficherMatrice(e2,N2+2,N2+1);
	printf("\n\n\n");
	afficherMatriceEntiers(racine2,N2,N2);
	printf("\n\n\n");
	construire_abr_optimal(racine2,N2);
	
	return 0;
}





