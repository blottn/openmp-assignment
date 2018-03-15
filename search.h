#include <omp.h>
int linear_search(int *arr, int size, int item, int threads) {
    int index = size;
    #pragma omp parallel for shared(index) num_threads(threads)
    for (int i = 0 ; i < size ; i++) {
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
