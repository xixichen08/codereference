#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
int n,water=0;
int A[101]={};
int area(int *B,int n){
	int i,tmp;
	int res=0;
	int *left,*right;
	i=0;
	if(n<3) return 0;
	while(i!=n-2){
		if(B[i]>B[i+1]){
			left=&B[i];
			printf("Left number is %d\n",*left);
			break;
		}
		i++;
	}
	i=n-1;
	while(i!=1){
		if(B[i-1]<B[i]){
			right=&B[i];
			printf("Right number is %d\n",*right);
			break;
		}
		i--;
	}
	while(left!=right){
		if(*left<*right){
			for(tmp=*left;*left<=tmp;left++){
				res+=(tmp-*left);
			}	
		}else{
			for(tmp=*right;*right<=tmp;right--){
				res+=(tmp-*right);
			}
				
		}
				
	}
	return res;
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
