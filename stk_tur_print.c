#include "monty.h"

/**
 * stk_pchar - prints the character at the top of the stack, followed
 * by a new line
 * @top: double pointer to the head of the stack
 * @pos: line number in monty file
 * Return: void
 */
void stk_pchar(stk_t **top, unsigned int pos)
{
	stk_t *currhead;

	currhead = *top;
	if (currhead == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", pos);
		fclose(progctx.fileptr);
		free(progctx.lncontent);
		free_stk(*top);
		exit(EXIT_FAILURE);
	}
	if (currhead->n > 127 || currhead->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", pos);
		fclose(progctx.fileptr);
		free(progctx.lncontent);
		free_stk(*top);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", currhead->n);
}

/**
 * stk_pstr - prints the string at the top of the stack, followed
 * by a new line
 * @top: double pointer to the head of the stack
 * @pos: line number in monty file
 * Return: void
 */
void stk_pstr(stk_t **top, unsigned int pos)
{
	stk_t *currenthead;
	(void)pos;

	currenthead = *top;
	while (currenthead != NULL)
	{
		if (currenthead->n > 127 || currenthead->n <= 0)
		{
			break;
		}
		printf("%c", currenthead->n);
		currenthead = currenthead->next;
	}
	printf("\n");
}

/**
 * stk_p - prints the top of the stack in LIFO mode
 * @top: double pointer to the head of the stack
 * @count: line number in the monty file
 * Return: void
 */
void stk_p(stk_t **top, unsigned int count)
{
	(void)top;
	(void)count;
	progctx.flags = 0;
}
