#include <stdio.h>
#include <stdlib.h>

struct File_Liste_Chainee
{
	struct File_Liste_Chainee *tete;
	struct File_Liste_Chainee *queue;
	struct File_Liste_Chainee *pred;
	int cle;
};

typedef struct File_Liste_Chainee FLC;
