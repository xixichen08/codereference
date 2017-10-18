/*
	\Author:xxc08
	\Brief:This is the code from the code reference
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(m,n) ((m)<(n)?(m):(n))
int findkth (int *A,int m,int *B,int n,int k){
	
	if(m<n) return findkth (B,n,A,m,k);
	if(n==0) return A[k-1];
	if(k==1) return min(A[0],B[0]);

	if(min(A[0],B[0])==A[0]) return findkth(&(A[1]),(m-1),B,n,--k);
	else return findkth (A,m,&(B[1]),(n-1),--k);




}
float search(int *bufferm,int m,int *buffern,int n){
	if((m+n)%2==0)
		return ( findkth(bufferm,m,buffern,n,(m+n)/2)+findkth(bufferm,m,buffern,n,((m+n)/2+1)))/2.0;
	else 
		return (findkth(bufferm,m,buffern,n,((m+n)/2+1)));
	
}
int main (int argc,char **argv){
	int A[7]={1,2,3,4,5,6,7};
	int B[11]={4,5,6,7,8,9,10,11,12,13,14};
	int C[12]={6,7,8,9,10,11,12,13,14,15,16,17};
	printf("Number is %f\n",search(B,11,A,7));
	printf("Number is %f\n",search(C,12,B,11));
	printf("Number is %f\n",search(C,12,A,7));
	
	return 0;


}
