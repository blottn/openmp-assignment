/*
 * This is a deliberately slightly inefficient implementation of serial linear search.
 * It avoids terminating early as I couldn't get the parallel implementation to terminate early
 * so I have made this one equally inefficient so they are comparing the usage of concurrency rather than the
 * implementation specifics.
 */
int serial_linear_search(int *arr, int size, int target) {
	int index = -1;
	for (int i = 0 ; i < size ; i++) {
		if (arr[i] == target && index == -1) {
			index = i;
		}
	}
	return index;
}
