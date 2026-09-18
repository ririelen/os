#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
        pid_t pid = fork();
        if (pid == 0) // if this is the child
        {
                execl("/bin/grep", "grep", "-n", "ar", "test.txt", (char *)NULL);
        }
        else
        {
                while(waitpid(pid, NULL, 0) > 0);
                printf("Parent process done\n");
        }
}
