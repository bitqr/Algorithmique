#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 4

typedef struct _POT{
        char * couleur;
        int contenance;
}POT;
        
typedef struct _PAIRE_POT{
        int premier;
        int second;
}PAIREPOT;

        
POT * creer_pot(char* coul , int contenance){
    POT * pot = (POT *) malloc(sizeof(POT));
    pot->couleur = (char *)malloc((strlen(coul)+1)*sizeof(char));
    pot->couleur = coul;
    pot->contenance = contenance;
    return pot;
}

PAIREPOT * creer_paire_pot(){
         PAIREPOT * p = (PAIREPOT *)malloc(sizeof(PAIREPOT));
         return p;
}

PAIREPOT ** creer_tableau_paire(int n){
        PAIREPOT ** P = (PAIREPOT **)malloc(n*sizeof(PAIREPOT *));
        int i;
        for(i=0;i<n;i++){
            P[i] = creer_paire_pot();
        }
    return P;
}

PAIREPOT ** tri_pots_quadratique(POT ** A, POT ** B, int n){
    int i,j,k=0,l;
    PAIREPOT ** P = creer_tableau_paire(n);
    for(i=0;i<n;i++){
        l=A[i]->contenance;
        for(j=0;j<n;j++){
            if(l==B[j]->contenance){
                P[k]->premier=i;
                P[k]->second =j;
                k++;
                break;
            }
        }
    }
    return P;
}

int main(){
    POT * p1 = creer_pot("rouge",50);
    POT * p2 = creer_pot("rouge",100);
    POT * p3 = creer_pot("rouge",150);
    POT * p4 = creer_pot("rouge",200);
    
    POT * q1 = creer_pot("bleu",50);
    POT * q2 = creer_pot("bleu",100);
    POT * q3 = creer_pot("bleu",150);
    POT * q4 = creer_pot("bleu",200);
    
    POT * A[N] = {q1,q2,q3,q4};

    POT * B[N] = {p2,p1,p4,p3};    

    PAIREPOT ** P = tri_pots_quadratique(A,B,N);

    int i;

    for(i=0;i<N;i++){
        printf("( %d ; %d )\n", P[i]->premier+1,P[i]->second+1);
    }
    printf("\n\n\n");
    return 0;
}

