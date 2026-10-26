#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

// i need to implement quicksort with no references, like only with my mind. otherwise my ego will be harmed.
// thiw will be for integers

void swap(int * p1, int * p2) {
	int temp = *p1;
	*p1 = *p2; // the address stored in p1 now contains the contents of the address stored at p2
	*p2 = temp; // if we swap the addresses between the pointers this would not work with arrays
};
// it is an in-place algorithm btw
int part_qs(int * array, int start, int end) { // ig lets make all inclusive, legal indices, not numbers...
	int pivo = array[end];
	int i = start;	// next free position to swap
	for (int j = start; j < end; j++) {
		if (array[j] < pivo) {
			// i++;
			swap(&array[i], &array[j]); // make pointers!
			i++;
		}
	}
	swap(&array[i], &array[end]);	// current i is the first index after all elements that are
					// smaller than pivo, so pivo belongs there
	return i;// returning the index of the pivot
}
void quicksort(int * array, int start, int end) { // initial call will be with (ptr, 0, n-1)
	if (start < end) {
		int pivo = part_qs(array, start, end);
		quicksort(array, start, pivo-1);
		quicksort(array, pivo+1, end);
	}
}
int main() {
	int arr[] = {9, 10, 1, 4, 6, 5, 7, 2, 8, 3, 0};
	quicksort(arr, 0, 10); // 10 = 11-1
	printf("\n");
	for (int i = 0; i < 11; i++) {
		printf("%d ", arr[i]);
	}
}
