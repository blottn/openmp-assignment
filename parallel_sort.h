#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include "util.h"

int partition(int* arr, int low, int high) {
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
            swap(arr + left ,arr + right );
        }
    }
    swap(arr + right, arr + low);
    return right;
}

void parallel_quicksort(int* arr, int low, int high, int num_threads) {
    if (low < high) {
        int pivot_index = partition(arr,low,high);
        parallel_quicksort(arr,low,pivot_index, num_threads / 2);
        parallel_quicksort(arr,pivot_index + 1,high, num_threads / 2);
    }
}
