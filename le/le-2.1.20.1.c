#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
int n,m;
void setzero(int **A,int m,int n){
	int i,j;
	int *B,*C;
	B=(int*)malloc(sizeof(int)*m);
	C=(int*)malloc(sizeof(int)*n);
	if(NULL==B||NULL==C) return ;
	for(i=0;i<m;i++){
		B[i]=1;
	}
	for(j=0;j<n;j++){
		C[j]=1;
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(A[i][j]==0){
				B[i]=0;
				C[j]=0;
			}
		}

	}
	for(i=0;i<m;i++){
		if(B[i]==0){
			for(j=0;j<n;j++){
				A[i][j]=0;
			}
		}	

	}
	for(j=0;j<n;j++){
		if(C[j]==0){
			for(i=0;i<m;i++){
				A[i][j]=0;

			}

		}

	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return ;

}
void zeroset(int **A,int m,int n){
	int i,j;
	int col=0;
	int row=0;
	for(i=0;i<m;i++){
		if(A[i][0]==0){
			row=1;	
		}
	}
	for(j=0;j<n;j++){
		if(A[0][j]==0){
			col=1;
		}
	}
	for(i=1;i<m;i++){
		for(j=1;j<n;j++){
			if(A[i][j]==0){
				A[i][0]=0;
				A[0][j]=0;
			}
		}

	}
	for(i=1;i<m;i++){
		for(j=1;j<n;j++){
			if(A[0][j]==0||A[i][0]==0){
				A[i][j]=0;
			}

		}

	}
	if(col==1){
		for(j=0;j<n;j++){
			A[0][j]=0;
		}
	}
	if(row==1){
		for(i=0;i<m;i++){
			A[i][0]=0;
		}

	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return ;	
}
int main(int argc,char **argv){
	int **A,i,j,tmp=0;
	printf("Please input the arrow number:\n");
	scanf("%d",&m);
	printf("Please input the collume number:\n");
	scanf("%d",&n);
	A=(int **)malloc(sizeof(int*)*m);
	if(NULL==A){
		printf("No memory !\n");
		return 0;
	}
	for(i=0;i<m;i++){
		A[i]=(int *)malloc(sizeof(int)*n);
		if(NULL==A[i]) return 0;
	}
	printf("Please input the mxn matrix:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&A[i][j]);
		}
	}	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
//	setzero(A,m,n);
	zeroset(A,m,n);
//	printf("The ways is %d \n",tmp);
	return 0;
}


