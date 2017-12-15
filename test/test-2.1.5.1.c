/*
	\Author:xxc08
	\Brief:This is the code from the code reference
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(m,n) ((m)<(n)?(m):(n))
int findkth(int *A,int n,int *B,int m,int k){
	int i;
	int target=m+n;
	if(n<m) return findkth(B,m,A,n,k);
	if(target<k) return 0;
	if(m==0) return A[n-k-1];
	if(target==k) return A[n-1]>B[m-1]?A[n-1]:B[m-1];
	if(k==1) return A[0]<B[0]?A[0]:B[0];

	int tb=(m>k/2)?(k/2):(m);
	int ta=k-tb;
	if(A[ta-1]>B[tb-1]){
		return findkth(A,n,tb==m?NULL:&B[tb],m-tb,ta);
	}else if (A[ta-1]<B[tb-1]){
		return findkth(&A[ta],n-ta,B,m,tb);
	
	}else{
		return A[ta-1];
	}
	return 0;
}
float findmedian(int *A,int n,int *B,int m){
	int target=m+n;
	int nr=target%2;
	if(nr!=0) {
		return findkth(A,n,B,m,1+target/2);
	}else{
		float tmp=(findkth(A,n,B,m,target/2)+findkth(A,n,B,m,1+target/2));
		return tmp/2.0;
	}
}
int main (int argc,char **argv){
	int i;
	int m,n;	
	printf("Please input the length of the A array:\n");
	scanf("%d",&n);
	int *A=(int*)malloc(sizeof(int)*n);
	if(NULL==A) return 0;
	printf("Please input the A array :\n");
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	printf("Please input the length of the B array:\n");
	scanf("%d",&m);
	int *B=(int*)malloc(sizeof(int)*m);
	if(NULL==B) return 0;
	printf("Please input the B array :\n");
	for(i=0;i<m;i++){
		scanf("%d",&B[i]);
	}
	printf("The median is %f \n",findmedian(A,n,B,m));	
	free(A);
	A=NULL;
	free(B);
	B=NULL;
	return 0;
}
