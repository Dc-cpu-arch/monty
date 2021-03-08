#include "monty.h"
/**
 * push_stack - add node into a doubly linked list(stack).
 * @stack: Pointer head of the double linkedlist.
 * @line_number: line number of bytecode file.
 *
 * Return: Always nothing.
 */
void push_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	char *value;
	int data;

	if (strcmp(vars.format, "queue") == 0)
		queue_format(stack, line_number);
	else
	{
		value = strtok(NULL, " ");
		if (value == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_all(stack, vars.buffer, vars.fd);
			exit(EXIT_FAILURE);
		}
		data =  check_integer(stack, value, line_number);
		new_node = malloc(sizeof(stack_t));
		if (!new_node)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_all(stack, vars.buffer, vars.fd);
			exit(EXIT_FAILURE);
		}
		new_node->n = data;
		new_node->prev = NULL;
		if (*stack == NULL)
			new_node->next = NULL;
		else
		{
			(*stack)->prev = new_node;
			new_node->next = *stack;
		}
		*stack = new_node;
	}
}
/**
 * queue_format - Function that adds a node at the end.
 * @stack: Head pointer of the double linked list.
 * @line_number: line number of bytecode file.
 *
 * Return: Always nothing.
 */
void queue_format(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	stack_t *tmp = NULL;
	int data;
	char *value;

	value = strtok(NULL, " ");
	if (value == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_all(stack, vars.buffer, vars.fd);
		exit(EXIT_FAILURE);
	}
	data =  check_integer(stack, value, line_number);
	tmp = *stack;
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all(stack, vars.buffer, vars.fd);
		exit(EXIT_FAILURE);
	}
	new_node->n = data;
	if (*stack == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		new_node->prev = tmp;
		new_node->next = NULL;
		tmp->next = new_node;
	}
}
