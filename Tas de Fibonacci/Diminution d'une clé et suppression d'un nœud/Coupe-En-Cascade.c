#include "TASFIB.h"

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
