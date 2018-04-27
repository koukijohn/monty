#include "monty.h"

/**
 * the_breaker - This breaks the input line into individual tokens.
 * @input: This is the line of input to break(parse) into tokens.
 * @command: The arguments sent into the function.
 *
 * Return: 0 skips the line, 1 moves onto the line.
 */
int the_breaker(char *input, command_t *command)
{
	char the_deliminator[] = " \t\r\n";
	char *argument;
	char *the_breaker;
	int size;
	unsigned int line_number = command->line_number;

	if (input == NULL)
		return (0);

	the_breaker = strtok(input, the_deliminator);
	if (the_breaker == NULL)
		return (0);
	if (*the_breaker == '#')
		return (0);
	if (strcmp(the_breaker, "stack") == 0)
	{
		*command->mode = 0;
		return (0);
	}
	if (strcmp(the_breaker, "queue") == 0)
	{
		*command->mode = 1;
		return (0);
	}
	if (strcmp(the_breaker, "push") == 0)
	{
		argument = strtok(NULL, the_deliminator);
		if (argument == NULL)
		{
			printf("L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);

		}
		size = strlen(argument);
		while (size--)
		{
			if (size == 0 && argument[size] == '-')
				break;
			if (argument[size] > 57 || argument[size] < 48)
			{
				printf("L%d: usage: push integer\n",
				       line_number);
				exit(EXIT_FAILURE);
			}
		}
		command->argument = atoi(argument);
		command->operation = the_breaker;
		return (1);
	}
	command->operation = the_breaker;
	return (1);
}
