#include "shell.h"
/**
 * _getline - function to get line
 * @buf: pointer char
 * @size: variable size_t
 * @stream: file
 * Return: size_t
 */

ssize_t _getline(char **buf, size_t *size, FILE *stream)
{
size_t count = 0;
char c;
while ((c = (char)getc(stream)) != '\n' && count < size[count] - 1)
{
*buf[count++] = c;
}
count = count + 1;
*buf[count] = '\0';
return (count);
}

/**
 * mystrtok - function str stock
 * @tr: pointer char
 * @comp: variable char
 * Return: char
 */
char  *mystrtok(char *str, char *comp)
{
static int pos;
static char *s;
static int start;
start = pos;
if (str != NULL)
s = str;
int j = 0;
while (s[pos] != '\0')
{
j = 0;
while (comp[j] != '\0')
{
if (s[pos] == comp[j])
{
s[pos] = '\0';
pos = pos + 1;
if (s[start] != '\0')
return (&s[start]);
else
{
start = pos;
pos--;
break;
}
}
j++;
}
pos++;
}
s[pos] = '\0';
if (s[start] == '\0')
return (NULL);
else
return (&s[start]);
}
