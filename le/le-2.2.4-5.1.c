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
list removedupli(int *A,int n){
	list head=(list)malloc(sizeof(listnode));
	if(NULL==head) return NULL;
	head->value=-1;
	head->next=listinit(A,n);
	list prev=head->next;
	while(NULL!=prev->next){
		if(prev->value==prev->next->value){
			list tmp=prev->next;
			prev->next=prev->next->next;
			free(tmp);
		}else{
			prev=prev->next;
		}

	}
	prev=head->next;
	while(NULL!=prev){
		printf("%d ",prev->value);
		prev=prev->next;
	}
	printf("\n");
	return head->next;
}	
list deletedupli(int *A,int n){
	list tmp;
	int flag=0;
	list head=(list)malloc(sizeof(listnode));
	if(NULL==head) return NULL;
	head->value=-1;
	head->next=listinit(A,n);
	list cur=head->next;
	list prev=head;
	while(NULL!=cur->next){
		if(cur->value==cur->next->value){
			tmp=cur->next;
			cur->next=cur->next->next;
			free(tmp);
			flag=1;
		}else{
			if(flag==1){
				tmp=cur;
				prev->next=cur->next;
				cur=cur->next;
				free(tmp);
				flag=0;
			}else{
				cur=cur->next;
				prev=prev->next;
			}
		}

	
	}
	if(flag==1){
		tmp=cur;
		prev->next=NULL;
		free(tmp);
		flag=0;
	}
	prev=head->next;
	while(NULL!=prev){
		printf("%d ",prev->value);
		prev=prev->next;
	}
	printf("\n");
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
//	removedupli(A,n);
	deletedupli(A,n);
	free(A);
	A=NULL;
	return 0; 
}



