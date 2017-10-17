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
			return 1;
		}
		if(buffer[left]<buffer[mid]){
			if(buffer[mid]>target&&buffer[left]<=target){
				right=mid-1;
			}
			else
				left=mid;
		}
		else if(buffer[left]==buffer[mid]){
			left++;
		}
		if(buffer[right-1]>buffer[mid]){
			if(buffer[mid]<target&&buffer[right-1]>=target){
				left=mid+1;
			}
			else
				right=mid;
			
		}
		else if (buffer[right]==buffer[mid]){
			right--;

			
		}		
	}
	if(buffer[left]==target) return 1;
	return 0;

}
int main (int argc,char **argv){
	int A[11]={1,1,1,2,3,4,4,4,5,6,1};
	int B[9]={5,6,6,8,0,1,2,3,4};
	int C[12]={3,3,4,5,6,0,0,1,1,1,1,2};
	printf("Index is %d\n",search(B,9,7));
	printf("Index is %d\n",search(C,12,3));
	printf("Index is %d\n",search(C,12,7));
	
	return 0;


}
