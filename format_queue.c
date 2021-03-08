#include "monty.h"
/**
 * format_queue - Function to switch from stack to queue.
 * @stack: Pointer head of the double linkedlist.
 * @line_number: line number of bytecode file.
 *
 * Return: Always nothing.
 */
void format_queue(stack_t **stack, unsigned int line_number)
{
	(void)(*stack);
	(void)line_number;
	vars.format = "queue";
}
