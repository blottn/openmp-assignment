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

void serial_quicksort(int* arr, int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr,low,high);
        serial_quicksort(arr,low,pivot_index);
        serial_quicksort(arr,pivot_index + 1,high);
    }
}
