#include <stdio.h>
#include <stdlib.h>
#define N 8

void permuter(int *A, int i, int j)
{
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

int partition_modifiee(int *A, int p, int r)
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
    if (i + 1 == r && A[i] == A[r])
    {
        return (p + r) / 2;
    }
    return i + 1;
}

int main()
{
    int A[N] = {3, 3, 3, 3, 3, 3, 3, 3};
    printf("%d\n\n", partition_modifiee(A, 0, N - 1));
    int i;
    return 0;
}
