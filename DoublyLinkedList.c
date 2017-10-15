#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int x;
	struct n* next;
	struct n* prev;
}node;

void printList(node* r){
	while(r !=NULL){
		printf("%i\n",r->x);
		r = r->next;
	}
}

void addInOrder(node** r,int x){
	
	if((*r) == NULL){
		*r = malloc(sizeof(node));
		(*r)->next = NULL;
		(*r)->prev = NULL;
		(*r)->x = x;
		return;
	}
	if((*r)->x > x){
		node* toBePrepended = malloc(sizeof(node));
		toBePrepended->x = x;
		toBePrepended->prev = NULL;
		toBePrepended->next = *r;
		*r = toBePrepended;
		return;
	}
	
	node* iter = *r;
	while(iter->next != NULL){
		iter = iter ->next;
	}
	iter->next = malloc(sizeof(node));
	iter->next->prev =iter;
	iter->next->x = x;	
	iter->next->next = NULL;

}


int main(){
	node* root;
	root = NULL;
	addInOrder(&root,5);
	addInOrder(&root,4);
	addInOrder(&root,3);
	addInOrder(&root,1);
	addInOrder(&root,7);


	puts("Before Deletion");
	printList(root);
	printf("\nAfter Deletion\n");
	printList(root);
	return 0;
}
	