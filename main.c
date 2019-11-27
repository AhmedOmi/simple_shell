#include "shell.h"
/**
 * main - function main
 *
 * Return: integer = 0
 */

int main(void)
{
char *buffer = NULL;
char **array;
/*signal to cancel ctrl + c*/
signal(SIGINT, sigintHandler);
while (1)
{
printf("#cisfun$ ");
buffer = r_line(buffer);
array = split(buffer);
env(array);
if (path_function(array) == 0)
{
perror("Error:");
}
}
return (0);
}