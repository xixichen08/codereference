#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
int n;
int graytobi(int n){
	int tmp=n;
	/*Means n>>1,and new n set to n*/
	while(n>>=1){
		tmp^=n;
	}
	return tmp;
}
int bitogray(int n){	
	return n^(n>>1);
}
int main(int argc,char **argv){
	int *A,tmp=0;
	printf("Please input the n:\n");
	scanf("%d",&n);
	tmp=1<<n;
	printf("Now tmp is 1<<%d,%d\n",n,tmp);
	A=(int *)malloc(sizeof(int)*tmp);
	if(NULL==A){
		printf("No memory !\n");
		return 0;
	}
//	printf("The ways is %d \n",tmp);
	for(int i=0;i<tmp;i++){
		A[i]=bitogray(i);
		printf("%d ",A[i]);
	}
	printf("\n");
	for(int i=0;i<tmp;i++){
		A[i]=graytobi(A[i]);
		printf("%d ",A[i]);
	}
	printf("\n");
	return 0;
}


