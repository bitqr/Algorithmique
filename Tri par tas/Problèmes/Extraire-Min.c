#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct tas
{
    int longueur; /* limite sous laquelle le tableau peut contenir des nombres valides */
    int taille;   /* limite des nombres compris dans le tas */
    int *tableau; /* tableau contenant les éléments du tas */
} TAS;

typedef TAS *P_TAS;

P_TAS creer_tas_Young(int taille, int m, int n)
{
    P_TAS t = (P_TAS)malloc(sizeof(TAS));
    t->longueur = m * n;
    t->taille = taille;
    int *tab = (int *)malloc(m * n * sizeof(int));
    t->tableau = tab;
    return t;
}

int gauche(int i)
{
    return 2 * i + 1;
}

int droite(int i)
{
    return 2 * i + 2;
}

void echanger(int *Y, int a, int b)
{
    int tmp = Y[b];
    Y[b] = Y[a];
    Y[a] = tmp;
}

void entasser_min(P_TAS tas, int i)
{
    int l = gauche(i);
    int r = droite(i);
    int min;
    int *A = tas->tableau;
    if ((l < tas->taille) && (A[l] < A[i]))
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

int extraire_min(P_TAS tas)
{
    int *A = tas->tableau;
    int n = tas->taille;
    int min = A[0];
    A[0] = A[n - 1];
    tas->taille--;
    entasser_min(tas, 0);
    return min;
}

int main()
{
    int j;
    P_TAS tas = creer_tas_Young(9, 4, 4);
    int tab[N] = {2, 3, 4, 5, 8, 9, 12, 14, 16};
    tas->tableau = tab;
    int n = extraire_min(tas);
    printf("Le minimum du tas est %d\n\n", n);
    for (j = 0; j < tas->taille; j++)
    {
        printf("%d\t", tas->tableau[j]);
    }
    printf("\n\n\n");
    return 0;
}
