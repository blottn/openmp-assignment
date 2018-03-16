#include <time.h>

//wrapper class to simplify time.h usage for timing things

clock_t start_t;

void start() {
    start_t = clock();
}

void end() {
    printf("duration: %f seconds\n",((double) (clock() - start_t)) / CLOCKS_PER_SEC);
}

int * get_file(char * fname, int size) {
	FILE *f = fopen(fname,"r");
	int * arr = malloc(size*sizeof(int));

	int i = 0;
	int num;
	while(fscanf(f,"%d\n",&num) == 1) {
		arr[i] = num;
	}
	return arr;
}

int * get_ordered(int size) {
	return get_file("ordered.txt",size);
}

int * get_unorderd(int size) {
	return get_file("unordered.txt",size);
}

int * get_random(int size) {
	return get_file("random.txt",size);
}
