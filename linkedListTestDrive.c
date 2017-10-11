#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int x;
	struct n* next;
}node;

void addElement(node* r,int x){
	while(r->next != NULL){
		r = r->next;
	}
		r->next = (node*)malloc(sizeof(node));
		r->next->x=x;
		r->next->next=NULL;
}


void printList(node* r){
	while( r != NULL){
		printf("%d\n",r->x);
		r = r->next;
	}
}

void delete(node** r,int x, node* r1){
	node* toBeDeleted;
	node* newRoot = r1;
	int endOfList = 0;
	while(endOfList !=1){
		if( (*r)->x == x){ 			//If the element you want to delete is the root of the list...
			toBeDeleted = (*r);		//...we are going to delete it and change the pointer to root with the new one.
			*r = (*r)->next;		//Then you have to check the list again with "continue" to see
			newRoot = *(r);			//...whether the data you want to delete is again in the root of your list or not.
			free(toBeDeleted);		//We also have to update the newRoot to be able to delete other elements if asked.
			continue;
		} 
		if(newRoot->next->x == x){ 					//If the element you want to delete is amongst the other elements...
			toBeDeleted = newRoot->next;			//...this will run to check whether your next element is the one...
			newRoot->next = toBeDeleted->next;		//...you want to delete. If so, the next element of the element...
			free(toBeDeleted);						//...you want to delete will be assigned to the current element's next not to...
			if(newRoot->next == NULL){ 				//...lose the rest of the list. If the newRoot's next element is NULL
				endOfList = 1;		   				//...that means we are at the end of the list so atTheEnd must be assigned 1.
				continue;
			}
			else
				continue;
		}
		
		newRoot = newRoot->next;
		if(newRoot->next == NULL){
			endOfList =1;
		}
	}
}
	
	

int main(){
	node* root;
	root = (node*)malloc(sizeof(node));
	root->next = NULL;
	root->x = 13;
	addElement(root,13);
	addElement(root,500);
	addElement(root,13);
	addElement(root,500);
	addElement(root,82);
	addElement(root,18);
	addElement(root,13);
	addElement(root,500);
	
	for(int i = 0; i < 5;i++){
		addElement(root,i*5);
	}
	addElement(root,13);
	printList(root);
	delete(&root,13,root);
	printf("\n");
	printList(root);
	return 0;
}
								
		
	