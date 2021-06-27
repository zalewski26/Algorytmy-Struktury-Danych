#include <iostream>
#include <array>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#define RAND 0
#define PERM 1

int comparisons = 0;
int moves = 0;

//---------------------------prints------------------------------
void insertionSortPrint(int* arr, int lo, int hi){
	for (int i = lo + 1; i <= hi; i++){
		int key = arr[i];
		int j = i - 1;
		while (j >= lo && arr[j] > key){
			std::cerr << "|comparison| - |" << key << " < " << arr[j] << "|\n";
			comparisons++;
			std::cerr << "|   move   | - |" << arr[j] << " -> arr[ " << j + 1 << "]|\n";
			moves++;
			arr[j + 1] = arr[j];
			j--;
		}
		if (j >= lo){
			std::cerr << "|comparison| - |" << key << " >= " << arr[j] << "|\n";
			comparisons++;
		}
		std::cerr << "|   move   | - |" << key << " -> arr[ " << j + 1 << "]|\n";
		moves++;
		arr[j + 1] = key;
	}
}

int partitionPrint(int* arr, int lo, int hi)
{
	std::cerr << "\tpivot = " << arr[hi] << std::endl;
    int pivot = arr[hi];  
    int i = (lo - 1); 
 
    for (int j = lo; j <= hi - 1; j++)
    {
        if (arr[j] <= pivot)
        {
			std::cerr << "\t|comparison| - |" << arr[j] << " <= " << pivot << "|\n";
			comparisons++;
            i++; 
			std::cerr << "\t|   swap   | - |" << arr[i] << " <-> " << arr[j] << "|\n";
			moves += 2;
            std::swap(arr[i], arr[j]);
        }
		else{
			std::cerr << "\t|comparison| - |" << arr[j] << " > " << pivot << "|\n";
			comparisons++;
		}
    }
	std::cerr << "\t|   swap   | - |" << arr[i + 1] << " <-> " << arr[hi] << "|\n";
	moves += 2;
    std::swap(arr[i + 1], arr[hi]);
	return (i + 1);
}

int partition_pivotPrint(int* arr, int lo, int hi, int pivot){
	std::cerr << "----------move pivot to the end----------\n";
	for (int i = lo; i <= hi; i++){
		std::cerr << "\t|comparison| - |" << arr[i] << " ?= " << pivot << "|\n";
		comparisons++;
		if (arr[i] == pivot){
			std::cerr << "\t|   swap   | - |" << arr[i] << " <-> " << arr[hi] << "|\n";
			moves += 2;
			std::swap(arr[i], arr[hi]);
			break;
		}
	}
	std::cerr << "----------move pivot to the end----------\n";
	return partitionPrint(arr, lo, hi);
}

int randomizedSelectPrint(int* arr, int lo, int hi, int stat){
	std::cerr << "\narr = [";
	for (int k = lo; k <= hi; k++){
		std::cerr << arr[k] << " ";
	}
	std::cerr << "]\nstat = " << stat << std::endl;
	if (lo == hi){
		std::cerr << "return " << arr[lo] << std::endl;
		return arr[lo];
	}
	std::cerr << "-----------partition----------\n";
	int pivot_pos = partitionPrint(arr, lo, hi);
	std::cerr << "------------------------------\n";
	int pivot_stat = pivot_pos - lo + 1;

	std::cerr << "|comparison| - |" << pivot_stat << " ?= " << stat << "|\n";
	if (pivot_stat == stat){
		std::cerr << "return " << arr[pivot_pos] << std::endl;
		return arr[pivot_pos];
	}
	else if (stat < pivot_stat){
		return randomizedSelectPrint(arr, lo, pivot_pos - 1, stat);
	}
	else {
		return randomizedSelectPrint(arr, pivot_pos + 1, hi, stat - pivot_stat);
	}
}

int selectPrint(int* arr, int lo, int hi, int stat){
	std::cerr << "\narr = [";
	for (int k = lo; k <= hi; k++){
		std::cerr << arr[k] << " ";
	}
	std::cerr << "]\nstat = " << stat << std::endl;
	if (lo == hi){
		std::cerr << "return " << arr[lo] << std::endl;
		return arr[lo];
	}
	int arrLength = hi - lo + 1;
	int numOf5Arr = arrLength / 5;
	int lastArrLength = arrLength % 5;

	int medianArrLength = (lastArrLength == 0) ? numOf5Arr : numOf5Arr + 1;
	int* medianArr = new int[medianArrLength];

	int first_id = lo;
	std::cerr << "-----------insertionSort----------\n";
	for (int i = 0; i < numOf5Arr; i++){
		insertionSortPrint(arr, first_id, first_id + 4);
		medianArr[i] = arr[first_id + 2];
		first_id += 5;
	}	
	if (lastArrLength != 0){
		insertionSortPrint(arr, first_id, first_id + lastArrLength - 1);
		medianArr[numOf5Arr] = arr[first_id + lastArrLength / 2];
	}
	std::cerr << "-----------------------------------\n";

	int medianOfMedians = selectPrint(medianArr, 0, medianArrLength - 1, medianArrLength / 2);
	std::cerr << "-----------partition----------\n";
	int pivot_pos = partition_pivotPrint(arr, lo, hi, medianOfMedians);
	std::cerr << "------------------------------\n";
	int pivot_stat = pivot_pos - lo + 1;
	
	delete medianArr;
	if (pivot_stat == stat){
		std::cerr << "return " << arr[pivot_pos] << std::endl;
		return arr[pivot_pos];
	}
	else if (stat < pivot_stat){
		return selectPrint(arr, lo, pivot_pos - 1, stat);
	}
	else {
		return selectPrint(arr, pivot_pos + 1, hi, stat - pivot_stat);
	}
}
//---------------------------prints------------------------------


//---------------------------fast--------------------------------
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

int randomizedSelect(int* arr, int lo, int hi, int stat){
	if (lo == hi){
		return arr[lo];
	}
	int pivot_pos = partition(arr, lo, hi);
	int pivot_stat = pivot_pos - lo + 1;
	if (pivot_stat == stat){
		return arr[pivot_pos];
	}
	else if (stat < pivot_stat){
		return randomizedSelect(arr, lo, pivot_pos - 1, stat);
	}
	else {
		return randomizedSelect(arr, pivot_pos + 1, hi, stat - pivot_stat);
	}
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
//---------------------------fast--------------------------------


//---------------------------help--------------------------------
void printResult(int* arr, int length, int stat, int fd){
	int pos = -1;
	for (int i = length - 1; i >= 0; i--){
		if (arr[i] == stat){
			pos = i;
			break;
		}
	}
	switch (fd){
		case 1:
			for (int i = 0; i < length; i++){
				if (i != pos){
					std::cout << arr[i] << " ";
				}
				else{
					std::cout << "|" << arr[i] << "| ";
				}
			}
			std::cout << std::endl;
			break;
		case 2:
			for (int i = 0; i < length; i++){
				if (i != pos){
					std::cerr << arr[i] << " ";
				}
				else{
					std::cerr << "|" << arr[i] << "| ";
				}
			}
			std::cerr << std::endl;
			break;	
	}
}
//---------------------------help--------------------------------


//---------------------------normal------------------------------
void setValues(int* arr1, int* arr2, int length, int flag){
	switch (flag){
		case RAND:
			for (int i = 0; i < length; i++){
				arr1[i] = arr2[i] = rand() % (2 * length);
			}
			break;
		case PERM:
			for (int i = 0; i < length; i++){
				arr1[i] = arr2[i] = i + 1;
			}
			for (int i = 0; i < length - 1; i++){
				int random = i + 1 + (rand() % (length - 1 - i));
				int temp = arr1[i];
				arr1[i] = arr2[i] = arr1[random];
				arr1[random] = arr2[random] = temp;
			}
			break;
	}
}

void classic(int length, int stat, int flag){
	int* arr1 = new int[length];
	int* arr2 = new int[length];

	setValues(arr1, arr2, length, flag);
	clock_t tic;
	clock_t toc;

	std::cerr << "Randomized Select:\n";
	tic = clock();
	int stat1 = randomizedSelectPrint(arr1, 0, length - 1, stat);
	toc = clock();
	std::cerr << "\nTotal number of comparisons: " << comparisons << "\n";
	std::cerr << "Total number of moves: " << moves << "\n";
	std::cerr << "Total time: " << (double)(toc - tic) / CLOCKS_PER_SEC << "\n";
	std::cerr << "------------------------------------------------------------";
	std::cout << "After Randomized Select:\n";
	printResult(arr1, length, stat1, 1);

	std::cerr << "\nSelect:\n";
	tic = clock();
	int stat2 = selectPrint(arr2, 0, length - 1, stat);
	toc = clock();
	std::cerr << "\nTotal number of comparisons: " << comparisons << "\n";
	std::cerr << "Total number of moves: " << moves << "\n";
	std::cerr << "Total time: " << (double)(toc - tic) / CLOCKS_PER_SEC << "\n";
	std::cout << "After Select:\n";
	printResult(arr1, length, stat2, 1);
	delete arr1;
	delete arr2;
}
//---------------------------normal------------------------------


//---------------------------test--------------------------------
void setValues(int* arr1, int* arr2, int* arr3, int* arr4, int* arr5, int* arr6, int length, int flag){
	switch (flag){
		case RAND:
			for (int i = 0; i < length; i++){
				arr1[i] = arr2[i] = arr3[i] = arr4[i] = arr5[i] = arr6[i] = rand() % (2 * length);
			}
			break;
		case PERM:
			for (int i = 0; i < length; i++){
				arr1[i] = arr2[i] = arr3[i] = arr4[i] = arr5[i] = arr6[i] =  i + 1;
			}
			for (int i = 0; i < length - 1; i++){
				int random = i + 1 + (rand() % (length - 1 - i));
				int temp = arr1[i];
				arr1[i] = arr2[i] = arr3[i] = arr4[i] = arr5[i] = arr6[i] =  arr1[random];
				arr1[random] = arr2[random] = arr3[random] = arr4[random] = arr5[random] = arr6[random] = temp;
			}
			break;
	}
}

void tests(char* filename){
	std::ofstream myfile;
  	myfile.open (filename);

	for (int i = 100; i <= 10000; i+=100){
		int arr[12][i];		// 0,1,2 - Rp		3,4,5 - Sp		6,7,8 - Rr		9,10,11 - Sr
		
		for (int j = 0; j < 100; j++){
			setValues(arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], i, PERM);
			setValues(arr[6], arr[7], arr[8], arr[9], arr[10], arr[11], i, RAND);

			comparisons = 0;
			moves = 0;
			randomizedSelect(arr[0], 0, i - 1, 25);
			myfile << "Rp " << i << " " << comparisons << " " << moves << "\n"; 
			comparisons = 0;
			moves = 0;
			randomizedSelect(arr[1], 0, i - 1, i / 2);
			myfile << "Rp " << i << " " << comparisons << " " << moves << "\n"; 
			comparisons = 0;
			moves = 0;
			randomizedSelect(arr[2], 0, i - 1, i - 25);
			myfile << "Rp " << i << " " << comparisons << " " << moves << "\n"; 
			
			comparisons = 0;
			moves = 0;
			select(arr[3], 0, i - 1, 25);
			myfile << "Sp " << i << " " << comparisons << " " << moves << "\n"; 
			comparisons = 0;
			moves = 0;
			select(arr[4], 0, i - 1, i / 2);
			myfile << "Sp " << i << " " << comparisons << " " << moves << "\n"; 
			comparisons = 0;
			moves = 0;
			select(arr[5], 0, i - 1, i - 25);
			myfile << "Sp " << i << " " << comparisons << " " << moves << "\n"; 

			comparisons = 0;
			moves = 0;
			randomizedSelect(arr[6], 0, i - 1, 25);
			myfile << "Rr " << i << " " << comparisons << " " << moves << "\n"; 
			comparisons = 0;
			moves = 0;
			randomizedSelect(arr[7], 0, i - 1, i / 2);
			myfile << "Rr " << i << " " << comparisons << " " << moves << "\n"; 
			comparisons = 0;
			moves = 0;
			randomizedSelect(arr[8], 0, i - 1, i - 25);
			myfile << "Rr " << i << " " << comparisons << " " << moves << "\n"; 

			comparisons = 0;
			moves = 0;
			select(arr[9], 0, i - 1, 25);
			myfile << "Sr " << i << " " << comparisons << " " << moves << "\n"; 
			comparisons = 0;
			moves = 0;
			select(arr[10], 0, i - 1, i / 2);
			myfile << "Sr " << i << " " << comparisons << " " << moves << "\n"; 
			comparisons = 0;
			moves = 0;
			select(arr[11], 0, i - 1, i - 25);
			myfile << "Sr " << i << " " << comparisons << " " << moves << "\n";
		} 
	}
}
//---------------------------test--------------------------------


//---------------------------main--------------------------------
int main(int argc, char** argv){
	if (argc == 1){
		std::cout << "./main -r/-p $dataSize $orderStat\n./main -t $filename\nFlags:\n-r - random data\n-p - random permutation\n-t - tests\n";
		return 1;
	}
	srand(time(NULL));

	if (std::string(argv[1]).compare("-r") == 0){
		classic(std::stoi(argv[2]), std::stoi(argv[3]), RAND);
	}
	else if (std::string(argv[1]).compare("-p") == 0){
		classic(std::stoi(argv[2]), std::stoi(argv[3]), PERM);
	}
	else if (std::string(argv[1]).compare("-t") == 0){
		tests(argv[2]);
		return 0;
	}
	else{
		return 1;
	}
}
//---------------------------main--------------------------------