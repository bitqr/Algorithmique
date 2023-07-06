#include "PROB.h"

int *rendu_monnaie(int n)
{
	int *T = (int *)malloc(5 * sizeof(int));
	int i;
	for (i = 0; i < 5; i++)
		T[i] = 0;
	while (n >= 50)
	{
		T[0]++;
		n = n - 50;
	}
	while (n >= 20)
	{
		T[1]++;
		n = n - 20;
	}
	while (n >= 10)
	{
		T[2]++;
		n = n - 10;
	}
	while (n >= 5)
	{
		T[3]++;
		n = n - 5;
	}
	T[4] = n;
	return T;
}

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		printf("Argument attendu: Somme à rendre\n");
		return 1;
	}
	int n = atoi(argv[1]);
	int *T = rendu_monnaie(n);
	TABLEAU C;
	C.longueur = K;
	C.tab = (int *)malloc(K * sizeof(int));
	int t[K] = {1, 5, 7, 10, 12, 25};
	C.tab = t;
	int *T2 = rendu(C, n);
	printf("\n\nLe rendu optimal de %d centimes est le suivant :\n\n\n", n);
	printf("On rend %d pièce(s) de un cent\n", T[4]);
	printf("On rend %d pièce(s) de cinq cents\n", T[3]);
	printf("On rend %d pièce(s) de dix cents\n", T[2]);
	printf("On rend %d pièce(s) de vingt cents\n", T[1]);
	printf("On rend %d pièce(s) de cinquante cents\n", T[0]);

	printf("\n\n\nLe rendu optimal de %d centimes est le suivant :\n\n\n", n);
	int i;
	for (i = 0; i < K; i++)
		printf("On rend %d pièce(s) de %d cent(s)\n", T2[i], C.tab[i]);
	printf("\n\n");
	return 0;
}
