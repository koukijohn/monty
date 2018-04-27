#include "monty.h"

/**
 * pint - This prints the integer value at top of stack.
 * @command: This is the data being accessed.
 *
 * Return: Void.
 */

void pint(command_t *command)
{
	stack_t *head = *command->head;

	if (head == NULL)
	{
		printf("L%d: can't pint, stack empty\n", command->line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}
