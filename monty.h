#ifndef STKQS_H
#define STKQS_H

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>

/**
 * struct progctx_s - structure for program data storage
 * @argval: pointer to values or arguments
 * @fileptr: pointer to the file associated with the monty program
 * @lncontent: pointer ot the content of the line
 * @flags: flag containing the mode-switch between stack and queue
 */
typedef struct progctx_s
{
	char *argval;
	FILE *fileptr;
	char *lncontent;
	int flags;
} progctx_t;
extern progctx_t progctx;

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
} stk_t;

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
	void (*f)(stk_t **stack, unsigned int line_number);
} instruction_t;

void stk_push(stk_t **top, unsigned int num);
void stk_pop(stk_t **top, unsigned int count);
void stk_swap(stk_t **top, unsigned int count);
void stk_pint(stk_t **top, unsigned int pos);
void stk_pall(stk_t **top, unsigned int num);

void stk_add(stk_t **top, unsigned int count);
void stk_sub(stk_t **top, unsigned int count);
void stk_mul(stk_t **top, unsigned int count);
void stk_div(stk_t **top, unsigned int count);
void stk_mod(stk_t **top, unsigned int count);

void stk_pchar(stk_t **top, unsigned int pos);
void stk_pstr(stk_t **top, unsigned int pos);
void stk_p(stk_t **top, unsigned int count);

void stk_nop(stk_t **top, unsigned int count);

void free_stk(stk_t *top);

void qs_addnode(stk_t **top, int num);
void qs_addqueue(stk_t **top, int num);
void qs_queue(stk_t **top, unsigned int count);

void stk_rotl(stk_t **top, unsigned int count);
void stk_rotr(stk_t **top, unsigned int count);

int sq_execute(char *lncontent,
		stk_t **top, unsigned int count, FILE *fileptr);

#endif
