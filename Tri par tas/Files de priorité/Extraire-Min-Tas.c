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

P_TAS creer_tas(int longueur, int taille)
{
    P_TAS t = (P_TAS)malloc(sizeof(TAS));
    t->longueur = longueur;
    t->taille = taille;
    int *tab = (int *)malloc(longueur * sizeof(int));
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
    {
        min = l;
    }
    else
    {
        min = i;
    }
    if (r < tas->taille && A[r] < A[min])
    {
        min = r;
    }
    if (min != i)
    {
        echanger(A, i, min);
        entasser_min(tas, min);
    }
}

int extraire_min_tas(P_TAS tas)
{
    if (tas->taille < 1)
    {
        printf("Limite inférieure dépassée\n\n\n");
        exit(1);
    }
    int *A = tas->tableau;
    int min = A[0];
    A[0] = A[tas->taille - 1];
    tas->taille--;
    entasser_min(tas, 0);
    return min;
}

int main()
{
    int j;
    P_TAS tas = creer_tas(N, N);
    int tab[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    tas->tableau = tab;
    int n = extraire_min_tas(tas);
    printf("Le minimum du tas est %d\n\n", n);
    for (j = 0; j < tas->taille; j++)
    {
        printf("%d\t", tas->tableau[j]);
    }
    printf("\n\n\n");
    return 0;
}
