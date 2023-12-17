#include "monty.h"

/**
 * qs_addnode - a function that adds a new node to the head of the stack
 * @top: double pointer to the head of the stack
 * @num: new value to the added to the head of the stack
 * Return: void
 */
void qs_addnode(stk_t **top, int num)
{
	stk_t *nnode, *currenthead;

	currenthead = *top;
	nnode = malloc(sizeof(stk_t));
	if (!nnode)
	{
		printf("Error\n");
		exit(0);
	}
	if (currenthead != NULL)
		currenthead->prev = nnode;
	nnode->n = num;
	nnode->next = *top;
	nnode->prev = NULL;
	*top = nnode;
}

/**
 * qs_addqueue - a fucntion thatadds a new node to the tail of the stack
 * @top: double pointer to the head of the stack
 * @num: new value to be added to the tail of the stack
 * Return: void
 */
void qs_addqueue(stk_t **top, int num)
{
	stk_t *nnode, *currenthead;

	currenthead = *top;
	nnode = malloc(sizeof(stk_t));
	if (!nnode)
	{
		printf("Error\n");
	}
	nnode->n = num;
	nnode->next = NULL;
	if (currenthead != NULL)
	{
		while (currenthead->next)
			currenthead = currenthead->next;
	}
	if (currenthead == NULL)
	{
		*top = nnode;
		nnode->prev = NULL;
	}
	else
	{
		currenthead->next = nnode;
		nnode->prev = currenthead;
	}
}

/**
 * qs_queue - a function that sets the stackmode to a queue using FIFO mode
 * @top: double pointer to the head of the stack
 * @count: line number in the monty file
 * Return: void
 */
void qs_queue(stk_t **top, unsigned int count)
{
	(void)top;
	(void)count;
	progctx.flags = 1;
}
