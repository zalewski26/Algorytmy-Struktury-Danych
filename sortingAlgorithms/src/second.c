#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "define.h"
#include "ex.h"
#include "sortFast.h"
#include "helpful.h"

char* rand_string(char *str, int size)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyz";
    if (size) {
        --size;
        for (int n = 0; n < size; n++) {
            int key = rand() % (int) (sizeof charset - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    return str;
}

void secondEx(char* filename, int k_max, int comp){
	srand(time(0));
	FILE* ptr = fopen(filename, "w");
	if (!ptr){
		printf("Error!\n");
		return;
	}
	clock_t tic;
	clock_t toc;

	if (comp == INCREASE || comp == DECREASE){
		for (int i = 100; i <= 10000; i+=100){
			int arr1[i];
			int arr2[i];
			int arr3[i];
			int arr4[i];
			int arr5[i];
			int temp;
			printf("n = %d\n", i);

			for (int k = 0; k < k_max; k++){
				for (int j = 0; j < i; j++){
					temp = rand() % i;
					arr1[j] = temp;
					arr2[j] = temp;
					arr3[j] = temp;
					arr4[j] = temp;
					arr5[j] = temp;
				}
			
				tic = clock();
				fast_insertion_sort(arr1, i);
				toc = clock();
				fprintf(ptr, "I %d %d %d %f\n", i, comparisons, moves, (double) (toc - tic) / CLOCKS_PER_SEC);
				comparisons = 0;
				moves = 0;
				tic = clock();
				fast_merge_sort(arr2, 0, i - 1);
				toc = clock();
				fprintf(ptr, "M %d %d %d %f\n", i, comparisons, moves, (double) (toc - tic) / CLOCKS_PER_SEC);
				comparisons = 0;
				moves = 0;
				tic = clock();
				quicker_sort(arr3, 0, i - 1);
				toc = clock();
				fprintf(ptr, "Q %d %d %d %f\n", i, comparisons, moves, (double) (toc - tic) / CLOCKS_PER_SEC);
				comparisons = 0;
				moves = 0;
				tic = clock();
				fast_dual_pivot_quicksort(arr4, 0, i - 1);
				toc = clock();
				fprintf(ptr, "D %d %d %d %f\n", i, comparisons, moves, (double) (toc - tic) / CLOCKS_PER_SEC);
				comparisons = 0;
				moves = 0;
				tic = clock();
				fast_optimized_quick_sort(arr5, 0, i - 1);
				toc = clock();
				fprintf(ptr, "H %d %d %d %f\n", i, comparisons, moves, (double) (toc - tic) / CLOCKS_PER_SEC);

				if (!checkSorting(arr1, i, INCREASE) || !checkSorting(arr2, i, INCREASE) || !checkSorting(arr3, i, INCREASE) 
										|| !checkSorting(arr4, i, INCREASE) || !checkSorting(arr4, 5, INCREASE)){
					fclose(ptr);
					ptr = fopen(filename, "w");
					fprintf(ptr, "Sorting error!\n");
					return;
				}
			}
		}
	}
	else {
		for (int i = 100; i <= 10000; i+=100){
			char arr1[i][50];
			char arr2[i][50];
			char arr3[i][50];
			char arr4[i][50];
			char arr5[i][50];
			char temp[50];
			printf("n = %d\n", i);

			for (int k = 0; k < k_max; k++){
				for (int j = 0; j < i; j++){
					rand_string(temp, 50);
					strcpy(arr1[j], temp);
					strcpy(arr2[j], temp);
					strcpy(arr3[j], temp);
					strcpy(arr4[j], temp);
					strcpy(arr5[j], temp);
				}
			
				tic = clock();
				words_fast_insertion_sort(arr1, i);
				toc = clock();
				fprintf(ptr, "I %d %d %d %f\n", i, comparisons, moves, (double) (toc - tic) / CLOCKS_PER_SEC);
				comparisons = 0;
				moves = 0;
				tic = clock();
				words_fast_merge_sort(arr2, 0, i - 1);
				toc = clock();
				fprintf(ptr, "M %d %d %d %f\n", i, comparisons, moves, (double) (toc - tic) / CLOCKS_PER_SEC);
				comparisons = 0;
				moves = 0;
				tic = clock();
				words_quicker_sort(arr3, 0, i - 1);
				toc = clock();
				fprintf(ptr, "Q %d %d %d %f\n", i, comparisons, moves, (double) (toc - tic) / CLOCKS_PER_SEC);
				comparisons = 0;
				moves = 0;
				tic = clock();
				words_fast_dual_pivot_quicksort(arr4, 0, i - 1);
				toc = clock();
				fprintf(ptr, "D %d %d %d %f\n", i, comparisons, moves, (double) (toc - tic) / CLOCKS_PER_SEC);
				comparisons = 0;
				moves = 0;
				tic = clock();
				words_fast_optimized_quick_sort(arr5, 0, i - 1);
				toc = clock();
				fprintf(ptr, "H %d %d %d %f\n", i, comparisons, moves, (double) (toc - tic) / CLOCKS_PER_SEC);

				if (!checkWords(arr1, i, INCREASE) || !checkWords(arr2, i, INCREASE) || !checkWords(arr3, i, INCREASE) 
										|| !checkWords(arr4, i, INCREASE) || !checkWords(arr5, i, INCREASE)){
					fclose(ptr);
					ptr = fopen(filename, "w");
					fprintf(ptr, "Sorting error!\n");
					return;
				}
			}
		}
	}
}
