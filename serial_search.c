#include <stdlib.h>
#include <stdio.h>
#include "benchmark.h"

/*
 * This is a deliberately slightly inefficient implementation of serial linear search.
 * It avoids terminating early as I couldn't get the parallel implementation to terminate early
 * so I have made this one equally inefficient so they are comparing the usage of concurrency rather than the
 * implementation specifics.
 */
int serial_linear_search(int *arr, int size, int target) {
	int index = -1;
	for (int i = 0 ; i < size ; i++) {
		if (arr[i] == target && index == -1) {	// only find first one
			index = i;
		}
	}
	return index;
}

int main(int argc, char **  argv) {

	int iterations = atoi(argv[1]);
	int size = atoi(argv[2]);
	int item = atoi(argv[3]);

	printf("Testing serial search with\n* %d iterations\n* %d numbers\n* for the number %d\n",iterations,size,item);

	double * times = malloc(sizeof(double)*iterations);
	for (int i = 0 ; i < iterations ; i++) {
		int * arr = get_ordered(size);
		start();
		serial_linear_search(arr, size, item);
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
		serial_linear_search(arr, size, item);
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
		serial_linear_search(arr, size, item);
		times[i] = end();
	}
	tot = 0;
	for (int i = 0 ; i < iterations ; i++) {
		tot += times[i];
	}
	tot /= (double) iterations;
	printf("average duration for randomised: %f\n",tot);

}
