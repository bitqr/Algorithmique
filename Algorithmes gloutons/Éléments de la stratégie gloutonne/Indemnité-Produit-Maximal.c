#include"Glouton.h"

long long int indemnite_produit_maximal(int *A, int *B, int n){
	int i,j;
	for(i=0;i<n;i++){
		A[i] = - A[i];
		B[i] = - B[i];
	}
	tri_rapide(A,0,n-1);
	tri_rapide(B,0,n-1);
	for(i=0;i<n;i++){
		A[i] = - A[i];
		B[i] = - B[i];
	}
	long long int produit = 1;
	for(j=0;j<n;j++){
		for(i=1;i<=B[j];i++){
			produit = produit * A[j];
		}
		
	}
	return produit;
}


int main(int argc, char **argv){
	int A[N3] = {3,4,2,8,4};
	int B[N3] = {2,6,4,3,5};
	long long int c = indemnite_produit_maximal(A,B,N3);
	printf("Le cout optimal est de %lld\n\n",c);
	return 0;
}


