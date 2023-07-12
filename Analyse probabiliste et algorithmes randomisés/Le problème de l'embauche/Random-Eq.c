#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N 7
#define A 3
#define B 6
#define P 0.5

int *creer_candidates(int n)
{
    int i;
    int *tab = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        tab[i] = rand() % 1000;
    }
    return tab;
}

int interviewer(int *t, int n)
{
    return t[n];
}

void embaucher(int n)
{
    printf("La secretaire %d est embauchee\n\n\n", n);
}

void embauche_secretaire(int n)
{
    int *t = creer_candidates(n);
    int i, j;
    int meilleure = 0; /*candidate 0 est une candidate fictive, moins qualifiée que quiconque */
    for (i = 0; i < n; i++)
    {
        j = interviewer(t, i);
        if (j > t[meilleure])
        {
            meilleure = i;
            embaucher(i + 1);
        }
    }
    free(t);
    printf("La candidate embauchée est finalement la secrétaire numéro %d\n\n\n", meilleure + 1);
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

void biased_random(float p)
{
    int n = rand() % 100;
    float m = 100. * p;
    float r = (float)n;
    printf("%d\n\n\n", r < m);
}

void random_eq()
{
    biased_random(0.5);
}

int main()
{
    srand(time(NULL));
    random_eq();
    return 0;
}
