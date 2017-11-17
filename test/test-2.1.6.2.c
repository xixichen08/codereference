#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define PRIM 271
#define max(a,b) ((a)>(b)?(a):(b))
int n;
typedef struct hash* hashnode;
typedef struct hash{
	hashnode next;
	int value;
	int index;
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
int hashsearch(int *A,int n){
	int i,j,res,cnt,maxres=0;
	/*Creat hashlist*/
	hashnode hash=(hashnode)malloc(sizeof(hashlist)*PRIM);
	if(NULL==hash) return 0;
	/*Init hashlist*/
	for(i=0;i<PRIM;i++){
		hash[i].value=-1;
		hash[i].index=-1;
		hash[i].next=NULL;
	}
	hashnode tail;
	/*Set number to hashlist */
	for(i=0;i<n;i++){
		res=abs(A[i]%PRIM);
		if(hash[res].index==-1){
			hash[res].index=i;
			hash[res].value=A[i];
		}
		else{
			tail=&hash[res];
			while(NULL!=tail->next){
				tail=tail->next;
			}
			
			hashnode newnode=(hashnode)malloc(sizeof(hashlist));
			if(NULL==newnode) return -1;
			newnode->index=i;
			newnode->value=A[i];
			newnode->next=NULL;
			tail->next=newnode;
			
		}
	}
	int nr;
	hashnode tmp;
	cnt=1;
	/*Search the longest concecutive*/
	for(i=0;i<n;i++){
		nr=A[i]-1;
		res=abs(nr%PRIM);
		tmp=&hash[res];
		while(tmp->index!=-1){
			while(NULL!=tmp->next&&tmp->value!=nr){
				tmp=tmp->next;
			}
			if(tmp->value==nr){
				nr--;
				cnt++;
				res=abs(nr%PRIM);
				tmp=&hash[res];	
			}
			else break;
		}
		nr=A[i]+1;
		res=abs(nr%PRIM);
		tmp=&hash[res];
		while(tmp->index!=-1){
			while(NULL!=tmp->next&&tmp->value!=nr){
				tmp=tmp->next;
			}
			if(tmp->value==nr){
				nr++;
				cnt++;
				res=abs(nr%PRIM);
				tmp=&hash[res];	
			}
			else break;
		}
		maxres=max(maxres,cnt);
		cnt=1;		
	}
	if(NULL!=hash) freehash(hash,PRIM);
	printf("The longest concecutive is %d\n",maxres);
	return maxres;
}
int main(int argc,char **argv){
	int *Number,maxres=0;
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
	maxres=hashsearch(Number,n);
	printf("The longest is :%d\n",maxres);
	free(Number);
	Number=NULL;
	return 0;
}
