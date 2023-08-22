#include "main.h"
char *lookforcmd(char *str, char **path)
{
        int index = 0;
        DIR *dir;
        struct dirent *dossier;
        int found = 0;
        

        while (path[index] != NULL)
        {
                dir = opendir(path[index]);
                if (dir == NULL)
                {
                        perror("opendir");
                        return(NULL);
                }
                while ((dossier = readdir(dir)) != NULL)
                {
                        if (dossier->d_type == DT_REG && _strcmp(dossier->d_name, str) == 0)
                        {
                                found = -1;
                                break;
                        }

                }
                if (found == -1)
                        break;
                index++;
        }
        if (found != -1)
        {
                /* errorfunction("not found"); */
                return (NULL);
        }
        return(path[index]);
}

char *check_add_path(char *str, char **path)
{
        char *pathcmd;
        char *directory;

        if (str == NULL || path == NULL)
                return(NULL);
        directory = lookforcmd(str, path);
        pathcmd = malloc(strlen(str) + strlen(directory) + 2 );
        pathcmd = _strcpy(pathcmd, directory);
        pathcmd = _strcat(pathcmd, "/");
        pathcmd = _strcat(pathcmd, str);
        pathcmd[_strlen(str) + _strlen(directory) +1] = '\0';
        return (pathcmd);
}
