#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
int n;
int A[101]={};
int swapone(int *B,int left,int right){

	B[left]=B[left]+B[right];
	B[right]=B[left]-B[right];
	B[left]=B[left]-B[right];	
	return 0;
}
int swap(int *B,int left,int right){
	while(left<right){
		swapone(B,left,right);
		left++;
		right--;
	}
	return 0;

}
int nextpermutation(int *B,int n){
	int i;
	if(n<1) return 0;
	for(i=n-1;i>0;--i){
		if(B[i-1]<B[i]){
			for(int j=n-1;j>i-1;--j){
				if(B[i-1]<B[j]){
					swapone(B,(i-1),j);
					swap(B,i,(n-1));
					return 0;

				}
			}
		}



	}
	swap(B,0,(n-1));
	return 0;
}
int main(int argc,int **argv){
	int i;
	printf("Please input the number of the array: \n");
	scanf("%d",&n);
//	printf("Please input the target :\n");
//	scanf("%d",&target);
	printf("Please input the array :\n");
	for(i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	nextpermutation(&A[1],n);
	for(i=1;i<=n;i++){
		printf("%d ",A[i]);
	}
	printf("\n");
	return 0;
}
