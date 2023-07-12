#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 14
#define N1 10
#define I 3

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
    {
        max = l;
    }
    else
    {
        max = i;
    }
    if (r < tas->taille && A[r] > A[max])
    {
        max = r;
    }
    if (max != i)
    {
        echanger(A, i, max);
        entasser_max(tas, max);
    }
}

void construire_tas_max(P_TAS tas)
{
    tas->taille = tas->longueur;
    int i, k;
    for (i = ceil((tas->longueur) / 2) - 1; i >= 0; i--)
    {
        k = i;
        entasser_max(tas, k);
    }
}

int extraire_max_tas(P_TAS tas)
{
    if (tas->taille < 1)
    {
        printf("Limite inférieure dépassée\n\n\n");
        system("PAUSE");
        exit(1);
    }
    int *A = tas->tableau;
    int max = A[0];
    A[0] = A[tas->taille - 1];
    tas->taille--;
    entasser_max(tas, 0);
    return max;
}

int *selection_priorite(P_TAS A, int n, int i)
{
    int j, m;
    construire_tas_max(A);
    int *B = (int *)malloc(i * sizeof(int));
    for (j = 1; j <= i; j++)
    {
        m = extraire_max_tas(A);
        B[i - j] = m;
    }
    return B;
}

int main()
{
    P_TAS tas = creer_tas(N1, N1);
    P_TAS tas2 = creer_tas(N, N);
    int j;
    int tab[N1] = {3, 6, 1, 16, 2, 3, 43, 8, 5, 16};
    int tab2[N] = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
    tas->tableau = tab;
    tas2->tableau = tab2;
    int *B = selection_priorite(tas, N1, I);
    for (j = 0; j < I; j++)
    {
        printf("%d\t", B[j]);
    }
    printf("\n\n\n");
    free(tas);
    free(tas2);
    free(B);
    return 0;
}
