#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH 1000
#define TEST1 28
#define TEST2 194
#define TEST3 879

struct node{
	int value;
	struct node* next;
};

struct node* initializeNode(int value){
	struct node* ptr = (struct node*) malloc(sizeof(struct node));

	ptr->value = value;
	ptr->next = NULL;

	return ptr;
}

int search(struct node* root, int value){
	struct node* temp = root;
	int counter = 0;
	while (temp != NULL && temp->value != value){
		temp = temp->next;
		counter ++;
	}
	if (temp != NULL){
		return counter;
	}
	return -1;
}

void insert(struct node** root, int value){
	struct node* newNode = initializeNode(value);
	newNode->next = *root;
	*root = newNode;
}

void delete(struct node** root, int value){
	if (*root == NULL){
		return;
	}
	struct node* temp = *root;
	if (temp->value == value){
		*root = temp->next;
		free(temp);
		return;
	}
	struct node* prev = NULL;

	while (temp != NULL && temp->value != value){
		prev = temp;
		temp = temp->next;
	}

	if (temp != NULL){
		prev->next = temp->next;
		free(temp);
	}
}

void show(struct node* root){
	struct node* temp = root;
	while (temp != NULL){
		printf("%d -> ", temp->value);
		temp = temp->next;
	}
	printf("NULL \n");
}

int* prepareArr(){
	int* arr = malloc(sizeof (int) * LENGTH);

	for (int i = 0; i < LENGTH; i++){
		arr[i] = i;
	}

	for (int i = 0; i < LENGTH - 1; i++){
		int random = i + 1 + (rand() % (LENGTH - 1 - i));
		int temp = arr[i];
		arr[i] = arr[random];
		arr[random] = temp;
	}

	return arr;
}

void merge(struct node** first, struct node** second){
	if (*first == NULL){
		*first = *second;
	}
	else{
		struct node* temp = *first;

		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = *second;
	}
}

int main(){
	srand(time(0));
	struct node* root;
	int* arr;

	double avg1 = 0;
	double avg2 = 0;
	double avg3 = 0;
	double avgRand = 0;

	for (int i = 0; i < 1000; i++){
		root = NULL;
		arr = prepareArr();
		for (int i = 0; i < LENGTH; i++){
			insert(&root, arr[i]);
		}

		avg1 += search(root, TEST1);
		avg2 += search(root, TEST2);
		avg3 += search(root, TEST3);
		avgRand += search(root, rand() % LENGTH);
	}
	avg1 /= 1000;
	avg2 /= 1000;
	avg3 /= 1000;
	avgRand /= 1000;

	printf("Średnia liczba przejść w 1000-elementowych listach jednokierunkowych w poszukiwaniu wartości:\n");
	printf("%d = %lf\n%d = %lf\n%d = %lf\nlosowa wartość = %lf\n\n",TEST1, avg1, TEST2, avg2, TEST3, avg3, avgRand);

	root = NULL;
	struct node* root2 = NULL;

	insert(&root, 4);
	insert(&root, 3);
	insert(&root, 2);
	insert(&root, 1);
	insert(&root2, 7);
	insert(&root2, 6);
	insert(&root2, 5);

	printf("Lista 1:\n");
	show(root);
	printf("Lista 2:\n");
	show(root2);
	printf("Efekt scalenia list 1 i 2:\n");
	merge(&root, &root2);
	show(root);
}