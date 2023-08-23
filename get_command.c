#include "main.h"
/**
 * check_exit - check for exit
 * @token: command
 * Return: int
 */
int check_exit(char *token)
{
	if (_strcmp(token, "exit") == 0)
		return (0);
	return(1);
}
/**
 * _envcommand - print env var
 * @token: string
 * Return: int
 */
int _envcommand(char *token)
{
	char **env = environ;
	size_t len;

	if (_strcmp(token, "env") == 0)
	{
		while (*env)
		{
		len = strlen(*env);
		write(STDOUT_FILENO, *env, len);
		write(STDOUT_FILENO, "\n", 1);
		env++;
		}
		return (1);
	}
	return (0);
}
/**
 * get_command - get command to exe
 * @buffer: string
 * Return: int
 */
int get_command(char *buffer)
{
        int i = 1, pathflag, exitflag;
        char *tokens[32];
        char *token;

        if (tokens == NULL)
        {
                return(0);
        }

        token = _strtok(buffer, " \n");
        tokens[0] = token;

        for (i = 1; token != NULL; i++)
        {
                token = _strtok(NULL, " \n");
                tokens[i] = token;
        }
        if (tokens[0] != NULL)
	{
                exitflag = check_exit(tokens[0]);
	        if (exitflag == 0)
		        return (100);
        }
        if (tokens[0] && _envcommand(tokens[0]) == 1)
		return (0);
	pathflag = is_it_path(tokens[0]);
        if (pathflag == 1)
        {
                return (check_add_path(tokens));
        }
        if (pathflag == 2)
                return (0);
        if (pathflag == 0)
                excute_command(tokens[0], tokens, __environ);
        
        free(token);


        return (1);

}
