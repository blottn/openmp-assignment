#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include "benchmark.h"
int parallel_linear_search(int *arr, int size, int item) {
    int index = size;
    #pragma omp parallel for shared(index)
    for (int i = 0 ; i < size; i++) {
        if (arr[i] == item) {
            if (i < index) {
                index = i;
            }
        }
    }
    if (index == size) {
        return -1;
    }
    return index;
}

int main(int argc, char ** argv) {
	int iterations = atoi(argv[1]);
	int size = atoi(argv[2]);
	int item = atoi(argv[3]);

	printf("Testing parallel search with\n* %d iterations\n* %d numbers\n* for the number %d\n",iterations,size,item);

	double * times = malloc(sizeof(double)*iterations);
	for (int i = 0 ; i < iterations ; i++) {
		int * arr = get_ordered(size);
		start();
		parallel_linear_search(arr, size, item);
		times[i] = end();
	}
	double tot = 0;
	for (int i = 0 ; i < iterations ; i++) {
		tot += times[i];
	}
	tot /= (double) iterations;
	printf("average duration for ordered: %f\n",tot);

	for (int i = 0 ; i < iterations ; i++) {
		int * arr = get_reversed(size);
		start();
		parallel_linear_search(arr, size, item);
		times[i] = end();
	}
	tot = 0;
	for (int i = 0 ; i < iterations ; i++) {
		tot += times[i];
	}
	tot /= (double) iterations;
	printf("average duration for reversed: %f\n",tot);
	
	for (int i = 0 ; i < iterations ; i++) {
		int * arr = get_random(size);
		start();
		parallel_linear_search(arr, size, item);
		times[i] = end();
	}
	tot = 0;
	for (int i = 0 ; i < iterations ; i++) {
		tot += times[i];
	}
	tot /= (double) iterations;
	printf("average duration for randomised: %f\n",tot);

}
