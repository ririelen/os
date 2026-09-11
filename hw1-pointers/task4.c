#include <stdio.h>

int main()
{
	int a = 7;
	int* ap = &a;
	int** app = &ap;
	printf("Single-p: a = %d\n", *ap);
	printf("Double-p: a = %d\n", **app);
}
