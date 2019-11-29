#include "shell.h"

/**
*_strcmp - concatination of strings
*@s1:  char pointer
*@s2:  char pointer
*Return: integer
*/
int _strcmp(char *s1, char *s2)
{
int i;
int j;
for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
{
if (s1[i] != s2[i])
{
j = s1[i] - s2[i];
s1[i + 1] = '\0';
}
else
j = 0;
}
return (j);
}
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

array[i] = mystrtok(str, ":");

while (array[i] != NULL)
array[++i] = mystrtok(NULL, ":");
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
