#include <stdio.h>
#include <stdlib.h>
#define N1 10

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

void entasser_max(P_TAS tas, int i)
{
    int l = gauche(i);
    int r = droite(i);
    int max;
    int *A = tas->tableau;
    if ((l < tas->taille) && (A[l] > A[i]))
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

int main()
{
    int j;
    P_TAS tas = creer_tas(N1, N1);
    int tab[N1] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    tas->tableau = tab;
    int n = extraire_max_tas(tas);
    printf("Le maximum du tas est %d\n\n", n);
    for (j = 0; j < tas->taille; j++)
    {
        printf("%d\t", tas->tableau[j]);
    }
    printf("\n\n\n");
    return 0;
}
