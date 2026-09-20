#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/wait.h>

void fun1(void)
{
	printf("fun1: I am registered first, and executed second!\n");
}
void fun2(void)
{
	printf("fun2: I am registered second, and executed first!\n");
}
int main(void) {
        atexit(fun1);
        atexit(fun2);
        pid_t pid = fork();
        if (pid == 0) // if that is child
        {
                printf("Child PID: %jd\n", (intmax_t) getpid());
                exit(0); // no error yet
        }
        else // if parent
        {
                printf("Parent PID: %jd\n", (intmax_t) getpid());
        }
}
