#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
int A[101]={};
int n,target;
int Index[2]={};
int fastsort(int left,int right){
	if(left>right) return 0;
	int temp,i,j;
	temp=A[left];
	i=left;
	j=right;
	while (i!=j){
		while(A[j]>=temp&&i<j) {j--;}		
		while(A[i]<=temp&&i<j) {i++;}
		if(i<j){
			A[j]=A[j]+A[i];
			A[i]=A[j]-A[i];
			A[j]=A[j]-A[i];
		}
	}
	A[left]=A[i];
	A[i]=temp;
//	fastsort((i+1),right);
	fastsort(left,(i-1));
	fastsort((i+1),right);



}
int search(void){
	for(int i=1;i<=n;i++){
		for(int j=n;j>i;j--){
			if((A[i]+A[j])==target) {
				Index[0]=i;
				Index[1]=j;
				printf("The index is %d,%d\n",Index[0],Index[1]);			
				return 0;	
			} 
		}

	}
	printf("No index match \n");

	return 0;

}

int main(int argc,char **argv){
	printf("Please input the number of the array:\n");
	scanf("%d",&n);
	printf("Please input the target:\n");
	scanf("%d",&target);
	printf("Please input the array:\n");
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);

	}
	fastsort(1,n);
	for(int m=1;m<=n;m++){
		printf("%d ",A[m]);
	}
	printf("\n");
	search();
	return 0;

}
