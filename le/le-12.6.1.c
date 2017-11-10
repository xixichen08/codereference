#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
int n,A[101]={};
int Index[2]={};
int containwater(int n,int *A){
	int i,j,tmp,res=0;
	for(i=0;i<n-1;i++){
		for(j=n-1;j>i;j--){
			tmp=(j-i)*min(A[i],A[j]);
			if(tmp>res){
				res=tmp;
				Index[0]=i;
				Index[1]=j;
			}		
		
		}


	}
	return res;

}
int main(int argc,char *argv){
	int i;
	printf("Please input the number of the array:\n");	
	scanf("%d",&n);
	printf("Please input the array :\n");
	for ( i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	printf("Lagrest area is %d!\n ",containwater(n,A));
	printf("The index is %d and %d!\n",Index[0],Index[1]);
}
