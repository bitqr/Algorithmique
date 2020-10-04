#include"PLSC.h"

void imprimer_plsc(char **b, SEQUENCE *X, int i, int j){
	if(i==0 || j==0)
		return ;
	if(b[i][j] == '`'){
		imprimer_plsc(b,X,i-1,j-1);
		printf("%c",X->table[i-1]);
	}
	else{
		if(b[i][j] == '|')
			imprimer_plsc(b,X,i-1,j);
		else
			imprimer_plsc(b,X,i,j-1);
	}
}




