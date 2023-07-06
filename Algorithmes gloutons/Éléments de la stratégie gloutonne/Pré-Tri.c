#include "Glouton.h"

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

void tri_rapide(int *A, int p, int r)
{
     if (p < r)
     {
          int q = partition(A, p, r);
          tri_rapide(A, p, q - 1);
          tri_rapide(A, q + 1, r);
     }
}

void pre_tri(int *V, int *w, int n)
{
     tri_rapide(w, 0, n - 1);
     int i;
     for (i = 0; i < n; i++)
          V[i] = -V[i];
     tri_rapide(V, 0, n - 1);
     for (i = 0; i < n; i++)
          V[i] = -V[i];
}
