#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 12
#define I 6

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

int Random(int a, int b){
    int i;
    if(a==0 && b==1)
        return rand()%2;
    int acc=0;
    for(i=a;i<b;i++){
        acc += Random(0,1);
    }
    return a + acc;
}

int partition_randomisee(int * A, int p, int r){
    int i = Random(p,r);
    permuter(A,r,i);
    return partition(A,p,r);
}

int selection_randomisee(int *A, int p, int r, int i){
    if(p==r)
        return A[p];
    int q=partition_randomisee(A,p,r);
    int k = q-p+1;
    if(i==k) // La valeur du pivot est la réponse
        return A[q];
    else{
        if(i<k)
            return selection_randomisee(A,p,q-1,i);
        else
            return selection_randomisee(A,q+1,r,i-k);
    }
}

int main(){
    int A[N] = {2,6,8,0,3,1,7,9,11,12,18,5};
    int i;
    for(i=1;i<=N;i++){                 
        printf("%d est le %d-ème plus petit élément.\n\n\n", selection_randomisee(A,0,N-1,i),i);
    }
    return 0;
}

