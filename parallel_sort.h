#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include "timer.h"

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

void parallel_quicksort(int *arr, int low, int high) {
	#pragma omp parallel
	{
		#pragma omp single 
		{
			quicksort_helper(arr, low, high);
		}
	}
}

int main(char ** argv, int argc) {
	char buf[10];
	read(0,buf,10);
	printf("%c",buf[9]);
}
