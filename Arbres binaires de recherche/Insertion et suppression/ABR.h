#ifndef DEF_ABR
#define DEF_ABR

struct abr
{
  int cle;
  struct abr *p;
  struct abr *gauche;
  struct abr *droite;
};

typedef struct abr ABR;

ABR *creer_abr(int cle, ABR *d, ABR *g);
void arbre_inserer(ABR *T, ABR *z);
ABR *arbre_supprimer(ABR *T, ABR *z);
void arbre_inserer_recursif(ABR *T, ABR *z);

#endif
