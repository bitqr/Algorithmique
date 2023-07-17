#include "TASFIB.h"

void elaguer_tas_fib(TAS_FIBONACCI_POUR_ELAGAGE *T, int r)
{
    if (r >= T->n)
    {
        T->n = 0;
        T->min = NIL;
        T->feuilles = NIL;
    }
    else
    {
        NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *x = T->feuilles;
        int i = 0;
        while (i < r)
        {
            if (x == T->min)
            {
                x = x->fd;
            }
            NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *y = x->p;
            if (y != NIL)
            {
                supprimerEnfantPourElagage(x, y);
                if (y->degre == 0)
                {
                    ajouterFeuillePourElagage(T, y);
                }
            }
            else
            {
                supprimerRacinePourElagage(x);
            }
            supprimerFeuillePourElagage(T, x);
            T->n--;
            i++;
            x = x->fd;
        }
    }
}

void supprimerEnfantPourElagage(NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *x, NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *y)
{
    if (x == y->enfant)
    {
        y->enfant = x->droite;
    }
    x->gauche->droite = x->droite;
    x->droite->gauche = x->gauche;
    y->degre--;
    if (y->degre == 0)
    {
        y->enfant = NIL;
    }
}

void ajouterFeuillePourElagage(TAS_FIBONACCI_POUR_ELAGAGE *T, NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *x)
{
    NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *f = T->feuilles;
    if (f == NIL)
    {
        x->fg = x;
        x->fd = x;
        T->min = x;
    }
    else
    {
        f->fg->fd = x;
        x->fg = f->fg;
        x->fd = f;
        f->fg = x;
    }
}

void supprimerRacinePourElagage(NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *x)
{
    x->gauche->droite = x->droite;
    x->droite->gauche = x->gauche;
}

void supprimerFeuillePourElagage(TAS_FIBONACCI_POUR_ELAGAGE *T, NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *x)
{
    x->fg->fd = x->fd;
    x->fd->fg = x->fg;
    T->feuilles = x->fd;
}

NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *creerNoeudTasFibonacciPourElagage(int cle, NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *enfant, NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *pere, NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *g, NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *d, int m, int dg, NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *fg, NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *fd)
{
    NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *x = (NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *)malloc(sizeof(NOEUD_TAS_FIBONACCI_POUR_ELAGAGE));
    x->cle = cle;
    x->gauche = g;
    x->droite = d;
    x->p = pere;
    x->marque = m;
    x->degre = dg;
    x->fg = fg;
    x->fd = fd;
    return x;
}

void afficherTasFibonacciPourElagage(TAS_FIBONACCI_POUR_ELAGAGE *T)
{
    if (T->n == 0)
    {
        printf("Tas vide.\n");
    }
    else
    {
        printf("Le tas a %d noeud(s)\n", T->n);
        NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *x = T->min;
        int c = 0;
        while (c < T->n)
        {
            printf("Arbre dont la racine est de degré %d :\n", x->degre);
            c += afficherArbreTasFibonacciPourElagage(x, 1);
            x = x->droite;
            printf("\n");
        }
    }
}

int afficherArbreTasFibonacciPourElagage(NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *x, int profondeur)
{
    int c = 0;
    if (x != NIL)
    {
        int i;
        for (i = 1; i <= profondeur; i++)
        {
            printf("\t");
        }
        printf("Noeud (%d)", x->cle);
        if (x->marque != FAUX)
        {
            printf(" marqué ");
        }
        else
        {
            printf(" non marqué ");
        }
        NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *x1 = x->enfant;
        if (x1 != NIL)
        {
            printf("d'enfant(s) ");
        }
        else
        {
            printf("sans enfants.");
        }
        int d = 0;
        c++;
        while (d < x->degre)
        {
            if (x1 != NIL)
            {
                printf("%d ", x1->cle);
                x1 = x1->droite;
                d++;
            }
        }
        printf("\n");
        x1 = x->enfant;
        d = 0;
        while (d < x->degre)
        {
            c += afficherArbreTasFibonacciPourElagage(x1, profondeur + 1);
            x1 = x1->droite;
            d++;
        }
    }
    return c;
}
