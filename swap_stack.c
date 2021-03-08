#include "monty.h"
/**
 * swap_stack - swaps the top two elements of the stack.
 * @stack: Pointer head of the double linkedlist.
 * @line_number: line number of bytecode file.
 *
 * Return: Always nothing.
 */
void swap_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	int data, number_of_nodes;

	number_of_nodes = len_stack(*stack);
	if (number_of_nodes >= 2)
	{
		tmp = (*stack)->next;
		data = tmp->n;
		tmp->n = (*stack)->n;
		(*stack)->n = data;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_all(stack, vars.buffer, vars.fd);
		exit(EXIT_FAILURE);
	}
}
