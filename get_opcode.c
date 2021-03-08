#include "monty.h"
/**
 * get_opcode - Calls for the function by opcode read.
 * @head: Pointer head of double linked list (stack).
 * @monty_command: Monty Command read from bytecode file.
 * @line_number:Number of line read from bytecode file.
 *
 * Return: Always nothing.
 */
void get_opcode(stack_t **head, char *monty_command, unsigned int line_number)
{
	int i;
	instruction_t command[] = {
		{"stack", format_stack},
		{"queue", format_queue},
		{"push", push_stack},
		{"pall", pall_stack},
		{"pint", pint_stack},
		{"pop", pop_stack},
		{"swap", swap_stack},
		{"add", add_stack},
		{"sub", sub_stack},
		{"mul", mul_stack},
		{"div", div_stack},
		{"mod", mod_stack},
		{"pchar", pchar_stack},
		{"pstr", pstr_stack},
		{"rotl", rotl_stack},
		{"rotr", rotr_stack},
		{NULL, NULL}
	};

	for (i = 0; command[i].opcode; i++)
	{
		if ((strcmp(command[i].opcode, monty_command)) == 0)
		{
			command[i].f(head, line_number);
			break;
		}
	}
	if (command[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, monty_command);
		free_all(head, vars.buffer, vars.fd);
		exit(EXIT_FAILURE);
	}
}
