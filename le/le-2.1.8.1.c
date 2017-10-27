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
	fastsort(left,i-1);
	fastsort(i+1,right);

	return 0;
}
int search(int *B,int n){
	/*Print the sorted array */
	int i;
	for(i=0;i<n;i++){
                 printf("%d ",B[i]);
        }
        printf("\n");
	if(n<3) return 0;
	/*Find the apropriate number and print them*/
	for(i=0;i<n-2;i++){
		int b=i+1;
		int j=n-1;
		while (b!=j){
			if((B[i]+B[b]+B[j])<0){
				b++;
					
			}
			else if((B[i]+B[b]+B[j])>0){
				j--;
			}
			else if ((B[i]+B[b]+B[j])==0){
				printf("The 3sum number is %d,%d,%d\n",B[i],B[b],B[j]);
				b++;
			}
			
		}

	}
	return 0;
}
int main(int argc,int **argv){
	int i;
	printf("Please input the number of the array !\n");
	scanf("%d",&n);
	printf("Please input the array !\n");
	for (i=1;i<=n;i++){
		scanf("%d",&A[i]);

	}
	fastsort(1,n);
	search(&A[1],n);
	return 0;
}
