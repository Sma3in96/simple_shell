#include "main.h"
/**
 * check_exit - check for exit
 * @tokens: command
 * Return: int
 */
int check_exit(char **tokens)
{
	if (_strcmp(tokens[0], "exit") == 0)
		return (0);
	return(1);
}
/**
 * get_command
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
	exitflag = check_exit(tokens);
	if (exitflag == 0)
		return (100);
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

