#include "monty.h"
/**
 * pstr_stack -  Prints the string starting at the top of the stack.
 * @stack: Pointer head of the double linkedlist.
 * @line_number: line number of bytecode file.
 *
 * Return: Always nothing.
 */
void pstr_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	(void)line_number;

	tmp = *stack;
	if (*stack)
	{
		while (tmp)
		{
			if (tmp->n >= 1 && tmp->n <= 127)
			{
				printf("%c", tmp->n);
				tmp = tmp->next;
			}
			else
				break;
		}
	}
	printf("\n");
}
