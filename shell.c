#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <stdbool.h>

void sigintHandler();
char *r_line(char *buffer);
/**
 * main - function main
 *
 * Return: integer = 0
 */

int main(void)
{
char *buffer = NULL;
char *token;
char **array = malloc(sizeof(char *) * 2);

/*signal to cancel ctrl + c*/
signal(SIGINT, sigintHandler);
while (1)
{
printf("#cisfun$ ");
buffer = r_line(buffer);
token = strtok(buffer, " \n");
array[0] = token;
array[1] = NULL;
if (execve(token, array, NULL) == -1)
{
perror("Error:");
}
}
return (0);
}

/**
 * sigintHandler - function to cancel ctrl+c
 *
 * Return: void
 */
void sigintHandler()
{

signal(SIGINT, sigintHandler);
printf("\n press CTRL + d to exit \n");
fflush(stdout);
}

/**
 * r_line - function to get line
 * @buffer: pointer char
 * Return: char
 */

char *r_line(char *buffer)
{
buffer = NULL;
size_t size_buffer;
ssize_t count = getline(&buffer, &size_buffer, stdin);
if (count == EOF)
{
write(STDOUT_FILENO, "\n", 1);
exit(0);
}
return (buffer);
}
