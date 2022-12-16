#include "monty.h"
/**
 * filter - filters opcode
 * @opcode: opcode
 * Return: 1 on success, -1 if it fails
 */

int filter(char *opcode)
{
	char *a[] = {"add", "sub", "div", "swap", "mul", "mod", NULL};
	int i = 0;

	while (a[i] != NULL)
	{
		if (strcmp(opcode, a[i]) == 0)
			return (1);
		i++;
	}
	return (-1);
}

/**
 * check_stack - check stack status
 * @stack: pointer to TOS
 * @token: opcode
 * @line: line number
 * Return: 0 on success, -1 if it fails
 */
int check_stack(stack_t **stack, char *token, unsigned int line)
{
	if (strcmp(token, "pop") == 0)
	{
		if (!(stack) || !(*stack))
		{
			free_list(stack);
			fprintf(stderr, "L%u: can't pop an empty stack\n", line);
			return (-1);
		}
	}
	else if (strcmp(token, "pint") == 0)
	{
		if (!(stack) || !(*stack))
		{
			free_list(stack);
			fprintf(stderr, "L%u: can't pint, stack empty\n", line);
			return (-1);
		}
	}
	else if (filter(token) == 1)
	{
		if (!(stack) || !(*stack) || (*stack)->next == NULL)
		{
			free_list(stack);
			fprintf(stderr, "L%u: can't %s, stack too short\n", line, token);
			return (-1);
		}
	}
	return (0);
}

/**
 * get_fun - interpreate the instructions
 * @buffer: string read from a file
 * @stack: pointer to pointer to TOS
 * Return: 0 on success, -1 if it fails
 */

int get_fun(stack_t **stack, char *buffer)
{
	unsigned int line_number = 1;
	int check_push = 0;
	char *token = NULL;

	token = strtok(buffer, "\n\t\a\r :;");
	while (token != NULL)
	{
		if (check_push == 1)
		{
			check_push = 0;
			if (push(stack, line_number, token) == -1)
				return (-1);
			token = strtok(NULL, "\n\t\a\r :;");
			line_number++;
			continue;
		}
		else if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, "\n\t\a\r :;");
			check_push = 1;
			continue;
		}
		else
		{
			if (check_stack(stack, token, line_number) == -1)
				return (-1);
			if (get_opcode(token) != 0)
				get_opcode(token)(stack, line_number);
			else
			{
				free_list(stack);
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
				return (-1);
			}
		}
			line_number++;
			token = strtok(NULL, "\n\t\a\r :;");
	}
	return (0);
}
