#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	char* args[1] = {"Chikibamboni"};
        pid_t pid = fork();
        if (pid == 0) // if this is the SECOND child
        {
                execl("/bin/echo", "echo", *args, (char *)NULL);
        }
        else
        {
                while(waitpid(pid, NULL, 0) > 0);
                printf("Parent process done\n");
        }
}
// I know I did not have to create an array and use pointers to pass arguments,
// but how can I miss a chance to exercise?...
// I think it is even mandatory, as my first programming language was Python...
// so I better work on myself ToT
