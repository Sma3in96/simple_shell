#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <signal.h>


int is_it_path(char *str);
char **convert_path(char *pathraw);
char *check_add_path(char *str, char **path);
int get_argc(char *buffer2, int nread); 
char **get_command(char *buffer, int argcount);
void freefunction (char *buffer, char **command1);
int excute_command(char **command, char **__environ);
char *read_line (int *nread);
void sigint_handler(int signum);

/* str_functions*/
char *_strstr(char *haystack, char *needle);
char *_strcpy(char *dest, char *src);
char *_strtok(char str[], const char *delim);
int cmp_chars(char str[], const char *delim);
int _strlen(const char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *_strstr(char *haystack, char *needle);

#endif
