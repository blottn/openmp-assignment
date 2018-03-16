#include <stdlib.h>

int * generate(int size, int ordered) {
	int* arr = malloc(sizeof(int)*size);
	if (ordered == 0) {			//ordered
		for (int i = 0 ; i < size ; i++) {
			arr[i] = i;
		}
	}
	else if (ordered == 1) {	//reversed
		for (int i = 0 ; i < size ; i++) {
			arr[i] = size -i;
		}
	}	
	else if (ordered == 2) {	//random
			// random!
	}
	return arr;
}
