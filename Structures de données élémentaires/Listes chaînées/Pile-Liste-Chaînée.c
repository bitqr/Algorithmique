#include<stdio.h>
#include<stdlib.h>

struct Pile_Liste_Chainee{
	struct Pile_Liste_Chainee * sommet;
	struct Pile_Liste_Chainee * suiv;
	int cle;
};

typedef struct Pile_Liste_Chainee PLC;



