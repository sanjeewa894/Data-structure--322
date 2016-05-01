#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

/*struct linked_node * create_list() 
{
  /* we will revisit this later / 
}*/


/****
 * Add to the head, return 0 on success, -1 otherwise
 **/
int addnode(int data, struct linked_node **head) 
{	//temporary pointer variable allocate 
	struct linked_node *tmp = malloc (sizeof(struct linked_node));
  if(!tmp)  //if not memory
    return -1;
  
  //add data potion to data temporary variable
  tmp -> data = data;
  tmp -> next = *head; //set address of node to tmp
  *head = tmp; //tmp address set to head

  return 0; 
  
}

/***
 * Add to the tail. Return 0 if successful, -1 otherwise 
 */
int addnodetail(int data, struct linked_node **head) 
{ 
  struct linked_node *tmp = malloc(sizeof(struct linked_node));
  struct linked_node *curr = *head; 
  
  if(!tmp) return -1; // no memory 
  
  tmp -> data = data; // create the node 
  tmp -> next = NULL; // this will be the new tail 
  
  if(!curr)    *head = tmp; // empty list, this will be the first
  
  else {
    while(curr -> next) curr = curr -> next; // go till last node
    curr -> next = tmp; //set address
  } 
  
  return 0;  
}

/***
 * add the new node to the correct palce in sorted list
 * return 0 on success, -1 otherwise
 */
int addnodeinplace(int data, struct linked_node **head)
{
  struct linked_node *tmp,*prev,*curr = *head;

	tmp =malloc (sizeof(struct linked_node));
	
	if(!tmp) return -1; // no memory 
	
	tmp -> data = data; //create node
	tmp -> next =NULL;  //this will be new node
	
	//check head null and data less than node data
	if(!*head || curr -> data >=  data ) {	
		tmp -> data = data;
		tmp -> next = *head;
		*head = tmp;		
	}
	else{
		
		//go to exact node to add new node
		while((curr -> next ) && (data > (curr -> data))){
			prev = curr; //store current node address
			curr = curr -> next;
			if((data <(curr -> data))) break;
		}
		
		//if data is higher then add to tail
		if((!(curr-> next)) && (data > (curr -> data)))  {
			curr -> next = tmp;
		}
		else if(data < (curr  -> data)){
			// add data to between 2 node
			tmp -> next =  prev -> next;
			prev -> next = tmp;
			
		}
		else{ //add new node to front node
			curr=curr ->next; 
			tmp -> next = curr -> next;
			curr -> next = tmp;
			
		}
	}
 
  return 0;
} 
  
/* delete the whole list
 * visit all the node and reclaim the memory 
 * Once done make the head points to NULL as well. 
 */ 
/***
 * delete the whole list 
 */
void deletelist(struct linked_node **head)
{
	struct linked_node *tmp =  *head;
	struct linked_node *next; 
	//run tha loop till tmp = null and free nodes
  while(tmp){	
  
  next = tmp -> next;  //point set to next node
  	free(tmp);  //free node
  tmp = next;  //set next node address to tmp variable becoz it freed
  }
  //if tmp = null then free that node also (when null head meet node not free)
  if(!tmp){
  	*head = NULL;
	}  
}


/*
* return 1 if the value is from list
*return otherwise
*/
int removenode(struct linked_node **head, int *val){
	
	if(!*head) return 0;
	
	struct linked_list *tmp = *head;
	
	tmp = *head;
	
	(*val) = tmp -> data;
	(*head) = tmp -> next;
	
	free(tmp);
	return 1;
	

}

//display value of nodes
void showlist(struct linked_node *head)
{	//run loop untill head is null
  
  int i;
  
  while(removenode(head,&i))
  	printf("%d\t",i);
  
  
  /*
  while(head) { 
    printf("%d\t", head -> data);
    head = head -> next;
  }*/
}




int main()
{
	//set initially head null
  struct linked_node *head = NULL;
  int val;
  
  //calling functions
 
  
  while(1) { 
    printf("Enter Value: ");
    scanf("%d", &val);
    if(!val) break; 
    addnodeinplace(val, &head);  
	}
	
  showlist(head);	
  deletelist(head); 

  return 0; 
}


