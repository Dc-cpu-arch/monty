#ifndef MONTY_INC_H
#define MONTY_INC_H

#include <stdlib.h>   /* malloc and frees handling */
#include <stdio.h>   /* file manipulation and prints */
#include <string.h> /* string compares and tokenization */

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
	FILE *fp;
	size buffer_size;
	char *buffer;
	unsigned int line_number;
	stack_t *head;
	instruction_t *code;
} file_t;

/* PROTOTYPES FOR ARMAGEDON */

void (*code(char *opcode))(stack_t **stack, unsigned int line_number);

#endif i/* MONTY_INC_H */
