#include "monty.h"

/**
 * pop - This removes the top element of the stack.
 * @command: This is data we are accessing from the command.
 *
 * Return: Void.
 */

void pop(command_t *command)
{
	stack_t **head = command->head;
	stack_t *the_removed = NULL;

	if (head == NULL || *head == NULL)
	{
		printf("L%d: can't pop an empty stack\n",
		       command->line_number);
		exit(EXIT_FAILURE);
	}
	the_removed = *head;
	*head = (*head)->next;
	free(the_removed);
}
