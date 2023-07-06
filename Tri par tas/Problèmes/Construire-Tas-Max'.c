#include <stdio.h>
#include <stdlib.h>
#define N 10
#define CLE 15

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

void echanger(int *A, int a, int b)
{
     int tmp = A[b];
     A[b] = A[a];
     A[a] = tmp;
}

int parent(int i)
{
     return (i - 1) / 2;
}

void augmenter_cle_tas(P_TAS tas, int i, int cle)
{
     int *A = tas->tableau;
     if (cle < A[i])
     {
          printf("Nouvelle clé plus petite que clé actuelle\n\n\n");
          system("PAUSE");
          exit(1);
     }
     A[i] = cle;
     while ((i > 0) && (A[parent(i)] < A[i]))
     {
          echanger(A, i, parent(i));
          i = parent(i);
     }
}

void inserer_tas_max(P_TAS tas, int cle)
{
     tas->taille++;
     long moins_infini = -100000000;
     tas->tableau[tas->taille - 1] = moins_infini;
     augmenter_cle_tas(tas, tas->taille - 1, cle);
}

void construire_tas_max_prim(P_TAS tas)
{
     tas->taille = 1;
     int i;
     for (i = 1; i < tas->longueur; i++)
          inserer_tas_max(tas, tas->tableau[i]);
}

int main()
{
     P_TAS tas = creer_tas(N, N);
     int j;
     int tab[N] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
     tas->tableau = tab;
     construire_tas_max_prim(tas);
     for (j = 0; j < tas->taille; j++)
          printf("%d\t", tas->tableau[j]);
     printf("\n\n\n");
     free(tas);
     return 0;
}
