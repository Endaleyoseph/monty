#include "monty.h"

/**
 * pall - prints all elements of the list
 * @stack: pointer to pointer to TOS
 * @line_number: line number
 *
 */

void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (!(stack) || !(*stack))
		return;
	while (*stack != NULL)
	{
		fprintf(stdout, "%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}

/**
 * pint - prints the value of TOS
 * @stack: pointer to TOS
 * @line_number: line number
 *
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!(stack) || !(*stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}
