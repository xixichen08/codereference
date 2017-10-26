#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PRIM 271
#define max(a,b) ((a)>(b)?(a):(b))
int n,target;
int Numbers[101]={};
typedef struct node *hashnode;
typedef struct node{
	int index;
	hashnode next;
}listhash;
int hashfree(hashnode hashtable ,int hashnumber){
	for(int i=0;i<hashnumber;i++){
		while (NULL!=hashtable[i].next){
			hashnode temp=hashtable[i].next;
			hashtable[i].next=temp->next;
			free(temp);
		}

	}
	free(hashtable);
	return 0;
}
int hashsearch(int *A,int n,int target){
	/*Creat hashtable*/
	if(n<1) return 0;
	int hashnumber=PRIM;
	hashnode hashtable=(hashnode)malloc(sizeof(listhash)*hashnumber);
	while (NULL==hashtable){
		printf("No memory for the hashtable !\n");
		return 0;
	}
	/*Init the hashtable*/
	int index;
	for(index=0;index<hashnumber;index++){
		hashtable[index].index=-1;
		hashtable[index].next=NULL;

	}
	/*Assign the hashtable*/
//	hashnode head[hashnumber];
	hashnode tail;
	for(index=0;index<n;index++){
		int bias=abs(A[index]%hashnumber);
		
		if(-1==hashtable[bias].index){
			hashtable[bias].index=index;
			tail=&hashtable[bias];	
		}else{
			hashnode temp=tail->next;
			while(NULL!=temp){
				tail=temp;
				temp=temp->next;
					
			
			}
			temp=(hashnode)malloc(sizeof(listhash));
			if(NULL==temp){
				printf("No memory for hashlist !\n");
				return 0;
			}
			temp->index=index;
			tail->next=temp;
			tail=temp;
			printf("The head list index is %d,%d\n",A[hashtable[bias].index],A[hashtable[bias].next->index]);
		}
	}
	/*Search the number*/
	int sbias=abs(target%hashnumber);
	hashnode search=&hashtable[sbias];
	printf("The search index is %d\n",A[search->index]);
	while(NULL!=search){
		if(A[search->index]==target) return 1;
		else search=search->next;
	}
	return 0;

}
int main (int argc ,char **argv){
	printf("Please input the number of the array ;\n");
	scanf("%d",&n);
	printf("Please input the target to search:\n");
	scanf("%d",&target);
	printf("Please input the array:\n");
	for(int i=1;i<=n;i++){
		scanf("%d",&Numbers[i]);
	}
        if(hashsearch(&Numbers[1],n,target)){
		printf("Target in the array!\n");	
	}
	else{
		printf("No target \n");
	}
	return 0;
}

