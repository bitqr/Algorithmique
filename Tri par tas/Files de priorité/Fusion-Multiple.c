#include <stdio.h>
#include <stdlib.h>
#define N 12
#define K 4

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

int *fusion_multiple(P_TAS tas, int k)
{
    int n = tas->taille;
    int min = tas->tableau[0];
    int *A = (int *)malloc((n / k) * sizeof(int));
    int *B = (int *)malloc(n * sizeof(int));
    int i, f = n / k - 1;
    long infini = 1000000000;
    int b;
    int in = 0;
    int d = 0;
    int a = 0;
    while (a != n)
    {
        while (f < n)
        {
            int j = 0;
            for (i = d; i <= f; i++)
            {
                A[j] = tas->tableau[i];
                j++;
            }
            b = 0;
            while (tas->tableau[d + b] == infini && b < 3)
            {
                b++;
            }
            if (min > A[b])
            {
                in = d + b;
                min = A[b];
            }
            d = f + 1;
            f = f + n / k;
        }
        tas->tableau[in] = infini;
        B[a] = min;
        min = infini;
        a++;
        d = 0;
        f = n / k - 1;
    }
    return B;
}

int main()
{
    P_TAS tas = creer_tas(N, N);
    int tab[N] = {3, 4, 5, 1, 2, 8, 7, 9, 11, 4, 6, 10};
    tas->tableau = tab;
    int i;
    int *B = fusion_multiple(tas, K);
    for (i = 0; i < N; i++)
    {
        printf("%d\t", B[i]);
    }
    printf("\n\n\n");
    return 0;
}
