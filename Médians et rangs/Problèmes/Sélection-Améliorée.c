#include<stdio.h>
#include<stdlib.h>
#define N 18
#define RG 8

void permuter(int*A,int i, int j){
     int tmp = A[i];
     A[i]=A[j];
     A[j]=tmp;
}

int partition_modifiee(int * A, int p, int r,int el){
    int k=p;
    while((A[k]!=el)&&(k<=r))
        k++;
    permuter(A,k,r);
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

void tri_insertion(int *A , int n){
     int i,j,cle;
     for(j=1;j<n;j++){
                      cle=A[j];
                      //Insère A[j] dans la séquence triée A[1..j-1].
                      i=j-1;
                      while((i>=0)&&(A[i]>cle)){
                                               A[i+1]=A[i];
                                               i--;
                                               }
                      A[i+1]=cle;
                      }
}


int selection(int *A,int p, int r, int rg){
    int i;
    int n = r-p+1;
    if(rg>n){
        fprintf(stderr,"Error, Unbound Value\n\n");
        exit(EXIT_FAILURE);
    }
    if(n==1)
        return A[p];
    int lmed = (n/5)+(n%5!=0);
    int * R = (int *)malloc(lmed*sizeof(int));
    int B[5] = {0};
    int j,k=0,m,median;
    for(i=0;i<n;i+=5){
        for(j=0;j<5;j++)
            B[j]=0;
        m=(i>=(n/5)*5)?n%5:5;
        for(j=0;j<m;j++){
            B[j]=A[p+i+j];
            }
        tri_insertion(B,m);
        R[k]=B[m/2-1+m%2];
        k++;
        }
    median = selection(R,0,lmed-1,lmed/2+lmed%2);
    int part = partition_modifiee(A,p,r,median);
    int l = part+1 - p;
    if(rg==l)
        return A[part];
    else if(rg<l)
        return selection(A,p,part-1,rg);
    else
        return selection(A,part+1,r,rg-l);
}

int selection_amelioree(int*A,int p,int r,int rg){
    int n = r-p+1;
    if(rg>=n/2)
        return selection(A,p,r,rg);
    else{
        int k=0, j=0;
		int *R = (int *) malloc(n/2 * sizeof(int));
		while(j<=n-2){
			if(A[j]>A[j+1])
				R[k]=A[j+1];
			else
				R[k]=A[j];
            j+=2;
			k++;
		}
		k--;
		int n1 = selection_amelioree(R,0,k,rg);
		int * S = (int *)malloc(2*rg*sizeof(int));
		int r2=0, c=0;
		while(c<n){
			if(A[c]<=n1){
				S[r2]=A[c];
				r2++;
			}
			c++;
		}
		r2--;
        free(R);
        return selection(S,0,r2,rg);
	}
}

int main(int argc, char ** argv){
    int A[N] = {8,23,17,15,63,12,42,66,27,19,3,6,83,1,-2,52,18,13};
    printf("%d est l'element selectionne\n\n",selection_amelioree(A,0,N-1,RG));
    return 0;
}
