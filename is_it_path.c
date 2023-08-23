#include "main.h"
/**
 * is_it_path - is it a path or not
 * @str: string
*/
int is_it_path(char *str)
{
        if (str == NULL)
                return (2);
        if (_strstr(str, "/bin/") == NULL )
                return(1);
        return(0);
                
}
