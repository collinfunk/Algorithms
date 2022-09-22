#include "radixsort.h"
#include <stdlib.h>

void radix_sort(int *array, int size) {
    int val = get_max(array, size);

    for (int i = 1; val / i > 0; i *= 10) {
        count_sort(array, size, i);
    }
}


int get_max(int *array, int size) {
    int max = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

void count_sort(int *array, int size, int exp) {
    int *output = (int*)malloc(size * sizeof(int)); // output array

    int count[10] = {0}; // 0-9

    // store count of occurrences
    for (int i = 0; i < size; i++) {
        count[(array[i] / exp) % 10]++;
    }

    // make position match
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // make output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    // copy output array to array
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }

    // free memory
    free(output);
}

