#include "monty.h"

/**
 * nop_cmd - nothing on particular
 * @head: head of a DLL
 * @line_number: line of the file
 */
void nop_cmd(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
}

/**
 * push_cmd - pushes an element to the stack
 * @head: head of a DLL
 * @line_number: current line of the file
 */
void push_cmd(stack_t **head, unsigned int line_number)
{
	char *string = NULL;
	unsigned int i = 0;
	int minus = 1;
	stack_t *new = NULL, *current;

	string = strtok(NULL, " \n\t");
	if (!string)
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		global_free(), exit(EXIT_FAILURE);
	if (string[0] == '-')
		minus = -1, string++;
	while (string[i] != '\000' && string[i] != '\n')
	{
		if (isdigit(string[i]) == 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			global_free(), exit(EXIT_FAILURE);
		}
		i++;
	}
	new = malloc(sizeof(stack_t));
	if (!new)
		fprintf(stderr, "Error: malloc failed\n"), global_free(),
		exit(EXIT_FAILURE);
	new->n = minus * atoi(string);
	new->next = NULL;
	if (!*head)
		new->prev = NULL, *head = new;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		new->prev = current;
		current->next = new;
	}
}

/**
 * pall_cmd - prints all the values on the stack, starting from the top
 * @head: head of a DLL
 * @line_number: current line of the file
 */
void pall_cmd(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	(void) line_number;
	if (*head)
	{
		while (current->next)
			current = current->next;
		while (current)
		{
			fprintf(stdout, "%d\n", current->n);
			current = current->prev;
		}
	}
}
