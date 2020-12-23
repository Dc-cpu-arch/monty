#ifndef MONTY_INC_H
#define MONTY_INC_H

#include <stdlib.h>   /* malloc and frees handling */
#include <stdio.h>   /* file manipulation and prints */
#include <string.h> /* string compares and tokenization */
#include <sys/types.h> /* open and close files*/
#include <sys/stat.h> /* open and close files */
#include <fcntl.h> /* open and close files */

/* STRUCTURES */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* GLOBAL VARIABLE [FILE STRUCTURE] */

/**
 * struct file_var - structure for file handling
 * @fp: file pointer to getline
 * @buffer_size: file line(s) size
 * @buffer: current line string
 * @line_number: current read line
 * @head: head of the stack (DLL)
 * @code: tokenized string with the commands
 *
 * Description: structure to handle the FILE variables for getline
 * and some other related variables usefull to decompose the
 * file's lines
 */
typedef struct file_var
{
	FILE *fp; /* NEEDS TO BE CLOSE */
	size_t buffer_size;
	char *buffer; /* NEEDS TO BE FREE */
	unsigned int line_number;
	stack_t *head; /* NEEDS TO BE FREE */
	instruction_t *code;
} file_t;

/* PROTOTYPES FOR ARMAGEDON */

void (*code(char *opcode))(stack_t **stack, unsigned int line_number);
void nop_cmd(stack_t **head, unsigned int line_number);

/* MEMORY MANAGEMENT */

void global_free(void);

#endif /* MONTY_INC_H */
