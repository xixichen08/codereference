#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 1000
#define max(a,b) ((a)>(b)?(a):(b))

int longestpalindrome(char* c){
	int i,j;
	int max=1,start=0;
	if(strlen(c)<2){ 
		printf("The length is %lu and the start is %d\n",strlen(c),start);
		return strlen(c);
	}
	int n=strlen(c);
	int **A=(int**)malloc(sizeof(int*)*n);
	if(NULL==A) return 0;
	for(i=0;i<n;i++){
		A[i]=(int*)malloc(sizeof(int)*n);
		if(NULL==A[i]) return 0;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			A[i][j]=0;
		}
	}
	for(i=0;i<n-1;i++){
		A[i][i]=1;
		for(j=i+1;j<n;j++){
			if(j-i==1){
				if(c[i]==c[j]) A[i][j]=1;
				else A[i][j]=0;
			}else if(j-i>1){
				if((c[i]==c[j])&&A[i+1][j-1]) {
					A[i][j]=1;
					if(j-i>max) start=i;
					max=max(j-i,max);
				}
				else A[i][j]=0;
			}
	
		}
	}
	printf("The length is %d and the start is %d \n",max,start);
	return max;
}
int main (int argc,char **argv){
	char *palin=(char*)malloc(sizeof(char)*MAXCHAR);
	if(NULL==palin) return 0;
	printf("Please input the string:\nInput:");
	fflush(stdin);
	fgets(palin,MAXCHAR,stdin);
	longestpalindrome(palin);
	free(palin);
	palin=NULL;
	return 0;
	


}
