#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 1000
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
char* insertbegin(char* tmp,char*a){
	char *new=(char*)malloc(sizeof(char)*(strlen(tmp)+strlen(a)));
	if(NULL==new) return NULL;
	int i,cnt=0;
	for(i=0;i<strlen(tmp);i++){
		new[i]=tmp[i];
	}
	for(i=0;i<strlen(a)-1;i++){
		new[i+strlen(tmp)]=a[i];
	}
	printf("string is %s \n",new);
	return new;
}
int addtwo(char* first ,char* second){
	char *a,*b;
	int m,n;
	if(strlen(first)>strlen(second)){
		a=first;
		b=second;
		n=strlen(first);
		m=strlen(second);
	}else{
		b=first;
		a=second;
		n=strlen(second);
		m=strlen(first);
	}
	char cnt='0';
	int na,nb;
	for(int i=n-2,j=m-2;i>=0;i--,j--){
		if(((j>=0?b[j]:'0')=='0'&&a[i]=='0')||((j>=0?b[j]:'0')=='1'&&a[i]=='1')){
			a[i]=cnt;
			cnt=(j>=0?b[j]:'0');
		}else if(((j>=0?b[j]:'0')=='0'&&a[i]=='1')||((j>=0?b[j]:'0')=='1'&&a[i]=='0')){
			a[i]=cnt=='1'?'0':'1';

		}

	}
	char* tmp=(char*)malloc(sizeof(char));
	tmp[0]='1';
	if(cnt=='1') {
		a=insertbegin(tmp,a);
	}
	printf("String is %s \n",a);
	return 0;
}
int main (int argc,char **argv){
	char *mother=(char*)malloc(sizeof(char)*MAXCHAR);
	char *son=(char*)malloc(sizeof(char)*MAXCHAR);
	mother[0]=1;
	son[0]='1';
	printf("%s,%s",mother,son);
	if(NULL==mother||NULL==son) return 0;
	printf("Please input the first string:\nInput:");
	fflush(stdin);
	fgets(mother,MAXCHAR,stdin);
	printf("Please input the second string:\nInput:");
	fflush(stdin);
	fgets(son,MAXCHAR,stdin);
	/*the realise of the strStr()*/
	addtwo(mother,son);
	free(mother);
	mother=NULL;
	free(son);
	son=NULL;
	return 0;
	


}
