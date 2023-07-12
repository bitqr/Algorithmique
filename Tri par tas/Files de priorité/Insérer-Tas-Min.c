#include <stdio.h>
#include <stdlib.h>
#define N 10
#define CLE 4

typedef struct tas
{
     int longueur; /* limite sous laquelle le tableau peut contenir des nombres valides */
     int taille;   /* limite des nombres compris dans le tas */
     int *tableau; /* tableau contenant les éléments du tas */
} TAS;

typedef TAS *P_TAS;

P_TAS creer_tas(int longueur, int taille)
{
     P_TAS t = (P_TAS)malloc(sizeof(TAS));
     t->longueur = longueur;
     t->taille = taille;
     int *tab = (int *)malloc(longueur * sizeof(int));
     t->tableau = tab;
     return t;
}

void permuter(int *A, int a, int b)
{
     int tmp = A[b];
     A[b] = A[a];
     A[a] = tmp;
}

int parent(int i)
{
     return (i - 1) / 2;
}

void diminuer_cle_tas(P_TAS tas, int i, int cle)
{
     int *A = tas->tableau;
     if (cle > A[i])
     {
          printf("Nouvelle clé plus grande que clé actuelle\n\n\n");
          exit(1);
     }
     A[i] = cle;
     while (i > 0 && A[parent(i)] > A[i])
     {
          permuter(A, i, parent(i));
          i = parent(i);
     }
}

void inserer_tas_min(P_TAS tas, int cle)
{
     tas->taille++;
     long infini = 100000000;
     tas->tableau[tas->taille - 1] = infini;
     diminuer_cle_tas(tas, tas->taille - 1, cle);
}

int main()
{
     P_TAS tas = creer_tas(N, N);
     int tab[N] = {1, 2, 7, 8, 10, 11, 12, 14, 17, 21};
     tas->tableau = tab;
     int i;
     inserer_tas_min(tas, CLE);
     for (i = 0; i < N + 1; i++)
     {
          printf("%d\t", tas->tableau[i]);
     }
     printf("\n\n\n");
     return 0;
}
