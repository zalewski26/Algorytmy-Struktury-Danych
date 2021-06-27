#include <iostream>
#include <fstream>

int comparisons = 0;
int moves = 0;

void insertionSort(int* arr, int lo, int hi){
	for (int i = lo + 1; i <= hi; i++){
		int key = arr[i];
		int j = i - 1;
		while (j >= lo && arr[j] > key){
			comparisons++;
			moves++;
			arr[j + 1] = arr[j];
			j--;
		}
		if (j >= lo){
			comparisons++;
		}
		moves++;
		arr[j + 1] = key;
	}
}

int partition(int* arr, int lo, int hi)
{
    int pivot = arr[hi];  
    int i = (lo - 1); 
 
    for (int j = lo; j <= hi - 1; j++)
    {
        if (arr[j] <= pivot)
        {
			comparisons++;
            i++; 
			moves += 2;
            std::swap(arr[i], arr[j]);
        }
		else{
			comparisons++;
		}
    }
	moves += 2;
    std::swap(arr[i + 1], arr[hi]);
	return (i + 1);
}

void quick_sort(int* arr, int first, int last){
	if (first < last){
		int q = partition(arr, first, last);
		quick_sort(arr, first, q - 1);
		quick_sort(arr, q + 1, last);
	}
}

int partition_pivot(int* arr, int lo, int hi, int pivot){
	for (int i = lo; i <= hi; i++){
		comparisons++;
		if (arr[i] == pivot){
			moves += 2;
			std::swap(arr[i], arr[hi]);
			break;
		}
	}
	return partition(arr, lo, hi);
}

int select(int* arr, int lo, int hi, int stat){ 
	if (lo == hi){
		return arr[lo];
	}
	int arrLength = hi - lo + 1;
	int numOf5Arr = arrLength / 5;
	int lastArrLength = arrLength % 5;

	int medianArrLength = (lastArrLength == 0) ? numOf5Arr : numOf5Arr + 1;
	int* medianArr = new int[medianArrLength];

	int first_id = lo;
	for (int i = 0; i < numOf5Arr; i++){
		insertionSort(arr, first_id, first_id + 4);
		medianArr[i] = arr[first_id + 2];
		first_id += 5;
	}	
	if (lastArrLength != 0){
		insertionSort(arr, first_id, first_id + lastArrLength - 1);
		medianArr[numOf5Arr] = arr[first_id + lastArrLength / 2];
	}

	int medianOfMedians = select(medianArr, 0, medianArrLength - 1, medianArrLength / 2);
	int pivot_pos = partition_pivot(arr, lo, hi, medianOfMedians);
	int pivot_stat = pivot_pos - lo + 1;
	
	delete medianArr;
	if (pivot_stat == stat){
		return arr[pivot_pos];
	}
	else if (stat < pivot_stat){
		return select(arr, lo, pivot_pos - 1, stat);
	}
	else {
		return select(arr, pivot_pos + 1, hi, stat - pivot_stat);
	}
}

void quick_select_sort(int* arr, int first, int last){
	if (first < last){
		int mid = (last - first) / 2 + first;;
		select(arr, first, last, (last - first) / 2 + 1);
		quick_select_sort(arr, first, mid - 1);
		quick_select_sort(arr, mid + 1, last);
	}
}

int dual_partition(int* arr, int first, int last, int* right){
	int l = first + 1;
	int r = last - 1;
	int current = first + 1;
	int left_pivot;
	int right_pivot;

	comparisons++;
	if (arr[first] > arr[last]){
		moves += 2;
		std::swap(arr[first], arr[last]);
	}
	left_pivot = arr[first];
	right_pivot = arr[last];

	while (current <= r){
		switch ((l - first) > (last - r)){
			case 1:
				comparisons++;
				if (arr[current] <= left_pivot){
					moves += 2;
					std::swap(arr[current], arr[l]);
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
					std::swap(arr[current], arr[r]);
					r--;			
				
					comparisons++;
					if (arr[current] <= left_pivot){				
						moves += 2;
						std::swap(arr[current], arr[l]);
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
					std::swap(arr[current], arr[r]);
					r--;
		
					comparisons++;
					if (arr[current] <= left_pivot){			
						moves += 2;
						std::swap(arr[current], arr[l]);
						l++;
					}
				}
				else if (arr[current] <= left_pivot){	
					comparisons++;		
					moves += 2;
					std::swap(arr[current], arr[l]);
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
	std::swap(arr[first], arr[l]);
	moves += 2;
	std::swap(arr[r], arr[last]);
	*right = r;
	return l;
}

void dual_pivot_quicksort(int* arr, int first, int last){
	if (first < last){
		int right;
		int left = dual_partition(arr, first, last, &right);
		dual_pivot_quicksort(arr, first, left - 1);
		dual_pivot_quicksort(arr, left + 1, right - 1);
		dual_pivot_quicksort(arr, right + 1, last);
	}
}

void dual_pivot_select_quicksort(int* arr, int first, int last){
	if (first < last){
		int left = (last - first) / 3 + first;
		int right = 2 * ((last - first) / 3) + first;

		select(arr, first, last, (last - first) / 3 + 1);
		select(arr, left, last, (last - first) / 3 + 1);
		
		dual_pivot_select_quicksort(arr, first, left - 1);
		dual_pivot_select_quicksort(arr, left + 1, right - 1);
		dual_pivot_select_quicksort(arr, right + 1, last);
	}
}

void normal(){
	srand(time(0));
	FILE* ptr = fopen("QuickVsSelect", "w");
	if (!ptr){
		printf("Error!\n");
		return;
	}
	clock_t tic;
	clock_t toc;

	for (int i = 100; i <= 10000; i+=100){
		int arr1[i];
		int arr2[i];
		int arr3[i];
		int arr4[i];

		for (int k = 0; k < 100; k++){
			for (int j = 0; j < i; j++){
				arr1[j] = arr2[j] = arr3[j] = arr4[j] = rand() % (2 * i);
			}
			comparisons = 0;
			moves = 0;
			tic = clock();
			quick_sort(arr1, 0, i - 1);
			toc = clock();
			fprintf(ptr, "Q %d %d %d %f\n", i, comparisons, moves, (double) (toc - tic) / CLOCKS_PER_SEC);
			comparisons = 0;
			moves = 0;
			tic = clock();
			quick_select_sort(arr2, 0, i - 1);
			toc = clock();
			fprintf(ptr, "S %d %d %d %f\n", i, comparisons, moves, (double) (toc - tic) / CLOCKS_PER_SEC);
			comparisons = 0;
			moves = 0;
			tic = clock();
			dual_pivot_quicksort(arr3, 0, i - 1);
			toc = clock();
			fprintf(ptr, "D %d %d %d %f\n", i, comparisons, moves, (double) (toc - tic) / CLOCKS_PER_SEC);
			comparisons = 0;
			moves = 0;
			tic = clock();
			dual_pivot_select_quicksort(arr4, 0, i - 1);
			toc = clock();
			fprintf(ptr, "Z %d %d %d %f\n", i, comparisons, moves, (double) (toc - tic) / CLOCKS_PER_SEC);
		}
	}
}

void pessimistic(){
	std::ofstream myfile;
  	myfile.open ("Pes");
	clock_t tic;
	clock_t toc;

	for (int i = 100; i <= 10000; i+=100){
		int arr1[i];
		int arr2[i];

		for (int k = 0; k < 100; k++){
			for (int j = 0; j < i; j++){
				arr1[j] = arr2[j] = j;
			}
			comparisons = 0;
			moves = 0;
			tic = clock();
			quick_sort(arr1, 0, i - 1);
			toc = clock();
			myfile << "Q " << i << " " << comparisons << " " << moves << " " << (double) (toc - tic) / CLOCKS_PER_SEC << "\n"; 
			comparisons = 0;
			moves = 0;
			tic = clock();
			quick_select_sort(arr2, 0, i - 1);
			toc = clock();
			myfile << "S " << i << " " << comparisons << " " << moves << " " << (double) (toc - tic) / CLOCKS_PER_SEC << "\n";
		}
		myfile.flush();
	}
	myfile.close();
}

int main(){
	//normal();
	//pessimistic();
}