#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define LENGTH 2000000

void swap(int* first, int* second){
	int temp = *first;
	*first = *second;
	*second = temp;
}

int moves = 0;
int comparisons = 0;

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
			case 0:
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
			case 1:
				if (arr[current] > right_pivot){
					comparisons++;
					while (arr[r] > right_pivot && current <= r){	
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

int main(){
	int arr[LENGTH];
	double avg = 0;
	for (int i = 0; i < 1; i++){
		for (int j = 0; j < LENGTH; j++){
			arr[j] = rand() % LENGTH;
		}
		comparisons = 0;
		fast_dual_pivot_quicksort(arr, 0, LENGTH - 1);
		avg += comparisons;
	}
	avg /= 5;
	printf("comps = %d\nconst = %f\n",comparisons, avg / (LENGTH * log(LENGTH)));
}