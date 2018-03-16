#include <stdio.h>
#include <time.h>

//utilities to help with running benchmarks
clock_t start_t;

void start() {
    start_t = clock();
}

double end() {
	double time = ((double) (clock() - start_t)) / CLOCKS_PER_SEC;
//    printf("duration: %f seconds\n",time);
	return time;
}

int * get_file(char * fname, int size) {
	FILE *f = fopen(fname,"r");
	int * arr = malloc(size*sizeof(int));

	int i = 0;
	int num;
	while(fscanf(f,"%d\n",&num) == 1) {
		arr[i] = num;
	}
	fclose(f);
	return arr;
}

int * get_ordered(int size) {
	return get_file("ordered.txt",size);
}

int * get_reversed(int size) {
	return get_file("reversed.txt",size);
}

int * get_random(int size) {
	return get_file("random.txt",size);
}
