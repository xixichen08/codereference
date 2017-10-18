#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc ,char **argv){
        int i=3;
	int *p,m=2;
	int *q,n=1;
	p=&m;
	q=&n;
	printf("Show the adress of p\n %p \n Show the number:%d\n",p,*p);
//	*q=*p;
	printf("Show the adress of q\n %p \n Show the number:%d\n",q,*q);
        if((--i)==2) printf("First cut down then compare\n");
        else printf("First compare then cut down\n");
	
        return 0;


}

