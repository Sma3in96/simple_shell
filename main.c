#include "main.h"
/**
 * sigint_handler - sginal
 * @signum
 *
 * Return : void
 */
void sigint_handler(int signum) 
{
        (void)signum;
	
	if (isatty(STDIN_FILENO))
        	write(STDOUT_FILENO, "\n&& ", 4);
        exit(0);
}
/**
 * main - entry point
 * Return: int
*/
int main(void)
{
        int i = 1, nread = 0;
        size_t len = 0;
        char *buffer = NULL;
        int fail;

        signal(SIGINT, sigint_handler);

        while (i == 1)
        {
                if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "&& ", 3);
                fflush(stdout);
                nread = getline(&buffer, &len, stdin);
                if (nread != -1)
                {
                        fail = get_command(buffer);
                        if (fail == 100)
                        {
				free(buffer);
				exit(0);
			}
                        fflush(stdout);
                }
                else
                {
                        i = 0;
			if (buffer != NULL)
				free(buffer);
                }
        }
        return (0);
}
