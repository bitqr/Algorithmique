#include <stdio.h>
#include <stdlib.h>
#define N 11

int max(int *A, int n)
{
    int m = 0;
    int i;
    for (i = 1; i < n; i++)
    {
        if (A[i] > A[m])
        {
            m = i;
        }
    }
    return m;
}

int pre_traitement(int *A, int n, int k, int a, int b)
{
    int i, j;
    int *C = (int *)malloc(k * sizeof(int));
    for (i = 0; i < k; i++)
    {
        C[i] = 0;
    }
    for (j = 0; j < n; j++)
    {
        if (A[j] >= a)
        {
            C[A[j]]++;
        }
    }
    for (i = 1; i < k; i++)
    {
        C[i] += C[i - 1];
    }
    return C[b];
}

int main()
{
    int A[N] = {6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2};
    int a = 3;
    int b = 5;
    int k = A[max(A, N)] + 1;
    printf("Le nombre d'éléments du tableau appartenant à [%d..%d] est de %d\n\n\n", a, b, pre_traitement(A, N, k, a, b));
    return 0;
}
