#include "monty.h"

/**
 * add - adds the top two elements
 * @stack: pointer to TOS
 * @line_number: line number
 *
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	stack_t *new;

	if (!(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	new->n = tmp->prev->n + tmp->n;
	new->prev = NULL;
	new->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = new;
	*stack = new;
	tmp->next = NULL;
	free(tmp->prev);
	free(tmp);
}
