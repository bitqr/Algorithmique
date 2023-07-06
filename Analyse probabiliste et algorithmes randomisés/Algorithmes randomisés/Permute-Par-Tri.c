#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define N 7

int Random(int a, int b)
{
    int i;
    if ((a == 0) && (b == 1))
        return rand() % 2;
    int acc = 0;
    for (i = a; i < b; i++)
    {
        acc += Random(0, 1);
    }
    return a + acc;
}

int rechmin(int *tab, int n)
{
    int i;
    int min = 0;
    for (i = 1; i < n; i++)
    {
        if (tab[min] > tab[i])
            min = i;
    }
    return min;
}

void trier_avec_cle(int *A, int *P, int n)
{
    int i, mi;
    int *B = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        mi = rechmin(P, n);
        B[i] = A[mi];
        P[mi] = n * n * n + 1;
    }
    for (i = 0; i < n; i++)
    {
        A[i] = B[i];
    }
    free(B);
}

int *permute_par_tri(int *A, int n)
{
    int *P = (int *)malloc(n * sizeof(int));
    int i, j;
    for (i = 0; i < n; i++)
    {
        P[i] = Random(1, n * n * n);
    }
    for (i = 0; i < n; i++)
        printf("%d\t", P[i]);
    printf("\n\n\n");
    trier_avec_cle(A, P, n);
    free(P);
    return A;
}

int *permute_par_tri2(int *A, int n)
{
    int *P = (int *)malloc(n * sizeof(int));
    int i, j;
    for (i = 0; i < n; i++)
    {
        P[i] = Random(1, n * n * n);
        for (j = 0; j < i; j++)
        {
            while (P[i] == P[j])
                P[i] = Random(1, n * n * n);
        }
    }
    for (i = 0; i < n; i++)
        printf("%d\t", P[i]);
    printf("\n\n\n");
    trier_avec_cle(A, P, n);
    free(P);
    return A;
}

int *creer_candidates(n)
{
    int i;
    int *tab = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        tab[i] = rand() % 1000;
    }
    return tab;
}

int main()
{
    int i, j;
    srand(time(NULL));
    int *A = creer_candidates(N);
    for (i = 0; i < N; i++)
        printf("%d\t", A[i]);
    printf("\n\n\n");
    permute_par_tri2(A, N);
    for (i = 0; i < N; i++)
        printf("%d\t", A[i]);
    printf("\n\n\n");
    return 0;
}
