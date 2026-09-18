#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/wait.h>

// maximal inclusivity for minimal intelligency

int main()
{
	pid_t pid = fork();
        siginfo_t info;
	if (pid == 0) // if child
	{
		execl("/bin/ls", "ls", NULL);
	}
	else // if parent
	{
		while(waitpid(pid, NULL, 0)>0);
		printf("Parent process done\n");
	}
}
