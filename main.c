#include "monty.h"
/**
 * main - Programm to execute command monty bytycodes
 * @argc: Arguments count from the terminal
 * @argv: Arguments array of strings from the terminal.
 *
 * Return: 0 for success and 1 when it fails.
 */
int main(int argc, char **argv)
{
	char *buffer = NULL, *monty_command = NULL;
	unsigned int line_number = 1;
	stack_t *head = NULL;
	FILE *fd;
	size_t len;

	vars.buffer = NULL;
	vars.fd = NULL;
	vars.format = "stack";
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	vars.fd = fd;
	while (getline(&buffer, &len, fd) != -1)
	{
		buffer[strlen(buffer) - 1] = '\0';
		vars.buffer = buffer;
		monty_command = strtok(buffer, " ");
		if (monty_command != NULL && strcmp(monty_command, "nop") != 0
		    && monty_command[0] != '#')
		{
			get_opcode(&head, monty_command, line_number);
		}
		line_number++;
	}
	free(buffer);
	free_stack(&head);
	fclose(fd);
	return (0);
}
