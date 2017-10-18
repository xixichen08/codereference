#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100
int readfile(const char *filename,char *dest,int maxlen){
	FILE *file;
	int pos,temp;
	file=fopen(filename,"r");
	if(NULL==file){
		fprintf(stderr,"open %s error! \n",filename);
		return -1;
	}
	pos=0;
	for(int i=0;i<maxlen-1;i++){
		temp=fgetc(file);
		if(EOF==temp) break;
		dest[pos++]=temp;		
	}
	fclose(file);
//	dest[pos]=0;	
	return pos;

}
int main(int argc,char **argv){
	if(argc!=2){
	fprintf(stderr,"Using ./le-2.1.1 <filename> \n");
	return -1;
	}
	char buffer[MAXLEN];
	int len=readfile(argv[1],buffer,MAXLEN);
	
//	char *p;
	printf("The string is \n %s \n",buffer);
	printf("The strlen is %d \n",len);
	printf("Now is the puts function!\n");
	puts(buffer);
	return 0;
//	int n;
//	int m=0;

/*	p=malloc(sizeof(p));
	gets(p);
	puts(p);
	printf("This is the number you put !\n");
	free(p);
	return 0;
*/
}

