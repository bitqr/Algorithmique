#include<stdio.h>
#include<stdlib.h>
#define N 10


typedef struct tas {
       int longueur;  /* limite sous laquelle le tableau peut contenir des nombres valides */
       int taille ;   /* limite des nombres compris dans le tas */
       int * tableau; /* tableau contenant les elements du tas */
       } TAS;

typedef TAS* P_TAS;
       
int minimum_tas(P_TAS t){
    return t->tableau[0];
}

P_TAS creer_tas(int longueur, int taille){
      P_TAS t = (P_TAS) malloc( sizeof(TAS));
      t->longueur = longueur;
      t->taille = taille;
      int * tab = (int *) malloc( longueur * sizeof(int));
      t->tableau = tab;
      return t;
}     


int main(){
    P_TAS tas = creer_tas(N,N);
    int tab[N] = {1,2,3,4,5,6,7,8,9,10};
    tas->tableau = tab;
    printf("Le minimum du tas est %d\n\n",minimum_tas(tas));
    return 0;
}
