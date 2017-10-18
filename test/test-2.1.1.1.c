#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc ,char **argv){
        int i=3;
        if((--i)==2) printf("First cut down then compare\n");
        else printf("First compare then cut down\n");
        return 0;


}

