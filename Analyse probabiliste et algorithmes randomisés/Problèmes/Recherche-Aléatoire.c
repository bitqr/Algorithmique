#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define CLE 66
#define N 24

int appartient(int *C, int n, int i)
{
    int j;
    for (j = 0; j < n; j++)
    {
        if (C[j] == i)
            return 1;
    }
    return 0;
}

int recherche_aleatoire(int *A, int n, int x)
{
    int *C = (int *)malloc(n * sizeof(int));
    int i, j, cpt = 0;
    while (cpt != n)
    {
        i = rand() % n;
        if (!appartient(C, cpt, i))
        {
            C[cpt] = i;
            cpt++;
        }
        if (A[i] == x)
        {
            free(C);
            printf("L'élément %d est à l'indice %d du tableau\n\n", x, i + 1);
            return i;
        }
    }
    printf("Introuvable\n\n\n");
    return -1;
}

int main()
{
    srand(time(NULL));
    int cle = CLE;
    int n = N;
    int A[N] = {3, 4, 2, 45, 53, 89, 43, 44, 109, 77, 45, 1, 3, 9, 66, 97, 156, 332, 86, 99, 12, 5, 62, 101};
    recherche_aleatoire(A, n, cle);
    return 0;
}
