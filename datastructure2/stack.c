#include<stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void stackCreate(struct node **);
void stackPush(struct node **,int);
void display(struct node **);
int stackPop(struct node **);
void stackDestroy (struct node **);
int StackIsEmpty(struct node **);
int stackPeek(struct node **);
void stackReverseRec(struct node **,struct node **);
int stackReverseIter(struct node *);

int main()
{
	struct node *top;
	stackCreate(&top);
	int ch=0,x,i;
	
	for(i=0;i<5;i++){
		stackPush(&top,30+2*i);//push values
	}
	//stackDestroy(&top); //destroy stack

	if(StackIsEmpty(&top))	printf("stack is empty\n"); //find whether stack is empty
	
	//printf("%d\n",stackPeek(&top)); //peek the stack & print
  
	/*for(i=0;!StackIsEmpty(&top);i++){		
			//printf("%d..\n",stackPop(&top)); //pop the stack & print				
	}*/
	
	//top = stackReverseIter(top); //reverse by iteration

	//if (top != NULL)    stackReverseRec(&top, &(top->next)); //reverse the stack	recursive	
	for(i=0;i<5;i++){
		if(!StackIsEmpty(&top))
			printf("%d-\n",stackPop(&top)); //pop the stack & print
		else break;		
	}
		
return 0;
}

void stackCreate(struct node **nod){
	*nod=NULL; //return null head with creating list
}
void display(struct node **n)
{
	struct node *temp=*n;
	
	if(*n==NULL){	
	printf("Stack is empty\n");
	return ;
	}
	printf("Stack elements are\n");
	while(temp!=NULL){
		printf("\t%d\n",temp->data);//print data end to list
		temp=temp->next; 
	}
	printf("\n");

}
void stackPush(struct node **n,int x)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x; //push value in to tempory node 
	temp->next=*n; // join with next node to n
	*n=temp; //join temp to head
}

int stackPop(struct node **n){
	if(*n==NULL) //find list empty
		return 0;
	int x;
	x=(*n)->data; //get data from node
	(*n)=(*n)->next; //point to next node

return x;
}

void stackDestroy (struct node **n){
	struct node *temp=*n;
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
int StackIsEmpty(struct node **n){
	 if((*n) == NULL) //find node is null
 		return 1;
	else return 0;
}

int stackPeek(struct node **n){
	if (StackIsEmpty(n)) {
         printf("Empty stack\n");
         return '\0';
      }
      return (*n)->data; //return top value
}
void stackReverseRec(struct node **n, struct node **n_next){
    struct node *temp; //get tempory node

    if (*n_next != NULL){
         temp = (*n_next)->next; //set next node
        (*n_next)->next = (*n);  //set next to next node
        *n = *n_next; //set next  node to current
        *n_next = temp; //set next node tepm node

        stackReverseRec(n, n_next); //recursive 
    }
}

int stackReverseIter(struct node *n){
   if(n== NULL) return NULL; //one element

	struct node *last = NULL; //get tempory node

   while(n != NULL){
		struct node *temp = n->next; //set next node to temp
        n->next = last;  //set next to last node (empty)
        last = n; //set  current  node to last
        n = temp; //set current node tepm node
    }
return last; //return reference
}


