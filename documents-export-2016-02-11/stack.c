/*
 * C Program to Implement a Stack using Linked List
 */
#include <stdio.h>
#include <stdlib.h>
#include"stack.h"

struct node
{
    int info;
    struct node *ptr;
};
 
struct node *top = (struct node*)malloc(sizeof(struct node));
struct node *top1 = (struct node*)malloc(sizeof(struct node));
struct node *tmp = (struct node*)malloc(sizeof(struct node));

int count = 0;

/* Create empty stack */
void Stackcreate(struct node* top_ref)
{
    top = NULL;
}
 
/* Count stack elements */
void stack_count(struct node* top_ref)
{
    printf("\n No. of elements in stack : %d\n", count);
}
 
/* Push data into stack */
void push(struct node* top_ref,int data)
{
    if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
}
 
/* Display stack elements */
void display(struct node* top_ref)
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
 
    while (top1 != NULL)
    {
        printf("%d ", top1->info);
        top1 = top1->ptr;
    }
 }
 
/* Pop Operation on stack */
int pop(struct node* top_ref)
{	int rtn;
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("\n Error : Trying to pop from empty stack\n");
        return;
    }
    else
        top1 = top1->ptr;
    //printf("\nPopped value : %d\n", top->info);
    rtn=top->info;
    free(top);
    top = top1;
    count--;
return rtn;
}
 
/* Return top element */
int topelement(struct node** top_ref)
{
    return(top->info);
}
 
/* Check if stack is empty or not */
void empty(struct node* top_ref)
{
    if (top == NULL)
        printf("\n Stack is empty\n");
    else
        printf("\n Stack is not empty with %d elements\n", count);
}
 
/* Destroy entire stack */
void Stackdestroy(struct node* top_ref)
{
    top1 = top;
 
    while (top1 != NULL)
    {
        top1 = top->ptr;
        free(top);
        top = top1;
        top1 = top1->ptr;
    }
    free(top1);
    top = NULL;
 
    printf("\n All stack elements destroyed\n");
    count = 0;
}

void  stackReverseRec(struct node* top_ref){	
	int rec;
  if (top_ref != NULL)
    {
        
        rec = pop(top_ref);
       addnodetail(rec,top_ref);
   stackReverseRec(struct node* top_ref);
}
	
}

/***
 * Add to the tail. Return 0 if successful, -1 otherwise 
 */
int addnodetail(int data, struct node **head) 
{ 
  struct node *tmp = malloc(sizeof(struct node));
  struct node *curr = *head; 
  
  if(!tmp) return -1; // no memory 
  
  tmp -> info = data; // create the node 
  tmp -> ptr = NULL; // this will be the new tail 
  
  if(!curr)    *head = tmp; // empty list, this will be the first
  
  else {
    while(curr -> ptr) curr = curr -> ptr; // go till last node
    curr -> ptr = tmp; //set address
  } 
  
  return 0;  
}

int main(void){






return 0;
}

