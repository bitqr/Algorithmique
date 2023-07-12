#include <stdio.h>
#include <stdlib.h>
#define N 6

int rechmin(int *A, int deb, int n)
{
    int i;
    int min = deb;
    for (i = deb + 1; i < n; i++)
    {
        if (A[min] > A[i])
        {
            min = i;
        }
    }
    return min;
}

void echanger(int *A, int a, int b)
{
    int tmp = A[b];
    A[b] = A[a];
    A[a] = tmp;
}

void tri_bulles(int *A, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (A[j] < A[j - 1])
            {
                echanger(A, j, j - 1);
            }
        }
    }
}

int main()
{
    int A[N] = {5, 2, 4, 6, 1, 3};
    tri_bulles(A, N);
    int i;
    for (i = 0; i < N; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n\n\n");
    return 0;
}
