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

			// first, let's make a timer!
			pid_t timerpid = fork(); // create a timer! i am too lazy to make it a function...
			if (timerpid == 0) // if this IS the timer
			{
				sleep(30);
				exit(0);
			}

		wait(&status); // the not-timer child will exit first anyway...
		printf("Child is done executing\n");
		while(waitpid(timerpid, NULL, 0) > 0); // has the time elapsed?
	}
}
