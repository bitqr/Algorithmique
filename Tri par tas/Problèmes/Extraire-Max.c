#include<stdio.h>
#include<stdlib.h>
#define N 10
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
   
void entasser_max_d_aire(P_TAS tas, int i, int d){
     int max=i;
     int * A = tas -> tableau;
     int deb = (i+1)*d-2;
     int f = (i+2)*d-3;
     int j;
     if(f<tas->taille){
                        for(j=deb;j<=f;j++){
                                            if(A[j]>A[max])
                                            max = j;
                                            }
                        if(max!=i){
                                   echanger(A,i,max);
                                   entasser_max_d_aire(tas,max,d);
                                   }
                        }
}




int extraire_max(P_TAS tas,int d){
    if(tas->taille<1){
                      printf("Limite inferieure depassee\n\n\n");
                      system("PAUSE");
                      exit(1);
                      }
    int * A = tas->tableau;
    int max = A[0];
    A[0] = A[tas->taille - 1];
    tas->taille--;
    entasser_max_d_aire(tas,0,d);
    return max;
}

int main(){
    int j;
    P_TAS tas = creer_tas(N,N);
    int tab[N] = {16,14,11,10,12,9,8,7,5,1};
    tas->tableau = tab;
    int n = extraire_max(tas,D);
    printf("Le maximum du tas est %d\n\n",n);
    for(j=0;j<tas->taille;j++){
                     printf("%d\t", tas->tableau[j]);
                     }
    printf("\n\n\n");
    return 0;
}

