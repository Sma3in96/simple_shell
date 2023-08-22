#include "main.h"

char **convert_path(char *pathraw)
{
    char **path = NULL;
    int len_path = 0, i = 0, j = 0, npaths = 1, flag = 0, count = 0;

    for (i = 0; pathraw[i] != '\0'; i++) {
        if (pathraw[i] == ':') {
            npaths++;
        }
    }
    path = (char **)malloc(sizeof(char *) * (npaths + 1));
    if (path == NULL) {
        perror("malloc");
        return NULL;
    }
    for (i = 0; pathraw[i] != '\0'; i++) {
        if (pathraw[i] != ':')
            len_path++;
        else 
        {
            path[count] = (char *)malloc(len_path + 1);
            if (path[count] == NULL) 
            {
                perror("malloc");
                for (j = 0; j < count; j++)
                    free(path[j]);
                free(path);
                return NULL;
            }
            _strncpy(path[count], pathraw + flag, len_path);
            path[count][len_path] = '\0';
            count++;
            len_path = 0;
            flag = i + 1;
        }
    }
    path[count] = (char *)malloc(len_path + 1);
    if (path[count] == NULL) 
    {
        perror("malloc");
        for (j = 0; j <= count; j++)
            free(path[j]);
        free(path);
        return NULL;
    }
    _strncpy(path[count], pathraw + flag, len_path);
    path[count][len_path] = '\0';
    count++;
    path[count] = NULL;
    return path;
}
