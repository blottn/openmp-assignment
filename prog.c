#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include "parallel_sort.h"
#include "serial_sort.h"
#include "parallel_search.h"
#include "serial_search.h"
#include "timer.h"

int main() {
    int size = 1000;
    int * arr = malloc(size*sizeof(int));
    for (int i = 0 ; i < size ; i++) {
		arr[i] = size - i;
       // arr[i] = (((100 - i) * 347)  % 101);	// "random" numbers
    }

//    for (int i = 0 ; i < size ; i++) {
//		printf("%d: %d\n",i,arr[i]);
//	}
    start();
	parallel_quicksort(arr,0,size);
    end();

	for (int i = 0 ; i < size ; i++) {
		printf("%d: %d\n",i,arr[i]);
	}
    
}
