#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include "util.h"

int partition(int* arr, int low, int high) {
    int pivot_val = arr[low];
    int left = low + 1;    //initialise markers
    int right = high - 1;

    while (right >= left) {
    
        while (left <= right && arr[left] <= pivot_val) {
            left++;
        }
        while (left <= right && arr[right] >= pivot_val) {
            right--;
        }

        if (right >= left) {
            //do swap
            swap(arr + left ,arr + right );
        }
    }
    swap(arr + right, arr + low);
    return right;
}

void quicksort(int* arr, int low, int high, int num_threads) {
    if (low < high) {
        int pivot_index = partition(arr,low,high);
        quicksort(arr,low,pivot_index, num_threads / 2);
        quicksort(arr,pivot_index + 1,high, num_threads / 2);
    }
}

int linear_search(int * arr, int size, int item, int threads) {
    int index = size;
    
    #pragma omp parallel for shared(index) num_threads(threads)
    for (int i = 0 ; i < size ; i++) {
        if (arr[i] == item) {
            if (i < index) {
                index = i;
            }
        } 
    }
    return index;
}
