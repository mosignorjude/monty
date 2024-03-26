#include "monty.h"
#include <fcntl.h>
#include <stdio.h>

/**
 * get_char - reads character from stdin
 *
 * Return: character read
 */
int get_char(void)
{
	char buffer;
	ssize_t no_bytes_read;


	no_bytes_read = read(STDIN_FILENO, &buffer, 1);
	if (no_bytes_read == -1)
		return (-1);

	return ((int)buffer);
}
/**
 * _getline - reads line from stdin
 * @lineptr: line pointer
 * @n: number of character read
 * @stream: stream to read from
 * Return: number of character read
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	if (!lineptr || !n || !stream)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		*n = READSIZE;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	return (readline(lineptr, n, stream));
}
/**
 * resize_buffer - resize getline buffer
 * @buffer: pointer to buffer (double pointer)
 * @size: pointer to size
 * Return: resized buffer
 */
char *resize_buffer(char **buffer, size_t *size)
{
	size_t new_size;
	char *new_buffer = NULL;

	new_size = *size * 2;
	new_buffer = realloc(*buffer, new_size);
	if (new_buffer == NULL)
	{
		free(*buffer);
		*size = 0;
		return (NULL);
	}
	*size = new_size;
	*buffer = new_buffer;
	return (new_buffer);
}

/**
 * readline - read from file stream
 * @lineptr: line pointer
 * @stream: file stream
 * @n: number of bytes
 * Return: number of characters read
 */
size_t readline(char **lineptr, size_t *n, FILE *stream)
{
	size_t i = 0;
	static int ch;
	static char *buffer;

	while (1)
	{
		ch = fgetc(stream);
		if (ch == -1)
		{
			if (i == 0)
			{
				free(buffer);
				*lineptr = NULL;
				*n = 0;
				return (-1);
			}
			break;
		}
		else if (ch == '\n')
			break;

		if (i >= *n - 1)
		{
			buffer = resize_buffer(lineptr, n);
			if (buffer == NULL)
			{
				free(*lineptr);
				*lineptr = NULL;
				*n = 0;
				return (-1);
			}
		}
		(*lineptr)[i++] = ch;
	}
	(*lineptr)[i] = '\0';
	return (i);
}

