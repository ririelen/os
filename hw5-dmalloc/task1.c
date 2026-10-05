#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/wait.h>

int main () {
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	printf("\n");
	int * array = malloc(sizeof(int) * n);
	if (array == NULL) {
		printf("Memory Allocation failed\n");
		return 1;
	}
	printf("Enter %d integers: ", n);
	int cur;
	int s = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &cur);
		array[i] = cur;
		s = s + cur; // i hope it is allowed...
// i mean that i do not wait till all the integers are input...
	}
	printf("\n");
	printf("Sum of the array: %d\n", s);
	free(array);
}
