#include "main.h"

/**
 * push - inserts a node to the TOS
 * @stack: pointer to pointer to top of stack
 * @line_number: line number
 * @n: number to be added
 *
 */

void push(stack_t **stack, unsigned int line_number, const char *n)
{
	stack_t *new;

	if ((isdigit(atoi(n)) == 0 && *n != '0') || n == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction push", line_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(n);
	new->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new;
	new->next = *stack;
	*stack = new;
}
