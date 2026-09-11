#include <stdio.h>

int main()
{
	int x = 10;
	int y = 99;
	printf("Before swap: x = %d, y = %d\n", x, y);
	swap(&x, &y);
	printf("After swap: x = %d, y = %d\n", x, y);
}
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
