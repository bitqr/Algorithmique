#include <stdio.h>
#include <stdlib.h>
#define N 12

void echanger(int *A, int i, int j)
{
	int tmp = A[i];
	A[i] = A[j];
	A[j] = tmp;
}

int hoare_partition(int *A, int p, int r)
{
	int x = A[p];
	int i = p - 1;
	int j = r + 1;
	while (1)
	{
		do
		{
			j--;
		} while (A[j] > x);
		do
		{
			i++;
		} while (A[i] < x);
		if (i < j)
		{
			echanger(A, i, j);
		}
		else
		{
			return j;
		}
	}
}

int main()
{
	int A[N] = {13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21};
	int i;
	printf("%d\n\n", hoare_partition(A, 0, N - 1));
	for (i = 0; i < N; i++)
	{
		printf("%d\t", A[i]);
	}
	printf("\n\n\n");
	return 0;
}
