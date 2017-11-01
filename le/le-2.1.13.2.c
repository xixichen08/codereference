#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PRIM 271
#define max(a,b) ((a)>(b)?(a):(b))
int n,permutation_nr,target;
int Numbers[101]={};
int fac(int n){
	if(n<=1) return 1;	
	return n*fac(n-1);
}
int uncantor(int *B,int n,int k){
	int used[100]={};
	int i,j,t,l;
	for(i=1;i<=n;i++){
		t=k/fac(n-i);
		k=k%fac(n-i);
		for(j=1,l=0;l<=t;j++){
			if(!used[j]) l++;

		}
		printf("The two number is %d ,%d\n",j,i);
		j--;
		used[j]=1;
		B[i-1]=j;

	}
	return 0;

}
int main (int argc ,char **argv){
	int nr,i;
	printf("Please input the number of the array :\n");
	scanf("%d",&n);
	printf("Please input the Kth to search:\n");
	scanf("%d",&target);
/*	printf("Please input the array:\n");
	for(i=1;i<=n;i++){
		scanf("%d",&Numbers[i]);
	}*/
	uncantor(Numbers,n,target-1);
	printf("The number is : \n");
	for(i=0;i<n;i++){
		printf("%d ",Numbers[i]);
	}	
	printf("\n");
	return 0;
}

