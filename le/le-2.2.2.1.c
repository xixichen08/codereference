#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define arraysize(a) (int)(sizeof(a)/sizeof(a[0])) 
typedef struct list_node *list;
typedef struct list_node{
	int value;
	list next;
}listnode;
list listinit(int *A,int n){
	int i;
	list head=(list)malloc(sizeof(listnode));
	if(NULL==head) return NULL;
	head->value=-1;
	head->next=NULL;
	list initlist=(list)malloc(sizeof(listnode)*n);
	if(NULL==initlist) return NULL;
	for(i=0;i<n;i++){
		initlist[i].value=A[i];
		initlist[i].next=NULL;
	}
	list tail;
	tail=head;
	for(i=0;i<n;i++){
		tail->next=&initlist[i];
		tail=&initlist[i];
	}
	printf("List created !\n");
	tail=head;
	while(NULL!=tail->next){
		printf("%d ",tail->next->value);
		tail=tail->next;
	}
	printf("\n");
	return head->next;
}
void freelist(list head){
	list tmp;
	tmp=head;
	if(NULL==head) return ;
	if(NULL!=head->next){
		tmp=head;
		head=head->next;
		free(tmp);
	}
	free(head);
	return ;
}
list reverselist(int *A,int length ,int m,int n){
	int i;
	list head=(list)malloc(sizeof(listnode));
	if(NULL==head) return NULL;
	head->value=-1;
	printf("Array size is %d \n",length);
	head->next=listinit(A,length);
	list tail=head;
	for(i=0;i<m;i++){
		tail=tail->next;
	}
	list const head2=tail;
	/*two elements that will reverse and the one is prev and the other is cur*/
	list prev=head2->next;
	list cur=prev->next;
	/*
		1, set prev->next,list cur->next to it ;
		2, set cur to head2->next;
		3, set prev to cur->next;
		4, give a new cur to cur it is prev->next;
	*/
	/*m-n-1 times */
	for(i=m;i<n;i++){
		prev->next=cur->next;
		cur->next=head2->next;
		head2->next=cur;
		cur=prev->next;
		tail=head->next;
		while(NULL!=tail){
			printf("%d ",tail->value);
			tail=tail->next;
		}
		printf("\n");
	}
	tail=head->next;
	while(NULL!=tail){
		printf("%d ",tail->value);
		tail=tail->next;
	}
	printf("\n");
	return head->next;

}	
int main(int argc,int **argv){
	int n,m,i;
	int left,right;
	int *A;
	printf("Please input the list length:\n");
	scanf("%d",&n);
	A=(int*)malloc(sizeof(int)*n);
	if(NULL==A) return 0;
	printf("Please input the list elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}		
	printf("Please input the left index to reverse:\n");
	scanf("%d",&left);
	printf("Please input the right index to reverse:\n");
	scanf("%d",&right);
	reverselist(A,n,left,right);
	free(A);
	A=NULL;
	return 0; 
}




