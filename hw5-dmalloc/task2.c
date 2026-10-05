#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	printf("\n");
	int * array = calloc(sizeof(int), n);
	if (array == NULL) {
		printf("Memory Allocation failed\n");
		return 1;
	}
	printf("Array after calloc:");
	for (int i = 0; i < n; i++) {
		printf(" %d", array[i]);
	}
	printf("\n");
	printf("Enter %d integers: ", n);
	int cur;
	int s = 0;
	// this time i will access array in a separate loop...
	for (int i = 0; i < n; i++) {
		scanf("%d", &cur);
		array[i] = cur;
	}
	printf("Updated array:");
	for (int i = 0; i < n; i++) {
		printf(" %d", array[i]);
		s = s + array[i]; // god forbid a student optimize their efforts...
	}
	printf("\n");
	float avg = s / n;
	printf("Average of the array: %f\n", avg);
	free(array);
}

