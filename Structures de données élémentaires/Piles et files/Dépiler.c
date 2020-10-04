#include<stdio.h>
#include<stdlib.h>
#define N 8

struct PILE{
    int taille;
    int sommet;
    int *tableau;
};

typedef PILE PILE;

PILE *creer_pile(int taille){
    PILE *P = (PILE*)malloc(sizeof(PILE));
    int *t = (int *)malloc(taille*sizeof(int));
    P->sommet=-1;
    P->taille=taille;
    P->tableau=t;
    return P;
}

void afficher_pile(PILE*P){
    int s = P->sommet;
    int i;
    printf("Les elements de la pile du plus ancien au plus recent sont : \n\n");
    for(i=0;i<=s;i++)
        printf("%d\t",P->tableau[i]);
    printf("\n\n");
}

int pile_vide(PILE *P){
    return(P->sommet==-1);
}

void empiler(PILE *P,int x){
    P->sommet++;
    P->tableau[P->sommet]=x;
}

int depiler(PILE *P){
    if(pile_vide(P)){
        printf("Erreur, debordement negatif!\n");
        exit(EXIT_FAILURE);
    }
    P->sommet--;
    return P->tableau[P->sommet+1];
}

int main(int agrc, char **argv){
    PILE *P=creer_pile(N);
    empiler(P,4);
    empiler(P,6);
    empiler(P,17);
    depiler(P);
    afficher_pile(P);
    free(P->tableau);
    free(P);
    return 0;
}
