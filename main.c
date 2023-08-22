#include "main.h"
void sigint_handler(int signum) 
{
        (void)signum;

        write(STDOUT_FILENO, "\n&& ", 4);
        exit(0);
}
/**
 * main
*/
int main(void)
{
        int i = 1, nread = 0, argcount = 0, j = 1, pathflag = 0;
        char *buffer;
        char **command;
        char *pathraw;
        char **path; 
        
        pathraw = getenv("PATH");
        path = convert_path(pathraw);
        signal(SIGINT, sigint_handler);

        while (i == 1)
        {
                write(STDOUT_FILENO, "&& ", 3);
                fflush(stdout);
                buffer = read_line(&nread);
                if (nread != -1)
                {
                        argcount = get_argc(buffer, nread);
                        command = get_command(buffer, argcount);
                        if (command == NULL)
                                continue;
                        if (command[0] == NULL)
                                continue;
                        pathflag = is_it_path(command[0]);
                        if (pathflag == 1)
                                command[0] = check_add_path(command[0], path);
                        if (pathflag == 2)
                                continue;
                        if (command[0] == NULL)
                        {
                                while (command[j] != NULL )
                                {
                                        free(command[j]);
                                        j++;
                                }
                                free(command);
                        }
                        excute_command(command, __environ);
                        freefunction(NULL, command);
                        fflush(stdout);
                }
                else
                {
                        i = 0;
                }
        }
        return (0);
}
