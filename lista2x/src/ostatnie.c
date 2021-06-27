#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int moves = 0;
int comparisons = 0;

void swap(int* first, int* second){
	int temp = *first;
	*first = *second;
	*second = temp;
}

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

int main(){
	srand(time(NULL));
	int temp;
	double avgTime1 = 0;
	double avgTime2 = 0;
	double avgComp1 = 0;
	double avgComp2 = 0;
	double avgMoves1 = 0;
	double avgMoves2 = 0;
	clock_t tic;
	clock_t toc;
	for (int i = 1; i < 200; i++){
		int arr1[i];
		int arr2[i];
		avgTime1 = 0;
		avgTime2 = 0;
		for (int j = 0; j < 1000; j++){
			for (int k = 0; k < i; k++){
				temp = rand() % 10;
				arr1[k] = temp;
				arr2[k] = temp;
			}
			comparisons = 0;
			moves = 0;
			tic = clock();
			quicker_sort(arr2, 0, i - 1);
			toc = clock();
			avgTime2 += (double) (toc - tic) / CLOCKS_PER_SEC;
			avgComp2 += comparisons;
			avgMoves2 += moves;

			comparisons = 0;
			moves = 0;
			tic = clock();
			fast_insertion_sort(arr1, i);
			toc = clock();
			avgTime1 += (double) (toc - tic) / CLOCKS_PER_SEC;
			avgComp1 += comparisons;
			avgMoves1 += moves;

		}
		printf("Size = %d\nInsertion time = %f\nInsertion comps = %f\nInsertion moves = %f\nQuick time = %f\nQuick comps = %f\nQuick moves = %f\n\n", i, avgTime1 / 1000 , avgComp1 / 1000, avgMoves1 / 1000,
						 avgTime2 / 1000 , avgComp2 / 1000, avgMoves2 / 1000);
	}
}
