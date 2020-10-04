#include<stdio.h>
#include<stdlib.h>
#define N1 9


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
     int max;
     int * A = tas -> tableau;
     if((l<tas->taille)&&(A[l]>A[i]))
                                      max = l;
     else                             max = i;
     if((r<tas->taille)&&(A[r]>A[max]))
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
   
void tri_par_tas(P_TAS tas){
     int j;
     construire_tas_max(tas);
     int i;
     int * A = tas->tableau;
     for(i=tas->longueur-1;i>=1;i--){
                                     echanger(A,0,i);
                                     tas->taille--;
                                     entasser_max(tas,0);
                                     }
}



int main(){
    P_TAS tas = creer_tas(N1,N1);
    int j;
    int tab[N1] = {5,13,2,25,7,17,20,8,4};
    tas->tableau = tab;
    tri_par_tas(tas);
    for(j=0;j<N1;j++)
                     printf("%d\t", tas->tableau[j]);
    printf("\n\n\n");
    free(tas);
    return 0;
}
