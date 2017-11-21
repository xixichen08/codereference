#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))

int removeduplicate(int *A,int n){
	int i,j,res=0;
	int flag=0;
	for(i=1;i<n;){		
		if(!flag&&A[res]==A[i]){
			flag=1;
			A[++res]=A[i++];	
		}else if(flag&&A[res]==A[i]){
			i++;
		}else if(A[res]!=A[i]){
			flag=0;
			A[++res]=A[i++];
		}	

	}
	return res+1;

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
