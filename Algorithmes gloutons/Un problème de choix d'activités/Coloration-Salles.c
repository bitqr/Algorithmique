#include"PCA.h"


int compatibles(int s1, int f1, int s2, int f2){
	if(s1 >= f2 || f1 <= s2)
		return 1;
	return 0; 
}


int * coloration_salles(int *s, int *f, int n){
	int *couleurs = (int *)malloc(n*sizeof(int));
	int i,j,nc=1,nbr = n-1,b;
	for(i=0;i<n;i++)
		couleurs[i] = 0;
	couleurs[0] = nc;
	while(nbr!=0){
		for(i=2;i<=n;i++)
			if(couleurs[i-1]==0){
				b = 1;
				for(j=1;j<=n;j++){
					if(couleurs[j-1] == nc && compatibles(s[j],f[j],s[i],f[i])==0){
						b = 0;
					}
				}
				if(b==1){
					couleurs[i-1] = nc;
					nbr--;
				}
			}
		nc++;
	}
	return couleurs;
}




