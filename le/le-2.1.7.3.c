#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define PRIM 271
#define max(a,b) ((a)>(b)?(a):(b))
int n,target;
int A[101]={};
typedef struct node *hashnode;
typedef struct node{
	hashnode next;
	int index;
}listhash;

void freehash(hashnode hashtable,int hashnumber){	
	for(int i=0;i<hashnumber;++i){
		hashnode tail=hashtable[i].next;
		while(NULL!=tail){
			hashnode temp=tail;
			tail=tail->next;
			free(temp);

		}
	
	}
	free(hashtable);

}

int hashsearch(int *B,int n){
	/*Creat a hashtable*/
	int hashnumber=PRIM;
	hashnode hashtable =(hashnode)malloc(sizeof(listhash)*hashnumber);
	if(NULL==hashtable){
		printf("No memory for the hashtable!\n");
		return 0;
	}
	/*Init the hashtable */
	for (int i=0;i<hashnumber;++i){
		hashtable[i].index=-1;
		hashtable[i].next=NULL;		

	}
	/*Assign the array into the hashtable */
	int tdex;
	for(int j=0;j<n;j++){
		tdex=abs(B[j]%hashnumber);
		if(-1==hashtable[tdex].index){
			hashtable[tdex].index=j;
		}
		else{
			hashnode tail=hashtable[tdex].next;
			tail=(hashnode)malloc(sizeof(listhash));
			if(NULL==tail){
				printf("No memory for the hashlist!\n");
				freehash(hashtable,hashnumber);
				return 0;
			}
			tail->index=j;
			tail->next=hashtable[tdex].next;
			hashtable[tdex].next=tail;
		}

	}
	/*Search the target*/
	int Index[2]={};
	for(int k=0;k<n;k++){
		int hdex=abs((target-B[k])%hashnumber);
		if(-1==hashtable[hdex].index){
			continue;
		}
		if((-1!=hashtable[hdex].index)&&(hashtable[abs(B[k]%hashnumber)].index!=hashtable[hdex].index)){
			Index[0]=hashtable[hdex].index+1;
			Index[1]=hashtable[abs(B[k]%hashnumber)].index+1;
			printf("The index is %d, %d\n",Index[0],Index[1]);
			if(NULL!=hashtable){
			freehash(hashtable,hashnumber);}
			return 0;
		}
		else{
			while (NULL!=hashtable[hdex].next){
				Index[0]=hashtable[hdex].next->index+1;
				Index[1]=hashtable[abs(B[k]%hashnumber)].index+1;
				printf("The index is %d ,%d \n ",Index[0],Index[1]);
				if(NULL!=hashtable){
				freehash(hashtable,hashnumber);
				}
				return 0;
			}
		}
	}
	if(NULL!=hashtable){
	freehash(hashtable,hashnumber);
	}
	printf("NO index match!");
	return 0;
}

int main(int argc,char **argv){
	printf("The sizeof listhash is %lu,the sizeof hashnode is %lu\n",sizeof(listhash),sizeof(hashnode));
	printf("Please input the number of the array :\n");
	scanf("%d",&n);
	printf("Please input the target :\n");
	scanf("%d",&target);
	printf("Please input the array :\n");
	for (int i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	hashsearch(&A[1],n);


}
