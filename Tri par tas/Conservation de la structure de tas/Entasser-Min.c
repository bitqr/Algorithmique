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

void entasser_min(P_TAS tas, int i)
{
    int l = gauche(i);
    int r = droite(i);
    int min;
    int *A = tas->tableau;
    if (l < tas->taille && A[l] < A[i])
        min = l;
    else
        min = i;
    if ((r < tas->taille) && (A[r] < A[min]))
        min = r;
    if (min != i)
    {
        echanger(A, i, min);
        entasser_min(tas, min);
    }
}

int main()
{
    P_TAS tas = creer_tas(N1, N1);
    int j;
    int tab[N1] = {1, 5, 6, 7, 2, 9, 15, 12, 11, 3};
    tas->tableau = tab;
    entasser_min(tas, 1);
    for (j = 0; j < N1; j++)
    {
        printf("%d\t", tas->tableau[j]);
    }
    printf("\n\n\n");
    free(tas);
    return 0;
}
