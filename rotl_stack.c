#include "monty.h"
/**
 * rotl_stack - Rotates the stack to the top
 * @stack: Pointer head of the double linkedlist.
 * @line_number: line number of bytecode file.
 *
 * Return: Always nothing.
 */
void rotl_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	int data;
	(void)line_number;

	tmp = *stack;
	if (*stack)
	{
		data = tmp->n;
		while (tmp->next)
		{
			tmp->n = tmp->next->n;
			tmp = tmp->next;
		}
		tmp->n = data;
	}
}
