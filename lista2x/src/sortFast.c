#include "define.h"
#include "sortFast.h"
#include "helpful.h"
#include <string.h>

void fast_insertion_sort(int* arr, int length){
	for (int i = 1; i < length; i++){
		int key = arr[i];
		int pos = i - 1;

		while (pos >= 0 && arr[pos] > key){
			comparisons++;
			moves++;
			arr[pos + 1] = arr[pos];
			pos--;
		}
		if (pos >= 0){
			comparisons++;
		}
		moves++;
		arr[pos + 1] = key;
	}
	return;
}

void fast_merge(int* arr, int first, int last, int middle){
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

	for (int i = first; i <= last; i++){
		if (counterL == lengthLeft){
			while (i <= last){
				moves++;
				arr[i] = rightArr[counterR];
				i++;
				counterR++;
			}
			break;
		}
		else if (counterR == lengthRight){
			while (i <= last){
				moves++;
				arr[i] = leftArr[counterL];
				i++;
				counterL++;
			}
			break;
		}
		comparisons++;
		if (leftArr[counterL] <= rightArr[counterR]){
			moves++;
			arr[i] = leftArr[counterL];
			counterL++;
		}
		else{
			moves++;
			arr[i] = rightArr[counterR];
			counterR++;
		}
	}
}

void fast_merge_sort(int* arr, int first, int last){
	if (last > first){
		int middle = (first + last) / 2;
		fast_merge_sort(arr, first, middle);
		fast_merge_sort(arr, middle + 1, last);
		fast_merge(arr, first, last, middle);
	}	
}

int fast_partition(int* arr, int first, int last){
	int pivot = arr[(first + last) / 2];
	int i = first - 1;
	int j = last + 1;
	
	while(1){
		do
		{
			i++;
			comparisons++;
		} while (arr[i] < pivot);

		do
		{
			j--;
			comparisons++;
		} while (arr[j] > pivot);

		if (i >= j){
			return j;
		}
		moves += 2;
		swap(&arr[i], &arr[j]);
	}
	return 0;
}

void quicker_sort(int* arr, int first, int last){
	if (first < last){
		int q = fast_partition(arr, first, last);
		quicker_sort(arr, first, q);
		quicker_sort(arr, q + 1, last);
	}
}

int fast_dual_partition(int* arr, int first, int last, int* right){
	int l = first + 1;
	int r = last - 1;
	int current = first + 1;
	int left_pivot;
	int right_pivot;

	comparisons++;
	if (arr[first] > arr[last]){
		moves += 2;
		swap(&arr[first], &arr[last]);
	}
	left_pivot = arr[first];
	right_pivot = arr[last];

	while (current <= r){
		switch ((l - first) > (last - r)){
			case 1:
				comparisons++;
				if (arr[current] <= left_pivot){
					moves += 2;
					swap(&arr[current], &arr[l]);
					l++;
				}
				else if (arr[current] > right_pivot){
					comparisons++;
					while (current <= r && arr[r] > right_pivot){
						comparisons++;
						r--;
					}
					if (current > r){
						break;
					}
					comparisons++;			
					moves += 2;
					swap(&arr[current], &arr[r]);
					r--;			
				
					comparisons++;
					if (arr[current] <= left_pivot){				
						moves += 2;
						swap(&arr[current], &arr[l]);
						l++;
					}
				}
				else{		
					comparisons++;
				}
				break;
			case 0:
				comparisons++;
				if (arr[current] > right_pivot){
					while (current <= r && arr[r] > right_pivot){	
						comparisons++;
						r--;
					}
					if (current > r){
						break;
					}	
					comparisons++;							
					moves += 2;
					swap(&arr[current], &arr[r]);
					r--;
		
					comparisons++;
					if (arr[current] <= left_pivot){			
						moves += 2;
						swap(&arr[current], &arr[l]);
						l++;
					}
				}
				else if (arr[current] <= left_pivot){	
					comparisons++;		
					moves += 2;
					swap(&arr[current], &arr[l]);
					l++;
				}
				else{
					comparisons++;
				}
				break;
		}
		current++;
	}
	
	l--;
	r++;
	moves += 2;
	swap(&arr[first], &arr[l]);
	moves += 2;
	swap(&arr[r], &arr[last]);
	*right = r;
	return l;
}

void fast_dual_pivot_quicksort(int* arr, int first, int last){
	if (first < last){
		int right;
		int left = fast_dual_partition(arr, first, last, &right);
		fast_dual_pivot_quicksort(arr, first, left - 1);
		fast_dual_pivot_quicksort(arr, left + 1, right - 1);
		fast_dual_pivot_quicksort(arr, right + 1, last);
	}
}

void fast_optimized_quick_sort(int* arr, int first, int last){
	if (first < last){
		if (last - first < 10){
			for (int i = first + 1; i <= last; i++){
				int key = arr[i];
				int pos = i - 1;

				while (pos >= 0 && arr[pos] > key){
					comparisons++;
					moves++;
					arr[pos + 1] = arr[pos];
					pos--;
				}
				if (pos >= 0){
					comparisons++;
				}
				moves++;
				arr[pos + 1] = key;
			}
		}
		else{
			int q = fast_partition(arr, first, last);
			fast_optimized_quick_sort(arr, first, q);
			fast_optimized_quick_sort(arr, q + 1, last);
		}
	}
}

void words_fast_insertion_sort(char arr[][50], int length){
	for (int i = 1; i < length; i++){
		char key[50];
		strcpy(key, arr[i]);
		int pos = i - 1;

		while (pos >= 0 && strcmp(arr[pos], key) > 0){
			comparisons++;
			moves++;
			strcpy(arr[pos + 1], arr[pos]);
			pos--;
		}
		if (pos >= 0){
			comparisons++;
		}
		moves++;
		strcpy(arr[pos + 1], key);
	}
	return;
}

void words_fast_merge(char arr[][50], int first, int last, int middle){
	int lengthLeft = middle - first + 1;
	int lengthRight = last - middle;
	
	char leftArr[lengthLeft][50];
	for (int i = 0; i < lengthLeft; i++){
		strcpy(leftArr[i], arr[first + i]);
	}
	char rightArr[lengthRight][50];
	for (int i = 0; i < lengthRight; i++){
		strcpy(rightArr[i], arr[middle + i + 1]);
	}

	int counterL = 0;
	int counterR = 0;

	for (int i = first; i <= last; i++){
		if (counterL == lengthLeft){
			while (i <= last){
				moves++;
				strcpy(arr[i], rightArr[counterR]);
				i++;
				counterR++;
			}
			break;
		}
		else if (counterR == lengthRight){
			while (i <= last){
				moves++;
				strcpy(arr[i], leftArr[counterR]);
				i++;
				counterL++;
			}
			break;
		}
		comparisons++;
		if (strcmp(leftArr[counterL], rightArr[counterR]) <= 0){
			moves++;
			strcpy(arr[i], leftArr[counterL]);
			counterL++;
		}
		else{
			moves++;
			strcpy(arr[i], rightArr[counterR]);
			counterR++;
		}
	}
}

void words_fast_merge_sort(char arr[][50], int first, int last){
	if (last > first){
		int middle = (first + last) / 2;
		words_fast_merge_sort(arr, first, middle);
		words_fast_merge_sort(arr, middle + 1, last);
		words_fast_merge(arr, first, last, middle);
	}	
}

int words_fast_partition(char arr[][50], int first, int last){
	char pivot[50];
	strcpy(pivot, arr[(first + last) / 2]);
	int i = first - 1;
	int j = last + 1;
	
	while(1){
		do
		{
			i++;
			comparisons++;
		} while (strcmp(arr[i], pivot) < 0);

		do
		{
			j--;
			comparisons++;
		} while (strcmp(arr[j], pivot) > 0);

		if (i >= j){
			return j;
		}
		moves += 2;
		words_swap(arr[i], arr[j]);
	}
	return 0;
}

void words_quicker_sort(char arr[][50], int first, int last){
	if (first < last){
		int q = words_fast_partition(arr, first, last);
		words_quicker_sort(arr, first, q);
		words_quicker_sort(arr, q + 1, last);
	}
}

int words_fast_dual_partition(char arr[][50], int first, int last, int* right){
	int l = first + 1;
	int r = last - 1;
	int current = first + 1;
	char left_pivot[50];
	char right_pivot[50];

	comparisons++;
	if (strcmp(arr[first], arr[last]) > 0){
		moves += 2;
		words_swap(arr[first], arr[last]);
	}
	strcpy(left_pivot, arr[first]);
	strcpy(right_pivot, arr[last]);

	while (current <= r){
		switch ((l - first) > (last - r)){
			case 1:
				comparisons++;
				if (strcmp(arr[current], left_pivot) <= 0){
					moves += 2;
					words_swap(arr[current], arr[l]);
					l++;
				}
				else if (strcmp(arr[current], right_pivot) > 0){
					comparisons++;
					while (current <= r && strcmp(arr[r], right_pivot) > 0){
						comparisons++;
						r--;
					}
					if (current > r){
						break;
					}
					comparisons++;			
					moves += 2;
					words_swap(arr[current], arr[r]);
					r--;			
				
					comparisons++;
					if (strcmp(arr[current], left_pivot) <= 0){				
						moves += 2;
						words_swap(arr[current], arr[l]);
						l++;
					}
				}
				else{		
					comparisons++;
				}
				break;
			case 0:
				comparisons++;
				if (strcmp(arr[current], right_pivot) > 0){
					while (current <= r && strcmp(arr[r], right_pivot) > 0){	
						comparisons++;
						r--;
					}
					if (current > r){
						break;
					}	
					comparisons++;							
					moves += 2;
					words_swap(arr[current], arr[r]);
					r--;
		
					comparisons++;
					if (strcmp(arr[current], left_pivot) <= 0){			
						moves += 2;
						words_swap(arr[current], arr[l]);
						l++;
					}
				}
				else if (strcmp(arr[current], left_pivot) <= 0){	
					comparisons++;		
					moves += 2;
					words_swap(arr[current], arr[l]);
					l++;
				}
				else{
					comparisons++;
				}
				break;
		}
		current++;
	}
	
	l--;
	r++;
	moves += 2;
	words_swap(arr[first], arr[l]);
	moves += 2;
	words_swap(arr[r], arr[last]);
	*right = r;
	return l;
}

void words_fast_dual_pivot_quicksort(char arr[][50], int first, int last){
	if (first < last){
		int right;
		int left = words_fast_dual_partition(arr, first, last, &right);
		words_fast_dual_pivot_quicksort(arr, first, left - 1);
		words_fast_dual_pivot_quicksort(arr, left + 1, right - 1);
		words_fast_dual_pivot_quicksort(arr, right + 1, last);
	}
}

void words_fast_optimized_quick_sort(char arr[][50], int first, int last){
	if (first < last){
		if (last - first < 10){
			for (int i = first + 1; i <= last; i++){
				char key[50];
				strcpy(key, arr[i]);
				int pos = i - 1;

				while (pos >= 0 && strcmp(arr[pos], key) > 0){
					comparisons++;
					moves++;
					strcpy(arr[pos + 1], arr[pos]);
					pos--;
				}
				if (pos >= 0){
					comparisons++;
				}
				moves++;
				strcpy(arr[pos + 1], key);
			}
		}
		else{
			int q = words_fast_partition(arr, first, last);
			words_fast_optimized_quick_sort(arr, first, q);
			words_fast_optimized_quick_sort(arr, q + 1, last);
		}
	}
}