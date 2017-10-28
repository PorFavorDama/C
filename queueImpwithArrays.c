#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int itemCount, firstIndex, sizeof_arr;
	int* arr;
}queue;

queue* define(){			//This will declare our struct -which will contain our array- and then return a pointer to it.
	queue* ptr = malloc(sizeof(queue));
	ptr->sizeof_arr = 2;	//Our queue size will be 2 byte by default.
	ptr->itemCount = 0;		//We have to keep track of our items in the queue		
	ptr->firstIndex = 0;	//And also our firstIndex as we will dequeue our items with dequeue(); --REMEMBER FIFO--
	ptr->arr = NULL;		//Our queue is not initialized yet.
	return ptr;
}

void printQueue(queue* ptr){	//Prints all the items in the queue.
	if(ptr->arr != NULL){		//If our queue is not initialized(NULL), then prints the message below.
		int i = ptr->firstIndex;
		for(; i < ptr->itemCount; i++){
			printf("In the queue -> %i\n", ptr->arr[i]);
		}
	}
	else //This message will be shown if our queue is not initialized yet(NULL).
		printf("You are trying to print a queue which is NULL...\nPlease add more items to the queue.\n");
}

void enqueue(queue* ptr, int a){
	if(ptr->arr == NULL){ //If the queue is uninitialized then we will have initialize it.
		ptr->arr = malloc(2*sizeof *(ptr->arr)); //2 bytes will be allocated by default.
	}
	if(ptr->itemCount >= ptr->sizeof_arr){	//If our itemCount is equal to or greater than our queue size...
		ptr->sizeof_arr *=2;				//...then we will have double the allocated memory.
		printf("New size of our queue = %i byte\n", ptr->sizeof_arr);	//Informs us about new allocation.
		int* arr2 = malloc(ptr->sizeof_arr*sizeof *arr2); //New int pointer which has more memory than the older one.
		for(int i = 0; i < ptr->sizeof_arr/2; i++){ //We carry the items from the old queue to the new one.
			arr2[i] = ptr->arr[i];
		}
		free(ptr->arr); 
		ptr->arr = arr2; //Change the old pointer to the new one.
	}
	
	ptr->arr[ptr->itemCount++] = a; //Enqueue the item and then increment item count by one.
}

int dequeue(queue* ptr){	//Dequeue Function
	if(ptr->itemCount-1 == ptr->firstIndex){	//If it is the last item we want to dequeue from the queue.
		int lastItem = ptr->arr[ptr->firstIndex]; //We have to subtract one from itemCount because it's the "count" not index.
		free(ptr->arr); //Free our memory. Because it was the last element.
		ptr->arr = NULL; //Reset values to the default.(Like in define() function)
		ptr->firstIndex = 0;  
		ptr->sizeof_arr = 2;
		ptr->itemCount = 0;
		return lastItem ; //Return the last item dequeued.
	}
	if(ptr->itemCount - ptr->firstIndex < ptr->sizeof_arr/4){ //If itemCount-firstIndex less than sizeof our queue...
		printf("Shrinking the size of our queue to %i bytes.\n",ptr->sizeof_arr/2); //...then we will shrink the queue.
		int* arr2 = malloc((ptr->sizeof_arr/2)*sizeof *arr2);	//New pointer to a fewer memory.
		int firstIndexTemp = ptr->firstIndex;
		for(int i = 0; i <= ptr->itemCount - ptr->firstIndex; i++){
			arr2[i] = ptr->arr[firstIndexTemp++];
		}
		
		ptr->itemCount -= ptr->firstIndex;
		ptr->firstIndex = 0;
		
		free(ptr->arr);
		ptr->sizeof_arr /=2;
		ptr->arr = arr2;	//Changing the pointer with the new one.
		
	} 	
	return ptr->arr[ptr->firstIndex++]; //Return dequeued item and increment the firstIndex by one.
	
}


void main(){
	queue* ptr = define(); //Define our struct.
	
	enqueue(ptr,3); //Enqueue
	enqueue(ptr,4);
	enqueue(ptr,5);
	enqueue(ptr,7);
	enqueue(ptr,8);
	enqueue(ptr,9);
	enqueue(ptr,10);
	enqueue(ptr,11);
	enqueue(ptr,12);
	enqueue(ptr,13);

	puts("--------------------BEFORE DEQUEUE-----------------\n");
	printQueue(ptr); 

	
	puts("\n-----------------HERE WE DEQUEUE-----------------");
	
	printf("\nDequeue -> %i\n",dequeue(ptr)); //Dequeue and print the item dequeued.
	printf("Dequeue -> %i\n",dequeue(ptr));
	printf("Dequeue -> %i\n",dequeue(ptr));
	printf("Dequeue -> %i\n",dequeue(ptr));
	printf("Dequeue -> %i\n",dequeue(ptr));
	printf("Dequeue -> %i\n",dequeue(ptr));
	printf("Dequeue -> %i\n",dequeue(ptr));
	printf("Dequeue -> %i\n",dequeue(ptr));
	printf("Dequeue -> %i\n",dequeue(ptr));
	printf("Dequeue -> %i\n",dequeue(ptr));
	
	
	puts("---------------------AFTER DEQUEU-------------------\n");
	printQueue(ptr);
	
	
	puts("\n---------------------ADDING NEW ITEMS TO THE QUEUE-------------------\n");
	enqueue(ptr,38);
	enqueue(ptr,39);
	enqueue(ptr,29);
	enqueue(ptr,59);
	enqueue(ptr,69);
	enqueue(ptr,79);
	enqueue(ptr,89);
	
	puts("\n-----------------BEFORE DEQUEUE-----------------\n");
	printQueue(ptr);
	
	puts("\n-----------------HERE WE DEQUEUE-----------------");
	
	
	printf("\nDequeue -> %i\n",dequeue(ptr));
	printf("Dequeue -> %i\n",dequeue(ptr));
	printf("Dequeue -> %i\n",dequeue(ptr));
	printf("Dequeue -> %i\n",dequeue(ptr));
	printf("Dequeue -> %i\n",dequeue(ptr));
	//printf("Dequeue -> %i\n",dequeue(ptr));
	//printf("Dequeue -> %i\n",dequeue(ptr));
	
	puts("\n--------------AFTER DEQUEUE-----------------\n");
	
	printQueue(ptr);
	
	free(ptr->arr);
	free(ptr);
}