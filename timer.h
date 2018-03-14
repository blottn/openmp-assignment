#include <time.h>

//wrapper class to simplify time.h usage for timing things

clock_t start_t;

void start() {
    start_t = clock();
}

void end() {
    printf("duration: %f seconds\n",((double) (clock() - start_t)) / CLOCKS_PER_SEC);
}
