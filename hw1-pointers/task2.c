#include <stdio.h>

int main()
{
	int i;
        int arr[5] = {10, 11, 12, 13, 14};
        int* arrp = arr;
        for(i = 0; i < 5; i++)
        {
                printf("%d\n", *(arrp+i));
        }
	for(i = 0; i < 5; i++)
	{
		*(arrp+i) = *(arrp+i)+5;
	}
        for(i = 0; i < 5; i++)
        {
                printf("%d\n", *(arrp+i));
        }
	for(i = 0; i < 5; i++)
	{
		printf("%d\n", arr[i]);
	}
}
