#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include "benchmark.h"

void parallel_swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

int parallel_partition(int* arr, int low, int high) {
    int pivot_val = arr[low];
    int left = low + 1;
    int right = high - 1;

    while (right >= left) {
    
        while (left <= right && arr[left] <= pivot_val) {
            left++;
        }
        while (left <= right && arr[right] >= pivot_val) {
            right--;
        }

        if (right >= left) {
            parallel_swap(arr + left ,arr + right );
        }
    }
    parallel_swap(arr + right, arr + low);
    return right;
}

void quicksort_helper(int* arr, int low, int high) {
    if (low < high) {
	    int pivot_index = parallel_partition(arr,low,high);
		#pragma omp task
		{
    		quicksort_helper(arr,low,pivot_index);
		}
		#pragma omp task
		{
        	quicksort_helper(arr,pivot_index + 1,high);
		}
    }
}

void parallel_sort(int *arr, int size) {
	#pragma omp parallel
	{
		#pragma omp single 
		{
			quicksort_helper(arr, 0, size - 1);
		}
	}
}

int main(int argc, char ** argv) {
	int iterations = atoi(argv[1]);
	int size = atoi(argv[2]);

	printf("Testing parallel sort with\n* %d iterations\n* %d numbers\n",iterations,size);

	double * times = malloc(sizeof(double)*iterations);
	for (int i = 0 ; i < iterations ; i++) {
		int * arr = get_ordered(size);
		start();
		parallel_sort(arr, size);
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
		parallel_sort(arr, size);
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
		parallel_sort(arr, size);
		times[i] = end();
	}
	tot = 0;
	for (int i = 0 ; i < iterations ; i++) {
		tot += times[i];
	}
	tot /= (double) iterations;
	printf("average duration for randomised: %f\n",tot);

}
