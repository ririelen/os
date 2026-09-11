#include <stdio.h>

int main()
{
	int x = 1;
	int* xp = &x;
	printf("Address through variable: %p\n", &x);
	printf("Address through pointer: %p\n", xp);
	printf("x = %d\n", x);
	*xp = 2;
	printf("x = %d\n", x);
}
