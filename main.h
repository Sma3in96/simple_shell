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

extern char **environ;

int is_it_path(char *str);
int check_add_path(char **str);
int get_argc(char *buffer2, int nread); 
int get_command(char *buffer);
void freefunction (char *buffer, char **command1);
int excute_command(char *pathcmd, char **command, char **__environ);
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

