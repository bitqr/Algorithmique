#include"Mat.h"


void affichage_parenthesage_optimal(int **s, int i, int j){
	if(i==j)
		printf("A%d",i+1);
	else{
		printf("( ");
		affichage_parenthesage_optimal(s,i,s[i][j]);
		printf(" ");
		affichage_parenthesage_optimal(s,s[i][j]+1,j);
		printf(" )");
	}
}

