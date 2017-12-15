#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 1000
#define max(a,b) ((a)>(b)?(a):(b))
int strStr(char* mother ,char* son){
	int n=strlen(mother);
	int m=strlen(son);
	int cnt=0;
	for(int i=0;i<=n-m;i++){
		for(int j=0;j<m-1;j++){
			if(mother[i+j]!=son[j]) {
				cnt=0;
				break;
			}else cnt++;
		}
		if(cnt==m-1){
			printf("Is son str!\n");
			return 1;
		}else{
			cnt=0;
		}
		
	}
	printf("No son str!\n");
	return 0;
}
int main (int argc,char **argv){
	char *mother=(char*)malloc(sizeof(char)*MAXCHAR);
	char *son=(char*)malloc(sizeof(char)*MAXCHAR);
	if(NULL==mother||NULL==son) return 0;
	printf("Please input the mother string:\nInput:");
	fflush(stdin);
	fgets(mother,MAXCHAR,stdin);
	printf("Please input the son string:\nInput:");
	fflush(stdin);
	fgets(son,MAXCHAR,stdin);
	/*the realise of the strStr()*/
	strStr(mother,son);
	free(mother);
	mother=NULL;
	free(son);
	son=NULL;
	return 0;
	


}
