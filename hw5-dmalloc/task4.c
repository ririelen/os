#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

int main() {
	char ** array = malloc(sizeof(char*) * 3);
	if (array == NULL) {
		printf("Allocation has failed\n");
		return 1;
	}
	for (int i = 0; i < 3; i++) {
		array[i] = malloc(sizeof(char) * 50);
		if (array[i] == NULL) {
                	printf("Allocation has failed\n");
                return 1;
        	}
	}
	printf("Enter 3 strings, separate them with spaces: ");
	for (int i = 0; i < 3; i++) {
		scanf("%s", array[i]);
	}
	printf("\n");
	printf("First 3 strings:");
	for (int i = 0; i < 3; i++) {
		printf(" %s", array[i]);
	}
	printf("\n");
	char ** newarray = realloc(array, sizeof(char*) * 5);
	if (newarray == NULL) {
                printf("Reallocation has failed\n");
                return 1;
        }
	array = newarray; // update the pointer... ig for metadata, no?
	for (int i = 3; i < 5; i++) {
		array[i] = malloc(sizeof(char) * 50);
		if (array[i] == NULL) {
			printf("Allocation falied\n");
			return 1;
		}
	}
	printf("Enter 2 more strings: ");
        for (int i = 3; i < 5; i++) {
                scanf("%s", array[i]);
        }
        printf("\n");
	printf("All strings:");
	for (int i = 0; i < 5; i++) {
                printf(" %s", array[i]);
        }
	printf("\n");
	for (int i = 0; i < 5; i++) {
		free(array[i]);
	}

	free(array);
}

