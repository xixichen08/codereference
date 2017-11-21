#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))

int singlenr(int *nr,int n){
	int i,j,min=0;
	/*sizeof return the byte of a data struct so sizeof(int)*8 is the bits */
	int m=sizeof(int)*8;
	printf("The total bits is %d \n",m);
	int *cnt=(int *)malloc(sizeof(int )*m);
	if(NULL==cnt) return 0;
	for(i=0;i<m;i++){
		cnt[i]=0;
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cnt[j]+=(nr[i]>>j)&1;	
			cnt[j]%=3;
		}
		
	}
	for(i=0;i<n;i++){		
		min|=cnt[i]<<i;
	}
	free(cnt);
	cnt=NULL;
	return min;
}
int singlenr2(int *A,int n){
	int one=0,two=0,three=0;
	for(int i=0;i<n;i++){
		two|=(one&A[i]);
		one^=A[i];
		three=~(one&two);
		one&=three;
		two&=three;
	}
	return one;
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
	printf("Singlenr2 is %d \n",singlenr2(nr,n));
	free(nr);
	nr=NULL;
	return 0; 
}
