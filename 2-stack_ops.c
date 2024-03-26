#include "monty.h"
#include <stdlib.h>
/**
 * mul - multiply top element of a stack
 * @stack: stack
 * @line_number: code line number
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int val_1, val_2;

	if (*stack == NULL || node_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(var.fd);
		multi_free(var.cmd);
		if (*stack)
			free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	val_1 = temp->n;
	*stack = (*stack)->next;
	val_2 = (*stack)->n;
	free(temp);
	(*stack)->n = val_2 * val_1;
}
/**
 * mod - modulus of top element of a stack
 * @stack: stack
 * @line_number: code line number
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int val_1, val_2;

	if (*stack == NULL || node_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(var.fd);
		multi_free(var.cmd);
		if (*stack)
			free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	val_1 = temp->n;
	if (val_1 == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(var.fd);
		multi_free(var.cmd);
		if (*stack)
			free_stack(*stack);
		exit(EXIT_FAILURE);

	}
	*stack = (*stack)->next;
	val_2 = (*stack)->n;
	free(temp);
	(*stack)->n = val_2 % val_1;
}
/**
 * pchar - prints the top most char value of the stack
 * @stack: stack
 * @line_number: code line number
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	char ch;
	stack_t *stack_ptr = *stack;

	if (stack_ptr == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(var.fd);
		multi_free(var.cmd);
		exit(EXIT_FAILURE);

	}
	else
	{
		if ((*stack)->n >= 0 && (*stack)->n <= 127)
		{
			ch = (*stack)->n;
			printf("%c\n", ch);
		}
		else
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n",
					line_number);
		}
	}
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: stack
 * @line_number: line number of the code
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	char ch;
	char *buffer;
	size_t index = 0;
	stack_t *stack_ptr = *stack;
	(void)line_number;

	if (stack_ptr == NULL)
	{
		printf("\n");
		fclose(var.fd);
		multi_free(var.cmd);
		exit(EXIT_SUCCESS);
	}
	else
	{
		buffer = malloc(sizeof(char *) * (node_len(stack_ptr) + 1));
		while (stack_ptr->next != NULL &&
				(stack_ptr->n > 0 && stack_ptr->n <= 127))
		{
			ch = stack_ptr->n;
			buffer[index] = ch;
			stack_ptr = stack_ptr->next;
			index++;
		}
		buffer[index] = '\0';
		printf("%s\n", buffer);
		free(buffer);
	}
}
/**
 * rotl - rotates the stack to the top
 * @stack: stack
 * @line_number: line number of the code
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *stack_ptr, *next;
	int top;
	(void)line_number;
	stack_ptr = *stack;

	if (stack_ptr == NULL)
	{
		fclose(var.fd);
		multi_free(var.cmd);
		exit(EXIT_SUCCESS);
	}
	else
	{
		top = stack_ptr->n;
		while (stack_ptr->next != NULL)
		{
			next = stack_ptr->next;
			stack_ptr->n = next->n;
			stack_ptr = stack_ptr->next;
		}
		stack_ptr->n = top;
	}
}
