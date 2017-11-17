#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define PRIM 271
#define max(a,b) ((a)>(b)?(a):(b))
typedef struct node *hashnode;
typedef struct node {
	int index;
	int value;
	hashnode next;
}hashlist;
void freehash(hashnode hash,int hashnumber){
	int i,j;
	hashnode tmp;
	for(i=0;i<hashnumber;i++){
		while (NULL!=hash[i].next){
			tmp=hash[i].next;
			hash[i].next=hash[i].next->next;
			free(tmp);
		}
	}
	free(hash);
	printf("Hash free ok !\n");
	return ;

}
int hashsearch(int *A,int n,int target){
	int i,j;
	/*Creat hashlist*/
	hashnode hash=(hashnode)malloc(sizeof(hashlist)*PRIM);
	if(NULL==hash) return 0;
	/*Init hashlist*/
	for(i=0;i<PRIM;i++){
		hash[i].index=-1;
		hash[i].value=-1;
		hash[i].next=NULL;
	}
	int res;
	hashnode tail;
	/*Set number to hashlist*/
	for(i=0;i<n;i++){
		res=abs(A[i]%PRIM);
		if(hash[res].index==-1){
			hash[res].index=i;
			hash[res].value=A[i];
			hash[res].next=NULL;
		}else{
			tail=&hash[res];
			while (NULL!=tail->next){
				tail=tail->next;
			}
			hashnode newnode=(hashnode)malloc(sizeof(hashlist));
			if(NULL==newnode) return 0;
			newnode->index=i;
			newnode->next=NULL;
			newnode->value=A[i];
			tail->next=newnode;
		}
	}
	hashnode tmp;
	/*Search the target*/
	for(i=0;i<n;i++){
		res=abs(target-A[i])%PRIM;
		if(hash[res].index!=-1){
			tmp=&hash[res];	
			while(tmp->value!=(target-A[i])&&NULL!=tmp->next){
				tmp=tmp->next;
			}
			if(tmp->value==(target-A[i])){
				if(hash ) freehash(hash,PRIM);
				return 1;
			}
		}
	}
	if(NULL!=hash) freehash(hash,PRIM);
	return 0;
}
int main(int argc,char **argv){
	int *Number,res=0;
	int n,target;
	printf("Please input the number of the array :\n");
	scanf("%d",&n);
	Number=(int *)malloc(sizeof(int )*n);
	if(NULL==Number){
		printf("No memory !\n");
		return 0;
	}
	printf("Please input the array:\n");
	for(int i=0;i<n;i++){
		scanf("%d",&Number[i]);

	}
	printf("Please input the target !:\n");
	scanf("%d",&target);
	res=hashsearch(Number,n,target);
	if(res){
		printf("Target is found!\n");
	}else{
		printf("No target !\n");
	}
	free(Number);
	Number=NULL;
	return 0;
}
