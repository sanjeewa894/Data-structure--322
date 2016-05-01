#include<stdio.h>
#include<stdlib.h>

int count=0;
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

void stackPush(struct node **top,int x){
	enqueue(top,x); //push value to queue
	count++; //get no of elements added to queue
		
}
int stackPop(struct node **n,struct node **m){
	int x,i,prev,swap;
	
	swap = queueIsEmpty(n); //get which queue is empty
	
	for(i=0;i<count;i++){	
		if(swap){
			x = dequeue(m); //pop value in queue
			prev = x;
			if(i+1==count){
				count--; //to get no of elements
				 return prev;	//return top value					 
			}
			enqueue(n,x); //push value to queue
			
		}else{
			x = dequeue(n); //pop value in queue
			prev = x;
			if(i+1==count){
				count--;
				 return prev; //return top value				
			}
			enqueue(m,x);//push value to queue
		}
	}
	
}
void stackCreate(struct node **top){
	queueCreate(top); //create stack using queue

}
void stackDestroy (struct node **n){
	 queueDestroy (n); //destroy stack that used queue
}
int StackIsEmpty(struct node **n){
	return queueIsEmpty(n); //return 1 if empty
}

int main(void){
		
	int i;
	
	struct node *top;
	struct node *top2;
	//create two stack
	stackCreate(&top);
	stackCreate(&top2);
	
	//push data to stack
	stackPush(&top,3);	
	stackPush(&top,5);
	stackPush(&top,7);
	stackPush(&top,9);
	
	for(i=0;i<4;i++)
	printf("%d\n",stackPop(&top,&top2)); //to pop top element
	

return 0;
}
