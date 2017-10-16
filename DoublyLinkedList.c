#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int x;
	struct n* next;
	struct n* prev;
}node;

void printList(node* r){
	while(r !=NULL){ // Runs if our list is not empty.
		printf("%i\n",r->x);
		r = r->next;
	}
}

void printBackwards(node* r){ 			// Prints the list backwards using the prev pointers.
	if(r != NULL){ 						//Runs if the list is not empty or all the items are not deleted.
	node* iter = r;
	while(iter->next != NULL){
		iter = iter->next;
	}
	while(iter !=NULL){
		printf("%i\n", iter->x);
		iter= iter->prev;
	}
	}else {
		printf("\nYou might have deleted all the items from the list. You can add some more items.^^\n");
	}
}

void addInOrder(node** r,int x){
	
	if((*r) == NULL){ 				//If the first item in our list is NULL. We have to allocate some memory.
		*r = malloc(sizeof(node));	//Allocating memory.
		(*r)->next = NULL;			//Assigning other variables.
		(*r)->prev = NULL;		
		(*r)->x = x;
		return;
	}
	if((*r)->x > x){
		node* toBePrepended = malloc(sizeof(node));
		toBePrepended->x = x;
		toBePrepended->prev = NULL;
		toBePrepended->next = *r;
		(*r)->prev = toBePrepended;
		*r = toBePrepended;
		return;
	}
	
	node* iter = *r;
	while(iter->next != NULL && iter->next->x < x){
		iter = iter->next;
	}
	node* temp = malloc(sizeof(node));
	temp->x = x;
	temp->next = iter->next;
	if(iter->next != NULL){
		iter->next->prev = temp;
	}
	temp->prev = iter;
	iter->next = temp;
	
	

}


		
void delete(node** r,int x){
	int endOfList = 0;		//Variable which will be changed to 1 if we are the end of the list.
	node* toBeDeleted;
	node* newRoot = *r; 	//Will be assigned our new root pointer.
	while(endOfList != 1){	//Loops unless we are at the end of the list...
		if((*r)->x == x){
			toBeDeleted = (*r);
			if((*r)->next != NULL){ 	
			*r = (*r)->next;
			(*r)->prev = NULL;
				newRoot= *r;
			free(toBeDeleted);
			}else if((*r)->next == NULL) {
				*r = NULL;
				endOfList = 1;
				continue;
			}

			if((*r)->next == NULL && (*r)->x != x){ // If we have one item remaining in the list and then item is not the same...
				endOfList = 1;		//... as the one we've recently deleted then we are at the end of the list therefore we have to quit looping.
				continue;
			}
						
			continue;
		}
		
		if(newRoot->next->x == x){ 						//If the item we want to delete is amongst other items.
			toBeDeleted = newRoot->next;
			newRoot->next = toBeDeleted->next;
			if(toBeDeleted->next != NULL){				//Checking whether we've deleted the item at the end of the list or not.
			toBeDeleted->next->prev = toBeDeleted->prev;	//If we are not deleting the item at the end then we should assign next item's prev.
			}else {											//to the prev of the item we will delete.
				free(toBeDeleted);
				endOfList = 1;
				continue;
			}
			free(toBeDeleted);
			continue;
		}
		   
		newRoot = newRoot->next; 			
		if(newRoot->next == NULL){ //If we are at the end of the list.
			endOfList = 1;
			continue;
		}
		
	}
}
	
		
int main(){
	node* root;
	root = NULL;
	addInOrder(&root,7);
	addInOrder(&root,4);
	addInOrder(&root,2);
	addInOrder(&root,1);
	addInOrder(&root,1);
	addInOrder(&root,3);
	addInOrder(&root,4);
	addInOrder(&root,7);
	addInOrder(&root,6);
	addInOrder(&root,8);
	addInOrder(&root,8);
	addInOrder(&root,15);
	addInOrder(&root,10);
	addInOrder(&root,12);
	addInOrder(&root,29);
	addInOrder(&root,0);
	addInOrder(&root,0);
	addInOrder(&root,17);
	addInOrder(&root,8);
	

	puts("\n------------Before Deletion------------\n");
	printList(root);
	printf("\n----Backwards----\n");
	printBackwards(root);
	delete(&root,2);
	delete(&root,7);
	delete(&root,8);
	delete(&root,4);
	delete(&root,17);
	delete(&root,12);
	delete(&root,29);
	delete(&root,15);
	delete(&root,10);
	delete(&root,0);
	delete(&root,6);
	delete(&root,3);
	delete(&root,1);
		
	
	

	puts("\n------------After Deletion------------\n");
	printList(root);
	printf("\n----Backwards----\n");
	printBackwards(root);
	
	
	return 0;
}
	