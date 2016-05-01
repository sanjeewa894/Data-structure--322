#include<stdio.h>
#include <stdlib.h>
#include"que.h"
#include"stack.h"


int main (){
	
	int value,rtn,i;
	struct node *stack1 = (struct node*)malloc(sizeof(struct node));
   	struct node *stack2 = (struct node*)malloc(sizeof(struct node));
		queueCreate (stack1);
	for( i=0;i<5;i++){
		scanf("%d",&value);
		enqueue(stack1,value);
	}
	queueCreate (stack2);
	for( i=0;i<5;i++){
		rtn =dequeue(stack1);
		
		enqueue(stack2,rtn);
	}
	
for( i=0;i<5;i++){
	rtn = dequeue(stack2);
	printf("%d\n",rtn);
	}
return 0;
}
