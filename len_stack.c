#include "monty.h"
/**
 * len_stack - Returns number of elements in a double linked list.
 * @head: Head of the double linked list.
 *
 * Return: the number of nodes.
 */
size_t len_stack(stack_t *head)
{
	stack_t *tmp = NULL;
	int n = 0;

	tmp = head;
	if (head)
	{
		while (tmp)
		{
			tmp = tmp->next;
			n++;
		}
		return (n);
	}
	return (0);
}
