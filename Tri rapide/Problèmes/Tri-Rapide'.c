#include<stdio.h>
#include<stdlib.h>
#define N 8

void permuter(int*A,int i, int j){
     int tmp = A[i];
     A[i]=A[j];
     A[j]=tmp;
}

int partition(int * A, int p, int r){
    int x = A[r];
    int i = p-1;
    int j;
    for(j=p;j<r;j++){
        if(A[j]<=x){
            i++;
            permuter(A,i,j);
        }
    }
    permuter(A,i+1,r);
    return i+1;
}

void tri_rapide_2(int*A, int p, int r){
    while(p<r){        //Partitionne et trie sous-tableau gauche.
        int q=partition(A,p,r);
        tri_rapide_2(A,p,q-1);
        p = q+1;
    }
}

int main(){
    int A[N]={2,8,7,1,3,5,6,4};
    tri_rapide_2(A,0,N-1);
    int i;
    for(i=0;i<N;i++)
        printf("%d\t", A[i]);
    printf("\n\n\n");
    return 0;
}
    
