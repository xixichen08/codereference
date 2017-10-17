/*
	\Author:xxc08
	\Brief:This is the code from the code reference
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(m,n) ((m)<(n)?(m):(n))
int search(int *bufferm,int m,int *buffern,int n){
	int* mb=bufferm;
	int* nb=buffern;
	int p;
	int k=0;
	int nn=0;
	int mm=0;
	for(int i=0;i<min(m,n);i++){
		if(mb[mm]>nb[nn]) {
			p=nb[nn];
			nn++;
			k++;
			
		}
		else{
			p=mb[mm];
			mm++;
			k++;
			
		}
		if(k==(m+n)/2)	 return p;

	}
	if(m>n) return mb[mm+(m+n)/2-k-1];
	else return nb[nn+(m+n)/2-k-1];
	

}
int main (int argc,char **argv){
	int A[7]={1,2,3,4,5,6,7};
	int B[11]={4,5,6,7,8,9,10,11,12,13,14};
	int C[12]={6,7,8,9,10,11,12,13,14,15,16,17};
	printf("Number is %d\n",search(B,11,A,7));
	printf("Number is %d\n",search(C,12,B,11));
	printf("Number is %d\n",search(C,12,A,7));
	
	return 0;


}
