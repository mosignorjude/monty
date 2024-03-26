#include "monty.h"
/**
 * rotr - rotates the stack to the top
 * @stack: stack
 * @line_number: line number of the code
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *stack_ptr, *next, *temp;
	int prev, curr_val;
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
		temp = stack_ptr;
		while (temp->next != NULL)
			temp = temp->next;
		prev = stack_ptr->n;
		stack_ptr->n = temp->n;
		while (stack_ptr->next != NULL)
		{
			next = stack_ptr->next;
			curr_val = next->n;
			next->n = prev;
			prev = curr_val;
			stack_ptr = next;
		}
	}
}

/**
 * stack_mode - sets format of the data to stack mode
 * @stack: the linked list
 * @line_number: line number of the code
 *
 * Return: void
 */
void stack_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	var.mode = true;
}

/**
 * queue_mode - sets format of the data to queue mode
 * @stack: the linked list
 * @line_number: line number of the code
 *
 * Return: void
 */
void queue_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	var.mode = false;
}



