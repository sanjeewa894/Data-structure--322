#ifndef __STACK_H__
#define __STACK_H__

/* data type */
struct stack_node { 
  int data; 
  struct stack_node *next; 
};

typedef struct stack_node stack_node_t; 
typedef stack_node_t *stack_t; 

/* push the given data to given stack
 * return 0 on success -1 otherwise
 */
int push(int data, stack_t *stack); 

/* pop the item to given variable and return 1
 * else return 0
 */
int pop(int *data, stack_t *stack);

/* return 1 if empty
 */
int isEmpty(stack_t *stack);



#endif
