#include <stdio.h>

int main()
{
	char str[] = "Hello";
	char* strp = str;
	int i = 0;
	while(*strp != '\0')
	{
		printf("%c ", *strp);
		strp++;
		i++;
	}
	printf("\nNumber of characters = %d\n", i);
}
