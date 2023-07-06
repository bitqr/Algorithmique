#include <stdio.h>
#include <stdlib.h>
#define N 10
#define I 3

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

int gauche(int i)
{
    return 2 * i + 1;
}

int droite(int i)
{
    return 2 * i + 2;
}

void entasser_max(P_TAS tas, int i)
{
    int l = gauche(i);
    int r = droite(i);
    int max;
    int *A = tas->tableau;
    if ((l < tas->taille) && (A[l] > A[i]))
    {
        max = l;
    }
    else
    {
        max = i;
    }
    if ((r < tas->taille) && (A[r] > A[max]))
    {
        max = r;
    }
    if (max != i)
    {
        echanger(A, i, max);
        entasser_max(tas, max);
    }
}

int extraire_max_tas(P_TAS tas)
{
    if (tas->taille < 1)
    {
        printf("Limite inferieure depassee\n\n\n");
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

void supprimer_tas(P_TAS tas, int i)
{
    int *A = tas->tableau;
    if (i == tas->taille - 1)
    {
        tas->taille--;
    }
    else
    {
        echanger(A, i, 0);
        while ((parent(i) != 0) && (A[parent(i)] < A[i]))
        {
            echanger(A, i, parent(i));
            i = parent(i);
        }
        extraire_max_tas(tas);
    }
}

int main()
{
    P_TAS tas = creer_tas(N, N);
    int tab[N] = {16, 14, 10, 8, 7, 9, 3, 4, 2, 1};
    tas->tableau = tab;
    int i;
    supprimer_tas(tas, I);
    for (i = 0; i < tas->taille; i++)
    {
        printf("%d\t", tas->tableau[i]);
    }
    printf("\n\n\n");
    return 0;
}
