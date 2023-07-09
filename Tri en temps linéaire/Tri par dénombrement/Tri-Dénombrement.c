#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 50

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

void tri_denombrement(int *A, int *B, int k, int n)
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
        C[A[j]]++;
    }
    // C[i] contient maintenant le nombre d'éléments égaux à i.
    for (i = 1; i < k; i++)
    {
        C[i] += C[i - 1];
    }
    // C[i] contient maintenant le nombre d'éléments inférieurs ou égaux à i.
    for (j = n - 1; j >= 0; j--)
    {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }
    free(C);
}

int main()
{
    int i, l;
    int *B = (int *)malloc(N * sizeof(int));
    time_t t1 = clock();
    long it = 50;
    for (l = 0; l < it; l++)
    {
        printf("Tableau initial :\n\n");
        int *A = (int *)malloc(N * sizeof(int));
        for (i = 0; i < N; i++)
        {
            A[i] = rand() % 200;
            printf("%d\t", A[i]);
        }
        printf("\n\n");
        int k = A[max(A, N)] + 1;
        tri_denombrement(A, B, k, N);
        printf("\n\nAprès tri:\n\n");
        for (i = 0; i < N; i++)
        {
            printf("%d\t", B[i]);
        }
        printf("\n\n\n------------------------------------------------------------\n\n");
    }
    time_t t2 = clock();
    printf("\n\nTemps CPU moyen : %lf\n", ((float)(t2 - t1)) / ((float)(it)));
    printf("\n\n\n");
    return 0;
}
