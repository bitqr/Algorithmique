#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
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

void echanger(int *A, int a, int b)
{
    int tmp = A[b];
    A[b] = A[a];
    A[a] = tmp;
}

void permute_sans_identite(int *A, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d\t", A[i]);
    printf("\n\n\n");
    for (i = 0; i < n - 1; i++)
    {
        echanger(A, i, Random(i + 1, n - 1));
    }
}

int *creer_candidates(int n)
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
    permute_sans_identite(A, N);
    for (i = 0; i < N; i++)
        printf("%d\t", A[i]);
    printf("\n\n\n");
    return 0;
}
