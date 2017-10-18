#include <stdio.h>

int main(){
	char test[] = "porfavordama";
	printf("Message = %s\n",test);
	printf("Stored at : %p\n",test);
	printf("Size (With sentinel char included): %lu\n",sizeof(test));
}