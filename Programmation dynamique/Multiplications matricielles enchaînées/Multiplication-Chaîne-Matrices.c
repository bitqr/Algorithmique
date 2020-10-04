#include"Mat.h"


MATRICE * multiplication_chaine_matrices(MATRICE **A, int **s, int i, int j){
	if(i==j)
		return A[i];
	else{
		int k = s[i][j];
		MATRICE *A1 = multiplication_chaine_matrices(A,s,i,k);
		MATRICE *A2 = multiplication_chaine_matrices(A,s,k+1,j);
		return multiplier_matrices(A1,A2);
	}
}


