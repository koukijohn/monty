#include "monty.h"

/**
 * main - This is our entry point into our code.
 * @argc: This is our argument count.
 * @argv: This is our argument vector.
 *
 * Return: Always 0.
 */

int main(int argc, char **argv)
{
	FILE *stream;
	char *input;
	size_t length = 0;
	ssize_t read;
	stack_t *head = NULL;
	stack_t *end = NULL;
	int mode = 0;
	unsigned int line_number = 1;

	if(argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}


	while ((read = getline(&input, &length, stream) != -1))
	{
		evaluation(&head, &end, &mode, line_number, input);
		line_number++;
	}

	fclose(stream);
	free(input);
	freedom(&head);
	return (EXIT_SUCCESS);
}
