#include <stdio.h>
#include <omp.h>

void quicksort(int* arr, int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr,low,high);
        quicksort(arr,low,pivot_index -1);
        quicksort(arr,pivot_index + 1,high);
    }
}

int partition(int* arr, int low, int high) {
    int part_val = arr[high -1];
    
    return 0;
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}


int main() {
    int x = 2;

    #pragma omp parallel num_threads(2) shared(x)
    {
        if (omp_get_thread_num() == 0) {
            x = 5;
        }
        else {
            printf("1: Thread# %d: x= %d\n",omp_get_thread_num(),x);
        }

        #pragma omp barrier
        if (omp_get_thread_num() == 0) {
            printf("2: Thread# %d: x= %d\n",omp_get_thread_num(),x);
        }
        else {
            printf("3: Thread# %d: x= %d\n",omp_get_thread_num(),x);
        }
    }
    return 0;
}




