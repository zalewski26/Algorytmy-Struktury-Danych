#pragma once

void swap(int* first, int* second);
void words_swap(char first[50], char second[50]);
void insertion_sort(int* arr, int length, int comp);
void merge_sort(int* arr, int first, int last, int comp);
void quick_sort(int* arr, int first, int last, int comp);
void dual_pivot_quicksort(int* arr, int first, int last, int comp);
void optimized_quick_sort(int* arr, int first, int last, int comp);
void words_insertion_sort(char words[][50], int length, int comp);
void words_merge_sort(char words[][50], int first, int last, int comp);
void words_quick_sort(char words[][50], int first, int last, int comp);
void words_dual_pivot_quicksort(char words[][50], int first, int last, int comp);
void words_optimized_quick_sort(char words[][50], int first, int last, int comp);