#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
int n,A[101]={};
int Index[2]={};
typedef struct node{
	int value;
	int index;

}small;
small* findsmall(int n,int *B){
	small* tmp;
	tmp=(small*)malloc(sizeof(small));
	if(NULL==tmp){
		printf("No memory!\n");
		return NULL;
	}
	tmp->value=B[0];
	tmp->index=0;
	for(int i=0;i<n;i++){
		if(B[i]<tmp->value){
			tmp->value=B[i];
			tmp->index=i;
		}

	}
//	printf("%d\n",tmp->value);
	return tmp;
}
int area(int n,int *B){
	int res=0;
	small* tmp;
	if(n<=1) return B[0];
	tmp=findsmall(n,B);
	res=n*tmp->value;
	res=max(res,area(tmp->index,B));
	res=max(res,area(n-1-tmp->index,&B[tmp->index+1]));
	return res;

}
int main(int argc,char *argv){
	int i;
	printf("Please input the number of the array:\n");	
	scanf("%d",&n);
	printf("Please input the array :\n");
	for ( i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	printf("Lagrest area is %d!\n ",area(n,A));
//	printf("The index is %d and %d!\n",Index[0],Index[1]);
}
