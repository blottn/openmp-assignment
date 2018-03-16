#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include "benchmark.h"

void parallel_swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void insertion_sort(int * arr, int low, int high) {
	for (int i = 1; i < high ; i++) {
		int val = arr[i];
		int j;
		for (j = i; j > low && val < arr[j - 1] ; j--) {
			arr[j] = arr[j - 1];
		}
		arr[j] = val;
	}
}

int parallel_partition(int* arr, int low, int high) {
	
	int pi = rand() %(high - low);
	parallel_swap(arr + low, arr + pi);

    int pivot_val = arr[low];
    int left = low + 1;
    int right = high - 1;

    while (right >= left) {
    
        while (left <= right && arr[left] < pivot_val) {
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
	if (high - low < 30) { // quicksort is slower than insertion sort on fewer than 30 elements because the function entry is generally very expensive
		insertion_sort(arr,low,high);
	}
	else if (low < high) {
	    int pivot_index = parallel_partition(arr,low,high);
		
		int top = pivot_index - 1;
		while (top > low && arr[top] == arr[pivot_index]) {
			top--;
		}

		int bottom = pivot_index + 1;
		while (bottom < high && arr[bottom] == arr[pivot_index]) {
			bottom++;
		}

		#pragma omp task
		{
    		quicksort_helper(arr,low,top);
		}
		#pragma omp task
		{
        	quicksort_helper(arr,bottom,high);
		}
    }
}

void parallel_sort(int *arr, int size) {
	#pragma omp parallel
	{
		#pragma omp single 
		{
			quicksort_helper(arr, 0, size);
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
