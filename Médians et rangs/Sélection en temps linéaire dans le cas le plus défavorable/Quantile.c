#include <stdio.h>
#include <stdlib.h>
#define N 12
#define K 4

typedef struct _elem
{
    int el;
    int rang;
} elem;

int max(elem *A, int n)
{
    int m = 0;
    int i;
    for (i = 1; i < n; i++)
    {
        if ((A[i].el) > (A[m].el))
            m = i;
    }
    return m;
}

void tri_denombrement(elem *A, elem *B, int k, int n)
{
    int i;
    int *C = (int *)malloc(k * sizeof(int));
    for (i = 0; i < k; i++)
    {
        C[i] = 0;
    }
    int j;
    for (j = 0; j < n; j++)
    {
        C[A[j].el]++;
    }
    // C[i] contient maintenant le nombre d'éléments égaux à i.
    for (i = 1; i < k; i++)
        C[i] += C[i - 1];
    // C[i] contient maintenant le nombre d'éléments inférieurs ou égaux à i.
    for (j = n - 1; j >= 0; j--)
    {
        B[C[A[j].el] - 1].el = A[j].el;
        B[C[A[j].el] - 1].rang = A[j].rang;
        C[A[j].el]--;
    }
    free(C);
}

elem *creer_tab_elem(int *A, int n)
{
    int i;
    elem *B = (elem *)malloc(n * sizeof(elem));
    for (i = 0; i < n; i++)
    {
        B[i].el = A[i];
        B[i].rang = i;
    }
    return B;
}

int *quantile(elem *A, int k, int n)
{
    int *B = (int *)malloc((k - 1) * sizeof(int));
    elem *C = (elem *)malloc(n * sizeof(elem));
    int i;
    for (i = 0; i < n; i++)
    {
        C[i].el = 0;
        C[i].rang = 0;
    }
    int m = max(A, n);
    tri_denombrement(A, C, A[m].el + 1, n);
    for (i = 1; i < k; i++)
    {
        B[i - 1] = C[i * n / k - 1].rang;
        printf("%d\t", B[i - 1]);
    }
    return B;
}

int main()
{
    int A[N] = {2, 6, 8, 0, 3, 1, 7, 9, 11, 12, 18, 5};
    elem *B = creer_tab_elem(A, N);
    quantile(B, K, N);
    return 0;
}
