#include<stdio.h>
#include<stdlib.h>
#define N 10
#define CLE 15
#define D 3

typedef struct tas {
       int longueur;  /* limite sous laquelle le tableau peut contenir des nombres valides */
       int taille ;   /* limite des nombres compris dans le tas */
       int * tableau; /* tableau contenant les elements du tas */
       } TAS;

typedef TAS* P_TAS;
       
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

int parent_d_aire(int i, int d){
    return (i-1)/d;
}

void augmenter_cle_tas_d_aire(P_TAS tas, int i, int cle, int d){
     int * A = tas->tableau;
     if(cle<A[i]){
                  printf("Nouvelle cle plus petite que cle actuelle\n\n\n");
                  system("PAUSE");
                  exit(1);
                  }
     A[i]=cle;
     while((i>0)&&(A[parent_d_aire(i,d)]<A[i])){
                                              echanger(A,i,parent_d_aire(i,d));
                                              i=parent_d_aire(i,d);
                                              }
}

void inserer(P_TAS tas, int cle, int d){
     tas->taille++;
     long moins_infini = -100000000;
     tas->tableau[tas->taille-1]= moins_infini;
     augmenter_cle_tas_d_aire(tas,tas->taille-1,cle,d);
}

int main(){
    P_TAS tas = creer_tas(N,N);
    int tab[N] = {16,14,11,10,12,9,8,7,5,1};
    tas->tableau=tab;
    int i;
    inserer(tas,CLE,D); 
    for(i=0;i<tas->taille;i++){
                     printf("%d\t",tas->tableau[i]);
                     }
    printf("\n\n\n");
    return 0;
}
                        
