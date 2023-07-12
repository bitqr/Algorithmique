#include <stdio.h>
#include <stdlib.h>
#define N 3
#define X 0.5

float horner(int *A, int n, float x)
{
    float y = 0;
    int i = n - 1;
    while (i >= 0)
    {
        y = A[i] + x * y;
        i--;
    }
    return y;
}

int main()
{
    int A[N] = {6, 1, 3};
    float a = horner(A, N, X);
    printf("%f", a);
    printf("\n\n\n");
    return 0;
}
