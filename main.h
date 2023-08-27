#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define _POSIX_C_SOURCE 200809L
#define  _GNU_SOURCE
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct list_s - list of args passed to functions
 * @lc: line count
 * @size: size of stack
 * @opcode: command read from file
 * @parsed: parsed command
 * @fd: file to read from
 * @f: pointer to function
 *
 * Description: for functions
 */
typedef struct info_s
{
	int c, size;
	char *opcode, **parsed;
	FILE *fd;
	void (*f)(stack_t **stack, unsigned int line_number);

} info_t;
extern info_t info[];

stack_t *add_nodeint(stack_t **head, int n);
void parse(stack_t **st, info_t *info); 
void findcmd(info_t *info);
void handle(stack_t **stack, info_t *info);
void freelist(info_t *info);
void freeall(stack_t *stack, info_t *info);
void _pall(stack_t **st, unsigned int line_number);
void _push(stack_t **st, unsigned int line_number);
char *strdup(const char *str);
#endif
