#include <stdio.h>
#include <stdlib.h>
#define N 8

int fusion_inv(int *A, int p, int q, int r)
{
     int n1 = q - p + 1;
     int n2 = r - q;
     long infini = 100000000;
     int cpt = 0;
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
     for (i = 0; i < n1; i++)
     {
          for (j = 0; j < n2; j++)
          {
               if (L[i] > R[j])
               {
                    cpt++;
               }
          }
     }
     free(L);
     free(R);
     return cpt;
}

int nombre_inversions(int *A, int p, int r)
{
     int q = (p + r) / 2;
     if (p < r)
     {
          return nombre_inversions(A, p, q) + nombre_inversions(A, q + 1, r) + fusion_inv(A, p, q, r);
     }
     if (p == r)
     {
          return 0;
     }
     return 0;
}

int main()
{
     int A[N] = {2, 3, 8, 6, 1};
     int n = nombre_inversions(A, 0, 4);
     printf("Il y a %d inversions dans le tableau\n", n);
     printf("\n\n\n");
     return 0;
}
