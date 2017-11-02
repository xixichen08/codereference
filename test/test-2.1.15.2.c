#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 100
#define STACK_INCREAMENT 10
int A[101]={};
int Numbers[101]={};
int n;
typedef struct node{
	int *top;
	int *base;
	int stacksize;
}stack;
int stackinit(stack *s){
	s->base=(int*)malloc(STACK_SIZE*sizeof(int));
	if(NULL==s->base) {
		printf("No memory for stack! \n");
		return 0;
	}
	s->top=s->base;
	
	s->stacksize=STACK_SIZE;
	printf("The s.base is %p ,The s.stacksize is %d \n",s->base,s->stacksize);
	return 0;

}
int push(stack *s,int value){
	
	if(s->top-s->base>=s->stacksize) {
		s->base=(int*)realloc(s->base,(s->stacksize+STACK_INCREAMENT)*sizeof(int));
		if(NULL==s->base){
			printf("No memory for stack increament!\n");
			return 0;
		}
		s->top=s->base+s->stacksize;
		s->stacksize+=STACK_INCREAMENT;

	}
//	printf("Push total %d number !\n",n);
	*(s->top)=value;
	s->top++;

	return 0;	
	
}	
int pop(stack *s){
	int res;
	if(s->top==s->base){
		res=*s->top;
		*s->top=0;
//		printf("All element pop out !\n");
		return res;
	}
	
	res=*s->top;
	s->top--;
	return res;
}
int destroy(stack *s){
	
	s->top=s->base;
	free(s->base);
	s->base=NULL;
	s->stacksize=0;
	return 0;
}
int isempty(stack *s ){
	if(s->top==s->base){
		return 1;
	}
	return 0;
}
int tranverse(stack *s ){
	int *temp;
	s->top--;
	temp=s->top;
	while(temp!=s->base){
		printf("%d ",*temp);
		temp--;
	}
	printf("%d \n",*s->base);
	return 0;

}
int gettop(stack *s){
	if(s->base==s->top) return 0;
	return *(--s->top);
}
int stacklength(stack *s){
	return (s->top-s->base+1);
}
int clearstack(stack *s){
	s->top=s->base;
	return 0;
}
int main(int argc,int **argv){
	int i;
	stack s;
//	printf("The length of stack is %lu \n",sizeof(s));	
	stackinit(&s);
	printf("Please input the number :\n");
	scanf("%d",&n);
	printf("Please input the array:\n");
	for(i=0;i<n;i++){
		scanf("%d",&Numbers[i]);
	}
	for(i=0;i<n;i++){
		push(&s,Numbers[i]);

	}
	tranverse(&s);
		printf("The %d number is %d\n",i,pop(&s));
	}
	clearstack(&s);
	printf("After clear the top is %d \n",gettop(&s));
	destroy(&s);
	return 0;
}
