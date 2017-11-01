#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
int n,water=0;
int A[101]={};
int area(int *B,int n){
	int i,j,index,max,temp;
	max=B[0];
	index=0;
	for(i=0;i<n;i++){
		if(max<B[i]) {
			max=B[i];
			index=i;
		}
	}
	temp=B[0];
	for(j=0;j<index;j++){
		if(B[j]>temp) temp=B[j];
		else water+=temp-B[j];

	}
	temp=B[n-1];
	for(j=n-1;j>index;j--){
		if(B[j]>temp) temp=B[j];
		else water+=temp-B[j];

	}
	return water;

}
int main(int argc,int **argv){
	int i;

	printf("Please input the number of the array: \n");
	scanf("%d",&n);
/*	printf("Please input the k number :\n");
	scanf("%d",&target);*/
	printf("Please input the array :\n");
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
/*	fastsort(1,n);
	printf("The sorted array is :\n");
	for(i=1;i<=n;i++){
		printf("%d ",A[i]);

	}	
	printf("\n");*/
	printf("The area is %d \n",area(A,n));
/*	while((i=permutation(&A[1],n,target))){
		if(i==2){
			printf("Kth array is found!\n");
			return 0;	
		}
		
	}*/
//	printf("The permutation_nr is %d\n",permutation_nr);
	return 0;		
}
