#include <stdio.h>
#include <stdlib.h>
#define M 4
#define N 4
#define CLE 12

static long inf = 100000000;

int **creer_matrice(int m, int n)
{
    int **Y = (int **)malloc(m * sizeof(int *));
    int i;
    for (i = 0; i < n; i++)
    {
        Y[i] = (int *)malloc(m * sizeof(int));
    }
    return Y;
}

int recherche_young(int Y[M][N], int m, int n, int cle)
{
    int i = 0;
    int j = 0;
    if (Y[0][0] > cle)
    {
        printf("L'élément %d ne figure pas dans ce tableau de Young\n\n", cle);
        return -1;
    }
    if (Y[0][0] == cle)
    {
        printf("L'élément %d figure à la ligne 1 à la colonne 1\n\n", cle);
        return 0;
    }
    if (m < 0 || m >= M)
    {
        return -1;
    }
    while (i < m)
    {
        if (Y[i][n] < cle)
        {
            i++;
        }
        if (Y[m][j] < cle)
        {
            j++;
        }
        if (Y[i][j] > cle)
        {
            i++;
            j = 0;
        }
        if (Y[i][j] < cle)
        {
            j++;
            if (j == n)
            {
                j = 0;
                i++;
            }
        }
        if (Y[i][j] == cle)
        {
            printf("L'élément %d figure à la ligne %d à la colonne %d\n\n\n", cle, i + 1, j + 1);
            return i * n + j;
        }
    }
    printf("L'élément %d ne figure pas dans ce tableau de Young\n\n", cle);
    return -1;
}

int main()
{
    int Y[M][N] = {{2, 3, 4, 5}, {8, 9, 12, 14}, {16, inf, inf, inf}, {inf, inf, inf, inf}};
    recherche_young(Y, M, N, CLE);
    return 0;
}
