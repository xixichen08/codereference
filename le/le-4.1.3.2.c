#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define STACK_SIZE 100
#define STACK_INCREAMENT 10
#define element int
int n,A[101]={};
typedef struct node {
	element *top;
	element *base;
	int stacksize;
}stack;
void stackinit(stack *s){
	s->base=(element*)malloc(STACK_SIZE*sizeof(element));
	if(NULL==s->base){
		printf("No memory for stack!\n");
		return ;
	}
	s->top=s->base;
	s->stacksize=STACK_SIZE;
	return ;
}
void push(stack *s,int value){
	if(s->top-s->base>=s->stacksize){
		s->base=(element*)realloc(s->base,(s->stacksize+STACK_INCREAMENT)*sizeof(element));
		if(NULL==s->base){
			printf("No memory for stack increament!\n");
			return ;
		}
		s->top=s->base;
		s->stacksize+=STACK_INCREAMENT;
		
	}
	*s->top=value;
	*s->top++;
	return ;
}
element* pop(stack *s){
	if(s->top==s->base){
		return NULL;
	}
	s->top--;
	return s->top;
}
int isempty(stack *s){
	if(s->top==s->base) return 1;
	return 0;
}
void destroy(stack *s){
	s->top=s->base;
	free(s->base);
	s->base=NULL;
	s->stacksize=0;
	return ;
}
element* top(stack *s){
	element* tmp;
	if(s->base==s->top){
		return NULL;	

	}
	tmp=(s->top-1);
	return tmp;
}
int area(stack *s,int *B,int n){
	int i,j,res=0;
	element* tmp;
	return res;

}
int main(int argc,int **argv){
	int i;
	stack s;
	stackinit(&s);
	printf("Please input the number of the array: \n");
	scanf("%d",&n);
	printf("Please input the array :\n");
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	printf("The area is %d \n",area(&s,A,n));
	destroy(&s);
	return 0;		
}
