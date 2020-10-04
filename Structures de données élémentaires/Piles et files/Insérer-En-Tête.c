#include<stdio.h>
#include<stdlib.h>
#define N 8


struct FILES{
    int longueur;
    int tete;
    int queue;
    int *tableau;
};

typedef FILES FILES;

FILES *creer_file(int taille){
    FILES *F = (FILES*)malloc(sizeof(FILES));
    int *t = (int *)malloc(taille*sizeof(int));
    F->tete =0;
    F->longueur=taille;
    F->queue=0;
    F->tableau=t;
    return F;
}

void afficher_file(FILES*F){
    if(F->tete==F->queue)
        printf("La liste est vide\n\n");
    else{
        int i=F->tete;
        printf("Les elements de la file du plus ancien au plus recent sont : \n\n");
        while(i!=F->queue){
            printf("%d\t",F->tableau[i]);
            i++;
            i=i%F->longueur;
        }
        printf("\n\n");
    }
}

void enfiler2(FILES *F, int x){
    if(F->tete == (F->queue+1)||((F->queue == F->longueur-1)&&(F->tete==0))){
        printf("File pleine: debordement\n\n");
        exit(EXIT_FAILURE);
    }
    F->tableau[F->queue]=x;
    if(F->queue+1 == F->longueur){
        if(F->tete!=0)
            F->queue = 0;
    }
    else{
        if(F->queue+1!=F->tete)
            F->queue++;
    }
}

void inserer_en_tete(FILES *F, int x){
    if(F->tete == (F->queue+1)||((F->queue == F->longueur-1)&&(F->tete==0))){
        printf("File pleine: debordement\n\n");
        exit(EXIT_FAILURE);
    }
    if(F->tete==0)
        F->tete=F->longueur-1;
    else
        F->tete--;
    printf("%d a ete insere en tete\n\n", x);
    F->tableau[F->tete]=x;
}



int main(int agrc, char **argv){
    FILES *F=creer_file(N);
    enfiler2(F,4);
    enfiler2(F,6);
    enfiler2(F,17);
    enfiler2(F,1);
    enfiler2(F,7);
    enfiler2(F,18);
    afficher_file(F);
    inserer_en_tete(F,9);
    afficher_file(F);
    free(F->tableau);
    free(F);
    return 0;
}
