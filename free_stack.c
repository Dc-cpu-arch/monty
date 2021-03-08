#include "monty.h"

/**
 * free_stack - Function that frees a double linked list (stack).
 * @head: Head of the double linked list.
 *
 * Return: Always nothing.
 */
void free_stack(stack_t **head)
{
	stack_t *tmp = NULL;

	if (*head)
	{
		while ((*head)->next)
		{
			tmp = *head;
			*head = (*head)->next;
			(*head)->prev = NULL;
			tmp->next = NULL;
			free(tmp);
		}
		free(*head);
	}
}
