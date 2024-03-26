#include "monty.h"
/**
 * add_node - adds data to the beginning of a linked list
 * @head: head node of the linked list
 * @data: data to be inserted
 *
 * Return: void
 */
stack_t *add_node(stack_t **head, int data)
{
	stack_t *new_node, *tail;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		perror("malloc failed");
		return (NULL);
	}
	new_node->n = data;
	if (*head == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*head = tail = new_node;
	}
	else
	{
		(*head)->prev = new_node;
		new_node->next = *head;
		*head = new_node;
	}
	return (new_node);
}

/**
 * add_nodeint_end - function that adds a new node at the end of a list.
 * @head: pointer to first node.
 * @data: given int to be added.
 * Return: the address of the new element
 */
stack_t *add_nodeint_end(stack_t **head, int data)
{
	stack_t *new_node;
	stack_t *temp;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = data;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
	}
	return (new_node);
}
/**
 * display -print the contents of stacked linked list
 * @head: head node of the linked list
 *
 * Return: void
 */
size_t display(stack_t *head)
{
	size_t count = 0;

	if (head == NULL)
	{
		printf("stack underflow\n");
	}
	else
	{
		while (head != NULL)
		{
			printf("%d\n", head->n);
			head = head->next;
			count++;
		}
	}
	return (count);
}
/**
 * delete_node - delete the top contents of linked list stack
 * @head: stacked linked list to be deleted
 *
 * Return: value of the deleted node
 */
int delete_node(stack_t **head)
{
	int data;
	stack_t *temp;

	if (*head != NULL)
	{
		temp = *head;
		(*head)->prev = NULL;
		*head = (*head)->next;
		data = temp->n;
		free(temp);
	}
	return (data);
}
/**
 * node_len - calculates the length of a list
 * @head: head of list
 * Return: number of elements in the list
 */
size_t node_len(stack_t *head)
{
	size_t count = 0;

	while (head)
	{
		head = head->next;
		count++;
	}
	return (count);
}
