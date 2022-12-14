#include "monty.h"

/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: Always 0 (on success)
 */

int main(int argc, char **argv)
{
	int fd, rd;
	char *buffer;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buffer = malloc(sizeof(char) * 100);
	if (buffer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	rd = read(fd, buffer, 100);
	if (rd == -1)
	{
		fprintf(stderr, "Error: can't read file %s\n", argv[1]);
		free(buffer);
		close(fd);
		exit(EXIT_FAILURE);
	}
	get_fun(&stack, buffer);
	free_list(&stack);
	free(buffer);
	close(fd);

	return (0);
}
