#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 8

int Random(int a, int b){
    int i;
    if((a==0)&&(b==1))
        return rand()%2;
    int acc=0;
    for(i=a;i<b;i++){
        acc += Random(0,1);
    }
    return a + acc;
}

void permuter(int*A,int i, int j){
     int tmp = A[i];
     A[i]=A[j];
     A[j]=tmp;
}

void echanger(int*A,int i, int j){
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

int partition_randomise(int * A, int p, int r){
    int i = Random(p,r);
    echanger(A,r,i);
    return partition(A,p,r);
}

int main(){
    srand(time(NULL));
    int A[N]={2,8,7,1,3,5,6,4};
    partition_randomise(A,0,N-1);
    int i;
    for(i=0;i<N;i++)
        printf("%d\t", A[i]);
    printf("\n\n\n");
    return 0;
}
    
