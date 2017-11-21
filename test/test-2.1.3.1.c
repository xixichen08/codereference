/*
	\Author:xxc08
	\Brief:This is the code from the code reference
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
int search(int *A,int n,int target){
	int i,tmp;
	int left=0,right=n-1;
	if(n<2) return target==A[0]?0:-1;
	while(left<=right){
		tmp=(left+right)/2;
		if(A[tmp]==target) return tmp;
		if(A[tmp]>A[left]){
			if(A[tmp]>target&&A[left]<=target){
				right=tmp-1;	
			}else	left=tmp;
	
		}else{
			if(A[right]>=target&&A[tmp]<target){
				left=tmp+1;
			}else	right=tmp;
		
		}

	}
	return -1;
}
int duplisearch(int *A,int n,int target){
	int left=0,right=n-1;
	int tmp;
	if(n<2) return A[0]==target?0:-1;
	while(left<=right){
		tmp=(right+left)/2;
		if(A[tmp]==target) return tmp;
		/*we use the increament array to decide which half to goto*/
		if(A[tmp]>A[left]){
			if(A[tmp]>target&&A[left]<=target){
				right=tmp-1;
			}else left=tmp;
		}else if(A[tmp]<A[left]){	
			if(A[tmp]<target&&target<=A[right]){
				left=tmp+1;

			}else right=tmp;	
		}else left++;
	}
	return -1;
}
int main (int argc,char **argv){
	int i,n,target;
	printf("Please input the number :\n");
	scanf("%d",&n);
	int *A=(int*)malloc(sizeof(int)*n);
	if(NULL==A) return 0;
	printf("Please input the array :\n");	
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	printf("Please input the target :\n");
	scanf("%d",&target);
	printf("Index is %d\n",search(A,n,target));
	printf("Dupli Index is %d\n",duplisearch(A,n,target));
	free(A);
	A=NULL;
	return 0;
}
