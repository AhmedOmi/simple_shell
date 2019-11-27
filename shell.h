#ifndef HEADER_FILE
#define HEADER_FILE


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

extern char **environ;

char *mystrtok(char *str, char *comp);
ssize_t _getline(char **buf, size_t *size, FILE *stream);
void sigintHandler();
char *r_line(char *buffer);
char **split(char *buffer);
void env(char **array);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
void strtoav(char *str, char *array[]);
int path_function(char **array);

#endif
