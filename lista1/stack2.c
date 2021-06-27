#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
	struct node* next;
};

struct node* initializeNode(int value){
    struct node *ptr = (struct node*) malloc(sizeof(struct node));

    ptr->value = value;
	ptr->next = NULL;
 
    return ptr;
}

int isEmpty(struct node* myNode){
	return !myNode;
}

void push(struct node** myNode, int value){
	struct node* newNode = initializeNode(value);
	newNode->next = *myNode;
	*myNode = newNode;
	printf("%d has been pushed onto the stack.\n", value);
}

void pop(struct node** myNode){
	if (isEmpty(*myNode)){
		printf("Stack is empty!\n");
		return;
	}
	struct node* temp = *myNode;
	*myNode = (*myNode)->next;
	printf("%d popped out of the stack!\n", temp->value);
	free(temp);
}

int main(){
	struct node* stack = NULL;

	for (int i = 0; i < 100; i++){
		push(&stack, i);
	}

	for (int i = 0; i < 101; i++){
		pop(&stack);
	}

}


