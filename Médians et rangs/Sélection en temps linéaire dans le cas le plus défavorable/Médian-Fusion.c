#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 8

int recherche_dichotomique(int*A,int deb,int fin,int cle){
    if(deb>=fin){
        return deb;
    }
    int mil = (deb + fin)/2;
    if(A[mil]==cle)
        return mil;
    if(A[mil]<cle)
        return recherche_dichotomique(A,mil+1,fin,cle);
    else
        return recherche_dichotomique(A,deb,mil-1,cle);
}

int median_fusion(int * X, int * Y, int n){
    if(X[n-1]<=Y[0])
        return X[n-1];
    int r;
    int x = X[(n-1)/2];
    int y = Y[(n-1)/2];
    if(x==y)
        return x;
    int maj = x>y?x:y;
    int min = x<y?x:y;
    if(min == x){
        r = recherche_dichotomique(X,0,n-1,y);
        return Y[n-r-2];
    }
    else{
        r = recherche_dichotomique(Y,0,n-1,x);
        return X[n-r-2];
    }
}

int main(){
    int X[N] = {1,6,8,11,15,18,19,22};
    int Y[N] = {3,15,16,17,21,23,25,30};
    printf("%d\n",median_fusion(X,Y,N));
    return 0;
}

