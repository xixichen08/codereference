#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
int n;
void add(int *A,int n){
	int i,nr,tmp=0;
	int c=1;
	for(i=n-1;i>=0;i--){
		tmp=A[i];
		A[i]=(tmp+c)%10;
		c=(tmp+c)/10;
	}
	nr=n;
	if(c==1){
		
		A=(int*)realloc(A,sizeof(int)*(n+1));
		if(NULL==A){
			printf("No memory for realloc!\n");
			return ;
		}
		nr=n+1;
		A[0]=1;
		A[n]=0;
	}
	for(i=0;i<nr;i++){
		printf("%d ",A[i]);
	}
	printf("\n");
	return ;
}
void add2(int *A,int n){
	int i,nr;
	for(i=n-1;i>=0;i--){
		if(A[i]==9){
			A[i]=0;

		}else{
			A[i]+=1;
			break;
		}

	}
	nr=n;
	if(A[0]==0) {
		A=(int *)realloc(A,sizeof(int)*(n+1));
		if(NULL==A){
			printf("No memory for realloc!\n");
			return ;
		}
		nr=n+1;
		A[0]=1;
		A[n]=0;
	}
	for(i=0;i<nr;i++){
		printf("%d ",A[i]);
	}
	printf("\n");
	return ;
}
int main(int argc,char **argv){
	int *A,i,j;
	printf("Please input the n number:\n");
	scanf("%d",&n);
	A=(int*)malloc(sizeof(int)*n);
	if(NULL==A){
		printf("No memory !\n");
		return 0;
	}
	printf("Please input the array :\n");
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);	
	}
	add(A,n);
	add2(A,n);
	return 0;
}


