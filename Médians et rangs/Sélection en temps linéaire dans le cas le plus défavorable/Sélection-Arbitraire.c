#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 12

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

int selection_randomisee_iterative(int *A, int p, int r, int i)
{
    if (i == 0)
    {
        return -1;
    }
    if (p == r)
    {
        return p;
    }
    int deb = p;
    int fin = r;
    int q;
    while (deb < fin)
    {
        q = partition_randomisee(A, deb, fin);
        int k = q - deb + 1;
        if (i == k) // La valeur du pivot est la réponse
        {
            return q;
        }
        else
        {
            if (i < k)
            {
                fin = q - 1;
            }
            else
            {
                deb = q + 1;
                i -= k;
            }
        }
    }
    return deb;
}

int retrouver_rang(int *A, int p, int r, int cle)
{
    int i;
    for (i = p; i <= r; i++)
    {
        if (A[i] == cle)
        {
            return i;
        }
    }
    return -1;
}

int boite_noire(int *A, int p, int r)
{
    return selection_randomisee_iterative(A, p, r, (int)(((float)(r - p) / 2)));
}

int selection_arbitraire(int *A, int p, int r)
{
    int *B = (int *)malloc(N * sizeof(int));
    int j;
    for (j = p; j <= r; j++)
    {
        B[j] = A[j];
    }
    int i = Random(1, N);
    int a = i;
    printf("i=%d\n\n\n", i);
    int k, deb = p, fin = r;
    while (deb < fin)
    {
        k = boite_noire(B, deb, fin);
        if (k == -1)
        {
            printf("%d est le %d-ème plus petit élément.\n\n\n", B[a - 1], a);
            return B[a - 1];
        }
        if (a == k + 1)
        {
            printf("%d est le %d-ème plus petit élément.\n\n\n", B[k], a);
            return B[k];
        }
        else
        {
            if (a <= k)
            {
                fin = k - 1;
            }
            else
            {
                deb = k + 1;
                i -= k;
            }
        }
    }
    printf("%d est le %d-ème plus petit element.\n\n\n", B[deb], a);
    return B[deb];
}

int main()
{
    int A[N] = {2, 6, 8, 0, 3, 1, 7, 9, 11, 12, 18, 5};
    srand(time(NULL));
    selection_arbitraire(A, 0, N - 1);
    return 0;
}
