#include "PROB.h"

void permuter(int* A, int i, int j){
	int tmp = A[i];
	A[i]=A[j];
	A[j]=tmp;
}

int partition_taches(int * A, int *P, int a, int b){
    int x = P[b];
    int i = a-1;
    int j;
    for(j=a;j<b;j++){
		if(P[j]<=x){
			i++;
			permuter(A,i,j);
			permuter(P,i,j);
		}
	}
    permuter(A,i+1,b);
    permuter(P,i+1,b);
    
    return i+1;
}

void tri_rapide_taches(int* A, int *P, int a, int b){
	if(a<b){
			int q=partition_taches(A,P,a,b);
			tri_rapide_taches(A,P,a,q-1);
			tri_rapide_taches(A,P,q+1,b);
	}
}

int * ordonnancement_taches(int *A, int *P, int n){
	tri_rapide_taches(A,P,0,n-1);
	return A;
}

int main(int argc, char ** argv){
	int A[8] = {1,2,3,4,5,6,7,8};
	int P[8] = {5,10,3,2,6,7,11,4};
	int *T = ordonnancement_taches(A,P,8);
	printf("L'ordonnancement optimal est affiche ainsi (les nombres	indiquent les taches qui sont executees, dans l'ordre, de gauche a droite :\n\n");
	int i,j,d=0,sd=0,n=8;
	for(i=0;i<n;i++){
		printf("|(%d)",A[i]);
		j=P[i];
		d+=j;
		sd+=d;
		j--;
		while(j!=0){
			printf("_");
			j--;
		}		
	}
	printf("|\n\nLe cout de l'ordonnancement optimal est de %f.\n\n",(double)(sd/8.0));
	
	int A2[8] = {1,2,3,4,5,6,7,8};
	int P2[8] = {5,10,3,2,6,7,11,4};
	int R2[8] = {2,1,4,7,2,6,0,6};
	int j1,t1=0,t2=0;
	
	LISTE_CHAINEE *L = ordonnancement_preemptif(A2,P2,R2,n);
	
	printf("L'ordonnancement optimal est le suivant :\n\n");
	while(L != NULL){
		j1 = L->cle;
		t2=t1;
		while(L!= NULL && L->cle == j1){	
			t2++;
			L=L->suiv;
		}
		if(j1==0) 
			printf("Aucune tache executee des dates %d a %d\n",t1,t2);
		else
			printf("La tache %d executee des dates %d a %d\n",j1,t1,t2);
		t1 = t2;
	}
	printf("\n\n");
	
	return 0;
}

