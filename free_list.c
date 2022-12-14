#include "monty.h"

/**
 * free_list - frees a linked list
 * @stack: pointer to pointer to TOS
 *
 */

void free_list(stack_t **stack)
{
	if (stack == NULL)
		return;

	while (*stack != NULL && (*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
	}
	free(*stack);
}
