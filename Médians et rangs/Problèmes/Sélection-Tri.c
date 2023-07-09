#include <stdio.h>
#include <stdlib.h>
#define N 14
#define I 5

void permuter(int *A, int i, int j)
{
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

int partition(int *A, int p, int r)
{
    int x = A[r];
    int i = p - 1;
    int j;
    for (j = p; j < r; j++)
    {
        if (A[j] <= x)
        {
            i++;
            permuter(A, i, j);
        }
    }
    permuter(A, i + 1, r);
    return i + 1;
}

void tri_rapide(int *A, int p, int r)
{
    if (p < r)
    {
        int q = partition(A, p, r);
        tri_rapide(A, p, q - 1);
        tri_rapide(A, q + 1, r);
    }
}

int *selection_tri(int *A, int n, int i)
{
    int *B = (int *)malloc(i * sizeof(int));
    tri_rapide(A, 0, n - 1);
    int j;
    for (j = 0; j < i; j++)
    {
        B[j] = A[n - i + j];
    }
    return B;
}

int main()
{
    int A[N] = {6, 6, 4, 3, 90, 32, 7, 37, 2, 88, 92, 113, 22, 11};
    int *B = selection_tri(A, N, I);
    int j;
    for (j = 0; j < I; j++)
    {
        printf("%d\t", B[j]);
    }
    printf("\n\n");
    return 0;
}
