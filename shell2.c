#include "shell.h"
/**
 * _strcat - function to concat
 * @dest: pointer char
 * @src: pointer char
 * Return: char
 */
char *_strcat(char *dest, char *src)
{
int i = 0;
int j = 0;
while (dest[i] != '\0')
i++;
while (src[j] != '\0')
{
dest[i] = src[j];
i++;
j++;
}
return (dest);
}

/**
 * strtoav - function from string to array
 * @str: pointer char
 * @array: table of strings
 * Return: void
 */

void strtoav(char *str, char *array[])
{
int i = 0;

array[i] = strtok(str, ":");

while (array[i] != NULL)
array[++i] = strtok(NULL, ":");
}

/**
 * path_function - function to get path
 * @array: pointer pointer char
 * Return: int
 */

int path_function(char **array)
{
struct stat buf;
int i;
char *str = strdup(getenv("PATH"));
char **tokens;
char *tmp;
char *cmd;
tokens = malloc(sizeof(char *) * 1024);
strtoav(str, tokens);
for (i = 0; array[i]; i++)
{
tmp = _strcat(tokens[i], "/");
cmd = _strcat(tmp, array[0]);

if (stat(cmd, &buf) != -1)
{
printf("%s\n", cmd);
array[0] = cmd;
break;
}
}
return (execve(array[0], array, NULL));
}