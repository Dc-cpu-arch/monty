#include "monty.h"
file_t file;

/**
 * main - gets the file pointer and decompose its strings to match commands
 * with the proper functions
 * @argc: number of arguments passed to the program
 * @argv: vertor [string] of arguments passed
 *
 * Return: EXIT_SUCCESS ^ EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	char *cmd;

	void (*funk)(stack_t **stack, unsigned int line_number) = NULL;

	file.line_number = 1;
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		global_free();
		exit(EXIT_FAILURE);
	}
	file.fp = fopen(argv[1], "r"); 
	if (!file.fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		global_free();
		exit(EXIT_FAILURE);
	}
	while (getline(&file.buffer, &file.buffer_size, file.fp) != EOF)
	{
		cmd = strtok(file.buffer, " \n\t");
		if (cmd[0] == '#')
			continue;
		if (cmd)
		{
			funk = code(cmd);
			if (funk != NULL)
				funk(&file.head, file.line_number);
			else
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", file.line_number, cmd);
				global_free();
				exit(EXIT_FAILURE);
			}
		}
		file.line_number++;
	}
	global_free();
	exit(EXIT_SUCCESS);
}
