#include "monty.h"
#include <unistd.h>
var_t var = {NULL, NULL, NULL, true};
/**
 * main - entry point
 * @ac: argument counter
 * @av: argument vector array
 * Return: 0 on success and 1 on failure
 */
int main(int ac, char **av)
{
	char *montycode = av[1];
	char *line, buffer[READSIZE], **cmd;
	const char *delim = " \n";
	FILE *fd;
	unsigned int line_no = 0;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(montycode, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", montycode);
		exit(EXIT_FAILURE);
	}
	var.fd = fd;
	while ((line = fgets(buffer, READSIZE, fd)) != NULL)
	{
		var.line = line;
		line_no++;
		cmd = split_str(line, delim);
		if (cmd == NULL)
			continue;
		var.cmd = cmd;
		execute_cmd(&stack, cmd, line_no, fd, line);
		multi_free(cmd);
	}
	free(line);
	fclose(fd);
	free_stack(stack);
	return (0);
}
