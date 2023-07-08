#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10

typedef struct _PAQUET
{
     float element;
     struct _PAQUET *precedent;
     struct _PAQUET *suivant;
} PAQUET;

PAQUET *init_list(float e, PAQUET *q)
{
     PAQUET *p = (PAQUET *)malloc(sizeof(PAQUET));
     p->element = e;
     p->suivant = q;
     return p;
}

void inserer_liste(PAQUET **B, float e, int j)
{
     if (B[j] == NULL)
     {
          PAQUET *p1 = (PAQUET *)malloc(sizeof(PAQUET));
          p1->element = e;
          p1->suivant = NULL;
          p1->precedent = NULL;
          B[j] = p1;
     }
     else
     {
          PAQUET *l = init_list(e, B[j]);
          B[j]->precedent = l;
          l->precedent = NULL;
          B[j] = l;
     }
}

PAQUET *queue(PAQUET *l)
{
     PAQUET *q = l;
     if (q == NULL)
          return NULL;
     while (q->suivant != NULL)
     {
          q = q->suivant;
     }
     return q;
}

PAQUET *inserer_element(PAQUET *p, float e)
{
     PAQUET *q = (PAQUET *)malloc(sizeof(PAQUET));
     q->suivant = NULL;
     q->precedent = NULL;
     q->element = e;
     if (p == NULL)
     {
          p = q;
          return p;
     }
     else
     {
          if (p->element >= e)
          {
               q->suivant = p;
               return q;
          }
          else
          {
               PAQUET *o = p;
               while ((o->suivant) && (o->suivant->element < e))
               {
                    o = o->suivant;
               }
               q->suivant = o->suivant;
               o->suivant = q;
               q->precedent = o;
               if (q->suivant)
                    q->suivant->precedent = q;
               return p;
          }
     }
}

PAQUET *trier_par_insertion(PAQUET *l)
{
     if (l == NULL)
          return l;
     if (l->suivant == NULL)
          return l;
     PAQUET *p = NULL;
     while (l)
     {
          float e = l->element;
          p = inserer_element(p, e);
          l = l->suivant;
     }
     return p;
}

PAQUET *concat(PAQUET *p, PAQUET *q)
{
     if (p == NULL)
          return q;
     if (q == NULL)
          return p;
     queue(p)->suivant = q;
     return p;
}

PAQUET *tri_paquets(float *A, int n)
{
     PAQUET **B = (PAQUET **)malloc(n * sizeof(PAQUET *));
     int i;
     PAQUET *C = NULL;
     for (i = 0; i < n; i++)
          B[i] = NULL;
     for (i = 0; i < n; i++)
     {
          inserer_liste(B, A[i], (int)(floor(n * A[i])));
     }
     for (i = 0; i < n; i++)
     {
          B[i] = trier_par_insertion(B[i]);
     }
     for (i = 0; i < n; i++)
     {
          C = concat(C, B[i]);
     }
     return C;
}

int main()
{
     float A[N] = {0.79, 0.13, 0.16, 0.64, 0.39, 0.20, 0.89, 0.53, 0.71, 0.42};
     PAQUET *C = tri_paquets(A, N);
     int i;
     printf("Voici les données avant le tri par paquets :\n\n\n");
     for (i = 0; i < N; i++)
     {
          printf("%.2f\t", A[i]);
     }
     printf("\n\n\n");
     printf("Voici les données après le tri par paquets :\n\n\n");
     while (C)
     {
          printf("%.2f\t", C->element);
          C = C->suivant;
     }
     printf("\n\n\n\n");
     return 0;
}
