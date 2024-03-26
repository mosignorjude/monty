#include "monty.h"
/**
 * swap - swap top element of a stack
 * @stack: stack
 * @line_number: code line number
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int val;

	if (*stack == NULL || node_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(var.fd);
		multi_free(var.cmd);
		if (*stack)
			free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	val = (*stack)->n;
	temp = (*stack)->next;
	(*stack)->n = temp->n;
	temp->n = val;
}
/**
 * add - add top element of a stack
 * @stack: stack
 * @line_number: code line number
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int val_1, val_2;

	if (*stack == NULL || node_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
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
	(*stack)->n = val_1 + val_2;
}
/**
 * nop - does nothing
 * @stack: stack
 * @line_number: code line number
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}
/**
 * sub - subtract top element of a stack
 * @stack: stack
 * @line_number: code line number
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int val_1, val_2;

	if (*stack == NULL || node_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
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
	(*stack)->n = val_2 - val_1;
}
/**
 * divi - divide top element of a stack
 * @stack: stack
 * @line_number: code line number
 * Return: void
 */
void divi(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int val_1, val_2;

	if (*stack == NULL || node_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
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
	(*stack)->n = val_2 / val_1;
}
