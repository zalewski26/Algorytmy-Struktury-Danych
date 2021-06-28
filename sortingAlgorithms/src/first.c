#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "define.h"
#include "ex.h"
#include "sortWithPrint.h"
#include "helpful.h"

void firstEx(int type, int comp){
	int length;
	printf("Pass the size of an array:\n");
	scanf("%d", &length);
	printf("Pass the values:\n");
	int arr[length];
	char words[length][50];

	if (comp == INCREASE || comp == DECREASE){
		for (int i = 0; i < length; i++){
			scanf("%d", &arr[i]);
		}
	}
	else{
		for (int i = 0; i < length; i++){
			scanf("%s", words[i]);
		}
	}

	clock_t tic = clock();
	if (comp == INCREASE || comp == DECREASE){
		switch (type){
			case INSERT:
				insertion_sort(arr, length, comp);
				break;
			case MERGE:
				merge_sort(arr, 0, length - 1, comp);
				break;
			case QUICK:
				quick_sort(arr, 0, length - 1, comp);		
				break;
			case DUAL:
				dual_pivot_quicksort(arr, 0, length - 1, comp);
				break;
			case HYBRID:
				optimized_quick_sort(arr, 0, length - 1, comp);
				break;	
		}
	}
	else{
		switch (type){
			case INSERT:
				words_insertion_sort(words, length, comp);
				break;
			case MERGE:
				words_merge_sort(words, 0, length - 1, comp);
				break;
			case QUICK:
				words_quick_sort(words, 0, length - 1, comp);		
				break;
			case DUAL:
				words_dual_pivot_quicksort(words, 0, length - 1, comp);
				break;
			case HYBRID:
				words_optimized_quick_sort(words, 0, length - 1, comp);
				break;
		}
	}
	clock_t toc = clock();

	if (comp == INCREASE || comp == DECREASE){
		if (!checkSorting(arr, length, comp)){
			printf("Sorting error!\n");
			return;
		}
	}
	else if (!checkWords(words, length, comp)){
		printf("Sorting error!\n");
		return;
	}

	fprintf(stderr, "\nTotal number of comparisons: %d\n", comparisons);
	fprintf(stderr, "Total number of  moves: %d\n", moves);
	fprintf(stderr, "Total time: %f\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	
	printf("\nAfter sorting:\n");
	if (comp == INCREASE || comp == DECREASE){
		for (int i = 0; i < length; i++){
			printf("%d ", arr[i]);
		}
	}
	else{
		for (int i = 0; i < length; i++){
			printf("%s ", words[i]);
		}
	}
	printf("\n");
}
