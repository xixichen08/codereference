#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define STACK_SIZE 100
#define STACK_INCREAMENT 10
typedef struct stack_element{
	int value;
	int index;
}element;
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
/*	for(int i=0;i<s->stacksize;i++){
		
	}*/
	return ;
}
void push(stack *s,int value,int index){
	element *tmp;
	if(s->top-s->base>=s->stacksize){
		s->base=(element*)realloc(s->base,(s->stacksize+STACK_INCREAMENT)*sizeof(element));
		if(NULL==s->base){
			printf("No memory for stack increament!\n");
			return ;
		}
		s->top=s->base;
		s->stacksize+=STACK_INCREAMENT;
		
	}
	tmp=s->top;
	tmp->value=value;
	tmp->index=index;
	s->top++;
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
	int value=0;
	push(s,0,-1);
	for(i=0;i<=n;i++){
		tmp=top(s);
		if(i==n) value=-1;
		else value=B[i];
		if(NULL!=tmp){
			if(value>=tmp->value){
				push(s,value,i);
			}
			while(value<tmp->value){
				res=max(res,(tmp->value)*(i-tmp->index));
				tmp=top(s);
				pop(s);
				if(top(s)->index==-1) {
					res=max(res,(tmp->value)*i);
					break;
				}
			}
			push(s,value,i);
		}
		else push(s,value,i);
	}
//	printf("The max is %d\n",res);
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
