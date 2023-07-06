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
        printf("La liste est vide\n\n");
    else
    {
        int i = F->tete;
        printf("Les éléments de la pile du plus ancien au plus récent sont : \n\n");
        while (i != F->queue)
        {
            printf("%d\t", F->tableau[i]);
            i++;
            i = i % F->longueur;
        }
        printf("\n\n");
    }
}

void enfiler2(FILES *F, int x)
{
    if (F->tete == (F->queue + 1) || ((F->queue == F->longueur - 1) && (F->tete == 0)))
    {
        printf("File pleine: débordement\n\n");
        exit(EXIT_FAILURE);
    }
    printf("%d a été inséré en queue \n\n", x);
    F->tableau[F->queue] = x;
    if (F->queue + 1 == F->longueur)
    {
        if (F->tete != 0)
            F->queue = 0;
    }
    else
    {
        if (F->queue + 1 != F->tete)
            F->queue++;
    }
}

void inserer_en_queue(FILES *F, int x)
{
    enfiler2(F, x);
}

int main(int agrc, char **argv)
{
    FILES *F = creer_file(N);
    inserer_en_queue(F, 4);
    inserer_en_queue(F, 6);
    inserer_en_queue(F, 17);
    inserer_en_queue(F, 1);
    inserer_en_queue(F, 7);
    inserer_en_queue(F, 18);
    inserer_en_queue(F, 11);
    afficher_file(F);
    free(F->tableau);
    free(F);
    return 0;
}
