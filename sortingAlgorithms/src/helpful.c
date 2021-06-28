#include "helpful.h"
#include "define.h"
#include <string.h>

void swap(int* first, int* second){
	int temp = *first;
	*first = *second;
	*second = temp;
}

void words_swap(char first[50], char second[50]){
	char temp[50];
	strcpy(temp, first);
	strcpy(first, second);
	strcpy(second, temp);
}

int checkSorting(int* arr, int length, int comp){
	for (int i = 1; i < length; i++){
		switch (comp){
			case INCREASE:
				if (arr[i] < arr[i - 1]){
					return 0;
				}
				break;
			case DECREASE:
				if (arr[i] > arr[i - 1]){
					return 0;
				}
				break;
		}
	}
	return 1;
}

int checkWords(char words[][50], int length, int comp){
	for (int i = 1; i < length; i++){
		switch (comp){
			case ALPHABETICAL:
				if (strcmp(words[i], words[i - 1]) < 0){ 
					return 0;
				}
				break;
			case REVERSE_ALPHABETICAL:
				if (strcmp(words[i], words[i - 1]) > 0){
					return 0;
				}
				break;
		}
	}
	return 1;
}