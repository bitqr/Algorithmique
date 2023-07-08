#include "VDCB.h"

void afficher_couts(int **c, int n, int e)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < e; j++)
		{
			printf("%d\t", c[i][j]);
		}
		printf("\n");
	}
}

void afficher_solution(char **S, char *x, char *y, int n, int m)
{
	printf("\n\nVoici comment on procède:\n\n");
	int i = 0, j = 0;
	while (j != n)
	{
		if (S[i][j] == 'c')
		{
			printf("On copie le caractere %c\n", x[i]);
			i++;
			j++;
		}
		else
		{
			if (S[i][j] == 'r')
			{
				printf("On remplace le caractère %c par le caractère %c\n", x[i], y[j]);
				i++;
				j++;
			}
			else
			{
				if (S[i][j] == 'i')
				{
					printf("On insère le caractère %c\n", y[j]);
					j++;
				}
				else
				{
					if (S[i][j] == 's')
					{
						printf("On supprime le caractère %c\n", x[i]);
						i++;
					}
					else
					{
						printf("On permute les caractères %c et %c\n", x[i], x[i + 1]);
						i += 2;
						j += 2;
					}
				}
			}
		}
	}
	if (i != m)
		printf("On équeute.\n");
	printf("C'est fini!\n");
}

int distance_d_edition(int m, int n, int couts[6], char *x, char *y, char **S)
{
	int i, j, a, b, c, d, e, min;
	int **C = (int **)malloc((m + 1) * sizeof(int *));
	for (i = 0; i < m + 1; i++)
	{
		C[i] = (int *)malloc((n + 1) * sizeof(int));
		for (j = 0; j < n + 1; j++)
		{
			C[i][j] = 0;
		}
	}
	C[m][n] = 0;
	S[m][n] = '0';
	for (j = n - 1; j >= 0; j--)
	{
		C[m][j] = couts[3] + C[m][j + 1];
		S[m][j] = 'i';
	}
	for (i = m - 1; i >= 0; i--)
	{
		C[i][n] = couts[5];
		S[i][n] = 'e';
	}
	for (i = m - 1; i >= 0; i--)
	{
		for (j = n - 1; j >= 0; j--)
		{
			if (i < m - 1 && j < n - 1 && x[i] == y[j] && x[i + 1] == y[j + 1] && x[i + 1] == x[i])
			{
				a = couts[4] + C[i + 2][j + 2];
				b = couts[3] + C[i][j + 1];
				min = (a < b) ? a : b;
				c = couts[2] + C[i + 1][j];
				min = (min < c) ? min : c;
				d = couts[1] + C[i + 1][j + 1];
				min = (min < d) ? min : d;
				e = couts[0] + C[i + 1][j + 1];
				min = (min < e) ? min : e;
				C[i][j] = (min == a) ? a : ((min == b) ? b : ((min == c) ? c : ((min == d) ? d : e)));
				S[i][j] = (min == a) ? 'p' : ((min == b) ? 'i' : ((min == c) ? 's' : ((min == d) ? 'r' : 'c')));
			}
			else
			{
				if (i < m - 1 && j < n - 1 && x[i] == y[j + 1] && x[i + 1] == y[j])
				{
					a = couts[4] + C[i + 2][j + 2];
					b = couts[3] + C[i][j + 1];
					min = (a < b) ? a : b;
					c = couts[2] + C[i + 1][j];
					min = (min < c) ? min : c;
					d = couts[1] + C[i + 1][j + 1];
					min = (min < d) ? min : d;
					C[i][j] = (min == a) ? a : ((min == b) ? b : ((min == c) ? c : d));
					S[i][j] = (min == a) ? 'p' : ((min == b) ? 'i' : ((min == c) ? 's' : 'r'));
				}
				else
				{
					if (x[i] == y[j])
					{
						a = couts[0] + C[i + 1][j + 1];
						b = couts[3] + C[i][j + 1];
						min = (a < b) ? a : b;
						c = couts[2] + C[i + 1][j];
						min = (min < c) ? min : c;
						d = couts[1] + C[i + 1][j + 1];
						C[i][j] = (min == a) ? a : ((min == b) ? b : (min == c) ? c
																				: d);
						S[i][j] = (min == a) ? 'c' : ((min == b) ? 'i' : (min == c) ? 's'
																					: 'r');
					}
					else
					{
						a = couts[3] + C[i][j + 1];
						b = couts[2] + C[i + 1][j];
						min = (a < b) ? a : b;
						c = couts[1] + C[i + 1][j + 1];
						min = (min < c) ? min : c;
						C[i][j] = (min == a) ? a : ((min == b) ? b : c);
						S[i][j] = (min == a) ? 'i' : ((min == b) ? 's' : 'r');
					}
				}
			}
		}
	}
	afficher_couts(C, m + 1, n + 1);
	afficher_solution(S, x, y, n, m);
	int result = C[0][0];
	free(C);
	return result;
}

int main(int argc, char **argv)
{
	int i, j;
	int couts[6] = {C_COP, C_REMP, C_SUP, C_INS, C_PERM, C_EQ};
	char **S = (char **)malloc((M1 + 1) * sizeof(char *));
	for (i = 0; i < M1 + 1; i++)
	{
		S[i] = (char *)malloc((N1 + 1) * sizeof(char));
	}
	char x[M1 + 1] = "algorithm";
	char y[N1 + 1] = "altruistic";
	int opt = distance_d_edition(M1, N1, couts, x, y, S);
	printf("\n\n\n\nLa distance d'édition de %s à %s est de %d\n\n", x, y, opt);
	return 0;
}
