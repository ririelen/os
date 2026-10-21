#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

struct t3 {
        char a;
        int b;
        double c;
};

#pragma pack(1)
struct t3p {
        char a;
        int b;
        double c;
	char d;
};

int main() {
	struct t3 s;
	printf("\nWithout #pragma pack:\n\n");
	printf("Size of s = %jd, Address of s: %p\n\nSize of a = %jd, Address of a: %p\nSize of b = %jd, Address of b: %p\nSize of c = %jd, Address of c: %p\n",
                                (intmax_t) sizeof(s), (void*)&s,
                                (intmax_t) sizeof(s.a), (void*)&s.a,
                                (intmax_t) sizeof(s.b), (void*)&s.b,
                                (intmax_t) sizeof(s.c), (void*)&s.c);

        struct t3p p;
        printf("\nWith #pragma pack:\n\n");
        printf("Size of p = %jd, Address of p: %p\n\nSize of a = %jd,  Address of a: %p\nSize of b = %jd, Address of b: %p\nSize of c = %jd,  Address of c: %p\nSize of d = %jd, Address of d: %p\n",
                                (intmax_t) sizeof(p), (void*)&p,
                                (intmax_t) sizeof(p.a), (void*)&p.a,
                                (intmax_t) sizeof(p.b), (void*)&p.b,
                                (intmax_t) sizeof(p.c), (void*)&p.c,
				(intmax_t) sizeof(p.d), (void*)&p.d);

};
