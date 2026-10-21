#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

int main() {
	int x;
	char c;
	double d;
	short s;
	printf("Size of x = %jd, Address of x: %p\nSize of c = %jd, Address of c: %p\nSize of d = %jd, Address of d: %p\nSize of s = %jd, Address of s: %p\n",
				(intmax_t) sizeof(x), (void*)&x,
				(intmax_t) sizeof(c), (void*)&c,
				(intmax_t) sizeof(d), (void*)&d,
				(intmax_t) sizeof(s), (void*)&s);
}
