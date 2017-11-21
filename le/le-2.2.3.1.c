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
list partition(int *A,int n,int target){
	list leftlist,rightlist,head;
	head=listinit(A,n);
	leftlist=(list)malloc(sizeof(listnode));
	if(NULL==leftlist) return NULL;
	rightlist=(list)malloc(sizeof(listnode));
	if(NULL==rightlist) return NULL;
	leftlist->value=-1;
	leftlist->next=NULL;
	rightlist->value=-1;
	rightlist->next=NULL;
	list tail=head;
	list lefttail=leftlist;
	list righttail=rightlist;
	while(NULL!=tail){
		if(tail->value<target){
			lefttail->next=tail;
			lefttail=tail;

		}else{
			righttail->next=tail;
			righttail=tail;

		}
		tail=tail->next;
	}
	lefttail->next=rightlist->next;
	lefttail=leftlist->next;
	while(NULL!=lefttail){
		printf("%d ",lefttail->value);
		lefttail=lefttail->next;
	}
	printf("\n");
	return leftlist->next;

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
	printf("Please input the partition target:\n");
	scanf("%d",&target);
	partition(A,n,target);
	free(A);
	A=NULL;
	return 0; 
}



