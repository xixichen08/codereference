#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define PRIM 271
#define max(a,b) ((a)>(b)?(a):(b))
int Number[101]={};
int n;
typedef struct node *hashnode;
typedef struct node{
	int value;
	int used;
	hashnode next;
}listhash;
int maxres=0;
void freehash(hashnode hashtable,int hashnumber){
	for(int i=0;i<hashnumber;i++){
		
		while(NULL!=hashtable[i].next){
			hashnode temp=hashtable[i].next;
			hashtable[i].next=temp->next;
			free(temp);
			
		}

	}
	free(hashtable);

}
int indexused(hashnode hashtable,int value,int hashnumber){
	hashnode head;
	int bias=abs(value%hashnumber);
	head=&hashtable[bias];
	while(NULL!=head){
		if(head->value==value){
			if(head->used==0) {
				head->used=1;
				return 1;
			}
			return 2;
		}else{
			head=head->next;
		}
	}
	return 0;
}
int hashsearch(int *A,int n){
	if(n<2) return 0;
	/*Create hashtable*/
	int hashnumber=PRIM;
	hashnode hashtable=(hashnode)malloc(sizeof(listhash)*hashnumber);
	if(NULL==hashtable){
		printf("No memory for hashtable\n");
		return 0;
	}
	/*Init hashtable*/
	for(int i=0;i<hashnumber;i++){
		hashtable[i].value=-1;
		hashtable[i].used=0;
		hashtable[i].next=NULL;

	}
	/*Assign array to the hashtable */
	hashnode tail;
	for(int j=0;j<n;j++){
		int bias=abs(A[j]%hashnumber);
		if(-1==hashtable[bias].value){
			hashtable[bias].value=A[j];
			tail=&hashtable[bias];	
		}else{
			hashnode temp=tail->next;
			temp=(hashnode)malloc(sizeof(listhash));
			if(NULL==temp){
				printf("No memory for hashlist\n");
				freehash(hashtable,hashnumber);
				return 0;
			}
			temp->value=A[j];
			tail->next=temp;
			tail=temp;
			
		}
	}
	/*Find the longest sequence*/
	int longest=1;
	int h;
	for(int k=0;k<n;k++){
		
		if(indexused(hashtable,A[k],hashnumber)==2){
			continue;
		}
			
//		printf("Now it will find the concecutive number!\n");		

		for(h=A[k]+1;indexused(hashtable,h,hashnumber)!=0;h++){
			longest++;
			
		}
		for(h=A[k]-1;indexused(hashtable,h,hashnumber)!=0;h--){
			longest++;
		}
		maxres=max(maxres,longest);
		longest=0;

	}
	if(NULL!=hashtable){
		freehash(hashtable,hashnumber);
	}
	return maxres;
}
int main(int argc,char **argv){
	printf("Please input the number of the array :\n");
	scanf("%d",&n);
	printf("Please input the array:\n");
	for(int i=1;i<=n;i++){
		scanf("%d",&Number[i]);

	}
	hashsearch(&Number[1],n);
	printf("The longest is :%d\n",maxres);
	return 0;
}
