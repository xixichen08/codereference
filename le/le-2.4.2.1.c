#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 100
#define STACK_INCREAMENT 10
#define max(a,b) ((a)>(b)?(a):(b)) 
/*Define the element character */
#define element int
char Numbers[101]={};
typedef struct node{
	element *top;
	element *base;
	int cnt;
	int stacksize;
}stack;
void initstack(stack* s){
	s->base=(element*)malloc(STACK_SIZE*sizeof(element));
	if(NULL==s->base){
		printf("No memory for stack!\n");
		return ;
	}
	s->top=s->base;
	s->stacksize=STACK_SIZE;
	s->cnt=0;
	return;
}
void push(stack *s,element value){
	if(s->top-s->base>=s->stacksize){
		s->base=(element*)realloc(s->base,(s->stacksize+STACK_INCREAMENT)*sizeof(element));
		if(NULL==s->base){
			printf("No memory for stack increament !\n");
			return ;
		}
		s->top=s->base+s->stacksize;
		s->stacksize+=STACK_INCREAMENT;

	}
	*s->top=value;
	++s->top;
	return ;
}
element pop(stack *s){
	if(s->top==s->base) return 0;
	--s->top;
	return *s->top;

}
int length(stack *s){
	return (s->top-s->base);
}
void clear(stack *s){
	s->top=s->base;
	return ;
}
int isempty(stack *s){
	if(s->top==s->base) return 1;
	return 0;

}
void destroy(stack *s){
	s->top=s->base;
	s->stacksize=0;
	free(s->base);
	s->base=NULL;
	return ;
}
element gettop(stack *s){
	element temp;
	temp=*(s->top-1);
	return temp;

}
int longestvalid(stack *s,char* A){
	int i,j,last=-1;
	int res=0;
	for(i=0;i<strlen(A);i++){
		if(A[i]=='('){
			push(s,i);
		}
		else if(A[i]==')'){
			if(isempty(s)){
				last=i;
			}
			else{
				pop(s);
				if(isempty(s)){
					res=max(res,i-last);
				}
				else{
					res=max(res,i-gettop(s));
	
				}

			}

		}
		else{
			printf("Wrong Char!\n");
			return 0;
		}

	}
	printf("The max length is %d\n",res);
	
	return res;
}
int main(int argc,int **argv){
	int i;
	stack s;
//	int temp;
//	printf("The length of stack is %lu ,%lu \n",sizeof(stack),sizeof(struct node));	
	initstack(&s);
	printf("Please input the char:\n");
	scanf("%s",Numbers);
//	printf("The string is %s,strlen is %lu\n",Numbers,strlen(Numbers));
	for(i=0;i<strlen(Numbers);i++){
		push(&s,Numbers[i]);
	}
	while(!isempty(&s)){
		printf("%c ",pop(&s));
	}
	printf("\n");
	printf("The string is %s\n",Numbers);
	longestvalid(&s,Numbers);
/*	for(i=0;i<temp;i++){
		printf("%c ",Numbers[i]);
	}*/
//	printf("\n");
//	printf("The longest valid is %d\n",temp);
//	printf("The longest string is %s,the size is %lu \n",temp,sizeof(temp));
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
