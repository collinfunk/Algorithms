#include "mergesort.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <time.h>


int main(int argc, char **argv) {

    int n = 10000; /* Dont change this to a 1 billion. i tried. */
    printf("sorting %d integers\n", n);
    double time = time_sort(n);
    printf("Time to sort %d random integers: %f seconds\n", n, time);


    return 0;
}
