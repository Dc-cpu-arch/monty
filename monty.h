#ifndef _FILE_H_
#define _FILE_H_

/*C standard libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>

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

/*Call the function for the command opcode*/
void get_opcode(stack_t **head, char *monty_command, unsigned int line_number);

/*Check if is a integer and convert it*/
int check_integer(stack_t **head, char *value, unsigned int line_number);

/*Add a node into the top of the stack*/
void push_stack(stack_t **stack, unsigned int line_number);

/*Prints all the stack data*/
void pall_stack(stack_t **stack, unsigned int line_number);

/* Prints the top of the stack*/
void pint_stack(stack_t **stack, unsigned int line_number);

/*Remove the top node of the stack*/
void pop_stack(stack_t **stack, unsigned int line_number);

/*Swaps the top two data value on the stack*/
void swap_stack(stack_t **stack, unsigned int line_number);

/*Swaps the top two data value on the stack*/
void add_stack(stack_t **stack, unsigned int line_number);

/*Calculate the Lenght of the stack*/
size_t len_stack(stack_t *head);

/*Subtracts the top two data value on the stack*/
void sub_stack(stack_t **stack, unsigned int line_number);

/*Multiply the top two data value on the stack*/
void mul_stack(stack_t **stack, unsigned int line_number);

/*Divide the top two data value on the stack*/
void div_stack(stack_t **stack, unsigned int line_number);

/*Computes the rest of the division of top two data value on stack*/
void mod_stack(stack_t **stack, unsigned int line_number);

/*Function that frees a double linked list (stack)*/
void free_stack(stack_t **head);

/*Function that frees all when a error occurs*/
void free_all(stack_t **head, char *buffer, FILE *fd);

/*Prints the char at the top of the stack*/
void pchar_stack(stack_t **stack, unsigned int line_number);

/*Prints the string starting at the top of the stack*/
void pstr_stack(stack_t **stack, unsigned int line_number);

/*Rotates the stack to the top*/
void rotl_stack(stack_t **stack, unsigned int line_number);

/*Rotates the stack to the bottom*/
void rotr_stack(stack_t **stack, unsigned int line_number);

/*Add a node at the end*/
void queue_format(stack_t **stack, unsigned int line_number);

/*Function to switch from stack to queue*/
void format_queue(stack_t **stack, unsigned int line_number);

/*Function to switch from queue to stack*/
void format_stack(stack_t **stack, unsigned int line_number);

/**
 * struct variable_s - Variables to free the stack when a error happen.
 * @buffer: Buffer save with the get.
 * @fd: FILE pointer to close the file open.
 *
 * Description: Variables need to free the stack when a error happens.
 */
typedef struct variable_s
{
	char *buffer;
	FILE *fd;
	char *format;
} variable_t;

/*Global variable*/
extern variable_t vars;
variable_t vars;

#endif /*_FILE_H_*/
