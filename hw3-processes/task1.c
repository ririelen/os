#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
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
