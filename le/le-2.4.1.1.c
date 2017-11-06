#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 100
#define STACK_INCREAMENT 10
/*Define the element character */
#define element char
int n,target;

int A[101]={};
element Numbers[101]={};

typedef struct node {
	element *base;
	element *top;
	int stacksize;

}stack;
void stackinit(stack* s){
	s->base=(element*)malloc(STACK_SIZE*sizeof(element));
	if(NULL==s->base){
		printf("No memory for stack!\n");
		return ;
	}
	s->top=s->base;
	s->stacksize=STACK_SIZE;
	return ;

}
element pop(stack *s){
	if(s->top==s->base) return 0;
	s->top--;
	return *s->top;

}
void push(stack *s ,element target){
	if(s->top-s->base>=STACK_SIZE){
		s->base=(element*)realloc(s->base,(s->stacksize+STACK_INCREAMENT)*sizeof(element));
		if(NULL==s->base) {
			printf("No memory for stack increament !\n");
			return ;
		}
		s->top=s->base+STACK_SIZE;
		s->stacksize+=STACK_INCREAMENT;

	}
	
	*s->top=target;
	s->top++;
	return ;

}
void clear(stack* s){
	s->top=s->base;
	return ;

}
void destroy(stack* s ){
	s->top=s->base;
	s->stacksize=0;
	free(s->base);
	s->base=NULL;
	return ;

}
void tranverse(stack *s ){
	element* temp;
	temp=s->top;
	if(temp==s->base)  return ;
	while(s->base!=temp){
		temp--;
		printf("%c ",*temp);
		
	}
	printf("\n");
	return ;
}	
int isempty(stack *s){
	if(s->top==s->base) return 1;
	return 0;

}
int valid(stack* s, element *A,int n){
	int i,res;
	element temp;
	for(i=0;i<n;i++){
		switch (A[i]){
			case ')':
				temp=pop(s);
				if(temp=='(') break; 
				else return 0;
			case '}':
				temp=pop(s);
				if(temp=='{') break;
				else return 0;
			case ']':
				temp=pop(s);
				if(temp=='[') break;
				else return 0;
			default :
				if(i==n-1) return 0;
				else push(s,A[i]);break;
		}

	}	
/*	for(i=0;i<res;i++){
		printf("%c ",B[i]);

	}
	printf("\n");
*/
	return 1;
}
int main(int argc,int **argv){
	int i;
	stack s;
	printf("The length of stack is %lu ,%lu \n",sizeof(stack),sizeof(struct node));	
	stackinit(&s);
//	printf("Please input the number :\n");
//	scanf("%d",&n);
	printf("Please input the char:\n");
	scanf("%s",Numbers);
	printf("The string is %s,strlen is %lu\n",Numbers,strlen(Numbers));
	for(i=0;i<strlen(Numbers);i++){
		push(&s,Numbers[i]);

	}
	n=(int)strlen(Numbers);
	if(1==valid(&s,Numbers,n)) printf("Valid! \n");
	else printf("Not valid!\n");
/*	tranverse(&s);
	while(0==isempty(&s)){
		printf("%c ",pop(&s));
	}
	printf("\n");*/
	clear(&s);
//	printf("After clear the top is %c \n",gettop(&s));
	destroy(&s);
	return 0;
}
