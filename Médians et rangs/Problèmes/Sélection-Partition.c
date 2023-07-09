#include <stdio.h>
#include <stdlib.h>
#define N 14
#define I 3

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

int Random(int a, int b)
{
    int i;
    if (a == 0 && b == 1)
    {
        return rand() % 2;
    }
    int acc = 0;
    for (i = a; i < b; i++)
    {
        acc += Random(0, 1);
    }
    return a + acc;
}

int partition_randomisee(int *A, int p, int r)
{
    int i = Random(p, r);
    permuter(A, r, i);
    return partition(A, p, r);
}

int selection_randomisee(int *A, int p, int r, int i)
{
    if (p == r)
    {
        return A[p];
    }
    int q = partition_randomisee(A, p, r);
    int k = q - p + 1;
    if (i == k) // La valeur du pivot est la réponse
    {
        return q;
    }
    else
    {
        if (i < k)
        {
            return selection_randomisee(A, p, q - 1, i);
        }
        else
        {
            return selection_randomisee(A, q + 1, r, i - k);
        }
    }
}

int *selection_partition(int *A, int n, int i)
{
    int p = selection_randomisee(A, 0, n - 1, n - i + 1);
    permuter(A, n - 1, p);
    partition(A, 0, n - 1);
    int *B = (int *)malloc(i * sizeof(int));
    int j;
    for (j = 0; j < i; j++)
    {
        B[j] = A[n - 1 - j];
    }
    return B;
}

int main()
{
    int A[N] = {6, 6, 4, 3, 90, 32, 7, 37, 2, 88, 92, 113, 22, 11};
    int *B = selection_partition(A, N, I);
    int j;
    for (j = 0; j < I; j++)
    {
        printf("%d\t", B[j]);
    }
    printf("\n\n");
    free(B);
    return 0;
}
