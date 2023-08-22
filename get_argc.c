#include "main.h"
/**
 * get_argc - number of arguments for a command line
 * 
*/
int get_argc(char *buffer, int nread)
{
        int count = 0, argnumber = 0, i;

        (void) nread;
        if (buffer == NULL)
                return (0);
        for (i = 0 ; buffer[i] != '\0'; i++ )
        {
                if (buffer[i] == ' ')
                        count = 0;
                else if (!count)
                {
                        argnumber++;
                        count = 1;
                }
        }

        return (argnumber);
}
