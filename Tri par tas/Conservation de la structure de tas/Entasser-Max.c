#include <stdio.h>
#include <stdlib.h>
#define N 14
#define N1 10

typedef struct tas
{
    int longueur; /* limite sous laquelle le tableau peut contenir des nombres valides */
    int taille;   /* limite des nombres compris dans le tas */
    int *tableau; /* tableau contenant les éléments du tas */
} TAS;

typedef TAS *P_TAS;

int gauche(int i)
{
    return 2 * i + 1;
}

int droite(int i)
{
    return 2 * i + 2;
}

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

void entasser_max(P_TAS tas, int i)
{
    int l = gauche(i);
    int r = droite(i);
    int max;
    int *A = tas->tableau;
    if (l < tas->taille && A[l] > A[i])
        max = l;
    else
        max = i;
    if ((r < tas->taille) && (A[r] > A[max]))
        max = r;
    if (max != i)
    {
        echanger(A, i, max);
        entasser_max(tas, max);
    }
}

int main()
{
    P_TAS tas = creer_tas(N1, N1);
    P_TAS tas2 = creer_tas(N, N);
    int j;
    int tab[N1] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    int tab2[N] = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
    tas->tableau = tab;
    tas2->tableau = tab2;
    entasser_max(tas, 1);
    entasser_max(tas2, 2);
    for (j = 0; j < N1; j++)
    {
        printf("%d\t", tas->tableau[j]);
    }
    printf("\n\n\n");
    free(tas);
    free(tas2);
    return 0;
}
