#include "main.h"
/**
 * get_command
 */
int get_command(char *buffer)
{
        int i = 1, pathflag;
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

