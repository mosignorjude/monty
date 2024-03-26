#include "monty.h"
#include <ctype.h>
/**
 * str_dup - Function Duplicates a string
 * @str: The string to duplicate
 *
 * Return: A pointer to the newly allocated duplicate string, or NULL
 */
char *str_dup(char *str)
{
	char *dup_str;
	size_t len = 0;

	if (str == NULL)
		return (NULL);

	len = strlen(str);
	dup_str = malloc(len + 1);

	if (dup_str == NULL)
	{
		perror("Error: Memory allocation failed");
		return (NULL);
	}

	strcpy(dup_str, str);

	return (dup_str);
}
/**
 * multi_free - frees multiple Memories
 * @ptr: pointer to Memory
 *
 * Return: void
 */
void multi_free(char **ptr)
{
	int i;

	for (i = 0; ptr[i] != NULL; i++)
		free(ptr[i]);
	free(ptr);
}
/**
 * str_to_int - integer-string to integer
 * @str: string to conver
 * @result: pointer to the converted number
 * Return: converted integer
 */
int str_to_int(char *str, int *result)
{
	char ch, minus = '\0';
	int i, value;

	if (str == NULL || result == NULL)
		return (0);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (i == 0 && str[0] == '-')
			minus = str[0];
		else
		{
		ch = str[i];
		if (!isdigit(ch))
			return (0);
		}
	}
	value = atoi(str);
	if (minus)
		*result = -value;
	else
		*result = value;
	return (1);
}
/**
 * free_stack - free stack
 * @stack:  stack
 *
 *  Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	temp = stack;
	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
