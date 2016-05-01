#include<stdio.h>
#include<stdlib.h> 
#include"que.h"


struct queue
{
   struct node *stack1; // two stacks as two nodes
   struct node *stack2; 
};
struct queue2
{
   struct node *stack3; // two stacks as two nodes
   struct node *stack4; 
};

void enQueue(struct queue *q, int x) //inserte a data element to the queue
{
   push(&q->stack1, x);
}
//for transfer to stack
void enQueue2(struct queue2 *st, int x) //inserte a data element to the stack
{
   push(&st->stack3, x);
}

int deQueue(struct queue *q) // remove a data element from the queue 
{
   int x; 
     
      if(q->stack1 == NULL && q->stack2 == NULL) // check queue is empty or not
   {  
      printf("Queue is empty\n");
     // exit(0); // exit the process.
   }
    
   if(q->stack2 == NULL) 
   {
     while(q->stack1 != NULL)
     {
        x = pop(&q->stack1);
        push(&q->stack2, x); //push value to the stack
     }
   } 
   x = pop(&q->stack2);//get value from the stack
   return x;
}

//for transfer to stack
int deQueue2(struct queue2 *st) // remove a data element from the stack 
{
   int x; 
     
      if(st->stack3 == NULL && st->stack4 == NULL) // check queue is empty or not
   {  
      printf("Queue is empty\n");
     // exit(0); // exit the process.
   }
    
   if(st->stack4 == NULL) 
   {
     while(st->stack3 != NULL)
     {
        x = pop(&st->stack3);
        push(&st->stack4, x); //push value to the stack
     }
   } 
   x = pop(&st->stack4);//get value from the stack
   return x;
}


void push(struct node** toprf, int new_data)
{
 
  struct node* head =
            (struct node*) malloc(sizeof(struct node));
  
  if(head == NULL)
  {
     printf("Overflow due to inadequate memory \n");
     exit(0);
  }            
  
	 head->data  = new_data;
 	 head->next = (*toprf);   
    
  (*toprf)    = head;
}

int pop(struct node** toprf)
{
  int rtn;
  struct node *top;
 
  if(*toprf == NULL)
  {
     printf("Overflow due to inadequate memory \n");
     exit(0);
  }
  else
  {
     top = *toprf;
     rtn = top->data;
     *toprf = top->next;
     free(top); //free the node
     
  return rtn;
  }
}
int isempty(struct node** toprf){
	if(toprf == NULL)
		return 0;
	else 
		return 1;
	
}
//transfer to new stack from queue
void transferToStack(struct queue2 *st,struct queue* topf){
	
	enQueue2(st,deQueue(topf)); //push to new stack
	printf("%d\n",deQueue2(st));//pop from stack
	
}

int main()
{
 
   struct queue *q = (struct queue*)malloc(sizeof(struct queue)); //create queue
		q->stack1 = NULL;
		q->stack2 = NULL;
	  
  	int i;
 
	for(i=0;i<5;i++)   enQueue(q,i+10); //add value to the queue
     
 	//for(i=0;i<5;i++)  printf("%d\n", deQueue(q)); //print the queue

  
  	struct queue2 *st= (struct queue2*)malloc(sizeof(struct queue2)); //create queue
		st->stack3 = NULL;
		st->stack4 = NULL;
 	
 	for(i=0;i<5;i++) transferToStack(st,q); //transfer to stack

 	
 	
 return 0;
}
