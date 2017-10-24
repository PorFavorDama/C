#include <stdio.h>
#include <stdlib.h>

/* 
//Compile this code like so, "gcc -g ....." -along with the debug info- to see whether the code works properly or not.
//Then run the code using "valgrind --leak-check=full ./filename" to see if you have any memory leak or not.
//Also by doing so you can realize your code works properly...
//...as to how it allocates memory and if you overflow valgrind will notice that and warn you.
*/
typedef struct s{
	int size;
	int top;
	int* arr; //pointer to int , which will point to our first element.
}stack;

stack* defineStack(){
	stack* s = malloc(sizeof(stack));
	
	s->arr = NULL;
	s->size = 2;
	s->top = 0;
	
	return s;
}

void push(int a, stack* ptr){
	
	
	if(ptr->arr == NULL){
		ptr->arr = malloc(2*sizeof *(ptr->arr));
	}
	
	
	if(ptr->top == ptr->size){
		int* arr2 = malloc(ptr->size*2*sizeof *arr2);
		for(int i = 0; i < ptr->size ; i++){
			arr2[i] = ptr->arr[i];
		}
		free(ptr->arr);
		ptr->arr = arr2;
		
		ptr->size *= 2;
	}
	
		ptr->arr[ptr->top++] = a;
	
}

int pop(stack* ptr){
	if(ptr->top <= (ptr->size/2)){
		int* arr2 = malloc((ptr->size/2)*sizeof *arr2); //Note the usage of size of here.
		for(int i=0; i < ptr->top; i++){
			arr2[i] = ptr->arr[i];
		}
		
		free(ptr->arr);
		ptr->arr = arr2;
		ptr->size /=2;
	}
		return ptr->arr[--ptr->top];
}

void printStack(stack* ptr){
	for(int i = 0; i < ptr->top ; i++){
		printf("%d\n",ptr->arr[i]);
	}
}

int main(){
	stack* foo = defineStack();
	
	push(10, foo);
	push(10, foo);
	push(10, foo);
	push(10, foo);
	push(10, foo);
	push(10, foo);
	push(30, foo);
	push(40, foo);
	push(40, foo);
	push(40, foo);
	push(40, foo);
	push(40, foo);
	push(40, foo);
	push(40, foo);
	push(50, foo);
	push(50, foo);
	push(50, foo);
	
	
	
	
	printStack(foo);
	
	printf("Array size %i\n",foo->size); //Gives us the size of our stack, in other words, the memory allocated.
	printf("Array top (number of elements in the stack) %i\n",foo->top); //The number of elements in our stack.
	
	puts("---------- AFTER -----------");
	
	printf("popped -> %d\n",pop(foo)); //A few pop examples.
	printf("popped -> %d\n",pop(foo));
	printf("popped -> %d\n",pop(foo));
	printf("popped -> %d\n",pop(foo));
	printf("popped -> %d\n",pop(foo));
	printf("popped -> %d\n",pop(foo));
	printf("popped -> %d\n",pop(foo));
	printf("popped -> %d\n",pop(foo));
	printf("popped -> %d\n",pop(foo));
	printf("popped -> %d\n",pop(foo));
	printf("popped -> %d\n",pop(foo));
	printf("popped -> %d\n",pop(foo));
		
	printf("Array size %i\n",foo->size); //And our last size NOTE THAT IT SHRINKS.
	printf("Array top (number of elements in the stack) %i\n",foo->top); //Number of elements in the stack.
	
	free(foo->arr); //Don't forget to free the pointer inside the struct...
	free(foo);		//...and the pointer to the struct itself.
}