#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct queue{
	int size;
	int head;
	int tail;
	int* items;
};

struct queue* initializeQueue(int size){
	struct queue* ptr = (struct queue*) malloc(sizeof(struct queue));

	ptr->size = size;
	ptr->head = 0;
	ptr->tail = 0;
	ptr->items = malloc(sizeof(int) * size);

	return ptr;
}

int isEmpty(struct queue* myQueue){
	if (myQueue->head == myQueue->tail){
		return 1;
	}
	return 0;
}

int isFull(struct queue* myQueue){
	if ((myQueue->tail + 1) % myQueue->size == myQueue->head){
		return 1;
	}
	return 0;
}

void enqueue(struct queue* myQueue, int value){
	if (isFull(myQueue)){
		printf("Queue is already full!\n");
		return;
	}
	myQueue->items[myQueue->tail] = value;
	printf("%d has been added to the queue.\n", value);
	myQueue->tail = (myQueue->tail + 1) % myQueue->size;
}

void dequeue(struct queue* myQueue){
	if (isEmpty(myQueue)){
		printf("Queue is empty!\n");
		return;
	}
	printf("%d has been removed from the queue.\n", myQueue->items[myQueue->head]);
	(myQueue->head) = (myQueue->head + 1) % myQueue->size;
}

int main(){
	struct queue* myQueue = initializeQueue(SIZE);

	for (int i = 0; i < SIZE; i++){
		enqueue(myQueue, i);
	}

	for (int i = 0; i < SIZE; i++){
		dequeue(myQueue);
	}
}