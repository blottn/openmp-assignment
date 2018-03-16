#include <stdio.h>
#include <time.h>

//utilities to help with running benchmarks
struct timespec * start_t;

void start() {
	if (start_t == NULL) {
		start_t = malloc(sizeof(struct timespec));
	}
	clock_gettime(CLOCK_MONOTONIC, start_t);
}

/*double end() {
	double time = ((double) (clock() - start_t)) / CLOCKS_PER_SEC;
//    printf("duration: %f seconds\n",time);
	return time;
}*/

double end() {
	struct timespec * end_t = malloc(sizeof(struct timespec));
	clock_gettime(CLOCK_MONOTONIC,end_t);
	double time =(double) (end_t->tv_sec - start_t->tv_sec);
	time += ((double) (end_t->tv_nsec - start_t->tv_nsec)) / (double) 1000000000;
	return time;
}

int * get_file(char * fname, int size) {
	FILE *f = fopen(fname,"r");
	int * arr = malloc(size*sizeof(int));

	int i = 0;
	int num;
	while(fscanf(f,"%d\n",&num) == 1) {
		arr[i] = num;
		i++;
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
