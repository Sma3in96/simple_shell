#include "main.h"
/**
 * excute_command - excute commands
 * @pathcmd: string
 * @command1: string
 * @__environ: var
 * Return: int
 */
int excute_command(char *pathcmd, char **command1, char **__environ)
{
        pid_t child;
        int status = 0;
        int i = 0;

        (void) i;
        child = fork();
        if (child == -1)
                exit(1);
        if (child == 0)
        {
                execve(pathcmd, command1, __environ);
                _exit(status);
        }
        else
        {
                wait(NULL);
                if (command1 == NULL)
                        write(STDOUT_FILENO,"commmmmd", 8);
        }
        return (0);
}
