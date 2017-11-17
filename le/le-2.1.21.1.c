#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
int n;
void gasstation(int *gas,int *cost,int n){
	int i,res=0;
	int j=-1;
	for(i=0;i<n;i++){
		res+=gas[i]-cost[i];
		if(res<0){
			j=i;
			res=0;

		}

	}
	printf("The station nr is %d \n",(j+1));
	return ;
}
int main(int argc,char **argv){
	int *A,*B,i,j;
	printf("Please input the n number:\n");
	scanf("%d",&n);
	A=(int *)malloc(sizeof(int)*n);
	B=(int *)malloc(sizeof(int)*n);
	if(NULL==A||NULL==B){
		printf("No memory !\n");
		return 0;
	}
	printf("Please input the gas array :\n");
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	printf("Please input the cost array :\n");
	for(i=0;i<n;i++){
		scanf("%d",&B[i]);
	}
	gasstation(A,B,n);
	return 0;
}


