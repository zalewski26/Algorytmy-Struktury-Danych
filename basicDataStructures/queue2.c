#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
	struct node* next;
};

struct queue{
	struct node* head;
	struct node* tail;
};

struct node* initializeNode(int value){
	struct node* ptr = (struct node*) malloc(sizeof(struct node));

	ptr->value = value;
	ptr->next = NULL;

	return ptr;
}

int isEmpty(struct queue* myQueue){
	if (myQueue->head == NULL){
		return 1;
	}
	return 0;
}

void enqueue(struct queue* myQueue, int value){
	struct node* myNode = initializeNode(value);
	if (myQueue->head == NULL){
		myQueue->head = myNode;
		myQueue->tail = myNode;
	}
	else{
		myQueue->tail->next = myNode;
		myQueue->tail = myNode;
	}
	printf("%d has been added to the queue.\n", value);
}

void dequeue(struct queue* myQueue){
	if (isEmpty(myQueue)){
		printf("Queue is empty!\n");
		return;
	}
	struct node* temp = myQueue->head;
	myQueue->head = myQueue->head->next;
	printf("%d has been removed from the queue.\n", temp->value);
	free(temp);
}

int main(){
	struct queue* myQueue = malloc(sizeof(struct queue));

	for (int i = 0; i < 100; i++){
		enqueue(myQueue, i);
	}

	for (int i = 0; i < 101; i++){
		dequeue(myQueue);
	}
}
