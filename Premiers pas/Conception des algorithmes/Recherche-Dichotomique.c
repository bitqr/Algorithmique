#include <stdio.h>
#include <stdlib.h>
#define N 8
#define CLE 7

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
        L[i] = A[p + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = A[q + j + 1];
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
}

void tri_fusion(int *A, int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        tri_fusion(A, p, q);
        tri_fusion(A, q + 1, r);
        fusion(A, p, q, r);
    }
}

int recherche_dichotomique(int *A, int deb, int fin, int cle)
{
    if (deb > fin)
    {
        if (A[deb] == cle)
        {
            return deb;
        }
        else
        {
            return -1;
        }
    }
    int mil = (deb + fin) / 2;
    if (A[mil] == cle)
    {
        return mil;
    }
    if (A[mil] < cle)
    {
        return recherche_dichotomique(A, mil + 1, fin, cle);
    }
    else
    {
        return recherche_dichotomique(A, deb, mil - 1, cle);
    }
}

int main()
{
    int A[N] = {5, 2, 4, 7, 1, 3, 2, 6};
    tri_fusion(A, 0, 7);
    int i;
    for (i = 0; i < N; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n\n\n");
    int n = recherche_dichotomique(A, 0, 7, CLE);
    if (n == -1)
    {
        printf("L'élément %d n'est pas dans le tableau\n\n", CLE);
    }
    else
    {
        printf("L'élément %d est dans le tableau à l'indice %d\n\n", CLE, n + 1);
    }
    printf("\n\n\n");
    return 0;
}
