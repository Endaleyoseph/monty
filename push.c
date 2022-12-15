#include "monty.h"

/**
 * push - inserts a node to the TOS
 * @stack: pointer to pointer to top of stack
 * @line_number: line number
 * @n: number to be added
 * Return: 0 on success, or -1 if it fails
 */

int push(stack_t **stack, unsigned int line_number, const char *n)
{
	stack_t *new;

	if (isdigit(atoi(n)) != 0 || (atoi(n) == 0 && *n != '0'))
	{
		free_list(stack);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		return (-1);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(n);
	new->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new;
	new->next = *stack;
	*stack = new;
	return (0);
}

/**
 * pop - removes the TOS element
 * @stack: pointer to TOS
 * @line_number: line number
 *
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_list(stack);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	if ((*stack)->next == NULL)
	{
		*stack = NULL;
		free(tmp);
	}
	else
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
}
