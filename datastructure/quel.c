#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void queueCreate (struct node **n){
	*n = NULL; //return null head with creating list
}

void queueDestroy (struct node **n){
	struct node *temp = *n;
	struct node *next;
	
	while(temp){
		next = temp -> next;  //point set to next node
  		free(temp);  //free node
  		temp = next;  //set next node address to tmp becoz it freed
 
	}
	//if tmp = null then free that node also (when null n meet node not free)
 	 if(!temp){
  		*n = NULL;
	} 

}

void enqueue(struct node **n,int val){
	struct node *tmp = malloc(sizeof(struct node));
  	struct node *curr = *n; 
  
  if(!tmp) return -1; // no memory 
  
  tmp -> data = val; // create the node 
  tmp -> next = NULL; // this will be the new tail 
  
  if(!curr)    *n = tmp; // empty list, this will be the first
  
  else {
    while(curr -> next) curr = curr -> next; // go till last node
    curr -> next = tmp; //set address
  } 
  
  return 0;  

}

int dequeue(struct node **n){
	int rtn;
	rtn = (*n) -> data;	//get data from node
	 (*n) = (*n)-> next;  //point set to next node
  	 
return rtn; //return data
}

int queuePeek (struct node **n){
	int rtn;
	rtn = (*n) -> data; //get data from node
return rtn; //return data
}

int queueIsEmpty (struct node **n){
	if((*n) == NULL) return 1;
	else return 0;
}

int main(void){
		
	struct node *top;
	queueCreate(&top);
	enqueue(&top,5);
	enqueue(&top,7);
	printf("%d\n",dequeue(&top));
	printf("%d\n",queuePeek(&top));
	//queueDestroy(&top);
	//printf("is empty - %d\n",queueIsEmpty(&top)); // if empty return 1 otherwise 0

return 0;
}
