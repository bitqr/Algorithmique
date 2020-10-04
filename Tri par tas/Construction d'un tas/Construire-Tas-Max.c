#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 14
#define N1 10

typedef struct tas {
    int longueur;  /* limite sous laquelle le tableau peut contenir des nombres valides */
    int taille ;   /* limite des nombres compris dans le tas */
    int * tableau; /* tableau contenant les elements du tas */
} TAS;

typedef TAS* P_TAS;
       
int gauche(int i){
    return 2*i+1;
}

int droite(int i){
    return 2*i+2;
}

P_TAS creer_tas(int longueur, int taille){
    P_TAS t = (P_TAS) malloc( sizeof(TAS));
    t->longueur = longueur;
    t->taille = taille;
    int * tab = (int *) malloc( longueur * sizeof(int));
    t->tableau = tab;
    return t;
}     

void echanger(int* A, int a, int b){
    int tmp = A[b];
    A[b] = A[a];
    A[a] = tmp;
}

void entasser_max(P_TAS tas, int i){
    int l = gauche(i);
    int r = droite(i);
    int j,max;
    int * A = tas -> tableau;
    if(l<tas->taille && A[l]>A[i])
        max = l;
    else
        max = i;
    if(r<tas->taille && A[r]>A[max])
        max = r;
    if(max!=i){
        echanger(A,i,max);
        entasser_max(tas, max);
    }
}

void construire_tas_max(P_TAS tas){
    tas -> taille = tas -> longueur;
    int i,k;
    for(i=ceil((tas->longueur)/2)-1;i>=0;i--){
        k=i;
        entasser_max(tas,k);
    }
}

int main(){
    P_TAS tas = creer_tas(N1,N1);
    int j;
    int tab[N1] = {4,1,3,2,16,9,10,14,8,7};
    tas->tableau = tab;
    construire_tas_max(tas);
    for(j=0;j<tas->taille;j++)
        printf("%d\t", tas->tableau[j]);
    printf("\n\n\n");
    free(tas);
    return 0;
}

