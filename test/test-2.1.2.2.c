#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))

int removeduplicate(int *A,int n){
	int i,res=2;
	if(n<3) return n;
	for(i=2;i<n;i++){
		if(A[i]!=A[res-2]){
			A[res++]=A[i];
		}		

	}	
	return res;
}
int main(int argc,int **argv){
	int n,i,m;
	int *nr;
	printf("Please input the number:\n");
	scanf("%d",&n);
	nr=(int*)malloc(sizeof(int)*n);
	if(NULL==nr) return 0;
	printf("Please input the nr:\n");
	for(i=0;i<n;i++){
		scanf("%d",&nr[i]);
	}
	m=removeduplicate(nr,n);
	printf("The new length is %d \n",m);
	for(int j=0;j<m;j++){
		printf("%d ",nr[j]);
	}
	printf("\n");
	free(nr);
	nr=NULL;
	return 0; 
}
