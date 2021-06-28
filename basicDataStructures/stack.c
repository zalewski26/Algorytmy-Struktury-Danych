#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct stack{
	int size;
	int top;
	int* plates;
};

struct stack* initializeStack(int size){
    struct stack *ptr = (struct stack*) malloc(sizeof(struct stack));

    ptr->size = size;
    ptr->top = -1;
    ptr->plates = malloc(sizeof(int) * size);
 
    return ptr;
}

int isFull(struct stack* myStack){
	if (myStack->top == myStack->size - 1){
		return 1;
	}
	return 0;
}

int isEmpty(struct stack* myStack){
	if (myStack->top == -1){
		return 1;
	}
	return 0;
}

void push(struct stack* myStack, int value){
	if (isFull(myStack)){
		printf("Stack is already full!\n");
		return;
	}
	(myStack->top)++;
	myStack->plates[myStack->top] = value;
	printf("%d has been pushed onto the stack.\n", value);
}

void pop(struct stack* myStack){
	if (isEmpty(myStack)){
		printf("Stack is empty!\n");
		return;
	}
	printf("%d popped out of the stack!\n", myStack->plates[myStack->top]);
	(myStack->top)--;
}

int main(){
	struct stack* myStack = initializeStack(SIZE);

	for (int i = 0; i < SIZE + 1; i++){
		push(myStack, i);
	}

	for (int i = 0; i < SIZE + 1; i++){
		pop(myStack);
	}

}