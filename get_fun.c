#include "monty.h"

/**
 * get_fun - interpreate the instructions
 * @buffer: string read from a file
 * @stack: pointer to pointer to TOS
 *
 */

void get_fun(stack_t **stack, char *buffer)
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
			push(stack, line_number, token);
			token = strtok(NULL, "\n\t\a\r :;");
			line_number++;
			continue;
		}
		else if (strcmp(token, "push") == 0)
		{
			check_push = 1;
			token = strtok(NULL, "\n\t\a\r :;");
			continue;
		}
		else
		{
			if (get_opcode(token) != 0)
				get_opcode(token)(stack, line_number);
			else
			{
				free_list(stack);
				printf("L%u: unknown instruction %s\n", line_number, token);
				free(token);
				exit(EXIT_FAILURE);
			}
		}
			line_number++;
			token = strtok(NULL, "\n\t\a\r :;");
	}
	free(token);
}
