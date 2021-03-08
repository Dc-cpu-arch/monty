#include "monty.h"

/**
 * free_all - Function that frees all when a error occurs.
 * @head: Head of the double linked list.
 * @buffer: Buffer string to free.
 * @fd: FILE pointer to close the file open.
 *
 * Return: Always nothing.
 */
void free_all(stack_t **head, char *buffer, FILE *fd)
{
	if (buffer)
		free(buffer);
	free_stack(head);
	fclose(fd);
}
