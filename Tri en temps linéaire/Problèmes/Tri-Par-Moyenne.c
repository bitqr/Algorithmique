#include<stdio.h>
#include<stdlib.h>
#define N 11
#define K 5

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


void tri_rapide(int*A, int p, int r){
     if(p<r){
             int q=partition(A,p,r);
             tri_rapide(A,p,q-1);
             tri_rapide(A,q+1,r);
             }
}


int* tri_par_moyenne(int * A, int n, int k){
     int ltab = n/k + (n%k!=0);
     int reste = n%k;
     int i = 0,j,l,m;
     int * B = (int *)malloc(ltab*sizeof(int));
     int * R = (int *)malloc(n*sizeof(int));
     while(i<k){
                  for(j=0;j<n/k;j++){
                                     B[j] = A[i+j*k];
                                     }
                  if(reste!=0){
                               m=n/k+1;
                               B[j] = A[i+j*k];
                               reste--;
                               }
                  else{
                       m=n/k;
                       }
                  tri_rapide(B,0,m);
                  for(l=0;l<m;l++){
                                   R[i+l*k] = B[l];
                                   }
                  i++;
                  }
     return R;
}


int main(){
     int A[N] = {3,8,5,6,1,2,9,0,4,7,10};

     int * R = tri_par_moyenne(A,N,K);

     int i;
     for(i=0;i<N;i++){
          printf("%d\t",R[i]);
     }
     printf("\n\n\n");
     return 0;
}

