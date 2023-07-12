#ifndef DEF_H
#define DEF_H

#define TAILLE 10
#define C 8

struct objet
{
	int cle;
};

typedef struct objet OBJET;

void inserer_adressage_direct(OBJET **T, OBJET *x);
void supprimer_adressage_direct(OBJET **T, OBJET *x);
int maximum_adressage_direct(OBJET **T, int m);

#endif
