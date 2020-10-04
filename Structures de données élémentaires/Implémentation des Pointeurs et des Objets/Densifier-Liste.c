#include<stdio.h>
#include<stdlib.h>
#include"ImplementationObjets.h"

void densifier_liste(int *pred, int *cle, int *succ, int *L, int *libre){
	int prochain = *L , i = 1;
	int s,c,p;
	while(prochain != -1){	
		s = succ[prochain - 1];
		succ[prochain - 1] = succ[i - 1];
		succ[i - 1] = s;
		c = cle[prochain - 1];
		cle[prochain - 1] = cle[i - 1];
		cle[i - 1] = c;
		p = pred[prochain - 1];
		pred[prochain - 1] = pred[i - 1];
		pred[i - 1] = p;

		if(pred[i - 1] != -1)
			pred[i - 1] = i-1;
		succ[pred[i - 1]-1] = i;
		if(succ[i-1] == i){
			succ[i-1] = prochain;	
			pred[prochain - 1] = i;
		}
		if(pred[prochain - 1] != -1)
			succ[pred[prochain - 1]-1] = prochain;
		if(succ[prochain - 1] != -1)
			pred[succ[prochain - 1]-1] = prochain;

		prochain = succ[i - 1];
		i++;
	}
	*L = 1;
	*libre = i;
}

