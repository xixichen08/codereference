#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PRIM 271
#define max(a,b) ((a)>(b)?(a):(b))
int n,permutation_nr;
int Numbers[101]={};
int fac(int n){
	if(n==1) return 1;	
	return n*fac(n-1);
}
int cantor(int *B,int n){
	int i,j,max=0;
	for(i=0;i<n-1;i++){
		int temp=0;
		for(j=i+1;j<n;j++){
			if(B[i]>B[j]){
				temp++;
			}
		}
		max+=temp*fac(n-i-1);	
	}
	return max;
}
int main (int argc ,char **argv){
	int nr;
	printf("Please input the number of the array :\n");
	scanf("%d",&n);
//	printf("Please input the target to search:\n");
//	scanf("%d",&target);
	printf("Please input the array:\n");
	for(int i=0;i<n;i++){
		scanf("%d",&Numbers[i]);
	}
	nr=cantor(Numbers,n);
	printf("The number is %d \n",nr+1);	
	return 0;
}

