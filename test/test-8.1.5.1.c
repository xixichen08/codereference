#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PRIM 271
#define max(a,b) ((a)>(b)?(a):(b))
int n,target;
int Numbers[101]={};
//int comb_nr=0;
//int s=0;
int A[101]={};
int swapone(int *B,int left,int right){
	int tmp;	
	tmp=B[left];
	B[left]=B[right];
	B[right]=tmp;
	return 0;

}
int swap(int *B,int left,int right){
	while(left<right){
		swapone(B,left,right);
		left++;
		right--;
	}
	return 0;
}
int comb(int *B,int s ,int comb_nr,int n,int k){
	int i,j;
	if(s>n) return 0;
	if(comb_nr>=k){
		for (i=0;i<k;i++){
			printf("%d ",A[i]);
		}
		printf("\n");
		return 0;
	}	
	A[comb_nr++]=B[s];
	comb(B,s+1,comb_nr,n,k);
	comb_nr--;
	comb(B,s+1,comb_nr,n,k);
	return 0;

}
int main (int argc ,char **argv){
	int nr,i;
	printf("Please input the number of the array :\n");
	scanf("%d",&n);
	printf("Please input the Kth to comb:\n");
	scanf("%d",&target);
	printf("Please input the array:\n");
	for(i=0;i<n;i++){
		scanf("%d",&Numbers[i]);
	}
	comb(Numbers,0,0,n,target);
/*	printf("The number is : \n");
	for(i=0;i<n;i++){
		printf("%d ",Numbers[i]);
	}	
	printf("\n");*/
	return 0;
}

