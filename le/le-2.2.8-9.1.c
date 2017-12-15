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
list  swaptwo(list swap){
	list head=(list)malloc(sizeof(listnode));
        if(NULL==head) return NULL;
        head->value=-1;
        head->next=swap;
	list wait=head;
        list slow=head->next;
        list fast=head->next->next;
        while(NULL!=fast){
		slow->next=fast->next;
		fast->next=slow;
		wait->next=fast;
		wait=wait->next->next;
		slow=wait->next;
		fast=NULL==slow?NULL:slow->next;

	}
	wait=head->next;
	while(NULL!=wait){
		printf("%d ",wait->value);
		wait=wait->next;
	}
	printf("\n");
	return head->next;
}
void swaplink(list head,int k){
	
	list prev=head->next;
	list cur=head->next->next;
	k--;	
	while(k--){
	prev->next=cur->next;
	cur->next=head->next;
	head->next=cur;
	cur=prev->next;	
	}
	return ;
}
list  swapkth(list swap,int target){
	list head=(list)malloc(sizeof(listnode));
        if(NULL==head) return NULL;
        head->value=-1;
        head->next=swap;
	int cnt=0;
	list tail=head->next;
	while(NULL!=tail){
		tail=tail->next;
		cnt++;
	}
	cnt/=target;
	list wait=head;
	while(cnt){
		swaplink(wait,target);
		for(int i=0;i<target;i++){
			wait=wait->next;
		}
		cnt--;
	}
	wait=head->next;
	while(NULL!=wait){
		printf("%d ",wait->value);
		wait=wait->next;
	}
	printf("\n");
	return NULL;


}
int main(int argc,int **argv){
	int n,i;
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
	printf("Which quantity you wanna swap :\nInput:");
	fflush(stdin);
	scanf("%d",&target);
	/*first swap two elements of the list */
	alist=swaptwo(alist);
	/*then swap kth of the list */
	swapkth(alist,target);
	free(A);
	A=NULL;
	return 0; 
}



