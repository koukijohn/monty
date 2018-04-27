#ifndef __MONTY__
#define __MONTY__

/*header files*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

/*structures*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct command_s - This is a command struct.
 * @argument: This is the argument for the function.
 * @line_number: This is the line number to be evaluated.
 * @operation: The name of the operation.
 * @mode: This is the stack or queue mode.
 * @head: This is the head of the linked list.
 * @tail: This is the tail of the linked list.
 *
 * Decription: This holds our argument, line_number, operation, mode,
 * head, and the end.
 */

typedef struct command_s
{
	int argument;
	unsigned int line_number;
	char *operation;
	int *mode;
	stack_t **head;
	stack_t **end;
} command_t;


/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(command_t *command);
} instruction_t;

/*prototypes*/

int main(int argc, char **argv);
void freedom(stack_t **head);
void evaluation(stack_t **head, stack_t **end, int *mode,
		unsigned int line_number, char *input);
int the_breaker(char *input, command_t *command);
void the_executer(command_t *command);
void push(command_t *command);
void pop(command_t *command);
void nop(command_t *command);
void pall(command_t *command);
void pint(command_t *command);

#endif /*__MONTY__*/
