#include "monty.h"

/**
 * pall - Prints all elements of a doubly linked list.
 * @command: This is the data being accessed.
 *
 * Return: Void.
 */

void pall(command_t *command)
{
	stack_t *head = *command->head;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
