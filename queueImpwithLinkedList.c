#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int x;
	struct n* next;
}queue;

void enqueue(queue** ptr, int a){ //We will get a pointer to pointer because we declare our queue in the method (Local scope).
	if(*ptr == NULL){			  //If it's not initialized then we initialize it
		*ptr = malloc(sizeof **ptr);
		(*ptr)->x = a; //And then add the first item to the queue of course.
		(*ptr)->next =NULL;
		return;
	}
	queue* tmp = *ptr; //If the queue is initialized which simply means it has items inside.
	while(tmp->next != NULL){ //Then we add our new item at the end of the queue.
		tmp = tmp->next;
	}
	tmp->next = malloc(sizeof *(tmp->next));
	tmp->next->next = NULL;
	tmp->next->x = a;
}

void dequeue(queue** ptr){ //Again we get a pointer to pointer because we will change...
	queue* tmp = *ptr;	   //...our pointer once we delete(enqueue) the first item. (REMEMBER FIFO)
	int dequeued = tmp->x; //First, we assign the data inside to another variable, which we will print later as to show what's been enqueued.
	(*ptr) = (*ptr)->next; //Then we change our pointer to the next one.
	tmp->next = NULL;		
	free(tmp);	//Now we can free the memory used by tmp.
	printf("Dequeued -> %i\n",dequeued);
}
	

void printQueue(queue* ptr){
	if(ptr != NULL){ //If the queue is not NULL , then print the queue.
	while(ptr != NULL){
		printf("In the queue -> %i\n",ptr->x);
		ptr = ptr->next;
	}
	} else
		printf("You are trying to print a queue which is NULL.\nFirst, enqueue something.\n");
}

void freeQueue(queue* ptr){ //Free all the memory used by the program before exit. Preventing memory leaks.
	queue* tmp;
	
	while(ptr != NULL){
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
}

void main(){
	puts("-----------------HERE IT GOES----------------\n");
	queue* foo = NULL;
	enqueue(&foo, 5);
	enqueue(&foo, 6);
	enqueue(&foo, 7);
	enqueue(&foo, 8);
	enqueue(&foo, 9);
	enqueue(&foo, 10);
	enqueue(&foo, 11);
	enqueue(&foo, 12);

	printQueue(foo);
	
	puts("\n---------------------DEQUEUE--------------------\n");
	dequeue(&foo);
	dequeue(&foo);
	dequeue(&foo);
	dequeue(&foo);
	dequeue(&foo);
	dequeue(&foo);
	dequeue(&foo);
	dequeue(&foo);
	
	puts("\n-------------AFTER DEQUEUE------------\n");
	printQueue(foo);
	
	//Enqueueing some items to the queue, again.
	enqueue(&foo, 35);
	enqueue(&foo, 32);
	enqueue(&foo, 15);

	puts("\n-----AFTER ENQUEUEING SOME OTHER ITEMS-----\n");
	printQueue(foo);
	
	freeQueue(foo);
}