#include <stdio.h>
#include <stdlib.h>
#define N 10

const int a = 0;
const int b = 1;

int compte(int *A, int n, int x)
{
    int i, cpt = 0;
    for (i = 0; i < n; i++)
    {
        if (A[i] == x)
        {
            cpt++;
        }
    }
    return cpt;
}

void tri_lineaire_stable(int *A, int n)
{
    int *B;
    int *C;
    int g = compte(A, n, a);
    int d = n - g;
    B = (int *)malloc(g * sizeof(int));
    C = (int *)malloc(d * sizeof(int));
    int i, j = 0, k = 0;
    for (i = 0; i < n; i++)
    {
        if (A[i] == a)
        {
            B[j] = A[i];
            j++;
        }
        else
        {
            C[k] = A[i];
            k++;
        }
    }
    for (i = 0; i < g; i++)
    {
        A[i] = B[i];
    }
    for (i = 0; i < d; i++)
    {
        A[g + i] = C[i];
    }
}

int main()
{
    int A[N] = {0, 1, 0, 1, 1, 1, 0, 1, 0, 0};
    tri_lineaire_stable(A, N);
    int i;
    for (i = 0; i < N; i++)
    {
        printf("%d\n", A[i]);
    }
    printf("\n\n\n");
    return 0;
}
