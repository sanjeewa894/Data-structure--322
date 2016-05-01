#include <stack.h>
#include <stdlib.h>


int push(int data, stack_t *stack)
{
  stack_node_t *tmp = malloc(sizeof(stack_node_t));
  if(tmp) {
    tmp -> data = data; 
    tmp -> next = *stack; 
    *stack = tmp; 
    return 0; 
  }
  return -1; 
}

int pop(int *data, stack_t *stack) 
{
  if(*stack) { 
    stack_node_t *tmp;
    tmp = *stack; 
    *stack = (*stack) -> next; 
    *data = tmp -> data; 
    free(tmp);
    return 1;
  }
  return 0;
}

int isEmpty(stack_t *stack)
{
  return *stack ? 0 : 1;
}

