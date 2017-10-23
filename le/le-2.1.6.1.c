#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct newarray{
	int *newarray;
	int maxres;


};
struct newarray* findlongest(struct newarray* array){
	struct newarray B;
	B->maxres=0;
	B->newarray=malloc(sizeof(array->newarray));
	B[0]=array[0];
	
	for(int i=1;i<sizeof(array->newarray);i++){
		if(array[i]>B[B->maxres]){
			if(array[i]==(B[B->maxres]+1)) B[++(B->maxres)]=array[i]; 
		}
		else if(array[i]<B[B->maxres]){
			if(array[i]==)		
		}
	}
	



}
int search(int *A){
	struct newarray* array;
	array->newarray=A;
	array->maxres=0;
	return	findlongest(array)->maxres;




}

int main(int argc,int **argv){
	int A[8]={100,2,3,99,4,5,98};
	int B[11]={13,11,12,6,8,9,7,14,15,16,18};
	int C[5]={2,1,4,3,100};
	
	printf("Longest consecutive number is %d \n",search(A));
	printf("Longest consecutive number is %d \n",search(B));
	printf("Longest consecutive number is %d \n",search(C));
	return 0;
}
