#include <stdlib.h>
#include <stdio.h>

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void print_arr(int *arr, int size) {
	printf("arr: ");
	for (int i = 0 ; i < size ; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
