#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int x;
	struct n* next;
	struct n* prev;
}node;

void printList(node* r){
	while(r !=NULL){ // Liste boş değilse elemanları yazdırır.
		printf("%i\n",r->x);
		r = r->next;
	}
}

void printBackwards(node* r){ // Prev pointerlarını kullanarak diziyi tersten yazdırır.
	if(r != NULL){ //Eğer dizi boş değilse ya da tüm elemanlar silinmemişse - çalışır.
	node* iter = r;
	while(iter->next != NULL){
		iter = iter->next;
	}
	while(iter !=NULL){
		printf("%i\n", iter->x);
		iter= iter->prev;
	}
	}else {
		printf("\nDizideki tüm elemanlar silinmiş olabilir. :( \nYeni elemanlar ekleyebilirsiniz ya da silinenlerden birkaçını silmek istemeyebilirsiniz.^^\n");
	}
}

void addInOrder(node** r,int x){
	
	if((*r) == NULL){ 		// Liste boş ise öncelikle memory allocate ederek başlar.
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
	int endOfList = 0;		//Listenin sonuna gelip gelmediğimizi kontrol edeceğimiz değişken.
	node* toBeDeleted;		// silinecek elemanlar buraya alınacak.
	node* newRoot = *r; 	//Eğer ilk eleman silinirse vs. yeni atanacak olan pointerı tutacak değişken.
	while(endOfList != 1){	//Listenin sonuna gelmediğimiz sürece çalışır...
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

			if((*r)->next == NULL && (*r)->x != x){ // Eğer listede 2 item kaldıysa, biz baştaki itemi yukarıda sildiysek... 
				endOfList = 1;		//...ve son kalan item de aynı değilse (çünkü aynı olan tüm elemanları siliyoruz). listenin sonundayız.
				continue;
			}
						
			continue;
		}
		
		if(newRoot->next->x == x){ 						//Eğer silmek istediğimiz eleman aradaysa.
			toBeDeleted = newRoot->next;
			newRoot->next = toBeDeleted->next;
			if(toBeDeleted->next != NULL){				//Dizi sonundaki elemanı silip silmediğimizi kontrol ediyoruz.
			toBeDeleted->next->prev = toBeDeleted->prev;	//Eğer dizi sonundaki bir elemanı silmiyorsak
			}else {											//next elemanın prev'ini sileceğimiz elemanın prev'i ile bağlıyoruz.
				free(toBeDeleted);
				endOfList = 1;
				continue;
			}
			free(toBeDeleted);
			continue;
		}
		   
		newRoot = newRoot->next;
		if(newRoot->next == NULL){
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
	