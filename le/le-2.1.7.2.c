#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
int A[101]={};
int n,target;
int Index[2]={};
int twosum(int *A,int n,int target){
	if(n==1) return 0;
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((A[i]+A[j])==target){
				Index[0]=i;
				Index[1]=j;	
				printf("The two index is %d,%d\n",Index[0],Index[1]);
			} 
				
		}

	}
	return 0;

}
int main(int argc,char **argv){
	
	printf("Please input the number of the array:\n");
	scanf("%d",&n);
	printf("Please input the target :\n");
	scanf("%d",&target);
	printf("Please input the array:\n");
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	printf("\n");
	twosum(A,n,target);

	return 0;
}
