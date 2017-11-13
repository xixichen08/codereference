#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
int n;
int climb(int n){
	int res=0;
	if(n<=1){
		return 1;	
	}
	res=climb(n-1)+climb(n-2);
	return res;
}
int main(int argc,char **argv){
	int tmp=0;
	printf("Please input the n stairs:\n");
	scanf("%d",&n);
	tmp=climb(n);
	printf("The ways is %d \n",tmp);
	return 0;
}


