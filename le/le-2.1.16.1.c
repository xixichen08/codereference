#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
int n;
void swap(int **A,int left1,int right1,int left2,int right2){
	int tmp;
	tmp=A[left1][right1];
	A[left1][right1]=A[left2][right2];
	A[left2][right2]=tmp;
	return ;
}
void reverse(int **A,int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			swap(A,i,j,j,i);
		}
	}
	for(j=0;j<n/2;j++){
		for(i=0;i<n;i++){
			swap(A,i,j,i,(n-1-j));
		}
	}
	return ;

}
int main(int argc,char **argv){
	int **A,i,j;
	printf("Please input the n number:\n");
	scanf("%d",&n);
	A=(int **)malloc(sizeof(int *)*n);
	if(NULL==A){
		printf("No memory !\n");
		return 0;
	}
	for(i=0;i<n;i++){
		A[i]=(int *)malloc(sizeof(int)*n);
		if(NULL==A[i]) return 0;
	}
	printf("Malloc ok!\n");
	printf("Please input the nxn array :\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&A[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	reverse(A,n);
	printf("The reverse array is :\n\n\n");	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	return 0;
}


