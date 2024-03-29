#include <stdio.h>
#include <stdlib.h>
#define N 8

struct FILES
{
    int longueur;
    int tete;
    int queue;
    int *tableau;
};

typedef struct FILES FILES;

FILES *creer_file(int taille)
{
    FILES *F = (FILES *)malloc(sizeof(FILES));
    int *t = (int *)malloc(taille * sizeof(int));
    F->tete = 0;
    F->longueur = taille;
    F->queue = 0;
    F->tableau = t;
    return F;
}

void afficher_file(FILES *F)
{
    if (F->tete == F->queue)
    {
        printf("La liste est vide\n\n");
    }
    else
    {
        int i = F->tete;
        printf("Les éléments de la file du plus ancien au plus récent sont : \n\n");
        while (i != F->queue)
        {
            printf("%d\t", F->tableau[i]);
            i++;
            i %= F->longueur;
        }
        printf("\n\n");
    }
}

void enfiler2(FILES *F, int x)
{
    if (F->tete == F->queue + 1 || (F->queue == F->longueur - 1 && F->tete == 0))
    {
        printf("File pleine: debordement\n\n");
        exit(EXIT_FAILURE);
    }
    F->tableau[F->queue] = x;
    printf("%d a été enfilé \n\n", x);
    if (F->queue + 1 == F->longueur)
    {
        if (F->tete != 0)
        {
            F->queue = 0;
        }
    }
    else
    {
        if (F->queue + 1 != F->tete)
        {
            F->queue++;
        }
    }
}

int defiler2(FILES *F)
{
    if (F->tete == F->queue)
    {
        printf("File vide\n\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        int x = F->tableau[F->tete];
        printf("%d a été défilé \n\n", x);
        if (F->tete + 1 == F->longueur)
        {
            F->tete = 0;
        }
        else
        {
            F->tete++;
        }
        return x;
    }
}

int main(int agrc, char **argv)
{
    FILES *F = creer_file(N);
    enfiler2(F, 4);
    enfiler2(F, 6);
    enfiler2(F, 17);
    enfiler2(F, 1);
    enfiler2(F, 7);
    enfiler2(F, 18);
    afficher_file(F);
    defiler2(F);
    afficher_file(F);
    free(F->tableau);
    free(F);
    return 0;
}
