#include "main.h"
/**
 * readline - read
 * 
*/
char *read_line (int *nread)
{
        char *buffer = NULL;
        size_t len = 0;

        *nread = getline(&buffer, &len, stdin);

        return (buffer);
}
