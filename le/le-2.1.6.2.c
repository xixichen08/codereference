#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
int A[101]={};
int n;
int fastsort(int left,int right){
	int temp,i,j;
	if(left>right) return 0;
	i=left;
	j=right;
	temp=A[left];
	while(i!=j){
		while(A[j]>=temp&&i<j){j--;}
		while(A[i]<=temp&&i<j){i++;}
		if(i<j){
			
			A[i]=A[i]+A[j];
			A[j]=A[i]-A[j];
			A[i]=A[i]-A[j];	
		}
	}

	A[left]=A[i];
	A[i]=temp;
	fastsort(i+1,right);	
	fastsort(left,i-1);
//	fastsort(i+i,right);

}

int search(int *A,int n){
	int i,temp[101],real[101]={};
	int j=0;
	int maxres,flag=0;
	temp[0]=A[0];
	for(int i=1;i<n;i++){
		if(A[i]==temp[j]+1) {
			temp[++j]=A[i];
		}
	
		else {
//			printf("Now j is %d\n",j);
			if(++j>maxres){
//				printf("Now j is %d\n",j);
				maxres=j++;
				for(int m=0;m<maxres;m++){real[m]=temp[m]; }
			}
			j=0;
			temp[j]=A[i];
		}
		
	}
	if(++j>maxres){
		maxres=j++;
		for(int h=0;h<maxres;h++){real[h]=temp[h];}
	}
	printf("The length is %d\n",maxres);
	printf("The longest concecutive array is :\n");
	for (int m=0;m<maxres;m++){
		
		printf("%d ",real[m]);
		
	}
	printf("\n");
	return 0;

}

int main(int argc,int **argv){

	printf("Please input the total length of the array \n");
	scanf("%d",&n);
		
	printf("Please input the input number \n");
	for (int i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	fastsort(1,n);

	printf("The sorted array is :\n");
	for(int j=1;j<=n;j++){
		printf("%d ",A[j]);
	}
	printf("\n");
	search(&A[1],n);
	return 0;
}
