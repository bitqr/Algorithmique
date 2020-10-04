#include"ABROPT.h"


float ** abr_optimal_efficace(float *p, float *q, int n, int **racine){
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
			if(i==j){
				r=i;
				e[i][j] = e[i][r-1] + e[r+1][j] + w[i][j];
				racine[i-1][j-1] = r;
			}
			else{
				for(r=racine[i-1][j-2];r<=racine[i][j-1];r++){
					t = e[i][r-1] + e[r+1][j] + w[i][j];
					if(t < e[i][j]){
						e[i][j] = t;
						racine[i-1][j-1] = r;
					}
				}
			}
		}
	}
	return e;
}







