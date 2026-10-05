#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
	int * array = malloc(sizeof(int)*10); // array of 10 elements
	if (array == NULL) {
                printf("Memory Allocation failed\n");
                return 1;
        }
	printf("Enter 10 integers: ");
        int cur;
        int s = 0;
        for (int i = 0; i < 5; i++) {
                scanf("%d", &cur);
                array[i] = cur;
        }
	printf("\n");
	int * newarray = realloc(array, sizeof(int)*5);
	if(newarray == NULL) {
		printf("Reallocation failed\n");
		return 1;
	}
	array = newarray; // updating pointer...
	printf("Array after resizing:");
	for (int i = 0; i < 5; i++) {
		printf(" %d", array[i]);
	}
	printf("\n");
	free(array);
}

