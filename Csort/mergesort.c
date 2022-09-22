#include <string.h>
#include <stdlib.h>
#include "mergesort.h"

void merge(int *arr, int *left, int *right, int left_size, int right_size) {
    int i = 0, j = 0, k = 0;
    
    while (i < left_size && j < right_size) {
        if (left[i] < right[j]) {
            arr[k] = left[i];
            i++;
        } 
        
        else {
            arr[k] = right[j];
            j++;
        }

        k++;
    }

    while (i < left_size) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int *arr, int size) {
    int mid, i, *left, *right;
    
    // base case
    if (size < 2) {
        return;
    }
    
    // Find mid point in each function call
    mid = size / 2;
    
    // Allocate memory for left and right subarrays
    left = (int*)malloc(mid * sizeof(int));
    right = (int*)malloc((size - mid) * sizeof(int));
    
    // Copy data to left and right subarrays
    for (i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }
    
    // recursively call merge sort on each subarray
    // and merge the sorted subarrays
    merge_sort(left, mid);
    merge_sort(right, size - mid);
    merge(arr, left, right, mid, size - mid);
    
    // so memory is not leaked
    free(left);
    free(right);
}

        