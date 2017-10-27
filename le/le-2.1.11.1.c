#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
int n,target;
int A[101]={};
int element(int *B,int n,int target){
	int *p,length=0;
	p=&B[0];
	for(int i=0;i<n;i++){
		while(B[i]==target){
			i++;
			length++;	
		
				
		}
		*p=B[i];
		p++;
		
	}
	printf("The length is %d\n",length);
	printf("The new array is :\n");
	for(int j=0;j<n-length;j++){
		printf("%d ",B[j]);
	}
	printf("\n");
	return 0;

}
int main(int argc,int **argv){
	int i;
	printf("Please input the number of the array: \n");
	scanf("%d",&n);
	printf("Please input the target :\n");
	scanf("%d",&target);
	printf("Please input the array :\n");
	for(i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	element(&A[1],n,target);
	return 0;
}
