#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
typedef struct list_node* list;
typedef struct list_node{
	int value;
	list next;
}listnode;
list listinit(int* A,int n){
	int i;
	/*Create list*/
	list head=(list)malloc(sizeof(listnode));
	if(NULL==head) return NULL;
	head->value=-1;
	head->next=NULL;
	/*Init list*/
	list tail=head;
	for(i=0;i<n;i++){
		list newlist=(list)malloc(sizeof(listnode));
		if(NULL==newlist) return NULL;
		newlist->value=A[i];
		newlist->next=NULL;
		tail->next=newlist;
		tail=newlist;
	}
	printf("List created !\n");
	tail=head->next;
	while(NULL!=tail){
		printf("%d ",tail->value);
		tail=tail->next;
	}
	printf("\n");
	return head->next;
}
void freelist(list head){
	list tmp;
	while(NULL!=head->next){
		tmp=head;
		head=head->next;
		free(tmp);

	}
	free(head);
	return ;
}
int creatcircle(list circle,int target){
	if(target==0) return 0;
	list head=(list)malloc(sizeof(listnode));
	if(NULL==head) return 0;
	head->value=-1;
	head->next=circle;
	list tail=head;
	list breaknode=head;
	while(NULL!=tail->next){
		tail=tail->next;

	}
	for(int i=0;i<target;i++){
		breaknode=breaknode->next;
	}
	tail->next=breaknode;
	return 1;

}
int  iscircle(list circle){
	list head=(list)malloc(sizeof(listnode));
	if(NULL==head) return 0;
	head->value=-1;
	head->next=circle;
	list slow=head->next;
	list fast=head->next;
	while(NULL!=fast->next){
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow){
			printf("Is circle!\n");
			return 1;
		}
	}
	printf("Not a circle!\n");
	return 0;
		
}	
list findbeginner(list circle){
	if(!iscircle(circle)) return NULL;
	list head=(list)malloc(sizeof(listnode));
	if(NULL==head) return 0;
	head->value=-1;
	head->next=circle;
	list slow=head->next;
	list fast=head->next;
	list beginner=head->next;
	while(NULL!=fast->next){
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow){
			while(slow!=beginner){
				slow=slow->next;
				beginner=beginner->next;

			}
			printf("Beginner %d is found !\n",beginner->value);
			return beginner;
			
		}
	}
	printf("Fatal error !\n");
	return NULL;


}
int main(int argc,int **argv){
	int n,m,i;
	int target;
	int *A;
	printf("Please input the list length:\n");
	scanf("%d",&n);
	A=(int*)malloc(sizeof(int)*n);
	if(NULL==A) return 0;
	printf("Please input the list elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}		
	list alist=listinit(A,n);
	printf("Which element is the circle beginner:\nInput:");
	fflush(stdin);
	scanf("%d",&target);
	/*creat a circle while input 0 means no circle*/
	creatcircle(alist,target);
	/*decide whether is a circle*/
	iscircle(alist);
	/*find the beginner of the circle*/
	findbeginner(alist);
	free(A);
	A=NULL;
	return 0; 
}



