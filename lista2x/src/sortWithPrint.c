#include <stdio.h>
#include <string.h>
#include "define.h"
#include "sortWithPrint.h"
#include "helpful.h"

void insertion_sort(int* arr, int length, int comp){
	switch (comp){
		case INCREASE:
			for (int i = 1; i < length; i++){
				fprintf(stderr, "\n");
				int key = arr[i];
				int pos = i - 1;

				while (pos >= 0 && arr[pos] > key){
					fprintf(stderr, "|comparison| - |%d < %d|\n", key, arr[pos]);
					comparisons++;
					fprintf(stderr, "|   move   | - |%d -> arr[%d]|\n", arr[pos], pos + 1);
					moves++;
					arr[pos + 1] = arr[pos];
					pos--;
				}
				if (pos >= 0){
					fprintf(stderr, "|comparison| - |%d >= %d|\n", key, arr[pos]);
					comparisons++;
				}
				fprintf(stderr, "|   move   | - |%d -> arr[%d]|\n", key, pos + 1);
				moves++;
				arr[pos + 1] = key;
			}
			return;
		case DECREASE:
			for (int i = 1; i < length; i++){
				fprintf(stderr, "\n");
				int key = arr[i];
				int pos = i - 1;
				while (pos >= 0 && arr[pos] < key){
					fprintf(stderr, "|comparison| - |%d > %d|\n", key, arr[pos]);
					comparisons++;
					fprintf(stderr, "|   move   | - |%d -> arr[%d]|\n", arr[pos], pos + 1);
					moves++;
					arr[pos + 1] = arr[pos];
					pos--;
				}
				if (pos >= 0){
					fprintf(stderr, "|comparison| - |%d <= %d|\n", key, arr[pos]);
					comparisons++;
				}
				fprintf(stderr, "|   move   | - |%d -> arr[%d]|\n", key, pos + 1);
				moves++;
				arr[pos + 1] = key;
			}
			return;
	}
}

void merge(int* arr, int first, int last, int middle, int comp){
	int lengthLeft = middle - first + 1;
	int lengthRight = last - middle;
	
	int leftArr[lengthLeft];
	for (int i = 0; i < lengthLeft; i++){
		leftArr[i] = arr[first + i];
	}
	int rightArr[lengthRight];
	for (int i = 0; i < lengthRight; i++){
		rightArr[i] = arr[middle + i + 1];
	}

	int counterL = 0;
	int counterR = 0;

	switch (comp){
		case INCREASE:
			fprintf(stderr, "\n");
			for (int i = first; i <= last; i++){
				if (counterL == lengthLeft){
					while (i <= last){
						fprintf(stderr, "|   move   | - |%d -> arr[%d]|\n", rightArr[counterR], i);
						moves++;
						arr[i] = rightArr[counterR];
						i++;
						counterR++;
					}
					break;
				}
				else if (counterR == lengthRight){
					while (i <= last){
						fprintf(stderr, "|   move   | - |%d -> arr[%d]|\n", leftArr[counterL], i);
						moves++;
						arr[i] = leftArr[counterL];
						i++;
						counterL++;
					}
					break;
				}
				fprintf(stderr, "|comparison| - |%d with %d|\n", leftArr[counterL], rightArr[counterR]);
				comparisons++;
				if (leftArr[counterL] <= rightArr[counterR]){
					fprintf(stderr, "|   move   | - |%d -> arr[%d]|\n", leftArr[counterL], i);
					moves++;
					arr[i] = leftArr[counterL];
					counterL++;
				}
				else{
					fprintf(stderr, "|   move   | - |%d -> arr[%d]|\n", rightArr[counterR], i);
					moves++;
					arr[i] = rightArr[counterR];
					counterR++;
				}
			}
			break;
		case DECREASE:
			fprintf(stderr, "\n");
			for (int i = first; i <= last; i++){
				if (counterL == lengthLeft){
					while (i <= last){
						fprintf(stderr, "|   move   | - |%d -> arr[%d]|\n", rightArr[counterR], i);
						moves++;
						arr[i] = rightArr[counterR];
						i++;
						counterR++;
					}
					break;
				}
				else if (counterR == lengthRight){
					while (i <= last){
						fprintf(stderr, "|   move   | - |%d -> arr[%d]|\n", leftArr[counterL], i);
						moves++;
						arr[i] = leftArr[counterL];
						i++;
						counterL++;
					}
					break;
				}
				fprintf(stderr, "|comparison| - |%d with %d|\n", leftArr[counterL], rightArr[counterR]);
				comparisons++;
				if (leftArr[counterL] >= rightArr[counterR]){
					fprintf(stderr, "|   move   | - |%d -> arr[%d]|\n", leftArr[counterL], i);
					moves++;
					arr[i] = leftArr[counterL];
					counterL++;
				}
				else{
					fprintf(stderr, "|   move   | - |%d -> arr[%d]|\n", rightArr[counterR], i);
					moves++;
					arr[i] = rightArr[counterR];
					counterR++;
				}
			}	
	}
}

void merge_sort(int* arr, int first, int last, int comp){
	if (last > first){
		int middle = (first + last) / 2;
		merge_sort(arr, first, middle, comp);
		merge_sort(arr, middle + 1, last, comp);
		merge(arr, first, last, middle, comp);
	}	
}

int partition(int* arr, int first, int last, int comp){
	int pivot = arr[(first + last) / 2];
	int i = first - 1;
	int j = last + 1;
	
	switch (comp){
		case INCREASE:
			while(1){
				fprintf(stderr, "\n");
				do
				{
					i++;
					fprintf(stderr, "|comparison| - |%d with %d|\n", pivot, arr[i]);
					comparisons++;
				} while (arr[i] < pivot);

				do
				{
					j--;
					fprintf(stderr, "|comparison| - |%d with %d|\n", pivot, arr[j]);
					comparisons++;
				} while (arr[j] > pivot);

				if (i >= j){
					return j;
				}
				fprintf(stderr, "|   swap   | - |%d <-> %d|\n", arr[i], arr[j]);
				moves += 2;
				swap(&arr[i], &arr[j]);
			}
			break;
		case DECREASE:
			while(1){
				fprintf(stderr, "\n");
				do
				{
					i++;
					fprintf(stderr, "|comparison| - |%d with %d|\n", pivot, arr[i]);
					comparisons++;
				} while (arr[i] > pivot);

				do
				{
					j--;
					fprintf(stderr, "|comparison| - |%d with %d|\n", pivot, arr[j]);
					comparisons++;
				} while (arr[j] < pivot);

				if (i >= j){
					return j;
				}
				fprintf(stderr, "|   swap   | - |%d <-> %d|\n", arr[i], arr[j]);
				moves += 2;
				swap(&arr[i], &arr[j]);
			}
			break;		
	}
	return 0;
}

void quick_sort(int* arr, int first, int last, int comp){
	if (first < last){
		int q = partition(arr, first, last, comp);
		quick_sort(arr, first, q, comp);
		quick_sort(arr, q + 1, last, comp);
	}
}

int dual_partition(int* arr, int first, int last, int* right, int comp){
	int l = first + 1;
	int r = last - 1;
	int current = first + 1;
	int left_pivot;
	int right_pivot;

	switch (comp){
		case INCREASE:
			fprintf(stderr, "|comparison| - |%d with %d|\n", arr[first], arr[last]);
			comparisons++;
			if (arr[first] > arr[last]){
				fprintf(stderr, "|   swap   | - |%d <-> %d|\n", arr[first], arr[last]);
				moves += 2;
				swap(&arr[first], &arr[last]);
			}
			left_pivot = arr[first];
			right_pivot = arr[last];

			while (current <= r){
				switch ((l - first) > (last - r)){
					case 1:
						fprintf(stderr, "|comparison| - |%d with %d|\n", arr[current], left_pivot);
						comparisons++;
						if (arr[current] <= left_pivot){
							fprintf(stderr, "|   swap   | - |%d <-> %d|\n", arr[current], arr[l]);
							moves += 2;
							swap(&arr[current], &arr[l]);
							l++;
						}
						else if (arr[current] > right_pivot){
							fprintf(stderr, "|comparison| - |%d with %d|\n", arr[current], right_pivot);
							comparisons++;
							while (current <= r && arr[r] > right_pivot){
								fprintf(stderr, "|comparison| - |%d with %d|\n", arr[r], right_pivot);
								comparisons++;
								r--;
							}
							if (current > r){
								break;
							}
							fprintf(stderr, "|comparison| - |%d with %d|\n", arr[r], right_pivot);
							comparisons++;

							fprintf(stderr, "|   swap   | - |%d <-> %d|\n", arr[current], arr[r]);
							moves += 2;
							swap(&arr[current], &arr[r]);
							r--;

							fprintf(stderr, "|comparison| - |%d with %d|\n", arr[current], left_pivot);
							comparisons++;
							if (arr[current] <= left_pivot){
								fprintf(stderr, "|   swap   | - |%d <-> %d|\n", arr[current], arr[l]);
								moves += 2;
								swap(&arr[current], &arr[l]);
								l++;
							}
						}
						else{
							fprintf(stderr, "|comparison| - |%d with %d|\n", arr[current], right_pivot);
							comparisons++;
						}
						break;
					case 0:
						fprintf(stderr, "|comparison| - |%d with %d|\n", arr[current], right_pivot);
						comparisons++;
						if (arr[current] > right_pivot){
							while (arr[r] > right_pivot && current <= r){
								fprintf(stderr, "|comparison| - |%d with %d|\n", arr[r], right_pivot);
								comparisons++;
								r--;
							}
							if (current > r){
								break;
							}
							fprintf(stderr, "|comparison| - |%d with %d|\n", arr[r], right_pivot);
							comparisons++;

							fprintf(stderr, "|   swap   | - |%d <-> %d|\n", arr[current], arr[r]);
							moves += 2;
							swap(&arr[current], &arr[r]);
							r--;

							fprintf(stderr, "|comparison| - |%d with %d|\n", arr[current], left_pivot);
							comparisons++;
							if (arr[current] <= left_pivot){
								fprintf(stderr, "|   swap   | - |%d <-> %d|\n", arr[current], arr[l]);
								moves += 2;
								swap(&arr[current], &arr[l]);
								l++;
							}
						}
						else if (arr[current] <= left_pivot){
							fprintf(stderr, "|comparison| - |%d with %d|\n", arr[current], left_pivot);
							comparisons++;
							fprintf(stderr, "|   swap   | - |%d <-> %d|\n", arr[current], arr[l]);
							moves += 2;
							swap(&arr[current], &arr[l]);
							l++;
						}
						else{
							fprintf(stderr, "|comparison| - |%d with %d|\n", arr[current], left_pivot);
							comparisons++;
						}
						break;
				}
				current++;
			}
			break;

		case DECREASE:
			fprintf(stderr, "|comparison| - |%d with %d|\n", arr[first], arr[last]);
			comparisons++;
			if (arr[first] < arr[last]){
				fprintf(stderr, "|   swap   | - |%d <-> %d|\n", arr[first], arr[last]);
				moves += 2;
				swap(&arr[first], &arr[last]);
			}
			left_pivot = arr[first];
			right_pivot = arr[last];

			while (current <= r){
				switch ((l - first) > (last - r)){
					case 1:
						fprintf(stderr, "|comparison| - |%d with %d|\n", arr[current], left_pivot);
						comparisons++;
						if (arr[current] >= left_pivot){
							fprintf(stderr, "|   swap   | - |%d <-> %d|\n", arr[current], arr[l]);
							moves += 2;
							swap(&arr[current], &arr[l]);
							l++;
						}
						else if (arr[current] < right_pivot){
							fprintf(stderr, "|comparison| - |%d with %d|\n", arr[current], right_pivot);
							comparisons++;
							while (arr[r] < right_pivot && current <= r){
								fprintf(stderr, "|comparison| - |%d with %d|\n", arr[r], right_pivot);
								comparisons++;
								r--;
							}
							if (current > r){
								break;
							}
							fprintf(stderr, "|comparison| - |%d with %d|\n", arr[r], right_pivot);
							comparisons++;

							fprintf(stderr, "|   swap   | - |%d <-> %d|\n", arr[current], arr[r]);
							moves += 2;
							swap(&arr[current], &arr[r]);
							r--;

							fprintf(stderr, "|comparison| - |%d with %d|\n", arr[current], left_pivot);
							comparisons++;
							if (arr[current] >= left_pivot){
								fprintf(stderr, "|   swap   | - |%d <-> %d|\n", arr[current], arr[l]);
								moves += 2;
								swap(&arr[current], &arr[l]);
								l++;
							}
						}
						else{
							fprintf(stderr, "|comparison| - |%d with %d|\n", arr[current], right_pivot);
							comparisons++;
						}
						break;
					case 0:
						fprintf(stderr, "|comparison| - |%d with %d|\n", arr[current], right_pivot);
						comparisons++;
						if (arr[current] < right_pivot){
							while (arr[r] < right_pivot && current <= r){
								fprintf(stderr, "|comparison| - |%d with %d|\n", arr[r], right_pivot);
								comparisons++;
								r--;
							}
							if (current > r){
								break;
							}
							fprintf(stderr, "|comparison| - |%d with %d|\n", arr[r], right_pivot);
							comparisons++;

							fprintf(stderr, "|   swap   | - |%d <-> %d|\n", arr[current], arr[r]);
							moves += 2;
							swap(&arr[current], &arr[r]);
							r--;

							fprintf(stderr, "|comparison| - |%d with %d|\n", arr[current], left_pivot);
							comparisons++;
							if (arr[current] >= left_pivot){
								fprintf(stderr, "|   swap   | - |%d <-> %d|\n", arr[current], arr[l]);
								moves += 2;
								swap(&arr[current], &arr[l]);
								l++;
							}
						}
						else if (arr[current] >= left_pivot){
							fprintf(stderr, "|comparison| - |%d with %d|\n", arr[current], left_pivot);
							comparisons++;
							fprintf(stderr, "|   swap   | - |%d <-> %d|\n", arr[current], arr[l]);
							moves += 2;
							swap(&arr[current], &arr[l]);
							l++;
						}
						else{
							fprintf(stderr, "|comparison| - |%d with %d|\n", arr[current], left_pivot);
							comparisons++;
						}
						break;
				}
				current++;
			}
			break;	
	}
	
	l--;
	r++;
	fprintf(stderr, "|   swap   | - |%d <-> %d|\n", arr[first], arr[l]);
	moves += 2;
	swap(&arr[first], &arr[l]);
	fprintf(stderr, "|   swap   | - |%d <-> %d|\n", arr[r], arr[last]);
	moves += 2;
	swap(&arr[r], &arr[last]);
	printf("\n");
	*right = r;
	return l;
}

void dual_pivot_quicksort(int* arr, int first, int last, int comp){
	if (first < last){
		int right;
		int left = dual_partition(arr, first, last, &right, comp);
		dual_pivot_quicksort(arr, first, left - 1, comp);
		dual_pivot_quicksort(arr, left + 1, right - 1, comp);
		dual_pivot_quicksort(arr, right + 1, last, comp);
	}
}

void optimized_quick_sort(int* arr, int first, int last, int comp){
	if (first < last){
		if (last - first < 10){
			switch (comp){
				case INCREASE:
					for (int i = first + 1; i <= last; i++){
						int key = arr[i];
						int pos = i - 1;

						while (pos >= 0 && arr[pos] > key){
							fprintf(stderr, "|comparison| - |%d < %d|\n", key, arr[pos]);
							comparisons++;
							fprintf(stderr, "|   move   | - |%d -> arr[%d]|\n", arr[pos], pos + 1);
							moves++;
							arr[pos + 1] = arr[pos];
							pos--;
						}
						if (pos >= 0){
							fprintf(stderr, "|comparison| - |%d >= %d|\n", key, arr[pos]);
							comparisons++;
						}
						fprintf(stderr, "|   move   | - |%d -> arr[%d]|\n", key, pos + 1);
						moves++;
						arr[pos + 1] = key;
					}
					break;

				case DECREASE:
					for (int i = 1; i <= last; i++){
						int key = arr[i];
						int pos = i - 1;
						while (pos >= 0 && arr[pos] < key){
							fprintf(stderr, "|comparison| - |%d > %d|\n", key, arr[pos]);
							comparisons++;
							fprintf(stderr, "|   move   | - |%d -> arr[%d]|\n", arr[pos], pos + 1);
							moves++;
							arr[pos + 1] = arr[pos];
							pos--;
						}
						if (pos >= 0){
							fprintf(stderr, "|comparison| - |%d <= %d|\n", key, arr[pos]);
							comparisons++;
						}
						fprintf(stderr, "|   move   | - |%d -> arr[%d]|\n", key, pos + 1);
						moves++;
						arr[pos + 1] = key;
					}	
					break;
			}	
		}
		else{
			int q = partition(arr, first, last, comp);
			optimized_quick_sort(arr, first, q, comp);
			optimized_quick_sort(arr, q + 1, last, comp);
		}
	}
}

void words_insertion_sort(char words[][50], int length, int comp){
	switch (comp){
		case ALPHABETICAL:
			for (int i = 1; i < length; i++){
				fprintf(stderr, "\n");
				char key[50];
				strcpy(key, words[i]);
				int pos = i - 1;

				while (pos >= 0 && strcmp(words[pos], key) > 0){ 
					fprintf(stderr, "|comparison| - |%s < %s|\n", key, words[pos]);
					comparisons++;
					fprintf(stderr, "|   move   | - |%s -> words[%d]|\n", words[pos], pos + 1);
					moves++;
					strcpy(words[pos + 1], words[pos]);
					pos--;
				}
				if (pos >= 0){
					fprintf(stderr, "|comparison| - |%s >= %s|\n", key, words[pos]);
					comparisons++;
				}
				fprintf(stderr, "|   move   | - |%s -> words[%d]|\n", key, pos + 1);
				moves++;
				strcpy(words[pos + 1], key);
			}
			return;
		case REVERSE_ALPHABETICAL:
			for (int i = 1; i < length; i++){
				char key[50];
				strcpy(key, words[i]);
				int pos = i - 1;
				while (pos >= 0 && strcmp(words[pos], key) < 0){ 
					fprintf(stderr, "|comparison| - |%s > %s|\n", key, words[pos]);
					comparisons++;
					fprintf(stderr, "|   move   | - |%s -> words[%d]|\n", words[pos], pos + 1);
					moves++;
					strcpy(words[pos + 1], words[pos]);
					pos--;
				}
				if (pos >= 0){
					fprintf(stderr, "|comparison| - |%s <= %s|\n", key, words[pos]);
					comparisons++;
				}
				fprintf(stderr, "|   move   | - |%s -> words[%d]|\n", key, pos + 1);
				moves++;
				strcpy(words[pos + 1], key);
			}
			return;
	}
}

void words_merge(char words[][50], int first, int last, int middle, int comp){
	int lengthLeft = middle - first + 1;
	int lengthRight = last - middle;
	
	char leftArr[lengthLeft][50];
	for (int i = 0; i < lengthLeft; i++){
		strcpy(leftArr[i], words[first + i]);
	}
	char rightArr[lengthRight][50];
	for (int i = 0; i < lengthRight; i++){
		strcpy(rightArr[i], words[middle + i + 1]);
	}

	int counterL = 0;
	int counterR = 0;

	switch (comp){
		case ALPHABETICAL:
			for (int i = first; i <= last; i++){
				if (counterL == lengthLeft){
					while (i <= last){
						fprintf(stderr, "|   move   | - |%s -> arr[%d]|\n", rightArr[counterR], i);
						moves++;
						strcpy(words[i], rightArr[counterR]);
						i++;
						counterR++;
					}
					break;
				}
				else if (counterR == lengthRight){
					while (i <= last){
						fprintf(stderr, "|   move   | - |%s -> arr[%d]|\n", leftArr[counterL], i);
						moves++;
						strcpy(words[i], leftArr[counterL]);
						i++;
						counterL++;
					}
					break;
				}
				fprintf(stderr, "|comparison| - |%s with %s|\n", leftArr[counterL], rightArr[counterR]);
				comparisons++;
				if (strcmp(leftArr[counterL], rightArr[counterR]) <= 0){ 
					fprintf(stderr, "|   move   | - |%s -> arr[%d]|\n", leftArr[counterL], i);
					moves++;
					strcpy(words[i], leftArr[counterL]);
					counterL++;
				}
				else{
					fprintf(stderr, "|   move   | - |%s -> arr[%d]|\n", rightArr[counterR], i);
					moves++;
					strcpy(words[i], rightArr[counterR]);
					counterR++;
				}
			}
			break;
		case REVERSE_ALPHABETICAL:
			for (int i = first; i <= last; i++){
				if (counterL == lengthLeft){
					while (i <= last){
						fprintf(stderr, "|   move   | - |%s -> arr[%d]|\n", rightArr[counterR], i);
						moves++;
						strcpy(words[i], rightArr[counterR]);
						i++;
						counterR++;
					}
					break;
				}
				else if (counterR == lengthRight){
					while (i <= last){
						fprintf(stderr, "|   move   | - |%s -> arr[%d]|\n", leftArr[counterL], i);
						moves++;
						strcpy(words[i], leftArr[counterL]);
						i++;
						counterL++;
					}
					break;
				}
				fprintf(stderr, "|comparison| - |%s with %s|\n", leftArr[counterL], rightArr[counterR]);
				comparisons++;
				if (strcmp(leftArr[counterL], rightArr[counterR]) >= 0){
					fprintf(stderr, "|   move   | - |%s -> arr[%d]|\n", leftArr[counterL], i);
					moves++;
					strcpy(words[i], leftArr[counterL]);
					counterL++;
				}
				else{
					fprintf(stderr, "|   move   | - |%s -> arr[%d]|\n", rightArr[counterR], i);
					moves++;
					strcpy(words[i], rightArr[counterR]);
					counterR++;
				}
			}	
	}
}

void words_merge_sort(char words[][50], int first, int last, int comp){
	if (last > first){
		int middle = (first + last) / 2;
		words_merge_sort(words, first, middle, comp);
		words_merge_sort(words, middle + 1, last, comp);
		words_merge(words, first, last, middle, comp);
	}	
}

int words_partition(char words[][50], int first, int last, int comp){
	char pivot[50];
	strcpy(pivot, words[(first + last) / 2]);
	int i = first - 1;
	int j = last + 1;
	
	switch (comp){
		case ALPHABETICAL:
			while(1){
				fprintf(stderr, "\n");
				do
				{
					i++;
					fprintf(stderr, "|comparison| - |%s with %s|\n", pivot, words[i]);
					comparisons++;
				} while (strcmp(words[i], pivot) < 0);

				do
				{
					j--;
					fprintf(stderr, "|comparison| - |%s with %s|\n", pivot, words[j]);
					comparisons++;
				} while (strcmp(words[j], pivot) > 0);

				if (i >= j){
					return j;
				}
				fprintf(stderr, "|   swap   | - |%s <-> %s|\n", words[i], words[j]);
				moves += 2;
				words_swap(words[i], words[j]);
			}
			break;
		case REVERSE_ALPHABETICAL:
			while(1){
				fprintf(stderr, "\n");
				do
				{
					i++;
					fprintf(stderr, "|comparison| - |%s with %s|\n", pivot, words[i]);
					comparisons++;
				} while (strcmp(words[i], pivot) > 0);

				do
				{
					j--;
					fprintf(stderr, "|comparison| - |%s with %s|\n", pivot, words[j]);
					comparisons++;
				} while (strcmp(words[j], pivot) < 0);

				if (i >= j){
					return j;
				}
				fprintf(stderr, "|   swap   | - |%s <-> %s|\n", words[i], words[j]);
				moves += 2;
				words_swap(words[i], words[j]);
			}
			break;		
	}
	return 0;
}

void words_quick_sort(char words[][50], int first, int last, int comp){
	if (first < last){
		int q = words_partition(words, first, last, comp);
		words_quick_sort(words, first, q, comp);
		words_quick_sort(words, q + 1, last, comp);
	}
}

int words_dual_partition(char words[][50], int first, int last, int* right, int comp){
	int l = first + 1;
	int r = last - 1;
	int current = first + 1;
	char left_pivot[50];
	char right_pivot[50];

	switch (comp){
		case ALPHABETICAL:
			fprintf(stderr, "|comparison| - |%s with %s|\n", words[first], words[last]);
			comparisons++;
			if (strcmp(words[first], words[last]) > 0){
				fprintf(stderr, "|   swap   | - |%s <-> %s|\n", words[first], words[last]);
				moves += 2;
				words_swap(words[first], words[last]);
			}
			strcpy(left_pivot, words[first]);
			strcpy(right_pivot, words[last]);

			while (current <= r){
				switch ((l - first) > (last - r)){
					case 1:
						fprintf(stderr, "|comparison| - |%s with %s|\n", words[current], left_pivot);
						comparisons++;
						if (strcmp(words[current], left_pivot) <= 0){
							fprintf(stderr, "|   swap   | - |%s <-> %s|\n", words[current], words[l]);
							moves += 2;
							words_swap(words[current], words[l]);
							l++;
						}
						else if (strcmp(words[current], right_pivot) > 0){
							fprintf(stderr, "|comparison| - |%s with %s|\n", words[current], right_pivot);
							comparisons++;
							while (current <= r && strcmp(words[r], right_pivot) > 0){
								fprintf(stderr, "|comparison| - |%s with %s|\n", words[r], right_pivot);
								comparisons++;
								r--;
							}
							if (current > r){
								break;
							}
							fprintf(stderr, "|comparison| - |%s with %s|\n", words[r], right_pivot);
							comparisons++;

							fprintf(stderr, "|   swap   | - |%s <-> %s|\n", words[current], words[r]);
							moves += 2;
							words_swap(words[current], words[r]);
							r--;

							fprintf(stderr, "|comparison| - |%s with %s|\n", words[current], left_pivot);
							comparisons++;
							if (words[current] <= left_pivot){
								fprintf(stderr, "|   swap   | - |%s <-> %s|\n", words[current], words[l]);
								moves += 2;
								words_swap(words[current], words[l]);
								l++;
							}
						}
						else{
							fprintf(stderr, "|comparison| - |%s with %s|\n", words[current], right_pivot);
							comparisons++;
						}
						break;
					case 0:
						fprintf(stderr, "|comparison| - |%s with %s|\n", words[current], right_pivot);
						comparisons++;
						if (words[current] > right_pivot){
							while (current <= r && strcmp(words[r], right_pivot) > 0){
								fprintf(stderr, "|comparison| - |%s with %s|\n", words[r], right_pivot);
								comparisons++;
								r--;
							}
							if (current > r){
								break;
							}
							fprintf(stderr, "|comparison| - |%s with %s|\n", words[r], right_pivot);
							comparisons++;

							fprintf(stderr, "|   swap   | - |%s <-> %s|\n", words[current], words[r]);
							moves += 2;
							words_swap(words[current], words[r]);
							r--;

							fprintf(stderr, "|comparison| - |%s with %s|\n", words[current], left_pivot);
							comparisons++;
							if (strcmp(words[current], left_pivot) <= 0){
								fprintf(stderr, "|   swap   | - |%s <-> %s|\n", words[current], words[l]);
								moves += 2;
								words_swap(words[current], words[l]);
								l++;
							}
						}
						else if (words[current] <= left_pivot){
							fprintf(stderr, "|comparison| - |%s with %s|\n", words[current], left_pivot);
							comparisons++;
							fprintf(stderr, "|   swap   | - |%s <-> %s|\n", words[current], words[l]);
							moves += 2;
							words_swap(words[current], words[l]);
							l++;
						}
						else{
							fprintf(stderr, "|comparison| - |%s with %s|\n", words[current], left_pivot);
							comparisons++;
						}
						break;
				}
				current++;
			}
			break;

		case REVERSE_ALPHABETICAL:
			fprintf(stderr, "|comparison| - |%s with %s|\n", words[first], words[last]);
			comparisons++;
			if (strcmp(words[first], words[last]) < 0){
				fprintf(stderr, "|   swap   | - |%s <-> %s|\n", words[first], words[last]);
				moves += 2;
				words_swap(words[first], words[last]);
			}
			strcpy(left_pivot, words[first]);
			strcpy(right_pivot, words[last]);

			while (current <= r){
				switch ((l - first) > (last - r)){
					case 1:
						fprintf(stderr, "|comparison| - |%s with %s|\n", words[current], left_pivot);
						comparisons++;
						if (strcmp(words[current], left_pivot) >= 0){
							fprintf(stderr, "|   swap   | - |%s <-> %s|\n", words[current], words[l]);
							moves += 2;
							words_swap(words[current], words[l]);
							l++;
						}
						else if (strcmp(words[current], right_pivot) < 0){
							fprintf(stderr, "|comparison| - |%s with %s|\n", words[current], right_pivot);
							comparisons++;
							while (words[r] < right_pivot && current <= r){
								fprintf(stderr, "|comparison| - |%s with %s|\n", words[r], right_pivot);
								comparisons++;
								r--;
							}
							if (current > r){
								break;
							}
							fprintf(stderr, "|comparison| - |%s with %s|\n", words[r], right_pivot);
							comparisons++;

							fprintf(stderr, "|   swap   | - |%s <-> %s|\n", words[current], words[r]);
							moves += 2;
							words_swap(words[current], words[r]);
							r--;

							fprintf(stderr, "|comparison| - |%s with %s|\n", words[current], left_pivot);
							comparisons++;
							if (strcmp(words[current], left_pivot) >= 0){
								fprintf(stderr, "|   swap   | - |%s <-> %s|\n", words[current], words[l]);
								moves += 2;
								words_swap(words[current], words[l]);
								l++;
							}
						}
						else{
							fprintf(stderr, "|comparison| - |%s with %s|\n", words[current], right_pivot);
							comparisons++;
						}
						break;
					case 0:
						fprintf(stderr, "|comparison| - |%s with %s|\n", words[current], right_pivot);
						comparisons++;
						if (strcmp(words[current], right_pivot) < 0){
							while (current <= r && strcmp(words[r], right_pivot) < 0){
								fprintf(stderr, "|comparison| - |%s with %s|\n", words[r], right_pivot);
								comparisons++;
								r--;
							}
							if (current > r){
								break;
							}
							fprintf(stderr, "|comparison| - |%s with %s|\n", words[r], right_pivot);
							comparisons++;

							fprintf(stderr, "|   swap   | - |%s <-> %s|\n", words[current], words[r]);
							moves += 2;
							words_swap(words[current], words[r]);
							r--;

							fprintf(stderr, "|comparison| - |%s with %s|\n", words[current], left_pivot);
							comparisons++;
							if (strcmp(words[current], left_pivot) >= 0){
								fprintf(stderr, "|   swap   | - |%s <-> %s|\n", words[current], words[l]);
								moves += 2;
								words_swap(words[current], words[l]);
								l++;
							}
						}
						else if (strcmp(words[current], left_pivot) >= 0){
							fprintf(stderr, "|comparison| - |%s with %s|\n", words[current], left_pivot);
							comparisons++;
							fprintf(stderr, "|   swap   | - |%s <-> %s|\n", words[current], words[l]);
							moves += 2;
							words_swap(words[current], words[l]);
							l++;
						}
						else{
							fprintf(stderr, "|comparison| - |%s with %s|\n", words[current], left_pivot);
							comparisons++;
						}
						break;
				}
				current++;
			}
			break;	
	}
	
	l--;
	r++;
	fprintf(stderr, "|   swap   | - |%s <-> %s|\n", words[first], words[l]);
	moves += 2;
	words_swap(words[first], words[l]);
	fprintf(stderr, "|   swap   | - |%s <-> %s|\n", words[r], words[last]);
	moves += 2;
	words_swap(words[r], words[last]);
	printf("\n");
	*right = r;
	return l;
}

void words_dual_pivot_quicksort(char words[][50], int first, int last, int comp){
	if (first < last){
		int right;
		int left = words_dual_partition(words, first, last, &right, comp);
		words_dual_pivot_quicksort(words, first, left - 1, comp);
		words_dual_pivot_quicksort(words, left + 1, right - 1, comp);
		words_dual_pivot_quicksort(words, right + 1, last, comp);
	}
}

void words_optimized_quick_sort(char words[][50], int first, int last, int comp){
	if (first < last){
		if (last - first < 10){
			switch (comp){
				case ALPHABETICAL:
					for (int i = first + 1; i <= last; i++){
						char key[50];
						strcpy(key, words[i]);
						int pos = i - 1;

						while (pos >= 0 && strcmp(words[pos], key) > 0){
							fprintf(stderr, "|comparison| - |%s > %s|\n", words[pos], key);
							comparisons++;
							fprintf(stderr, "|   move   | - |%s -> arr[%d]|\n", words[pos], pos + 1);
							moves++;
							strcpy(words[pos + 1], words[pos]);
							pos--;
						}
						if (pos >= 0){
							fprintf(stderr, "|comparison| - |%s <= %s|\n", words[pos], key);
							comparisons++;
						}
						fprintf(stderr, "|   move   | - |%s -> arr[%d]|\n", key, pos + 1);
						moves++;
						strcpy(words[pos + 1], key);
					}
					break;

				case REVERSE_ALPHABETICAL:
					for (int i = 1; i <= last; i++){
						char key[50];
						strcpy(key, words[i]);
						int pos = i - 1;
						while (pos >= 0 && strcmp(words[pos], key) < 0){
							fprintf(stderr, "|comparison| - |%s > %s|\n", key, words[pos]);
							comparisons++;
							fprintf(stderr, "|   move   | - |%s -> arr[%d]|\n", words[pos], pos + 1);
							moves++;
							strcpy(words[pos + 1], words[pos]);
							pos--;
						}
						if (pos >= 0){
							fprintf(stderr, "|comparison| - |%s <= %s|\n", key, words[pos]);
							comparisons++;
						}
						fprintf(stderr, "|   move   | - |%s -> arr[%d]|\n", key, pos + 1);
						moves++;
						strcpy(words[pos + 1], key);
					}	
					break;
			}	
		}
		else{
			int q = words_partition(words, first, last, comp);
			words_optimized_quick_sort(words, first, q, comp);
			words_optimized_quick_sort(words, q + 1, last, comp);
		}
	}
}