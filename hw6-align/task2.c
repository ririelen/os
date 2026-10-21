#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

struct test {
        char a;
        double b;
        int c;
};

int main() {
	struct test s;
	printf("Size of s = %jd, Address of s: %p\n\nSize of a = %jd, Address of a: %p\nSize of b = %jd, Address of b: %p\nSize of c = %jd, Address of c: %p\n",
                                (intmax_t) sizeof(s), (void*)&s,
                                (intmax_t) sizeof(s.a), (void*)&s.a,
                                (intmax_t) sizeof(s.b), (void*)&s.b,
                                (intmax_t) sizeof(s.c), (void*)&s.c);


};
