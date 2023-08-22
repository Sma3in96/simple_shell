#include "main.h"
/**
 * excute_command -
 */
int excute_command(char **command1, char **__environ)
{
        pid_t child;
        int status = 0;


        child = fork();
        if (child == -1)
                exit(1);
        if (child == 0)
        {
                execve(command1[0], command1, __environ);
                perror(command1[0]);
                _exit(status);
        }
        else
        {
                wait(NULL);
        }
        return (0);
}
