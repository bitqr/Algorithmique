#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 20
#define K 6

typedef struct _elem{
        int el;
        int nombre;
}elem;
        
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

int max(elem * A, int n){
    int m = 0;
    int i;
    for(i=1;i<n;i++){
        if(A[i].el>A[m].el)
            m=i;
    }
    return m;
}

void tri_denombrement(elem * A, elem * B, int k, int n){
    int i;
    int * C = (int *) malloc(k*sizeof(int));
    for(i=0;i<k;i++){
        C[i] = 0;
    }
    int j;
    for(j=0;j<n;j++)
        C[A[j].el]++;
    // C[i] contient maintenant le nombre d'éléments égaux à i.
    for(i=1;i<k;i++)
        C[i] += C[i-1];
    // C[i] contient maintenant le nombre d'éléments inférieurs ou égaux à i.
    for(j=n-1;j>=0;j--){
        B[C[A[j].el]-1].el = A[j].el;
        B[C[A[j].el]-1].nombre = A[j].nombre;
        C[A[j].el]--;
    }
}

int * voisinage_median(int * S, int n, int k){
    int m = selection_randomisee(S,0,n-1,(n+1)/2);
    int * S2 = (int *) malloc((n-1)*sizeof(int));
    elem * E = (elem *) malloc((n-1)*sizeof(elem));
    elem * E1 = (elem *) malloc((n-1)*sizeof(elem));
    int * R = (int *) malloc(k*sizeof(int));
    int i,j=0;
    for(i=0;i<n;i++){
        if(S[i]!=m){
            S2[j]=S[i];
            j++;
        }
    }
    for(i=0;i<n-1;i++){
        E[i].el = abs(S2[i] - m);
        E[i].nombre = S2[i];
    }
    tri_denombrement(E,E1,E[max(E,n-1)].el+1,n-1);
    for(i=0;i<k;i++){
        R[i] = E1[i].nombre;
    }
    return R;
}

int main(){
    int A[N] = {3,5,98,65,19,64,8,18,32,67,89,91,15,44,78,55,60,21,80,11};
    int * R = voisinage_median(A,N,K);
    int i;
    for(i=0;i<K;i++){
        printf("%d\t",R[i]);
    }
    printf("\n\n\n");
    return 0;
}

