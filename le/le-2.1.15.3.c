#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define STACK_SIZE 100
#define STACK_INCREAMENT 10
int n,A[101]={};
typedef struct stackelement{
	int value;
	int index;
}element;
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
	for(int i=0;i<STACK_SIZE;i++){
		s->base[i].value=0;
		s->base[i].index=-1;
	}
	return ;
}
void push(stack *s,int value,int index){
	element tmp;
	if(s->top-s->base>=s->stacksize){
		s->base=(element*)realloc(s->base,(s->stacksize+STACK_INCREAMENT)*sizeof(element));
		if(NULL==s->base){
			printf("No memory for stack increament!\n");
			return ;
		}
		s->top=s->base;
		s->stacksize+=STACK_INCREAMENT;
		
	}
	tmp.value=value;	
	tmp.index=index;
	*s->top=tmp;
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
	int value ,index=0;
	if(n<3) return 0;
	for(i=0;i<n;i++){
		while(!isempty(s)){
			tmp=top(s);
			/*This is interesting ,because i-tmp.index-1,means B[i] need two number to decide 
			   the next number's water!while the B[i]<tmp.value,that means i-tmp.index-1=0,and i will 
			push the number to the stack .while B[i]>tmp.value ,i will set the value to value and pop
			then another min(top(s),B[i]) to decide the water next to the B[i],add it to res!quite nice
			*/
			res+=(min(B[i],tmp->value)-value)*(i-tmp->index-1);
			value=tmp->value;
			if(B[i]>tmp->value){
				pop(s);			
			}else{
				break;
			}
		}		
		push(s,B[i],i);
	}
	return res;

}
int main(int argc,int **argv){
	int i;
	stack s;
	stackinit(&s);
	printf("Please input the number of the array: \n");
	scanf("%d",&n);
/*	printf("Please input the k number :\n");
	scanf("%d",&target);*/
	printf("Please input the array :\n");
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
/*	fastsort(1,n);
	printf("The sorted array is :\n");
	for(i=1;i<=n;i++){
		printf("%d ",A[i]);

	}	
	printf("\n");*/
	printf("The area is %d \n",area(&s,A,n));
/*	while((i=permutation(&A[1],n,target))){
		if(i==2){
			printf("Kth array is found!\n");
			return 0;	
		}
		
	}*/
	destroy(&s);
//	printf("The permutation_nr is %d\n",permutation_nr);
	return 0;		
}
