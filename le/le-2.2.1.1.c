#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
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
int addtwo(int *A,int n,int *B,int m){
	list lista,listb,head,tail;
	int nr,cnt=0;
	lista=listinit(A,n);
	listb=listinit(B,m);
	head=(list)malloc(sizeof(listnode));	
	if(NULL==head) return 0;
	head->value=-1;
	head->next=NULL;
	tail=head;
	for(;NULL!=lista||NULL!=listb;lista=(lista==NULL?NULL:lista->next),listb=(listb==NULL?NULL:listb->next)){
		nr=((NULL==lista?0:lista->value)+(NULL==listb?0:listb->value)+cnt);
		cnt=nr/10;
		nr%=10;
		list newnode=(list)malloc(sizeof(listnode));
		if(NULL==newnode) return 0;
		newnode->value=nr;
		newnode->next=NULL;
		tail->next=newnode;
		tail=newnode;

	}
	if(cnt){
		list newnode=(list)malloc(sizeof(listnode));
		if(NULL==newnode) return 0;
		newnode->value=1;
		newnode->next=NULL;
		tail->next=newnode;
	}
	tail=head;
	while(NULL!=tail->next){
		printf("%d ",tail->next->value);
		tail=tail->next;
	}
	printf("\n");
	freelist(head);
	return 0;

}	
int main(int argc,int **argv){
	int n,m,i,j;
	int *A,*B;
	printf("Please input the 1st number:\n");
	scanf("%d",&n);
	A=(int*)malloc(sizeof(int)*n);
	if(NULL==A) return 0;
	printf("Please input the A:\n");
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}	
	printf("Please input the 2st number:\n");
	scanf("%d",&m);
	B=(int*)malloc(sizeof(int)*m);
	if(NULL==B) return 0;
	printf("Please input the B:\n");
	for(i=0;i<m;i++){
		scanf("%d",&B[i]);
	}
	addtwo(A,n,B,m);
	free(A);
	free(B);
	A=NULL;
	B=NULL;
	return 0; 
}
