#include "monty.h"
#include <stdbool.h>
#include <stdio.h>
/**
 * execute_cmd - execute commands
 * @stack: linked list implementation of stack
 * @line_no: line number
 * @cmd: command to be executed
 * @file: byte code file
 * @lineptr: line pointer
 * Return: void
 */
void execute_cmd(stack_t **stack, char **cmd, unsigned int line_no,
		FILE *file, char *lineptr)
{
	int i;
	char *command = NULL;
	instruction_t instructions[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub}, {"div", divi},
		{"mul", mul}, {"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr},
		{"stack", stack_mode}, {"queue", queue_mode}, {NULL, NULL}
	};
	(void)lineptr;

	if (cmd != NULL && cmd[0] != NULL)
	{
		command = cmd[0];
		if (command[0] == '#')
		{
			nop(stack, line_no);
		}
		else
		{
			for (i = 0; instructions[i].opcode != NULL; i++)
			{
				if (strcmp(command, instructions[i].opcode) == 0)
				{
					instructions[i].f(stack, line_no);
					break;
				}
			}
			if (instructions[i].opcode == NULL)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_no, cmd[0]);
				multi_free(cmd);
				fclose(file);
				free_stack(*stack);
				exit(EXIT_FAILURE);
			}
		}
	}
}
/**
 * push - push function for stack
 * @stack: stack
 * @line_number: code line number
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *arg = var.cmd[1];
	int value;

	if (arg != NULL && str_to_int(arg, &value))
	{
		if (var.mode == false)
			add_nodeint_end(stack, value);
		else
			add_node(stack, value);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(var.fd);
		multi_free(var.cmd);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
/**
 * pall - print all content of the stack
 * @stack: stack
 * @line_number: code line number
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *stack_ptr = *stack;
	(void)line_number;

	if (stack_ptr != NULL)
	{
		display(stack_ptr);
	}
}
/**
 * pint - prints the top most value of the stack
 * @stack: stack
 * @line_number: code line number
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *stack_ptr = *stack;

	if (stack_ptr == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(var.fd);
		multi_free(var.cmd);
		exit(EXIT_FAILURE);

	}
	else
	{
		printf("%d\n", (*stack)->n);
	}
}
/**
 * pop - remove top element of a stack
 * @stack: stack
 * @line_number: code line number
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(var.fd);
		multi_free(var.cmd);
		exit(EXIT_FAILURE);
	}
	delete_node(stack);
}
