#include "monty.h"
/**
 * sub_stack - subtracts the top two elements of the stack.
 * @stack: Pointer head of the double linkedlist.
 * @line_number: line number of bytecode file.
 *
 * Return: Always nothing.
 */
void sub_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	int number_of_nodes;

	number_of_nodes = len_stack(*stack);
	if (number_of_nodes >= 2)
	{
		tmp = *stack;
		*stack = tmp->next;
		(*stack)->n = (*stack)->n - tmp->n;
		(*stack)->prev = NULL;
		free(tmp);
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_all(stack, vars.buffer, vars.fd);
		exit(EXIT_FAILURE);
	}
}
