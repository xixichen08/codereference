#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 1000
#define max(a,b) ((a)>(b)?(a):(b))
int isan(char c){
	if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>=0&&c<=9)) return 1;
	return 0;

}
int toma(char c){
	if(c>='A'&&c<='Z') return 'a'+c-'A';
	return c;

}
int ispalindrome(char* c){
	if(NULL==c) {
		printf("Is palindrome!\n");
		return 1;
	}
	int n=strlen(c);
	for(int i=0,j=n-1;j>i;){	
			if(!isan(c[j])){
				j--;
				continue;
			}
			if(!isan(c[i])){
				i++;
				continue;
			}
			if(toma(c[i])==toma(c[j])){
				i++;
				j--;
	
			}else {
				printf("No palindrome !\n");
				return 0;
			}			
	
	}
	printf("Is palindrome!\n");
	return 1;
}
int main (int argc,char **argv){
	char *palin=(char*)malloc(sizeof(char)*MAXCHAR);
	if(NULL==palin) return 0;
	printf("Please input the string:\nInput:");
	fflush(stdin);
	fgets(palin,MAXCHAR,stdin);
	ispalindrome(palin);
	free(palin);
	palin=NULL;
	return 0;
	


}
