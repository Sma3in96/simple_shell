#include "main.h"

void freefunction(char *buffer, char **command1)
{
        int i = 0;

        if (buffer == NULL)
		free(buffer);
        while (command1[i] !=  NULL)
        {
                free(command1[i]);
                i++;
        }
        free(command1);
}
