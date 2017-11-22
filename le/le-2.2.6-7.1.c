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
list kthrotate(int *A,int n ,int k){
	int i,length=1;
	list head=(list)malloc(sizeof(listnode));
	if(NULL==head) return NULL;
	head->value=-1;
	head->next=listinit(A,n);
	list tail=head->next;
	while(NULL!=tail->next){
		tail=tail->next;
		length++;
	}
	tail->next=head->next;
	k%=length;
	length-=k;
	while(length--){
		tail=tail->next;
	}
	head->next=tail->next;
	tail->next=NULL;
	tail=head->next;
	while(NULL!=tail){
		printf("%d ",tail->value);
		tail=tail->next;
	}
	printf("\n");
	return head->next;
}
int nthfromend(int *A,int n,int k){
	int i,cnt=0;
	list head=(list)malloc(sizeof(listnode));
	if(NULL==head) return 0;
	head->value=-1;
	head->next=listinit(A,n);
	list prev=head->next;
	list cur=prev;
	while(NULL!=prev){
		if(cnt!=k){
			prev=prev->next;
			cnt++;
		}else{
			prev=prev->next;
			cur=cur->next;
		}
	}
	printf("The %dth from the end is %d \n",k,cur->value);
	freelist(head);
	return 0;
}	
int main(int argc,int **argv){
	int n,k,i;
	int *A;
	printf("Please input the list length:\n");
	scanf("%d",&n);
	A=(int*)malloc(sizeof(int)*n);
	if(NULL==A) return 0;
	printf("Please input the list elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}		
	printf("Please input the kth from the end:\n");
	scanf("%d",&k);
	//kthrotate(A,n,k);
	nthfromend(A,n,k);
	free(A);
	A=NULL;
	return 0; 
}




