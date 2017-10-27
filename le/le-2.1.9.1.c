#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(a,b) ((a)<(b)?(a):(b))
int n,target;
int A[101]={};
int Array[3]={};
void fastsort(int left,int right){
	if(left>right) return ;
	int temp,i,j;
	temp=A[left];
	i=left;
	j=right;
	while (i!=j){
		while(A[j]>=temp&&i<j){j--;}
		while(A[i]<=temp&&i<j){i++;}
		if(i!=j){
			A[j]=A[j]+A[i];
			A[i]=A[j]-A[i];
			A[j]=A[j]-A[i];
		}
	}
	A[left]=A[i];
	A[i]=temp;
	fastsort(left,i-1);
	fastsort(i+1,right);

}
int search(int *B,int n,int target){
	/*Print the sorted array */
	int i;
	for(i=0;i<n;i++){
		printf("%d ",B[i]);

	}
	printf("\n");
	if(n<3) return 0;
	int b,j,min;
	int minres=abs(target-B[0]-B[1]-B[n-1]);
	Array[0]=B[0];
	Array[1]=B[1];
	Array[2]=B[2];
	/*Search the min to target */
	for(i=0;i<n-2;i++){
		b=i+1;
		j=n-1;
		while (b<j){
			min=abs(target-(B[i]+B[b]+B[j]));	
			if(min(min,minres)==min){
				Array[0]=B[i];
				Array[1]=B[b];
				Array[2]=B[j];
				minres=min;
			}
			b++;
			j--;	
		}
	}
	printf("The min array is %d %d %d \n",Array[0],Array[1],Array[2]);
}
int main(int argc,int **argv){
	int i;
	printf("Please input the number of the array :\n");
	scanf("%d",&n);
	printf("Please input the target :\n");
	scanf("%d",&target);
	printf("Please input the array !\n");
	for (i=1;i<=n;i++){
		scanf("%d",&A[i]);

	}
	fastsort(1,n);
	search(&A[1],n,target);
	return 0;
}
