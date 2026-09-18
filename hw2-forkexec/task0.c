#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
	pid_t pid = fork();
	pid = fork();
	siginfo_t info;

	// if child
	if (pid == 0) // no error handling for now :(((((((
	{
		printf("\nDeepest child\n");
		printf("Output! PID: %jd", (intmax_t) getpid());
        	printf(", PPID: %jd\n", (intmax_t) getppid());
	        return 0;
	}
	// if has children
	else
	{
		while (waitid(P_ALL, 0, &info, WEXITED)); // id_t id is ignored if P_ALL
		printf("\nHas children\n");
		printf("Output! PID: %jd", (intmax_t) getpid());
		printf(", PPID: %jd\n", (intmax_t) getppid());
		return 0;
	}
}
// yes my code repeats but its just testing ToT (crying emodji) :'(
