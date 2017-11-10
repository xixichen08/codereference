#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 100
#define STACK_INCREAMENT 10
#define max(a,b) ((a)>(b)?(a):(b)) 
char Numbers[101]={};
/*Define the element character */
int longestvalid(int n,char* A){
	int i,j,res=0;
	int *DP;
	DP=(int*)malloc(n*sizeof(int));
	if(NULL==DP){
		printf("No memory for DP!\n");
		return 0;
	}
	for(i=0;i<n;i++){
		DP[i]=0;
	}
	for(i=1;i<n;i++){
		if(A[i]==')'){
			if(A[i-1-DP[i-1]]=='('){
				DP[i]=DP[i-1]+2;//This is for the ((())) model
			}
			DP[i]+=DP[i-DP[i]];//This is for the extra ()((()))
			res=max(res,DP[i]);

		}

	}
	free(DP);
	DP=NULL;
	printf("The longest valid is %d \n",res);
	return res;
}
int main(int argc,int **argv){
	int i;
	printf("Please input the char:\n");
	scanf("%s",Numbers);
//	printf("The string is %s,strlen is %lu\n",Numbers,strlen(Numbers));
	longestvalid(strlen(Numbers),Numbers);
	return 0;
}
