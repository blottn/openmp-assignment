#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include "parallel_sort.h"
#include "parallel_search.h"
#include "serial_search.h"
#include "timer.h"

int main() {
    int size = 10000000;
    int * arr = malloc(size*sizeof(int));
    for (int i = 0 ; i < size ; i++) {
        arr[i] = (((100 - i) * 347)  % 101);	// "random" numbers
    }
    
    start();
    printf("found -6 at: %d\n",parallel_linear_search(arr,size,-6,8));

    end();
    
}
