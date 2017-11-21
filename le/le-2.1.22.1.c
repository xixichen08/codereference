#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))

int kthnr(int*ratings,int k,int n,int* candy){
	if(k>0&&ratings[k]>ratings[k-1]){
		candy[k]=max(candy[k],kthnr(ratings,k-1,n,candy)+1);
	}
	if(k<n-1&&ratings[k]>ratings[k+1]){
		candy[k]=max(candy[k],kthnr(ratings,k+1,n,candy)+1);
	}
	return candy[k];
}
int candy(int *ratings,int n){
	int min,i;
	int *candy=(int*)malloc(sizeof(int)*n);
	if(NULL==candy) return 0;
	for(i=0;i<n;i++){
		candy[i]=1;
	}
	for(i=0;i<n;i++){
		min+=kthnr(ratings,i,n,candy);
	}
	return min;
}
int main(int argc,int **argv){
	int n,i,j;
	int *ratings;
	printf("Please input the number:\n");
	scanf("%d",&n);
	ratings=(int*)malloc(sizeof(int)*n);
	if(NULL==ratings) return 0;
	printf("Please input the ratings:\n");
	for(i=0;i<n;i++){
		scanf("%d",&ratings[i]);
	}
	printf("Min candy is %d \n",candy(ratings,n));
	free(ratings);
	ratings=NULL;
	return 0; 
}
