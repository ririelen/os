#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

int main () {
	int n;
	printf("Enter the number of students: ");
	scanf("%d", &n);
	int high = 0;
	int low = 100;
	int * array = malloc(sizeof(int) * n);
	if (array == NULL) {
		printf("Allocation fail\n");
		return 1;
	}
	printf("Enter the grades: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &array[i]);
		if (array[i] < low) {
			low = array[i];
		}
		if (array[i] > high) {
                        high = array[i];
                }
	}
	printf("Highest grade: %d\nLowest grade: %d\n", high, low);
	free(array);
}
