#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))

int singlenr(int *nr,int n){
	int single=0;
	for(int i=0;i<n;i++){
		single^=nr[i];
	}
	return single;
}
int main(int argc,int **argv){
	int n,i,j;
	int *nr;
	printf("Please input the number:\n");
	scanf("%d",&n);
	nr=(int*)malloc(sizeof(int)*n);
	if(NULL==nr) return 0;
	printf("Please input the nr:\n");
	for(i=0;i<n;i++){
		scanf("%d",&nr[i]);
	}
	printf("Singlenr is %d \n",singlenr(nr,n));
	free(nr);
	nr=NULL;
	return 0; 
}
