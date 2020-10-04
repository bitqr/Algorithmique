#ifndef DEF_IMPL
#define DEF_IMPL 

#define TAILLE 8
#define X 5
#define H 3



void liberer_objet(int x);

int allouer_objet(int *succ, int *libre);

void afficherObjet();

int allouer_objet_2(int *unique,int *libre2);

void liberer_objet_2(int x, int *unique, int *libre2);

void afficherObjet2();

void densifier_liste(int *pred, int *cle, int *succ, int *L, int *libre);

#endif


