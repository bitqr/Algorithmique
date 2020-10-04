#include<stdio.h>
#include<stdlib.h>
#define N 16

int minimum(int * A, int n){
    int i,min = A[0];
    for(i=1;i<n;i++){
        if(min>A[i])
            min = A[i];
    }
    return min;
}

int main(){
    int A[N] = {65,3,8,0,1,7,11,13,9,18,22,28,4,24,30,84};
    printf("Le minimum est %d.\n\n", minimum(A,N));
    return 0;
}

