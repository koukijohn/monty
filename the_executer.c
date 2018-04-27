#include "monty.h"

/**
 * the_executer - This runs the specified function.
 * @command: This is the data to pss to the function.
 *
 * Return: Void.
 */

void the_executer(command_t *command)
{
	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
/*		{"swap", swap},{"add", add},*/
		{"nop", nop},
	};
	int x = 0;

	while (functions[x].opcode != NULL)
	{
		if (strcmp(command->operation, functions[x].opcode) == 0)
		{
			functions[x].f(command);
			return;
		}
		x++;
	}
	printf("L%d: unknown instruction %s\n", command->line_number,
	       command->operation);
	exit(EXIT_FAILURE);
}
