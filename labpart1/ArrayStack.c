#include <stdio.h>
#include <stdlib.h>

unsigned long *StArray;
int caps,pbno,pbnostor1,pbnostor2,ok=0;

void stackCreate (int capasity){
	int i;
	caps = capasity;
	StArray = (int *)malloc(capasity*sizeof(int));
	//StArray[0] = NULL;
	if(StArray == NULL)
		printf("Error - unable to allocate required memory\n");
	else{
		for(i=0;i<caps;i++) StArray[i] = NULL;	
		printf("array OK,%d\n",caps);   
	}
}

void stackDestroy (){
	int i;
	
	for(i=0;StArray[i] != NULL;i++)
		StArray[i] = NULL;	
	printf("Stack is successfully destroyed\n");
}

void stackPush(int size){
	int i;
	for(i=0;i<caps;i++){	
		if(StArray[i] == NULL){
			StArray[i] = size;
			//if(i<caps)StArray[i+1] = NULL;		
			break;
		}	
	}
}
void stackPushback(int size){
	int i;
	for(i=caps-1;i>=0;i--){	
		if(StArray[i] == NULL){
			StArray[i] = size;	
			pbno=i;	
	pbnostor1 = pbno;
			break;
		}	
	}
}

int StackPop(){
	int i,rtn;	
	 for(i=0;i<caps-pbno;i++){	
		if(pbno != caps && i+1 == caps-pbno){
			rtn = StArray[i];
			StArray[i] = NULL;
		break;		
		}
		if(StArray[i+1] == NULL){
			rtn = StArray[i];
			StArray[i] = NULL;
			break;
		}	
		if(StArray[i] == NULL){
			rtn = 0;
			break;
		}	
			
	} 
return rtn;
}

int StackPopback(){
 int rtn;
		rtn = StArray[pbnostor1];
		StArray[pbnostor1] = NULL;	
		pbnostor1++;
return rtn;
}



int stackPeek (){
	int rtn;	
	rtn = StArray[pbno-1];	
	
return rtn;
}

int stackPeekback(){
	return StArray[caps-1]; 
}


int StackIsEmpty (){
	int rtn;
	if(StArray[0] == NULL)
		return 1;
	else
		return 0;
}
int StackIsEmptyback(){
	int rtn;
	if(StArray[caps-1] == NULL)
		return 1;
	else
		return 0;
}

int StackIsFull (){
	int i,rtn;	
	for(i=0;i<caps;i++){
		if(StArray[i] == NULL){
			if(i == caps)	return 1;
			else return 0;
		}			
	}
}


int main(){
	int i=0,val=0;
	int Capsity = 12;
	//char str[100];  //for get string from stdin
	stackCreate(Capsity);
	
return 0;
}

/*2.2 reverse string
	 printf( "Enter a value :");  
    		gets( str );  //get string
 	//*..push to the stack..
	for(i=0;str[i] != NULL;i++) {
		
		if(StackIsFull ()) {
			printf("Stack is FULL last element count - %d\n",i+1);
			val = Capsity;
			break;
		}
		stackPush(str[i] );
		val = i+1;
	}
	
	//stackDestroy ();
	if(StackIsEmpty()){
		printf("Stack is Empty\n");
		exit(0);
	}
	//print string
	 for(i=0;i<val;i++) 
	printf("%c", StackPop ());
	printf("\n"); */

/*2.3
	//for two stack in one array
	for(i=0;i<Capsity;i++) {
		if(StackIsFull ()){
			 printf("stack is full\n");
			break;
		}
		stackPush(34+i);
		stackPushback(50+i);

	}
	
	
		printf("peekback %d\n", stackPeekback());
		printf("peekback %d\n", stackPeek());

	for(i=0;i<Capsity;i++) {		
		if(!StackIsEmpty ()) printf("from begining %d\n", StackPop ());
		if(!StackIsEmptyback ()) printf("backward %d\n", StackPopback());
		if (StackIsEmpty ()==1 && StackIsEmptyback ()==1){
			printf("stack 1 is empty\n");	
			printf("stack 2 is empty\n");		
			break;		
		}		
	}
*/


