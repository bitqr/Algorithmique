#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 8
#define M 40

typedef struct _INTERVALLE
{
    float ai;
    float bi;
} INTERVALLE;

typedef INTERVALLE *P_INTERVALLE;

P_INTERVALLE creer_intervalle(float a, float b)
{
    P_INTERVALLE inter = (P_INTERVALLE)malloc(sizeof(INTERVALLE));
    inter->ai = a;
    inter->bi = b;
    return inter;
}

void permuter_intervalle(P_INTERVALLE *A, int i, int j)
{
    P_INTERVALLE tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

int partition_intervalles(P_INTERVALLE *A, int p, int r)
{
    int x = A[r]->ai;
    int i = p - 1;
    int j;
    for (j = p; j < r; j++)
    {
        if ((A[j]->bi < A[r]->ai))
        {
            if ((A[j]->ai) <= x)
            {
                i++;
                permuter_intervalle(A, i, j);
            }
        }
    }
    permuter_intervalle(A, i + 1, r);
    return i + 1;
}

void tri_flou(P_INTERVALLE *A, int p, int r)
{
    if (p < r)
    {
        int q = partition_intervalles(A, p, r);
        tri_flou(A, p, q - 1);
        tri_flou(A, q + 1, r);
    }
}

int main()
{
    int i;
    float a, b;
    srand(time(NULL));
    P_INTERVALLE *A = (P_INTERVALLE *)malloc(N * sizeof(P_INTERVALLE));
    for (i = 0; i < N; i++)
    {
        a = rand() % M;
        b = a + rand() % (int)(M - a + 1);
        A[i] = creer_intervalle(a, b);
    }
    for (i = 0; i < N; i++)
    {
        printf("[%2.f ; %2.f ]\t", A[i]->ai, A[i]->bi);
    }
    printf("\n\n\n\n\n\n");
    tri_flou(A, 0, N - 1);
    for (i = 0; i < N; i++)
    {
        printf("[%2.f ; %2.f ]\t", A[i]->ai, A[i]->bi);
    }
    printf("\n\n\n");
    return 0;
}
