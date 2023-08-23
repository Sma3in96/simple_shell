#include "main.h"
/**
 * lookforcmd - look for command
 * @str: string
 * Return: string
 */
char *lookforcmd(char *str)
{
        int index = 0;
        DIR *dir;
        struct dirent *dossier;
        int found = 0;
        char *token;
        
        token = _strtok(getenv("PATH"), ":");
        while (token != NULL)
        {
                dir = opendir(token);
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
                                closedir(dir);
                                break;
                        }

                }
                if (found == -1)
                        break;
                index++;
                closedir(dir);
                token = _strtok(NULL, ":");
        }
        if (found != -1)
        {
                write(STDERR_FILENO, "command not found\n", 18);
                return (NULL);
        }
        return(token);
}
/**
 * check_add_path - check path
 * @str: double pointer
 * Return: int
 */
int check_add_path(char **str)
{
        char *pathcmd;
        char *directory;

        if (str[0] == NULL)
                return(0);
        directory = lookforcmd(str[0]);
        if (directory == NULL)
                return (0);
        pathcmd = malloc(sizeof(char) * (_strlen(str[0]) + _strlen(directory) + 2));
        if (pathcmd == NULL)
        {
                free(pathcmd);
                return (0);
        }
        pathcmd = _strcpy(pathcmd, directory);
        pathcmd = _strcat(pathcmd, "/");
        pathcmd = _strcat(pathcmd, str[0]);
        excute_command(pathcmd, str, __environ);

        free(pathcmd);

        return (1);
}
