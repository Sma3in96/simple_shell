#include "main.h"
/**
 * get_command
 */
char **get_command(char *buffer, int argcount)
{
        char *token = NULL;
        char **command;
        int i = 1, j = 0;

        if (buffer == NULL)
                return (NULL);

        command = malloc(argcount * sizeof(char *));
        if (command == NULL)
                return (NULL);

        token = _strtok(buffer, " \n");
        if (token == NULL)
        {
                command[0] = NULL;
                return (NULL);
        }
        command[0] = malloc((_strlen(token) + 1) * sizeof(char));
        if (command[0] == NULL)
        {
                free(command);
                return(NULL);
        }
        _strcpy(command[0], token);
        while ((token = _strtok(NULL, " \n")) != NULL)
        {
                command[i] = malloc((_strlen(token) + 1) * sizeof(char));
                if (command[i] == NULL)
                {
                        for (j = 0; j < i; j++)
                                free(command[j]);
                        free(command);
                        break;
                }
                _strcpy(command[i], token);
                i++;
        }
        command[i] = NULL;
        return (command);
}
