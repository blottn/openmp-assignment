#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

void swap(int* x, int* y) {
    int temp = x[0];
    *x = *y;
    *y = temp;
}

int partition(int* arr, int low, int high) {
    int pivot_val = arr[low];

    int left = low + 1;    //initialise markers
    int right = high - 1;

    while (right >= left) {
        while ((left <= right) && (arr[left] <= pivot_val)) {
            left++;
        }
        while (left <= right && arr[right] >= pivot_val) {
            right--;
        }

        if (right >= left) {
            //do swap
            swap(arr + left * sizeof(int),arr + right * sizeof(int));
        }
    }

    return left + 1;
}

void quicksort(int* arr, int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr,low,high);
        quicksort(arr,low,pivot_index -1);
        quicksort(arr,pivot_index + 1,high);
    }
}

int linear_search(int * arr, int size, int item) {
    int index = size;
    
    #pragma omp parallel for shared(index) 
    for (int i = 0 ; i < size ; i++) {
        if (arr[i] == item) {
            if (i < index) {
                index = i;
            }
        } 
    }
    return index;
}
/*
int main() {

    int* arr = malloc(sizeof(int)*10);
    for (int i = 0 ; i < 10 ; i++) {
        arr[i] = i;
    }

    for (int i = 0 ; i < 10; i++) {
        printf("%d\n",arr[i]);
    }
    
    partition(arr,0,10);

    for (int i = 0 ; i < 10; i++) {
        printf("%d\n",arr[i]);
    }

    int index = linear_search(arr,10,4);
    return 0;
}
*/


