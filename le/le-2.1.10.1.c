#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define PRIM 271
int A[101]={};
int n,target;
typedef struct node *hashnode;
typedef struct node{
	int value;
	int a;
	int b;
	hashnode next;
}listhash;
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
int hashsearch(int *B,int n,int target){
	/*Creat a hashtable*/
	int hashnumber=PRIM;
	int i;
	hashnode hashtable=(hashnode)malloc(sizeof(listhash)*hashnumber);
	if(NULL==hashtable){
		printf("No memory for hashtable !\n");
		return 0;
	}
	/*Init the hashtable*/
	for(i=0;i<hashnumber;i++){
		hashtable[i].value=-1;
		hashtable[i].a=-1;
		hashtable[i].b=-1;
		hashtable[i].next=NULL;
	}
	int sum2;
	/*Assign the number to the hashtable*/
	hashnode tail;
	for(i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			sum2=abs((B[i]+B[j])%hashnumber);
			if(hashtable[sum2].a<0){
				hashtable[sum2].value=B[i]+B[j];
				hashtable[sum2].a=i;
				hashtable[sum2].b=j;
				tail=&hashtable[sum2];

			}
			else{
				hashnode temp=tail->next;
				temp=(hashnode)malloc(sizeof(listhash));
				if(NULL==temp){
					printf("No memory for hashlist !\n");
					freehash(hashtable,hashnumber);
					return 0;
				}
				temp->value=B[i]+B[j];
				temp->a=i;
				temp->b=j;
				tail->next=temp;
				tail=temp;
				printf("The tail now is %d\n",tail->value);
			}
				
		}
	}

	/*Now is to search the hashtable to find the target*/
	for(i=0;i<hashnumber;i++){
		hashnode head=&hashtable[i];
		while(NULL!=head&&head->a>=0){
			int bias=abs((target-head->value)%hashnumber);
			hashnode head2=&hashtable[bias];
			while (NULL!=head2&&head2->a>=0){
		 		if((head->a>head2->a)&&(head->a>head2->b)&&(head->b>head2->a)&&(head->b>head2->b)){
					if(head->value+head2->value==target){
						printf("The array is %d %d %d %d\n",B[head->a],B[head->b],B[head2->a],B[head2->b]);
					}
				}
				head2=head2->next;
			}
			head=head->next;	
		}

	}
	if(NULL!=hashtable){
		freehash(hashtable,hashnumber);
	}
	return 0;
}
int main(int argc,int **argv){
	int i;
	printf("Please input the number of the array: \n");
	scanf("%d",&n);
	printf("Please input the target :\n");
	scanf("%d",&target);
	printf("Please input the array :\n");
	for(i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	hashsearch(&A[1],n,target);
	return 0;
}
