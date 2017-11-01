#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
int n,target,permutation_nr=1;
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
	int temp;
	temp=B[left];
	B[left]=B[right];
	B[right]=temp;	
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
int permutation(int *B,int n,int target){
	int i;
	if(n<1) return 0;
	if(target ==1) {
		for(i=0;i<n;i++){
			printf("%d ",B[i]);
		}
		printf("\n");
		return 1;
	}
	
	for(i=n-1;i>0;i--){
		if(B[i-1]<B[i]){
			for(int j=n-1;j>i-1;j--){
				if(B[i-1]<B[j]){
					swapone(B,i-1,j);
					swap(B,i,n-1);
					permutation_nr++;
					if(permutation_nr==target){ 
						for(int k=0;k<n;k++){
							printf("%d ",B[k]);
						}
						printf("\n");
						return 2;
					}
					return 1;
				}


			}
		}


	}
	
	return 0;	
	
}
int main(int argc,int **argv){
	int i;

	printf("Please input the number of the array: \n");
	scanf("%d",&n);
	printf("Please input the k number :\n");
	scanf("%d",&target);
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
	
	while((i=permutation(&A[1],n,target))){
		if(i==2){
			printf("Kth array is found!\n");
			return 0;	
		}
		
	}
	printf("The permutation_nr is %d\n",permutation_nr);
	return 0;		
}
