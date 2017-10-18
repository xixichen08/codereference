#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100
int readfile(const char *filename ,char *buffer,int maxlen){
	FILE *file;
	int temp,pos;
	file=fopen(filename,"r");
	if(NULL==file){
		fprintf(stderr,"Can not open the file  \n");
		return -1;
	}
	pos=0;
	for(int i=0;i<maxlen-1;i++){
		temp=fgetc(file);
		if(EOF==temp) break;
		buffer[pos++]=temp;
	}
	fclose(file);
	return pos;
}
int main(int argc,char**argv){
	if(argc!=2){
		fprintf(stderr,"Using ./le-2.1.1 <filename>\n");
		return -1;
	}
	char buffer[MAXLEN];
	int len = readfile(argv[1],buffer,MAXLEN);
	printf("The buffer is\n %d \n",buffer[0]);
	printf("The strlen is %d \n",len);
	return 0;
}
