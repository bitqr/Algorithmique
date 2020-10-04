#include"MATRO.h"

void permuter(int*A,int i, int j){
     int tmp = A[i];
     A[i]=A[j];
     A[j]=tmp;
}

int partition_decroissant(int * A, int *w, int p, int r){
    int x = w[A[r]];
    int i = p-1;
    int j;
    for(j=p;j<r;j++){
		if(w[A[j]]>=x){
			i++;
			permuter(A,i,j);
		}
	}
    permuter(A,i+1,r);
    return i+1;
}

void tri_rapide_matroide_decroissant(int*A, int *w, int p, int r){
	if(p<r){
		int q=partition_decroissant(A,w,p,r);
		tri_rapide_matroide_decroissant(A,w,p,q-1);
		tri_rapide_matroide_decroissant(A,w,q+1,r);
	}
}

int appartient(int x, ENSEMBLE *J){
	int i;
	for(i=0;i<J->longueur;i++){
		if(J->elements[i] == x)
			return 1;
	}
	return 0;
}

int appartient_independant(ENSEMBLE *F, int x, INDEPENDANTS *I){
	F->longueur++;
	F->elements[F->longueur-1] = x;
	int j,i;
	for(j=0;j<I->longueur;j++){
		ENSEMBLE * J = I->ensembles[j];
		if(J->longueur == F->longueur){
			i=0;
			while(appartient(F->elements[i],J) && i<F->longueur){
				i++;
			}
			if(i==F->longueur){
				F->longueur--;
				return 1;
			}
		}
	}
	F->longueur--;
	return 0;
}

ENSEMBLE* glouton(MATROIDE *M, int *w){
	ENSEMBLE * F = (ENSEMBLE *) malloc(sizeof(ENSEMBLE));
	F->taille = MAX;
	F->longueur = 0;
	F->elements = (int *)malloc(F->taille*sizeof(int));
	tri_rapide_matroide_decroissant(M->E->elements,w,0,M->E->longueur-1);
	tri_rapide_matroide_decroissant(M->S->elements,w,0,M->S->longueur-1);
	int i,x;
	for(i=0;i<M->S->longueur;i++){
		x = M->S->elements[i];
		if(appartient_independant(F,x,M->I)){
			F->longueur++;
			F->elements[F->longueur-1] = x;
		}
	}
	return F;
}

int main(int argc, char **argv){
	MATROIDE *M = (MATROIDE *)malloc(sizeof(MATROIDE));
	M->E = (ENSEMBLE *)malloc(sizeof(ENSEMBLE));
	M->E->taille = MAX;
	M->E->longueur = N;
	M->E->elements = (int *)malloc(M->E->longueur*sizeof(int));
	M->S = (ENSEMBLE *)malloc(sizeof(ENSEMBLE));
	M->S->taille = MAX;
	M->S->longueur = N;
	M->S->elements = (int *)malloc(M->S->longueur*sizeof(int));
	int i;
	for(i=0;i<M->E->longueur;i++){
		M->E->elements[i] = i;
		M->S->elements[i] = i;
	}
	int w[N] = {3,14,23,12,8,9,2,21,11,6};
	INDEPENDANTS * I = (INDEPENDANTS *)malloc(sizeof(INDEPENDANTS));
	I->longueur = M1;
	I->taille = MAX;
	ENSEMBLE ** EN = (ENSEMBLE **)malloc(M1*sizeof(ENSEMBLE*));
	for(i=0;i<I->longueur;i++){
		EN[i] = (ENSEMBLE *)malloc(sizeof(ENSEMBLE));
		EN[i]->taille = MAX;
	}
	
	EN[0]->longueur = 3 ;
	EN[0]->elements = (int *)malloc(EN[0]->longueur*sizeof(int));
	EN[0]->elements[0] = 2;EN[0]->elements[1] = 7;EN[0]->elements[2] = 9;
	
	EN[1]->longueur = 2; 
	EN[1]->elements = (int *)malloc(EN[1]->longueur*sizeof(int));
	EN[1]->elements[0] = 1;EN[1]->elements[1] = 4;
	
	EN[2]->longueur = 3;
	EN[2]->elements = (int *)malloc(EN[2]->longueur*sizeof(int));
	EN[2]->elements[0] = 0;EN[2]->elements[1] = 3;EN[2]->elements[2] = 5;
	
	EN[3]->longueur = 1;
	EN[3]->elements = (int *)malloc(EN[3]->longueur*sizeof(int));
	EN[3]->elements[0] = 2;

	EN[4]->longueur = 2;
	EN[4]->elements = (int *)malloc(EN[4]->longueur*sizeof(int));
 	EN[4]->elements[0] = 7;EN[4]->elements[1] = 9;
 
	EN[5]->longueur = 2;
	EN[5]->elements = (int *)malloc(EN[5]->longueur*sizeof(int));
	EN[5]->elements[0] = 2;EN[5]->elements[1] = 4;
	
	EN[6]->longueur = 1;
	EN[6]->elements = (int *)malloc(EN[6]->longueur*sizeof(int));
	EN[6]->elements[0] = 4;
	
	EN[7]->longueur = 2;
	EN[7]->elements = (int *)malloc(EN[7]->longueur*sizeof(int));
	EN[7]->elements[0] = 2;EN[7]->elements[1] = 7;
	
	EN[8]->longueur = 1;
	EN[8]->elements = (int *)malloc(EN[8]->longueur*sizeof(int));
	EN[8]->elements[0] = 1;

	EN[9]->longueur = 1;
	EN[9]->elements = (int *)malloc(EN[9]->longueur*sizeof(int));
	EN[9]->elements[0] = 7;
	
	EN[10]->longueur = 1; 
	EN[10]->elements = (int *)malloc(EN[10]->longueur*sizeof(int));
	EN[10]->elements[0] = 9;
	
	EN[11]->longueur = 2;
	EN[11]->elements = (int *)malloc(EN[11]->longueur*sizeof(int));
	EN[11]->elements[0] = 2;EN[11]->elements[1] = 9;
	
	EN[12]->longueur = 1;
	EN[12]->elements = (int *)malloc(EN[12]->longueur*sizeof(int));
	EN[12]->elements[0] = 0;
	
	EN[13]->longueur = 1;
	EN[13]->elements = (int *)malloc(EN[13]->longueur*sizeof(int));
	EN[13]->elements[0] = 3;
	
	EN[14]->longueur = 1;
	EN[14]->elements = (int *)malloc(EN[14]->longueur*sizeof(int));
	EN[14]->elements[0] = 5;
	
	EN[15]->longueur = 2;
	EN[15]->elements = (int *)malloc(EN[15]->longueur*sizeof(int));
	EN[15]->elements[0] = 0;EN[15]->elements[1] = 3;
	
	EN[16]->longueur = 2;
	EN[16]->elements = (int *)malloc(EN[16]->longueur*sizeof(int));
	EN[16]->elements[0] = 3;EN[11]->elements[1] = 5;
	
	EN[17]->longueur = 2;
	EN[17]->elements = (int *)malloc(EN[17]->longueur*sizeof(int));
	EN[17]->elements[0] = 0;EN[17]->elements[1] = 5;
	
	EN[18]->longueur = 3;
	EN[18]->elements = (int *)malloc(EN[18]->longueur*sizeof(int));
	EN[18]->elements[0] = 0;EN[18]->elements[1] = 1;EN[18]->elements[2] = 4;
	
	EN[19]->longueur = 3;
	EN[19]->elements = (int *)malloc(EN[19]->longueur*sizeof(int));
	EN[19]->elements[0] = 0;EN[19]->elements[1] = 2;EN[19]->elements[2] = 9;
	
	EN[20]->longueur = 3;
	EN[20]->elements = (int *)malloc(EN[20]->longueur*sizeof(int));
	EN[20]->elements[0] = 0;EN[20]->elements[1] = 7;EN[20]->elements[2] = 9;
	
	EN[21]->longueur = 3;
	EN[21]->elements = (int *)malloc(EN[21]->longueur*sizeof(int));
	EN[21]->elements[0] = 0;EN[21]->elements[1] = 2;EN[21]->elements[2] = 7;
	
	EN[22]->longueur = 3;
	EN[22]->elements = (int *)malloc(EN[22]->longueur*sizeof(int));
	EN[22]->elements[0] = 2;EN[22]->elements[1] = 4;EN[22]->elements[2] = 5;
	
	EN[23]->longueur = 2;
	EN[23]->elements = (int *)malloc(EN[23]->longueur*sizeof(int));
	EN[23]->elements[0] = 0;EN[23]->elements[1] = 1;
	
	EN[24]->longueur = 2;
	EN[24]->elements = (int *)malloc(EN[24]->longueur*sizeof(int));
	EN[24]->elements[0] = 2;EN[24]->elements[1] = 3;
	
	EN[25]->longueur = 2;
	EN[25]->elements = (int *)malloc(EN[25]->longueur*sizeof(int));
	EN[25]->elements[0] = 0;EN[25]->elements[1] = 2;
	
	EN[26]->longueur = 2;
	EN[26]->elements = (int *)malloc(EN[26]->longueur*sizeof(int));
	EN[26]->elements[0] = 4;EN[26]->elements[1] = 7;
	
	EN[27]->longueur = 2;
	EN[27]->elements = (int *)malloc(EN[27]->longueur*sizeof(int));
	EN[27]->elements[0] = 4;EN[27]->elements[1] = 9;
	
	EN[28]->longueur = 2;
	EN[28]->elements = (int *)malloc(EN[28]->longueur*sizeof(int));
	EN[28]->elements[0] = 0;EN[28]->elements[1] = 9;
	
	EN[29]->longueur = 2;
	EN[29]->elements = (int *)malloc(EN[29]->longueur*sizeof(int));
	EN[29]->elements[0] = 3;EN[29]->elements[1] = 7;
	
	EN[30]->longueur = 2;
	EN[30]->elements = (int *)malloc(EN[30]->longueur*sizeof(int));
	EN[30]->elements[0] = 3;EN[30]->elements[1] = 9;
	
	EN[31]->longueur = 2;
	EN[31]->elements = (int *)malloc(EN[31]->longueur*sizeof(int));
	EN[31]->elements[0] = 0;EN[31]->elements[1] = 4;
	
	EN[32]->longueur = 2;
	EN[32]->elements = (int *)malloc(EN[32]->longueur*sizeof(int));
	EN[32]->elements[0] = 0;EN[32]->elements[1] = 7;
	
	EN[33]->longueur = 2;
	EN[33]->elements = (int *)malloc(EN[33]->longueur*sizeof(int));
	EN[33]->elements[0] = 1;EN[33]->elements[1] = 7;
	
	EN[34]->longueur = 2;
	EN[34]->elements = (int *)malloc(EN[34]->longueur*sizeof(int));
	EN[34]->elements[0] = 1;EN[34]->elements[1] = 2;
	
	EN[35]->longueur = 2;
	EN[35]->elements = (int *)malloc(EN[35]->longueur*sizeof(int));
	EN[35]->elements[0] = 3;EN[35]->elements[1] = 4;
	
	EN[36]->longueur = 2;
	EN[36]->elements = (int *)malloc(EN[36]->longueur*sizeof(int));
	EN[36]->elements[0] = 1;EN[36]->elements[1] = 3;
	
	EN[37]->longueur = 2;
	EN[37]->elements = (int *)malloc(EN[37]->longueur*sizeof(int));
	EN[37]->elements[0] = 2;EN[37]->elements[1] = 5;
	
	EN[38]->longueur = 2;
	EN[38]->elements = (int *)malloc(EN[38]->longueur*sizeof(int));
	EN[38]->elements[0] = 5;EN[38]->elements[1] = 7;
	
	EN[39]->longueur = 2;
	EN[39]->elements = (int *)malloc(EN[39]->longueur*sizeof(int));
	EN[39]->elements[0] = 4;EN[39]->elements[1] = 5;
	
	EN[40]->longueur = 3;
	EN[40]->elements = (int *)malloc(EN[40]->longueur*sizeof(int));
	EN[40]->elements[0] = 2;EN[40]->elements[1] = 5;EN[40]->elements[2] = 7;
	
	EN[41]->longueur = 3;
	EN[41]->elements = (int *)malloc(EN[41]->longueur*sizeof(int));
	EN[41]->elements[0] = 0;EN[41]->elements[1] = 2;EN[41]->elements[2] = 7;
	
	EN[42]->longueur = 3;
	EN[42]->elements = (int *)malloc(EN[42]->longueur*sizeof(int));
	EN[42]->elements[0] = 2;EN[42]->elements[1] = 5;EN[42]->elements[2] = 9;
	
	EN[43]->longueur = 3;
	EN[43]->elements = (int *)malloc(EN[43]->longueur*sizeof(int));
	EN[43]->elements[0] = 0;EN[43]->elements[1] = 2;EN[43]->elements[2] = 4;
	
	EN[44]->longueur = 3;
	EN[44]->elements = (int *)malloc(EN[44]->longueur*sizeof(int));
	EN[44]->elements[0] = 2;EN[44]->elements[1] = 4;EN[44]->elements[2] = 7;
	
	EN[45]->longueur = 3;
	EN[45]->elements = (int *)malloc(EN[45]->longueur*sizeof(int));
	EN[45]->elements[0] = 0;EN[45]->elements[1] = 2;EN[45]->elements[2] = 3;
	
	EN[46]->longueur = 3;
	EN[46]->elements = (int *)malloc(EN[46]->longueur*sizeof(int));
	EN[46]->elements[0] = 2;EN[46]->elements[1] = 3;EN[46]->elements[2] = 5;
	
	EN[47]->longueur = 3;
	EN[47]->elements = (int *)malloc(EN[47]->longueur*sizeof(int));
	EN[47]->elements[0] = 0;EN[47]->elements[1] = 1;EN[47]->elements[2] = 5;
	
	EN[48]->longueur = 3;
	EN[48]->elements = (int *)malloc(EN[48]->longueur*sizeof(int));
	EN[48]->elements[0] = 0;EN[48]->elements[1] = 2;EN[48]->elements[2] = 5;
	
	EN[49]->longueur = 3;
	EN[49]->elements = (int *)malloc(EN[49]->longueur*sizeof(int));
	EN[49]->elements[0] = 0;EN[49]->elements[1] = 5;EN[49]->elements[2] = 7;
	
	EN[50]->longueur = 3;
	EN[50]->elements = (int *)malloc(EN[50]->longueur*sizeof(int));
	EN[50]->elements[0] = 1;EN[50]->elements[1] = 2;EN[50]->elements[2] = 4;
	
	EN[51]->longueur = 3;
	EN[51]->elements = (int *)malloc(EN[51]->longueur*sizeof(int));
	EN[51]->elements[0] = 0;EN[51]->elements[1] = 1;EN[51]->elements[2] = 4;
	
	EN[52]->longueur = 3;
	EN[52]->elements = (int *)malloc(EN[52]->longueur*sizeof(int));
	EN[52]->elements[0] = 0;EN[52]->elements[1] = 1;EN[52]->elements[2] = 3;
	
	EN[53]->longueur = 3;
	EN[53]->elements = (int *)malloc(EN[53]->longueur*sizeof(int));
	EN[53]->elements[0] = 0;EN[53]->elements[1] = 3;EN[53]->elements[2] = 7;
	
	I->ensembles = EN;
	
	M->I = I;
	
	printf("Matroide M\n\n");
	printf("E = { ");
	int j,k;
	for(j=0;j<M->E->longueur-1;j++){
		printf("%d , ",M->E->elements[j]);
	}
	printf("%d }\n\n",M->E->elements[j]);
	
	printf("I = { \n\n");
	for(j=0;j<I->longueur-1;j++){
		printf("{ ");
		for(k=0;k<I->ensembles[j]->longueur-1;k++){
			printf("%d , ",I->ensembles[j]->elements[k]);
		}
		printf("%d }\n\n",I->ensembles[j]->elements[k]);
	}
		
	printf(" }\n\n");
	
	ENSEMBLE *F = glouton(M,w);
	int wF = 0;
	printf("\n\nL'ensemble independant F optimal est :\n\n");
	printf(" { ");
	for(j=0;j<F->longueur-1;j++){
		printf("%d , ", F->elements[j]);
		wF+=w[F->elements[j]];
	}
	printf("%d }\n", F->elements[j]);
	wF+=w[F->elements[j]];
	
	printf("\nde poids %d\n\n\n",wF);
	
	return 0;
}

