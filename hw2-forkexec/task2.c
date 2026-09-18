#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	pid_t pid1 = fork();
	if (pid1 != 0) // if this is parent
	{
		while(waitpid(pid1, NULL, 0) > 0); // wait till 1st ch. terminates
		pid_t pid2 = fork();
		if (pid2 == 0) // if this is the SECOND child
		{
			execl("/bin/date", "date", NULL);
		}
		else
		{
			while(waitpid(pid2, NULL, 0) > 0);
			printf("Parent process done\n");
		}
	}
	else // only inside the FIRST child
	{
		execl("/bin/ls", "ls", NULL);
	}

}
