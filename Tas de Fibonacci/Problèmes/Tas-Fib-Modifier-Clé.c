#include "TASFIB.h"

void diminuer_cle_tas_fib(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *x, int k)
{
    if (k > x->cle)
    {
        printf("nouvelle clé plus grande que clé courante");
        exit(EXIT_FAILURE);
    }
    x->cle = k;
    NOEUD_TAS_FIBONACCI *y = x->p;
    if (y != NIL && x->cle < y->cle)
    {
        couper(T, x, y);
        coupe_en_cascade(T, y);
    }
    if (x->cle < T->min->cle)
    {
        T->min = x;
    }
}

void tas_fib_modifier_cle(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *x, int k)
{
    if (k <= x->cle)
    {
        diminuer_cle_tas_fib(T, x, k);
    }
    else
    {
        x->cle = k;
        ajouterEnfantsAuxRacines(T, x);
        x->enfant = NIL;
        x->degre = 0;
    }
}
