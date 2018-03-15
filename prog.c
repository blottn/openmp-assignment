#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include "sort.h"
#include "timer.h"

int main() {
    int size = 1000000;
    int * arr = malloc(size*sizeof(int));
    for (int i = 0 ; i < size ; i++) {
        arr[i] = (((100 - i) * 347)  % 101);
  //      arr[i] = size - i;
    }
//    print_arr(arr,size);
    
//    swap(arr,arr + size - 1);
    start();
    //quicksort(arr,0,size,1);
    linear_search(arr,size,-6,8);
    end();
    
//    print_arr(arr,size);
}
