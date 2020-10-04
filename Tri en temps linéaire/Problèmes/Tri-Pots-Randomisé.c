#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 8
#define K 650

typedef struct _POT{
        char * couleur;
        int contenance;
        int rang;
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

POT ** creer_tableau_pots(int n, char* coul){
    POT ** p =(POT **)malloc(n*sizeof(POT *));
    int i;
    for(i=0;i<n;i++){
        p[i] = creer_pot(coul,0);
        p[i]->rang = i+1;
    }
    return p;
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

int Random(int a, int b){
    int i;
    if(a==0 && b==1)
        return rand()%2;
    int acc=0;
    for(i=a;i<b;i++){
        acc += Random(0,1);
    }
    return a + acc;
}

POT** tri_denombrement_pots(POT ** A, int n, int k){
    POT ** B = creer_tableau_pots(n,"rouge");
    int i;
    int * C = (int *) malloc(k*sizeof(int));
    for(i=0;i<k;i++){
        C[i] = 0;
    }
    int j;
    for(j=0;j<n;j++){
        C[A[j]->contenance]++;
    }
    // C[i] contient maintenant le nombre d'éléments égaux à i.
    for(i=1;i<k;i++){
        C[i] += C[i-1];
    }
    // C[i] contient maintenant le nombre d'éléments inférieurs ou égaux à i.
    for(j=n-1;j>=0;j--){
        B[C[A[j]->contenance]-1]->contenance = A[j]->contenance;
        B[C[A[j]->contenance]-1]->rang = A[j]->rang;
        C[A[j]->contenance]--;
    }
    return B;
}

int recherche_dichotomique_pots(POT ** A, int deb, int fin, int cle){
    if(deb>fin){
        if(A[deb]->contenance==cle)
           return deb;
        else
            return -1;
    }
    int mil = (deb + fin)/2;
    if(A[mil]->contenance==cle)
        return mil;
    if(A[mil]->contenance<cle)
        return recherche_dichotomique_pots(A,mil+1,fin,cle);
    else
        return recherche_dichotomique_pots(A,deb,mil-1,cle);
}

PAIREPOT ** tri_pots_randomise(POT ** A, POT ** B, int n){
    POT ** B2 = tri_denombrement_pots(B,n,K);
    PAIREPOT ** C = creer_tableau_paire(n);
    int k = 0;
    int i,l,m,r;
    for(i=0;i<n;i++){
        l = A[i]->contenance;
        r = Random(0,n-1);
        if(B2[r]->contenance>l)
            m = recherche_dichotomique_pots(B2,0,r-1,l);
        else
            m = recherche_dichotomique_pots(B2,r,n-1,l);
        C[k]->premier = A[i]->rang;
        C[k]->second = B2[m]->rang;
        k++;
    }
    return C;
}

int main(){
    POT * p1 = creer_pot("rouge",50);
    POT * p2 = creer_pot("rouge",100);
    POT * p3 = creer_pot("rouge",150);
    POT * p4 = creer_pot("rouge",200);
    POT * p5 = creer_pot("rouge",75);
    POT * p6 = creer_pot("rouge",122);
    POT * p7 = creer_pot("rouge",190);
    POT * p8 = creer_pot("rouge",643);
    
    POT * q1 = creer_pot("bleu",50);
    POT * q2 = creer_pot("bleu",100);
    POT * q3 = creer_pot("bleu",150);
    POT * q4 = creer_pot("bleu",200);
    POT * q5 = creer_pot("bleu",75);
    POT * q6 = creer_pot("bleu",122);
    POT * q7 = creer_pot("bleu",190);
    POT * q8 = creer_pot("bleu",643);
    
    POT * A[N] = {q3,q5,q8,q6,q1,q7,q2,q4};

    POT * B[N] = {p8,p3,p1,p2,p6,p5,p4,p7};  
    
    int j;
    for(j=0;j<N;j++){
                     A[j]->rang = j+1;
                     B[j]->rang = j+1;
                     }  

    PAIREPOT ** P = tri_pots_randomise(A,B,N);

    int i;
    for(i=0;i<N;i++){
        printf("%d\t", A[i]->contenance);
    }
    printf("\n\n\n");
    for(i=0;i<N;i++){
        printf("%d\t", B[i]->contenance);
    }
    printf("\n\n\n");
    for(i=0;i<N;i++){
        printf("( %d ; %d )\n", P[i]->premier,P[i]->second);
    }
    printf("\n\n\n");
    return 0;
}

