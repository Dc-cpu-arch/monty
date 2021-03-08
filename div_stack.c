#include "monty.h"
/**
 * div_stack - divides second top element of the stack by top element of stack.
 * @stack: Pointer head of the double linkedlist.
 * @line_number: line number of bytecode file.
 *
 * Return: Always nothing.
 */
void div_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	int number_of_nodes;

	number_of_nodes = len_stack(*stack);
	if (number_of_nodes >= 2)
	{
		tmp = *stack;
		*stack = tmp->next;
		if (tmp->n != 0)
			(*stack)->n = (*stack)->n / tmp->n;
		else
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			free_all(stack, vars.buffer, vars.fd);
			exit(EXIT_FAILURE);
		}
		(*stack)->prev = NULL;
		free(tmp);
	}
	else
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_all(stack, vars.buffer, vars.fd);
		exit(EXIT_FAILURE);
	}
}
