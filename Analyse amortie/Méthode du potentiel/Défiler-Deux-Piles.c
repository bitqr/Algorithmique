#include"DEUXPILES.h"

int pile_vide(PILE *P){
    return(P->sommet==-1);
}

int depiler(PILE *P){
    if(pile_vide(P)){
        printf("Erreur, debordement negatif!\n");
        exit(EXIT_FAILURE);
    }
    P->sommet--;
    return P->tableau[P->sommet+1];
}

int defiler_deux_piles(FILEDEUXPILES *F){
	if(pile_vide(F->p))
		while(F->q->sommet >=0)
			empiler(F->p,depiler(F->q));
	return depiler(F->p);
}

int main(int agrc, char **argv){
	FILEDEUXPILES *F=creer_file_deux_piles(N);
	int i;
	enfiler_deux_piles(F,4);
	enfiler_deux_piles(F,12);
	enfiler_deux_piles(F,23);
	enfiler_deux_piles(F,42);
	defiler_deux_piles(F);
	defiler_deux_piles(F);
	enfiler_deux_piles(F,43);
	enfiler_deux_piles(F,26);	
	afficher_file_deux_piles(F);
	return 0;
}



