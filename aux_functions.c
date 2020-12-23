#include "monty.h"
file_t file;

/**
 * global_free - frees all the allocations on the program
 */
void global_free(void)
{
	stack_t *current = file.head, *temp = NULL;

	if (file.buffer)
		free(file.buffer);
	if (file.fp)
		close(file.fp);
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

/**
 * code - fetches a function for a command request
 * @opcode: operation code [command] from tokenized buffer
 * 
 * Return: void
 */
void (*code(char *opcode))(stack_t **stack, unsigned int line_number)
{
	unsigned int i = 0;

	instruction_t commands[] = {
	//	{"push", push_cmd},
	//	{"pall", pall_cmd},
	//	{"pint", pint_cmd},
	//	{"pop", pop_cmd},
	//	{"swap", swap_cmd},
		{"nop", nop_cmd},
		{NULL, NULL}
	};

	while (commands[i].opcode)
	{
		if (strcmp(commands[i].opcode, opcode) == 0)
			return (commands[i].f);
		i++;
	}
	return (NULL);
}
