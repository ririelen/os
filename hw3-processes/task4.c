#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
	int status1;
	int status2;
	pid_t pid1 = fork();
	if (pid1 == 0) // if that is child #1
	{
		printf("Child #1 PID: %jd\n", (intmax_t) getpid());
		exit(0); // no error yet
	}
	else // if parent
	{
		pid_t pid2 = fork(); // creating child #2
		if (pid2 == 0) // if that IS child #2
        	{
                	printf("Child #2 PID: %jd\n", (intmax_t) getpid());
                	exit(-1); // no error yet
        	}
		while(waitpid(pid1, &status1, 0) > 0);
		while(waitpid(pid2, &status2, 0) > 0);
		printf("Parent PID: %jd\n", (intmax_t) getpid());
		printf("Child #1 PID: %jd, exit status: %jd\n", (intmax_t) pid1, (intmax_t) status1);
		printf("Child #2 PID: %jd, exit status: %jd\n", (intmax_t) pid2, (intmax_t) status2);
	}
}
