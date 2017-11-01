#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
int n;
int A[101]={};
int fastsort(int left,int right){
	if(left>right) return 0;
	int temp,i,j;
	temp=A[left];
	i=left;
	j=right;
	while(i!=j){
		while(A[j]>=temp&&i<j){j--;}
		while(A[i]<=temp&&i<j){i++;}
		if(i<j){
			A[j]=A[i]+A[j];
			A[i]=A[j]-A[i];
			A[j]=A[j]-A[i];

		}
	}
	A[left]=A[i];
	A[i]=temp;
	fastsort(i+1,right);
	fastsort(left,i-1);
	return 0;

}
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
					return 1;

				}
			}
		}



	}
//	swap(B,0,(n-1));
	return 0;
}
int main(int argc,int **argv){
	int i;
	int permutation_nr;
	printf("Please input the number of the array: \n");
	scanf("%d",&n);
//	printf("Please input the target :\n");
//	scanf("%d",&target);
	printf("Please input the array :\n");
	for(i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	fastsort(1,n);
	printf("The sorted array is :\n");
	for(i=1;i<=n;i++){
		printf("%d ",A[i]);

	}	
	printf("\n");
	permutation_nr=1;
	while(nextpermutation(&A[1],n)){
		for(i=1;i<=n;i++){
			printf("%d ",A[i]);
		}
		printf("\n");
		permutation_nr++;
	}
	printf("The permutation_nr is %d \n",permutation_nr);
	return 0;
}
