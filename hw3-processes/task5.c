#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

int main() {
	pid_t pid = fork();
	if (pid == 0) // if that is child
	{
		printf("Child PID: %jd\n", (intmax_t) getpid());
		sleep(10);
		exit(0); // no error yet
	}
	else // if parent
	{
		int status;
		printf("Parent PID: %jd\n", (intmax_t) getpid());
		// no wait:
		// sleep(30);
		// wait:

		wait(&status);
		printf("Child is done executing\n");
		sleep(30);
	}
}
