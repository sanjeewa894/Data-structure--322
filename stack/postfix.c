#include <stack.h>
#include <stdio.h>
#include <assert.h>


char expression[] = "49+2*"; 

int isOperator(char c) 
{
  if( (c == '+') || 
      (c == '-') ||
      (c == '*') ||
      (c == '/') ) return 1;

  return 0;
}

int doOperation(char a, char b, char op)
{
  int val1, val2;
  val1 = (int) a; 
  val2 = (int) b;

  if(op == '+') return val1+val2;
  if(op == '-') return val1-val2;
  if(op == '*') return val1*val2;
  if(op == '/') return val1/val2;

  assert("Should not be here");
  return 0;
}



int main()
{ 
  return 0;
}
