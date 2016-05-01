#include<stdio.h>
#include<stdlib.h>

int caps,rear;
int *StArray;

void queueCreate (int capasity){
	int i;
	caps = capasity;
	rear = caps-1; //set rear position of array
	StArray = (int *)malloc(capasity*sizeof(int)); //allocate array
	//check array has created or not
	if(StArray == NULL) //not created
		printf("Error - unable to allocate required memory\n");
	else{ //array created
		for(i=0;i<caps;i++) StArray[i] = NULL;	
		printf("%d, array OK\n",caps);   
	}
}

void queueDestroy (){
	int i;
	for(i=0;i<caps;i++) StArray[i] = NULL;	 //all element in array set to null
}

void enqueue(int val){
	int i=rear,j;
	if(StArray[i] == NULL) //if queue is empty 
		StArray[i] = val;
	else	{ //queue is not empty
		for(j=rear;StArray[j] !=NULL ;j--) if(j==0) break; //get front element position
		for(;j<rear;j++) StArray[j] = StArray[j+1]; //swap element to forward
		StArray[j] = val; //new value set to end of array
	}

}

int dequeue(){
	int j,rtn;
	
		for(j=rear;StArray[j] !=NULL ;j--);
		if(j==0){ //if queue is full
			rtn = StArray[j];
			StArray[j] = NULL;
			return rtn;
		}			
		else{ //queue is not full
			rtn = StArray[j+1]; //get the value of front element
			StArray[j+1] = NULL; //free the element in array
			return rtn; //return value
		}
}

int queuePeek (){
	int j,rtn;	
		for(j=rear;StArray[j] !=NULL ;j--); //get position of the front element of array 
		if(j==0)	return StArray[j];	//if full return front element 	
		else	return StArray[j+1];	//return front element 	
}

int queueIsEmpty (){
	if(StArray[rear] == NULL) //if que is empty last element in array should  be null if it is not null queue is not empty
		return 1;
	else return 0; //not empty

}

int queueIsFull (){
	if(StArray[0] == NULL) //if que is full first element in array should not be null if it is null queue is not full
		return 0;
	else return 1; //queue is full
}

int main(void){
	int i=0;
	queueCreate (12); //create queue
	
	for(;i<13;i++){
		if(!queueIsFull ()) //check whether queue is full or not if not data enter otherwise discard
			enqueue(15+i);	//enter data to queue
	}
	
	//queueDestroy (); //destroy the queue
	
	for(i=0;i<12;i++) printf("%d..asasadasj\n",StArray[i]); //print the data in the queue from the begining to show it has implemented correctly
	
	//printf("%d..\n",dequeue()); //dequeue the que and print
	
	//printf("%d..\n",queuePeek ());//peek the que and print
	
	
return 0;
}

