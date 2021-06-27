#include <iostream>
#include <array>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iomanip>

int comparisons = 0;

int binarySearchPrint(int* arr, int lo, int hi, int key){
	int middle = (hi + lo) / 2;
	std::cerr << "\nśrodek = " << arr[middle] << std::endl;
	std::cerr << "|comparison| - |" << arr[middle] << " ?= " << key << "|\n";
	comparisons++;
	if (arr[middle] == key){
		return 1;
	}
	else{
		if (lo == hi){
			return 0;
		}
		else if (key < arr[middle]){
			std::cerr << "|comparison| - |" << arr[middle] << " > " << key << "|\n";
			comparisons++;
			return binarySearchPrint(arr, lo, middle - 1, key);
		}
		else{
			std::cerr << "|comparison| - |" << arr[middle] << " < " << key << "|\n";
			comparisons++;
			return binarySearchPrint(arr, middle + 1, hi, key);
		}
	}
}

int binarySearch(int* arr, int lo, int hi, int key){
	if (lo > hi){
		return 0;
	}
	int middle = (hi + lo) / 2;
	comparisons++;
	if (arr[middle] == key){
		return 1;
	}
	else{
		if (lo == hi){
			return 0;
		}
		else if (key < arr[middle]){
			comparisons++;
			return binarySearch(arr, lo, middle - 1, key);
		}
		else{
			comparisons++;
			return binarySearch(arr, middle + 1, hi, key);
		}
	}
}

void tests(char* filename){
	std::ofstream myfile;
  	myfile.open (filename);

	clock_t tic;
	clock_t toc;
	int* arr;
	for (int i = 1000; i <= 1000000; i+=1000){
		arr = new int[i];

		for (int j = 0; j < 100; j++){
			for (int k = 0; k < i; k++){
				arr[k] = 2 * k;
			}
			int random = rand() % (2 * i - 1);
			if (random % 2 == 0){
				random += 1;
			}

			comparisons = 0;
			tic = clock();
			binarySearch(arr, 0, i - 1, 50);
			toc = clock();
			myfile << i << " " << comparisons << " " << (double)(toc - tic) / CLOCKS_PER_SEC << "\n"; 

			comparisons = 0;
			tic = clock();
			binarySearch(arr, 0, i - 1, i);
			toc = clock();
			myfile << i << " " << comparisons << " " << (double)(toc - tic) / CLOCKS_PER_SEC << "\n"; 

			comparisons = 0;
			tic = clock();
			binarySearch(arr, 0, i - 1, 2 * i - 50);
			toc = clock();
			myfile << i << " " << comparisons << " " << (double)(toc - tic) / CLOCKS_PER_SEC << "\n"; 

			comparisons = 0;
			tic = clock();
			binarySearch(arr, 0, i - 1, random);
			toc = clock();
			myfile << i << " " << comparisons << " " << (double)(toc - tic) / CLOCKS_PER_SEC << "\n";
		}
		delete arr;
	}
}

void testsRandom(char* filename){
	std::ofstream myfile;
  	myfile.open (filename);

	clock_t tic;
	clock_t toc;
	int* arr;
	for (int i = 1000; i <= 1000000; i+=1000){
		arr = new int[i];

		for (int j = 0; j < 300; j++){
			for (int k = 0; k < i; k++){
				arr[k] = 2 * k;
			}
			int random = rand() % (2 * i - 1);
			if (random % 2 == 1){
				random += 1;
			}

			comparisons = 0;
			tic = clock();
			binarySearch(arr, 0, i - 1, random);
			toc = clock();
			myfile << i << " " << comparisons << " " << (double)(toc - tic) / CLOCKS_PER_SEC << "\n"; 
		}
		delete arr;
	}
}

int main(int argc, char** argv){
	if (argc == 1){
		std::cout << "./zad3 -b\n./zad3 -t/-r $filename\nFlags:\n-b - binary search\n-t - tests\n-r - random tests\n";
		return 1;
	}
	srand(time(NULL));
	if (std::string(argv[1]).compare("-b") == 0){
		std::cout << "Pass the size of an array:\n";
		int length;
		std::cin >> length;
		int arr[length];
		std::cout << "Pass the values of an array:\n";
		for (int i = 0; i < length; i++){
			std::cin >> arr[i];
		}
		std::cout << "Pass the value you are looking for:\n";
		int value;
		std::cin >> value;

		clock_t tic = clock();
		int result = binarySearchPrint(arr, 0, length - 1, value);
		clock_t toc = clock();

		if (result){
			std::cout << "\nZnaleziono " << value << "\nLiczba porównań: " << comparisons << "\nŁączny czas: " << (double)(toc - tic) / CLOCKS_PER_SEC << std::endl;
		}
		else{
			std::cout << "\nNie znaleziono " << value << "\nLiczba porównań: " << comparisons << "\nŁączny czas: " << (double)(toc - tic) / CLOCKS_PER_SEC << std::endl;
		}

	}
	else if (std::string(argv[1]).compare("-t") == 0){
		tests(argv[2]);
		return 0;
	}
	else if (std::string(argv[1]).compare("-r") == 0){
		testsRandom(argv[2]);
		return 0;
	}
	else{
		return 1;
	}
}