/*
# This is a simple, straightforward stack implementation with linked lists.
# There are three methods used, which are (i) push 		-> pushes an element onto the stack.
#										 (ii) pop  		-> pops up an element from the stack.
#										(iii) printList -> prints all the elements in the stack. 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int x;			//Any data and data type that we want to keep in our stack.
	struct n* next; //Which will be pointing to our next element in the stack.
}node;

void push(node** ptr, int a){
	if(*ptr == NULL){				//If our pointer is NULL... 
		*ptr = malloc(sizeof **ptr);//...then we have to allocate some memory for the first element of our stack.
		(*ptr)->x = a;
		(*ptr)->next = NULL;
		return;
	}
	//---- IF NOT ----
	node* iter = *ptr;
	while(iter->next != NULL){
		iter = iter->next;
	}
	
	iter->next = malloc(sizeof **ptr);
	iter->next->next = NULL;
	iter->next->x = a;
}

int pop(node** ptr){
	int x;
	node* temp = *ptr;
	if((*ptr)->next == NULL){ //If it is the last element of the stack that we want to pop out.
		x = (*ptr)->x;
		free(*ptr);
		*ptr = NULL;
	}
	else {	
	//IF NOT ----
	while(temp->next->next !=NULL){
		temp = temp->next;
	}
	x = temp->next->x;
	free(temp->next->next);
	free(temp->next);
	temp->next = NULL;
	}
	
	return x;
}


void printList(node* ptr){
	if(ptr == NULL)
		printf("You are trying to print a stack which is already \"NULL\"\n");
	else{
		while(ptr != NULL){
		printf("Value -> %i\n",ptr->x);
		ptr = ptr->next;
		}
	}
}

void main(){
	node* ptr = NULL;

	push(&ptr, 160);
	push(&ptr, 720);
	push(&ptr, 660);
	push(&ptr, 50);
	push(&ptr, 20);
	push(&ptr, 140);
	puts("\n-----------------------------------");
	
	puts("-------------BEFORE----------------\n");
	printList(ptr);
	puts("\n");
	
	printf("Popped -> \"%i\"\n",pop(&ptr));
	printf("Popped -> \"%i\"\n",pop(&ptr));
	printf("Popped -> \"%i\"\n",pop(&ptr));
	printf("Popped -> \"%i\"\n",pop(&ptr));
	printf("Popped -> \"%i\"\n",pop(&ptr));
	printf("Popped -> \"%i\"\n",pop(&ptr));

	puts("\n");
	puts("---------------AFTER---------------\n");
	
	printList(ptr);
	puts("\n-----------------------------------");
}