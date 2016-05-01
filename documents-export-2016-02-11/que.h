#include"stack.h"
 

int queueCreate (struct node* top_ref){	
	Stackcreate(top_ref);
}

void queueDestroy(struct node* top_ref){
	Stackdestroy(top_ref);
} 

void enqueue(struct node* top_ref,int data){
	push(top_ref, data);
	
}

int dequeue(struct node* top_ref){
	return pop(top_ref);
}

void queueIsEmpty(struct node* top_ref){
	empty(top_ref);
	
}

int queuePeek(struct node* top_ref){
	return topelement(top_ref);
} 



