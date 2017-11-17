#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
int n;
int maxsub(int *A,int n){
	int i,res=A[0];
	int sub1=0;
	int sub2=0;
	for(i=0;i<n;i++){
		res=max(res,A[i]);
	}
	for(i=0;i<n;i++){
		sub1=max(A[i],sub1+A[i]);
	}
	for(i=n-1;i>=0;i--){
		sub2=max(A[i],sub2+A[i]);
	}
	printf("The max is %d \n",max(res,max(sub1,sub2)));
	return 0;
}
int submax(int *A,int n){
	int i,res=INT_MIN,sub=0;
	for(i=0;i<n;i++){
		sub=max(A[i],sub+A[i]);
		res=max(res,sub);
	}
	printf("The max is %d \n",res);
	return 0;
}
int main(int argc,char **argv){
	int *A,i;
	printf("Please input the number:\n");
	scanf("%d",&n);
	A=(int *)malloc(sizeof(int)*n);
	if(NULL==A){
		printf("No memory !\n");
		return 0;
	}
	printf("Please input the n! array :\n");
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	maxsub(A,n);
	submax(A,n);	
	return 0;
}


