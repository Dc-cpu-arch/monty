#include "monty.h"
/**
 * pop_stack - Remove the top data of the stack.
 * @stack: Pointer head of the double linkedlist.
 * @line_number: line number of bytecode file.
 *
 * Return: Always nothing.
 */
void pop_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (*stack && stack)
	{
		tmp = *stack;
		*stack = tmp->next;
		if (tmp->next)
			tmp->next->prev = NULL;
		free(tmp);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_all(stack, vars.buffer, vars.fd);
		exit(EXIT_FAILURE);
	}
}
