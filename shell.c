#include "shell.h"
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
/*exit*/
if (strcmp(buffer, "exit\n") == 0)
{
free(buffer);
exit(1);
}
/*ctrl + d*/
if (count == EOF)
{
write(STDOUT_FILENO, "\n", 1);
exit(0);
}
return (buffer);
}

/**
 * split - function test of line
 * @buffer: pointer char
 * Return: char
 */

char **split(char *buffer)
{
int i = 0;
int size_buffer = 64;
char **array = malloc(sizeof(char *) * size_buffer);
char *token;
if (!array)
{
exit(EXIT_FAILURE);
}

token = strtok(buffer, " \n");
while (token != NULL)
{
array[i] = token;
i++;
if (i >= size_buffer)
{
size_buffer += 64;
array = realloc(array, sizeof(char *) * size_buffer);
if (!array)
exit(EXIT_FAILURE);
}
token = strtok(NULL, " \n");
}
array[i] = NULL;
return (array);
}
/**
 * env - function environement
 * @array: pointer char
 * Return: void
 */
void env(char **array)
{
  if(strcmp(array[0], "env") == 0)
  {
  int i = 0;
  int tmp;

  while (environ[i] != NULL)
  {
       for (tmp = 0; environ[i][tmp] != '\0'; tmp++)
      write(STDOUT_FILENO, &environ[i][tmp], 1);
      write(STDOUT_FILENO, "\n", 1);
      i++;
    }
  }
}