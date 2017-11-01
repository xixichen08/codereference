#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
int n,permutation_nr=0;
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
int permutation(int *B,int n,int index){
//        printf("Now B[%d] is %d \n",index,B[index]);
	int i;
//	int permutation_nr=1;
	if(index>=n-1){	
		for(i=0;i<n;i++){
			printf("%d ",B[i]);

		}
		printf("\n");
		
		permutation_nr++;
//		printf("The permutation_nr is %d\n",permutation_nr);
		return 0;
	}else{
		for(i=index;i<n;i++){
			swapone(B,i,index);
//			printf("Now B[%d] is %d \n",index,B[index]);
			permutation(B,n,index+1);
			/*we should know that if the last two number return the 
			original sort then in turn the last three numbers is also 
			swap to the original sort and in the end we get the tree*/
			swapone(B,i,index);

		}
	}
//	printf("The permutation_nr is %d\n",permutation_nr);
	return 0;	
}
int main(int argc,int **argv){
	int i;
//	int permutation_nr;
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
	permutation(&A[1],n,0);	
	printf("The permutation_nr is %d\n",permutation_nr);
	return 0;
}
