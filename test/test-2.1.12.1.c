#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 3
#define max(a,b) ((a)>(b)?(a):(b))
int fn(int n){
	if(n<2) return 1;
	return n*fn(n-1);	
}
int swapone(int *A,int left,int right){
	int tmp;
	tmp=A[left];
	A[left]=A[right];	
	A[right]=tmp;
	return 0;
}
int swap(int *A,int left,int right){
	while(left<right){
		swapone(A,left,right);
		left++;
		right--;
	}
	return 0;
}
int fastsort(int *A,int left,int right){
	int l,r,tmp,res;
	if(left>=right) return 0;
	tmp=A[left];
	l=left;
	r=right;
	while(l<r){
		while(A[r]>=tmp&&l<r){r--;}
		while(A[l]<=tmp&&l<r) {l++;}
		if(l<r){
			res=A[l];
			A[l]=A[r];
			A[r]=res;		
		}	

	}
	A[left]=A[l];
	A[l]=tmp;
	fastsort(A,left,l-1);
	fastsort(A,l+1,right);
	return 0;
}
int nextpermutation(int *A,int n){
	int i,j;
	for(i=n-1;i>0;i--){
		if(A[i]>A[i-1]){		
			for(j=n-1;j>i-1;j--){
				if(A[i-1]<A[j]){
					swapone(A,i-1,j);
					swap(A,i,n-1);
					for(i=0;i<n;i++){
						printf("%d ",A[i]);
					}
					printf("\n");
					return 0;
				}
			}	
		}
	}
	swap(A,0,n-1);	
	for(i=0;i<n;i++){
		printf("%d ",A[i]);
	}
	printf("\n");
	return 0;
}
int kthpermu(int *A,int n,int k){
	int i,j,t,tmp;
	int *u=(int *)malloc(sizeof(int)*(n+1));
	if(NULL==u) return 0;
	for(i=0;i<=n;i++){
		u[i]=0;
	}	
	int *a=(int *)malloc(sizeof(int)*n);
	if(NULL==a) return 0;
	for(i=0;i<n;i++){
		a[i]=0;
	}
	fastsort(A,0,n-1);
	/*use cantor */
	k--;
	for(i=n-1;i>=0;i--){
		tmp=k/fn(i);	
		k%=fn(i);
		for(j=0,t=0;j<=tmp;t++){
			if(!u[t]) j++;
		}
		tmp=t-1;
		u[tmp]=1;
		a[n-1-i]=A[tmp];
	}
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	free(u);
	u=NULL;
	free(a);
	a=NULL;
	return 0;
}
int nriskth(int *A,int n){
	int i,j,kth=1,cnt=0;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(A[i]>A[j]) cnt++;

		}
		kth+=cnt*fn(n-i-1);
		cnt=0;
	}
	printf("This is the %dth number. \n",kth);
	return kth;

}
int main(int argc,int **argv){
	int i,n,kth;
	char *info;
	printf("Please input the length of the array: \n");
	scanf("%d",&n);
	int *A=(int* )malloc(sizeof(int)*n);
	if(NULL==A) return 0;
	printf("Please input the array :\n");
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	nextpermutation(A,n);
	nriskth(A,n);
	fgets(info,MAXCHAR,stdin);	
//	fflush(stdin);
	while(1){
		printf("would you want next permutation?\n(y/n):");
		fflush(stdin);
		fgets(info,MAXCHAR,stdin);	
		if(info[0]=='y'){
			nextpermutation(A,n);
			nriskth(A,n);
		}
		else if(info[0]=='n') break;
		else printf("Wrong number!\nYou can enter 'n' to quit.\n");
		
	}
	printf("Please input the kth :\n");
	scanf("%d",&kth);
	kthpermu(A,n,kth);
	free(A);
	A=NULL;
	return 0;
}
