#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
int n;
int triangle(int **A,int n){
	int i,j;
	int *DP;
	DP=(int *)malloc(sizeof(int)*n);
	if(NULL==DP){
		printf("No memory !\n");
		return 0;
	}
	for(i=0;i<n;i++){
		DP[i]=A[n-1][i];
	}
	/*From the second last row we get the shortest length*/
	for(i=n-2;i>=0;i--){
		for(j=0;j<=i;j++){
			DP[j]=A[i][j]+min(DP[j],DP[j+1]);
		}
	}
	return DP[0];	
}
int main(int argc,char **argv){
	int **A,i,j;
	printf("Please input the n step:\n");
	scanf("%d",&n);
	A=(int **)malloc(sizeof(int *)*n);
	if(NULL==A){
		printf("No memory !\n");
		return 0;
	}
	for(i=0;i<n;i++){
		A[i]=(int *)malloc(sizeof(int)*(n+1));
		if(NULL==A[i]) return 0;
	}
	printf("Malloc ok!\n");
	printf("Please input the n! array :\n");
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			scanf("%d",&A[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	printf("The shortest length is %d\n",triangle(A,n));	
	return 0;
}


