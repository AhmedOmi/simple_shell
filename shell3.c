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
while ((c = (char)getc(stream)) != '\n' && count < size[count] - 1) {
*buf[count++] = c;
}
*buf[count] = '\0';
return (count);
}