#include "monty.h"

/**
 * evaluation - This function evaluates the operation.
 * @head: This is the head of the doubly linked list.
 * @end: This is the end of the doubly linked list.
 * @mode: This is the stack (or queue) mode.
 * @line_number: This is the line number to be evaluated.
 * @input: This is the line of input to parse.
 *
 * Return: Void.
 */

void evaluation(stack_t **head, stack_t **end, int *mode,
		unsigned int line_number, char *input)
{
	command_t command;

	command.head = head;
	command.end = end;
	command.mode = mode;
	command.line_number = line_number;

	if (the_breaker(input, &command))
		the_executer(&command);
}
