#include "monty.h"

/**
 * freedom - This frees our stack.
 * @head: This points to our head.
 *
 * Return: Void.
 */

void freedom(stack_t **head)
{
	stack_t *traverser;
	stack_t *newnode;

	if (*head != NULL)
	{
		traverser = *head;
		*head = NULL;

		while (traverser->next != NULL)
		{
			newnode = traverser;
			traverser = traverser->next;
			free(newnode);
		}
		free(traverser);
	}
}
