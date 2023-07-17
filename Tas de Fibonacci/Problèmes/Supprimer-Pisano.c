#include "TASFIB.h"

void supprimer_pisano(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *x)
{
    if (x == T->min)
    {
        extraire_min_tas_fib(T);
    }
    else
    {
        NOEUD_TAS_FIBONACCI *y = x->p;
        if (y != NIL)
        {
            couper(T, x, y);
            coupe_en_cascade(T, y);
        }
        ajouterEnfantsAuxRacines(T, x);
        supprimerRacinePisano(T, x);
    }
}

void supprimerRacinePisano(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *x)
{
    x->gauche->droite = x->droite;
    x->droite->gauche = x->gauche;
    T->n--;
}

void concatenerListes(NOEUD_TAS_FIBONACCI *x, NOEUD_TAS_FIBONACCI *r)
{
    if (r == NIL)
    {
        r = x;
        printf("Concaténation avec liste vide de %d\n", r->cle);
    }
    else
    {
        NOEUD_TAS_FIBONACCI *y = r->gauche;
        NOEUD_TAS_FIBONACCI *z = x->gauche;
        z->droite = r;
        r->gauche = z;
        y->droite = x;
        x->gauche = y;
    }
}

void ajouterEnfantsAuxRacines(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *x)
{
    if (x->enfant == NIL)
    {
        return;
    }
    NOEUD_TAS_FIBONACCI *enfant = x->enfant;
    NOEUD_TAS_FIBONACCI *y = x->enfant;
    do
    {
        enfant->p = NIL;
        enfant = enfant->droite;
    } while (enfant != y);
    y = T->min->gauche;
    NOEUD_TAS_FIBONACCI *z = x->enfant->gauche;
    z->droite = T->min;
    T->min->gauche = z;
    y->droite = x->enfant;
    x->enfant->gauche = y;
}

NOEUD_TAS_FIBONACCI *extraire_min_tas_fib(TAS_FIBONACCI *T)
{
    NOEUD_TAS_FIBONACCI *z = T->min;
    if (z != NIL)
    {
        NOEUD_TAS_FIBONACCI *x = z->enfant;
        NOEUD_TAS_FIBONACCI *y = x;
        if (x != NIL)
        {
            do
            {
                x->p = NIL;
                x = x->droite;

            } while (x != y);
            concatenerListes(x, z);
        }
        supprimerRacine(z);
        if (z == z->droite)
        {
            T->min = NIL;
        }
        else
        {
            T->min = z->droite;
            consolider(T);
        }
        T->n--;
    }
    return z;
}

void consolider(TAS_FIBONACCI *T)
{
    int i;
    int D = log(T->n) / log(2);
    NOEUD_TAS_FIBONACCI **A = (NOEUD_TAS_FIBONACCI **)malloc((D + 1) * sizeof(NOEUD_TAS_FIBONACCI *));
    for (i = 0; i <= D; i++)
    {
        A[i] = NIL;
    }
    NOEUD_TAS_FIBONACCI *a = T->min;
    int racines = 0;
    if (a != NIL)
    {
        a = a->droite;
        racines = 1;
        while (a != T->min)
        {
            racines++;
            a = a->droite;
        }
    }
    int j = 0;
    NOEUD_TAS_FIBONACCI *w = T->min;
    while (j < racines)
    {
        j++;
        NOEUD_TAS_FIBONACCI *x = w;
        int d = x->degre;
        w = w->droite;
        while (A[d] != NIL)
        {
            NOEUD_TAS_FIBONACCI *y = A[d];
            if (x->cle > y->cle)
            {
                permuter(&x, &y);
            }
            relier_tas_fib(T, y, x);
            A[d] = NIL;
            d++;
        }
        A[d] = x;
    }
    T->min = NIL;
    for (i = 0; i <= D; i++)
    {
        if (A[i] != NIL)
        {
            ajouterListeRacines(T, A[i]);
            if (T->min == NIL || A[i]->cle < T->min->cle)
            {
                T->min = A[i];
            }
        }
    }
    free(A);
}

void supprimerRacine(NOEUD_TAS_FIBONACCI *x)
{
    x->gauche->droite = x->droite;
    x->droite->gauche = x->gauche;
}

void permuter(NOEUD_TAS_FIBONACCI **x, NOEUD_TAS_FIBONACCI **y)
{
    NOEUD_TAS_FIBONACCI *t = *x;
    *x = *y;
    *y = t;
}

void relier_tas_fib(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *y, NOEUD_TAS_FIBONACCI *x)
{
    supprimerRacine(y);
    y->p = x;
    if (x->enfant == NIL)
    {
        y->gauche = y;
        y->droite = y;
    }
    else
    {
        NOEUD_TAS_FIBONACCI *z = x->enfant->gauche;
        y->droite = x->enfant;
        x->enfant->gauche = y;
        z->droite = y;
        y->gauche = z;
    }
    x->enfant = y;
    x->degre++;
    y->marque = FAUX;
}

void couper(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *x, NOEUD_TAS_FIBONACCI *y)
{
    supprimerEnfant(x, y);
    ajouterListeRacines(T, x);
    x->p = NIL;
    x->marque = FAUX;
}

void coupe_en_cascade(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *y)
{
    NOEUD_TAS_FIBONACCI *z = y->p;
    if (z != NIL)
    {
        if (y->marque == FAUX)
        {
            y->marque = VRAI;
        }
        else
        {
            couper(T, y, z);
            coupe_en_cascade(T, z);
        }
    }
}

void supprimerEnfant(NOEUD_TAS_FIBONACCI *x, NOEUD_TAS_FIBONACCI *y)
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

void ajouterListeRacines(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *x)
{
    NOEUD_TAS_FIBONACCI *r = T->min;
    if (r == NIL)
    {
        x->gauche = x;
        x->droite = x;
        T->min = x;
    }
    else
    {
        r->gauche->droite = x;
        x->gauche = r->gauche;
        x->droite = r;
        r->gauche = x;
    }
}

NOEUD_TAS_FIBONACCI *creerNoeudTasFibonacci(int cle, NOEUD_TAS_FIBONACCI *enfant, NOEUD_TAS_FIBONACCI *pere, NOEUD_TAS_FIBONACCI *g, NOEUD_TAS_FIBONACCI *d, int m, int dg)
{
    NOEUD_TAS_FIBONACCI *x = (NOEUD_TAS_FIBONACCI *)malloc(sizeof(NOEUD_TAS_FIBONACCI));
    x->cle = cle;
    x->gauche = g;
    x->droite = d;
    x->p = pere;
    x->marque = m;
    x->degre = dg;
    return x;
}

int afficherArbreTasFibonacci(NOEUD_TAS_FIBONACCI *x, int profondeur)
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
        NOEUD_TAS_FIBONACCI *x1 = x->enfant;
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
            c += afficherArbreTasFibonacci(x1, profondeur + 1);
            x1 = x1->droite;
            d++;
        }
    }
    return c;
}

void afficherTasFibonacci(TAS_FIBONACCI *T)
{
    if (T->n == 0)
    {
        printf("Tas vide.\n");
    }
    else
    {
        printf("Le tas a %d noeud(s)\n", T->n);
        NOEUD_TAS_FIBONACCI *x = T->min;
        int c = 0;
        while (c < T->n)
        {
            printf("Arbre dont la racine est de degré %d :\n", x->degre);
            c += afficherArbreTasFibonacci(x, 1);
            x = x->droite;
            printf("\n");
        }
    }
}

int main(int argc, char **argv)
{
    printf("\n\nCréation du tas de Fibonacci T : \n");
    TAS_FIBONACCI *T = (TAS_FIBONACCI *)malloc(sizeof(TAS_FIBONACCI));
    T->n = 0;
    T->min = NIL;
    printf("T est vide.\n");
    NOEUD_TAS_FIBONACCI *x1 = creerNoeudTasFibonacci(7, NIL, NIL, NIL, NIL, FAUX, 3);
    NOEUD_TAS_FIBONACCI *x2 = creerNoeudTasFibonacci(18, NIL, NIL, x1, NIL, VRAI, 2);
    NOEUD_TAS_FIBONACCI *x3 = creerNoeudTasFibonacci(38, NIL, NIL, x2, x1, FAUX, 1);
    NOEUD_TAS_FIBONACCI *x4 = creerNoeudTasFibonacci(24, NIL, x1, NIL, NIL, FAUX, 2);
    NOEUD_TAS_FIBONACCI *x5 = creerNoeudTasFibonacci(17, NIL, x1, x4, NIL, FAUX, 1);
    NOEUD_TAS_FIBONACCI *x6 = creerNoeudTasFibonacci(23, NIL, x1, x5, x4, FAUX, 0);
    NOEUD_TAS_FIBONACCI *x7 = creerNoeudTasFibonacci(21, NIL, x2, NIL, NIL, FAUX, 1);
    NOEUD_TAS_FIBONACCI *x8 = creerNoeudTasFibonacci(39, NIL, x2, x7, x7, VRAI, 0);
    NOEUD_TAS_FIBONACCI *x9 = creerNoeudTasFibonacci(41, NIL, x3, NIL, NIL, FAUX, 0);
    NOEUD_TAS_FIBONACCI *x10 = creerNoeudTasFibonacci(26, NIL, x4, NIL, NIL, VRAI, 1);
    NOEUD_TAS_FIBONACCI *x11 = creerNoeudTasFibonacci(46, NIL, x4, x10, x10, FAUX, 0);
    NOEUD_TAS_FIBONACCI *x12 = creerNoeudTasFibonacci(30, NIL, x5, NIL, NIL, FAUX, 0);
    NOEUD_TAS_FIBONACCI *x13 = creerNoeudTasFibonacci(52, NIL, x7, NIL, NIL, FAUX, 0);
    NOEUD_TAS_FIBONACCI *x14 = creerNoeudTasFibonacci(35, NIL, x10, NIL, NIL, FAUX, 0);
    x1->droite = x2;
    x1->gauche = x3;
    x1->enfant = x4;
    x2->droite = x3;
    x2->enfant = x7;
    x3->enfant = x9;
    x4->droite = x5;
    x4->gauche = x6;
    x4->enfant = x10;
    x5->droite = x6;
    x5->enfant = x12;
    x7->droite = x8;
    x7->gauche = x8;
    x7->enfant = x13;
    x9->droite = x9;
    x9->gauche = x9;
    x10->droite = x11;
    x10->gauche = x11;
    x10->enfant = x14;
    x12->droite = x12;
    x12->gauche = x12;
    x13->droite = x13;
    x13->gauche = x13;
    x14->droite = x14;
    x14->gauche = x14;
    T->n = 14;
    T->min = x1;
    printf("\n\nTas de Fibonacci T avant suppression de la clé 23 :\n\n");
    afficherTasFibonacci(T);
    supprimer_pisano(T, x6);
    printf("\n\nTas de Fibonacci T après suppression de la clé 23 :\n\n");
    afficherTasFibonacci(T);
    supprimer_pisano(T, x10);
    printf("\n\nTas de Fibonacci T après suppression de la clé 26 :\n\n");
    afficherTasFibonacci(T);
    tas_fib_modifier_cle(T, x4, 28);
    printf("\n\nTas de Fibonacci T après modification de la clé 24 en 28 :\n\n");
    afficherTasFibonacci(T);
    free(T);

    printf("\n\nCréation du tas de Fibonacci T1 : \n");
    TAS_FIBONACCI_POUR_ELAGAGE *T1 = (TAS_FIBONACCI_POUR_ELAGAGE *)malloc(sizeof(TAS_FIBONACCI_POUR_ELAGAGE));
    NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *y1 = creerNoeudTasFibonacciPourElagage(7, NIL, NIL, NIL, NIL, FAUX, 3, NIL, NIL);
    NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *y2 = creerNoeudTasFibonacciPourElagage(18, NIL, NIL, y1, NIL, VRAI, 2, NIL, NIL);
    NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *y3 = creerNoeudTasFibonacciPourElagage(38, NIL, NIL, y2, y1, FAUX, 1, NIL, NIL);
    NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *y4 = creerNoeudTasFibonacciPourElagage(24, NIL, y1, NIL, NIL, FAUX, 2, NIL, NIL);
    NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *y5 = creerNoeudTasFibonacciPourElagage(17, NIL, y1, y4, NIL, FAUX, 1, NIL, NIL);
    NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *y6 = creerNoeudTasFibonacciPourElagage(23, NIL, y1, y5, y4, FAUX, 0, NIL, NIL);
    NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *y7 = creerNoeudTasFibonacciPourElagage(21, NIL, y2, NIL, NIL, FAUX, 1, NIL, NIL);
    NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *y8 = creerNoeudTasFibonacciPourElagage(39, NIL, y2, y7, y7, VRAI, 0, NIL, NIL);
    NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *y9 = creerNoeudTasFibonacciPourElagage(41, NIL, y3, NIL, NIL, FAUX, 0, y8, NIL);
    NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *y10 = creerNoeudTasFibonacciPourElagage(26, NIL, y4, NIL, NIL, VRAI, 1, NIL, NIL);
    NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *y11 = creerNoeudTasFibonacciPourElagage(46, NIL, y4, y10, y10, FAUX, 0, NIL, NIL);
    NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *y12 = creerNoeudTasFibonacciPourElagage(30, NIL, y5, NIL, NIL, FAUX, 0, y11, y6);
    NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *y13 = creerNoeudTasFibonacciPourElagage(52, NIL, y7, NIL, NIL, FAUX, 0, y6, y8);
    NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *y14 = creerNoeudTasFibonacciPourElagage(35, NIL, y10, NIL, NIL, FAUX, 0, y9, y11);
    y1->droite = y2;
    y1->gauche = y3;
    y1->enfant = y4;
    y2->droite = y3;
    y2->enfant = y7;
    y3->enfant = y9;
    y4->droite = y5;
    y4->gauche = y6;
    y4->enfant = y10;
    y5->droite = y6;
    y5->enfant = y12;
    y7->droite = y8;
    y7->gauche = y8;
    y7->enfant = y13;
    y9->droite = y9;
    y9->gauche = y9;
    y10->droite = y11;
    y10->gauche = y11;
    y10->enfant = y14;
    y12->droite = y12;
    y12->gauche = y12;
    y13->droite = y13;
    y13->gauche = y13;
    y14->droite = y14;
    y14->gauche = y14;
    y6->fg = y12;
    y6->fd = y13;
    y8->fg = y13;
    y8->fd = y9;
    y9->fd = y14;
    y11->fg = y14;
    y11->fd = y12;
    T1->n = 14;
    T1->min = y1;
    T1->feuilles = y14;
    printf("\n\nTas de Fibonacci T1 avant élagage de 2 noeuds :\n\n");
    afficherTasFibonacciPourElagage(T1);
    elaguer_tas_fib(T1, 2);
    printf("\n\nTas de Fibonacci T1 après élagage de 2 noeuds :\n\n");
    afficherTasFibonacciPourElagage(T1);
    elaguer_tas_fib(T1, 3);
    printf("\n\nTas de Fibonacci T1 après élagage de 3 noeuds :\n\n");
    afficherTasFibonacciPourElagage(T1);
    return 0;
}
