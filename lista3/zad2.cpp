#include <iostream>
#include <fstream>
#define RAND 0
#define PERM 1
#define ELEMENTS 25

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
	int numOf5Arr = arrLength / ELEMENTS;
	int lastArrLength = arrLength % ELEMENTS;

	int medianArrLength = (lastArrLength == 0) ? numOf5Arr : numOf5Arr + 1;
	int* medianArr = new int[medianArrLength];

	int first_id = lo;
	for (int i = 0; i < numOf5Arr; i++){
		insertionSort(arr, first_id, first_id + ELEMENTS - 1);
		medianArr[i] = arr[first_id + ELEMENTS / 2];
		first_id += ELEMENTS;
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

void setValues(int* arr1, int* arr2, int* arr3, int length, int flag){
	switch (flag){
		case RAND:
			for (int i = 0; i < length; i++){
				arr1[i] = arr2[i] = arr3[i] = rand() % (2 * length);
			}
			break;
		case PERM:
			for (int i = 0; i < length; i++){
				arr1[i] = arr2[i] = arr3[i] = i + 1;
			}
			for (int i = 0; i < length - 1; i++){
				int random = i + 1 + (rand() % (length - 1 - i));
				int temp = arr1[i];
				arr1[i] = arr2[i] = arr3[i] = arr1[random];
				arr1[random] = arr2[random] = arr3[random] = temp;
			}
			break;
	}
}

int main(int argc, char** argv){
	std::ofstream myfile;
  	myfile.open (argv[1]);

	for (int i = 100; i <= 10000; i+=100){
		int arr[6][i];
		
		for (int j = 0; j < 100; j++){
			setValues(arr[0], arr[1], arr[2], i, PERM);
			setValues(arr[3], arr[4], arr[5], i, RAND);
			
			comparisons = 0;
			moves = 0;
			select(arr[0], 0, i - 1, 25);
			myfile << "Sp " << i << " " << comparisons << " " << moves << "\n"; 
			comparisons = 0;
			moves = 0;
			select(arr[1], 0, i - 1, i / 2);
			myfile << "Sp " << i << " " << comparisons << " " << moves << "\n"; 
			comparisons = 0;
			moves = 0;
			select(arr[2], 0, i - 1, i - 25);
			myfile << "Sp " << i << " " << comparisons << " " << moves << "\n"; 

			comparisons = 0;
			moves = 0;
			select(arr[3], 0, i - 1, 25);
			myfile << "Sr " << i << " " << comparisons << " " << moves << "\n"; 
			comparisons = 0;
			moves = 0;
			select(arr[4], 0, i - 1, i / 2);
			myfile << "Sr " << i << " " << comparisons << " " << moves << "\n"; 
			comparisons = 0;
			moves = 0;
			select(arr[5], 0, i - 1, i - 25);
			myfile << "Sr " << i << " " << comparisons << " " << moves << "\n";
		} 
	}
}