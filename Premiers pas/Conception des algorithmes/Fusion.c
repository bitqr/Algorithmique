#include <stdio.h>
#include <stdlib.h>
#define N 8

void fusion(int *A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    long infini = 100000000;
    int *L = (int *)malloc((n1 + 1) * sizeof(int));
    int *R = (int *)malloc((n2 + 1) * sizeof(int));
    int i, j;
    for (i = 0; i < n1; i++)
    {
        L[i] = A[p + i - 1];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = A[q + j];
    }
    L[n1] = infini;
    R[n2] = infini;
    i = 0;
    j = 0;
    int k;
    for (k = p; k < r + 1; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
    for (i = 0; i < n1; i++)
    {
        printf("%d\t", L[i]);
    }
    printf("\n\n\n");
    for (i = 0; i < n2; i++)
    {
        printf("%d\t", R[i]);
    }
    printf("\n\n\n");
}

int main()
{
    int A[N] = {5, 2, 4, 7, 1, 3, 2, 6};
    fusion(A, 1, 4, 8);
    return 0;
}
