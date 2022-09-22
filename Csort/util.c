#include "util.h"

#include "mergesort.h"
#include "radixsort.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <time.h>

// Creates a large list of n random integers to test the sorting algorithm
void write_unsorted_file(const char *filename, int n) {
    FILE *fp = fopen(filename, "w");
    assert(fp != NULL);
    
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", rand());
    }

    fclose(fp);
}

// Reads a file of integers separated by newlines and returns an array of integers
int *read_file(const char *filename, int *n) {
    FILE *fp = fopen(filename, "r");
    assert(fp != NULL);
    
    // Count the number of integers in the file
    int count = 0;
    char c;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
            count++;
        }
    }

    int *arr = (int*)malloc(count * sizeof(int));
    assert(arr != NULL);
    
    rewind(fp);
    for (int i = 0; i < count; i++) {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);
    
    *n = count;
    return arr;
}

// Get time to sort n random integers
double time_sort(int n) {
    const char *filename = "unsorted.txt";
    write_unsorted_file(filename, n);

    int *arr;
    int size;
    arr = read_file(filename, &size);
    
    // Sort the array
    clock_t start = clock();
    //merge_sort(arr, size);
    radix_sort(arr, size);
    clock_t end = clock();
    
    for (int i = 0; i < size - 1; i++) {
        assert(arr[i] <= arr[i + 1]);
    }
    
    free(arr);

    FILE *fp = fopen("stats.txt", "a");
    assert(fp != NULL);
    fprintf(fp, "n = %d, time = %f seconds\n", n, (double)(end - start) / CLOCKS_PER_SEC);
    // print sorted array to file
    for (int i = 0; i < size; i++) {
        fprintf(fp, "%d\n", arr[i]);
    }

    fclose(fp);
    
    return (double)(end - start) / CLOCKS_PER_SEC;
}