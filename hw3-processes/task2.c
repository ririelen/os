#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
	pid_t pid = fork();
	if (pid == 0) // if that is the first child
	{
		printf("Child PID: %jd\n", (intmax_t) getpid());
		exit(0); // no error yet
	}
	else // if parent
	{
		int status;
		wait(&status);
		printf("Child #1 exited with status %jd\n", (intmax_t) status);
		pid = fork();
		if (pid == 0) // another child
		{
			printf("Child #2, PID: %jd\n", (intmax_t) getpid());
			exit(88);
		}
		else
		{
			while(waitpid(pid, &status, 0) > 0);
			printf("Child #2 exited with status %jd\n", (intmax_t) status);
			printf("Parent PID: %jd\n", (intmax_t) getpid());
		}
	}
}
