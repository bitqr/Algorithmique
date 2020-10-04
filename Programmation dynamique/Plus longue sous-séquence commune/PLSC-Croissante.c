#include"PLSC.h"

void fusion(int * A, int p , int q, int r){
	int n1 = q-p+1;
	int n2 = r-q;
	long infini = 100000000;
	int * L = (int *) malloc((n1 + 1)*sizeof(int));
	int * R = (int *) malloc((n2 + 1)*sizeof(int));
	int i,j;
	for(i=0;i<n1;i++)
		L[i]=A[p+i];
	for(j=0;j<n2;j++)
		R[j]=A[q+j+1];
	L[n1]= infini;
	R[n2]= infini;
	i=0;
	j=0;
	int k;
	for(k=p;k<r+1;k++){
		if(L[i]<=R[j]){
			A[k]=L[i];
			i++;
		}
		else{
			A[k]=R[j];
			j++;
		}
	}
}

void tri_fusion(int* A, int p, int r){
	int q;
	if(p<r){
		q=(p+r)/2;
		tri_fusion(A,p,q);
		tri_fusion(A,q+1,r);
		fusion(A,p,q,r);
	}
}

void initSequenceEntiers(SEQUENCE *S, int *C){
	int i=0;
	int p = S->longueur;
	while(i<p){
		S->entiers[i] = C[i];
		i++;
	}
}

int ** longueurPlscEntiers(SEQUENCE *X, SEQUENCE *Y, char **b){
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
			if(X->entiers[i-1]==Y->entiers[j-1]){
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

void imprimerPlscEntiers(char **b, SEQUENCE *X, int i, int j){
	if(i==0 || j==0)
		return ;
	if(b[i][j] == '`'){
		imprimerPlscEntiers(b,X,i-1,j-1);
		printf("%d ",X->entiers[i-1]);
	}
	else{
		if(b[i][j] == '|')
			imprimerPlscEntiers(b,X,i-1,j);
		else
			imprimerPlscEntiers(b,X,i,j-1);
	}
}

void plsc_croissante(SEQUENCE *X){
	int n = X->longueur;
	SEQUENCE *Y = creerSequence(n);
	int *triee = (int *)malloc(n*sizeof(int));
	int i;
	for(i=0;i<n;i++)
		triee[i] = X->entiers[i];
	tri_fusion(triee,0,n-1);
	initSequenceEntiers(Y,triee);
	char **b = initSP(n + 1,n + 1);
	int ** c = longueurPlscEntiers(X,Y,b);
	imprimerPlscEntiers(b,X,n,n);
}

