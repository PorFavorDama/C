#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int x;
	struct n* next;
}node;


void printList(node* r){
	node* realRoot = r;
	node* iter = r;
	printf("%i\n",iter->x);
	iter = iter->next;
	while(iter != realRoot){
		printf("%i\n",iter->x);
		iter = iter-> next;	
		}
}



void delete(node** r,int x){
	node* toBeDeleted;
	node* newRoot = *r;
	node* newRootCopy;
	int endOfList = 0;
	node* iter = *r;
	while(endOfList !=1){
		if( (*r)->x == x){ 			//If the element you want to delete is the root of the list...
			toBeDeleted = (*r);		//...we are going to delete it and change the pointer to root with the new one.
			*r = (*r)->next;		//Then you have to check the list again with "continue" to see...
			newRoot = *r;			//...whether the data you want to delete is again in the root of your list or not.
			newRootCopy = *r;

			while( newRootCopy->next != toBeDeleted ){
				newRootCopy = newRootCopy->next;
			}
			newRootCopy->next = newRoot ;
			free(toBeDeleted);
			
			continue;
		}
		
		if(newRoot->next->x == x){ 					//If the element you want to delete is amongst the other elements...
			toBeDeleted = newRoot->next;			//...this will run to check whether your next element is the one...
			newRoot->next = toBeDeleted->next;		//...you want to delete. If so, the next element of the element...
			free(toBeDeleted);						//...you want to delete will be assigned to the current element's next not to...
			continue;							 	//...lose the rest of the list.
		}
		
		newRoot = newRoot->next;
		if(newRoot->next == (*r)){
			endOfList =1;
		}
	}
	
}

void addInOrder(node** r,int x){
	
	node* root = *r;
	if(root == NULL){								
		root = malloc(sizeof(node));				
		root->x = x;
		*r = root;			
		root->next = (*r);	
		return;
	}
		
	if( (*r)->x > x){												
		node* iter;													
		node* toBePrepended = malloc(sizeof(node));			
		toBePrepended-> x = x;	
		toBePrepended->next = *r;
		iter = *r;
		node* dondur = iter;
		(*r) = toBePrepended;
		
		while(iter->next != dondur){
			iter = iter->next;
		}
		iter->next = toBePrepended;
		
		return;
	}
	
	node* iter = *r;
	
	while( iter->next != *r && iter->next->x < x){	//while iter->next is not null and iter->next's x is less than our X... 
		iter = iter-> next;								
	}
	node* temp = malloc(sizeof(node));					//Allocate memory for our new element.
	temp->next = iter->next;							//Then assign the iter's null to our new element's next item.
	temp->x = x;										//Assign the x value.
	iter->next = temp;									//Now our current element's next should point to our new element...
}														//...which is greater than the 	current element.
		

int main(){
	node* root;
	root = NULL;
	addInOrder(&root,5);
	addInOrder(&root,3);
	addInOrder(&root,3);
	addInOrder(&root,2);
	addInOrder(&root,4);
	addInOrder(&root,1);
	addInOrder(&root,1);
	addInOrder(&root,10);
	addInOrder(&root,16);
	addInOrder(&root,6);
	node* root2 = malloc(sizeof(node));

	puts("Before Deletion");
	printList(root);
	delete(&root,16);
	delete(&root,5);
	printf("\nAfter Deletion\n");
	printList(root);
	return 0;
}
								
		
	