#include "monty.h"

/**
 * _div - adds the top two elements
 * @stack: pointer to TOS
 * @line_number: line number
 *
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	stack_t *new;

	if (!(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	new->n = tmp->n / tmp->prev->n;
	new->prev = NULL;
	new->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = new;
	*stack = new;
	tmp->next = NULL;
	free(tmp->prev);
	free(tmp);
}

/**
 * mul - substracts top two elements
 * @stack: pointer to TOS
 * @line_number: line number
 *
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	stack_t *new;

	if (!(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	new->n = tmp->n * tmp->prev->n;
	new->prev = NULL;
	new->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = new;
	*stack = new;
	tmp->next = NULL;
	free(tmp->prev);
	free(tmp);
}

/**
 * mod - computs the modulus of TOS
 * @stack: pointer to TOS
 * @line_number: line number
 *
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	tmp->n = tmp->n % tmp->prev->n;
	*stack = tmp;
	tmp->prev->next = NULL;
	free(tmp->prev);
}
