#include "monty.h"

/**
 * push - This adds a new node to the top of a stack_t list.
 * @command: This is the data being accessed.
 *
 * Return: This returns the address of the new node or NULL if failed.
 */

void push(command_t *command)
{
	stack_t *new_node;
	stack_t **head;

	new_node = NULL;
	head = command->head;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (head == NULL)
	{
		printf("L%d: usage: push integer\n", command->line_number);
		exit(EXIT_FAILURE);
	}
	if (*head == NULL)
	{
		new_node->n = command->argument;
		new_node->next = *head;
		new_node->prev = NULL;
		*head = new_node;
		return;
	}

	(*head)->prev = new_node;
	new_node->n = command->argument;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
