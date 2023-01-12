#include "main.h"
int argument_counter(char *input);

char **command = NULL;

int main(void)
{
	char *input = NULL;
	size_t size_input = 0;
	int isat = isatty(STDIN_FILENO);
	
	isat && write(1, "$ ", 2);
	while (getline(&input, &size_input, stdin) >= 0)
	{
		isat && write(1, "$ ", 2);
	}
	if (input) free(input);
	return (0);
}
int argument_counter(char *copy_input)
{
	int counter = 0;
	char *tok = strtok(copy_input, " \t\n");
	while (tok)
	{
		counter++;
		tok = strtok(NULL, " \t\n");
	}
	free(copy_input);
	return counter;
}