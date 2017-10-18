/*
	\Author:xxc08
	\Brief:This is the code from the code reference
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int search(int *buffer,int n,int target){
	int right=n;
	int left=0;
	while(left!=right){
	     int mid=(right+left)/2;
		if(buffer[mid]==target){
			return mid;
		}
		if(buffer[left]<=buffer[mid]){
			if(buffer[mid]>target&&buffer[left]<=target){
				right=mid-1;
			}
			else
				left=mid;
		}
		else{
			if(buffer[mid]<target&&buffer[right-1]>=target){
				left=mid+1;
			}
			else
				right=mid;
			
		}		
	}
	return (right+left);

}
int main (int argc,char **argv){
	int A[11]={0,1,2,3,4,5,6,7,8,9,10};
	int B[9]={5,6,7,8,0,1,2,3,4};
	int C[7]={3,4,5,6,0,1,2};
	printf("Index is %d\n",search(B,9,4));
	printf("Index is %d\n",search(C,7,3));
	
	return 0;


}
